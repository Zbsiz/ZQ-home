#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <net/if.h>
#include <net/if_arp.h>
#include <sys/ioctl.h>
#include <ifaddrs.h>
#include <netinet/in.h>

int read_in(int socket, char *buf, int len)
{
  char *s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);
  while ((c>0) && (s[c-1] != '\n')) {
    s += c; slen -= c;
    c = recv(socket, s, slen, 0);
  }
  if (c < 0)
    return c;
  else if (c == 0)
    buf[0] = '\0';
  else
    s[c-1]='\0';
  return len - slen;
}

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int say(int socket, char *s)
{
  int result = send(socket, s, strlen(s), 0);
  if (result == -1)
    fprintf(stderr, "%s: %s\n", "和客户端通信时发生了错误", strerror(errno));
  return result;
}

int main(int argc, char *argv[])
{
    struct ifaddrs * ifAddrStruct=NULL;
    void * tmpAddrPtr=NULL;
    char ip_addr_show[38];

    getifaddrs(&ifAddrStruct);

    while (ifAddrStruct!=NULL) {

        if (ifAddrStruct->ifa_addr->sa_family == PF_INET) {
            tmpAddrPtr=&((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            if (!strncasecmp("eth0", ifAddrStruct->ifa_name,4))
            {
                strcpy(ip_addr_show, addressBuffer);
                int ip_addr_size = strlen(ip_addr_show);
                ip_addr_show[ip_addr_size] = '\r';
                ip_addr_show[ip_addr_size+1] = '\n';
                ip_addr_show[ip_addr_size+2] = '\0';
            }
        }
        ifAddrStruct=ifAddrStruct->ifa_next;
    }
  
  int listener_d = socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);

  int reuse = 1;
  if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
    error("Can't set the 'reuse' option on the socket.");

  if (bind(listener_d,  (struct sockaddr *) &name, sizeof(name)) == -1)
    error("Can't bind the port");

  listen(listener_d, 10);
  puts("waiting for connection");

  for(;;) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
    if (connect_d == -1)
      error("Can't open secondary socket");
    char buf[255];
    if ( !fork()) {
      if (say(connect_d, "Internet Knock-Knock Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") != -1) {     
        read_in(connect_d, buf, sizeof(buf));
        if (!strcmp("Where is here?", buf))    
          say(connect_d, ip_addr_show);
      }
      close(connect_d);
      exit(0);
    }
    close(connect_d);
  }


  return 0;
}
