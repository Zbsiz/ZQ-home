#include <stdio.h>                      /* 该服务器脚本可以监听本机所有ip的30000地址，可以与多个客户端交互数据     */
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int listener_d;

void handle_shutdown(int sig)      /*  如果有人在服务器运行期间按了 Ctrl-c (也就是发送了 SIGINT信号)，这个函数就会赶在程序结束前关闭套接字   */
{
  if (listener_d)
    close(listener_d);
  fprintf(stderr, "\nBye!\n");
  exit(0);
}

void error(char *msg)      /* 该函数用来返回错误信息  */
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int open_listener_socket()
{
  int s = socket(PF_INET, SOCK_STREAM, 0);
  if (s == -1)
    error("Can't open socket");

  return s;
}

void bind_to_port(int socket, int port)     /* 该函数用来绑定端口    */
{
  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  int reuse = 1;
  if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1)
    error("Can't set the reuse option on the socket");
  int c = bind(socket, (struct sockaddr *)&name, sizeof(name));
  if (c == -1)
    error("Can't bind to socket");
}

int say(int socket, char *s)      /*  该函数用来向客户端发送字符串  */
{
  int result = send(socket, s, strlen(s), 0);
  if (result == -1)
    fprintf(stderr, "%s: %s\n", "和客户端通信时发生了错误", strerror(errno));
  return result;
}

int read_in(int socket, char *buf, int len)     /* 该函数创建为接收客户端发出的字符串，将会读取所有的字符串，比如带有空格之间的 "Nihao a..."     */
{
  char *s = buf;
  int slen = len;
  int c = recv(socket, s, slen, 0);         /* <读了几个字节> = recv(<描述符>, <缓冲区>, <要读几个字节>, 0);  注意 recv() 不以 \0 结尾，以 \r\n 结尾     */
  while ((c>0) && (s[c-1] != '\n')) {         /*  循环读取字符，直到没有字符或读取到 '\n' ， c>0 表示 c赋值成功注意 recv的返回值为字节数， s[c-1] 表示字符串倒数第二个字段    */
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

int main(int argc, char* argv[])
{
  if (signal(SIGINT, handle_shutdown) == SIG_ERR)      /*  SIGINT = ctrl-c = intr    */
    error("Can't set the interrupt handler");
  listener_d = open_listener_socket();
  bind_to_port(listener_d, 30000);
  if (listen(listener_d, 10) == -1)     /* 监听连接   */
    error("Can't listen");
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof client_addr;
  puts("Waiting for connection");
  char buf[255];
  for(;;) {
    int connect_d = accept(listener_d, (struct sockaddr *)&client_addr,
                           &address_size);
    if (connect_d == -1)
      error("Can't open secondary socket");
    if ( !fork()) {     /* 这里会检查连接时的进程号，如果返回值为0则表示该进程是子进程需要在操作，否者跳过    */
      if (say(connect_d, "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ") != -1) {     /* 向客户端发送数据  */
        read_in(connect_d, buf, sizeof(buf));
        if (strncasecmp("Who's there?", buf, 12))    /* 比较 buf 变量的值是否为 who's there?   */
          say(connect_d, "You should say 'Who's there?'!");
        else {
          if (say(connect_d, "Oscar\r\n> ") != -1) {
            read_in(connect_d, buf, sizeof(buf));
            if (strncasecmp("Oscar who?", buf, 10))
              say(connect_d, "You should say 'Oscar who?'!\r\n");
            else
              say(connect_d, "Oscar silly question, you get a silly answer\r\n");
          }
        }
      }
      close(connect_d);
      exit(0);
    }
    close(connect_d);
  }
  return 0;
}
