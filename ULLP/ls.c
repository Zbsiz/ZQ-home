        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>
        #include <dirent.h>
        #include <unistd.h>
        #include <sys/types.h>
        #include <sys/ioctl.h>
        
        
        
        void do_ls(char *, int, int);
        
        int main(int ac, char **av)
        {
          int r_flag = 0;
          int q_flag = 0;
          int anyfiles = 1;
        
          if (ac == 1)
          {
            do_ls(".", r_flag, q_flag);
            anyfiles = 0;
          }
          else
            while (--ac)
            {
              if (strcmp("-r", *++av) == 0)
              {
                r_flag = 1;
                continue;
              }
              if (strcmp("-q", *av) == 0)
              {
                q_flag = 1;
                continue;
              }
        
              printf("%s: \n\n", *av);
              do_ls(*av, r_flag, q_flag);
              anyfiles = 0;
            }
          
          if (anyfiles)
            do_ls(".", r_flag, q_flag);
        }
        
        
        void list_init();
        void list_append(char *);
        void list_sort(int, int);
        void list_show();
        void list_finish();
        void fatal(char *, char *);
        
        
        void do_ls(char *dirname, int reverse, int none)
        {
          DIR *dir_ptr;
          struct dirent *direntp;
        
          list_init();
        
          dir_ptr = opendir(dirname);
          while (direntp = readdir(dir_ptr))
          {
            list_append(direntp->d_name);
          }
        
          closedir(dir_ptr);
        
          list_sort(reverse, none);
          list_show();
          list_finish();
        }
        
        
        #define CHUNKLEN 100
        
        void *emalloc(unsigned), *erealloc(void *, unsigned);
        char **namelist = NULL;
        int listlen, taken, chunksize;
        
        void list_init()
        {
          namelist = (char **) emalloc(CHUNKLEN * sizeof(char *));
          listlen = CHUNKLEN - 1;
          chunksize = (CHUNKLEN * sizeof(char *));
          taken = 0;
        }
        
        void list_append(char *str)
        {
          char *newstring(char *);
          char *name = newstring(str);
        
          if (taken == listlen)
          {
            listlen += CHUNKLEN;
            chunksize += chunksize;
            namelist = (char **) erealloc(namelist, chunksize);
          }
        
          namelist[taken++] = name;
        }
        
        void list_sort(int revflag, int noneflag)
        {
          if (noneflag)
            return;
          int comp_increasing(const void *, const void *);
          int comp_decreasing(const void *, const void *);
        
          qsort((void *)namelist, (size_t) taken, sizeof(char *), 
              (revflag?comp_decreasing:comp_increasing));
        }
        
        int comp_increasing(const void *p1, const void *p2)
        {
          char **a = NULL;
          char **b = NULL;
          
          a = (char **) p1;
          b = (char **) p2;
        	return strcmp(*a, *b);
        }
        
        int comp_decreasing(const void *p1, const void *p2)
        {
          char **a = NULL;
          char **b = NULL;
          
          a = (char **) p1;
          b = (char **) p2;
        	return strcmp(*b, *a);
        }
        
        
        int get_screen_width();
        
        void list_show()
        {
          int i, col, cols, maxlen;
          cols = maxlen = 0;
        
          for (i=0; i<taken; i++)
            if (strlen(namelist[i]) > maxlen)
              maxlen = strlen(namelist[i]);
        
          maxlen += 1;
          col = get_screen_width() / maxlen;
        
          for (i=0; i<taken; i++)
          {
            cols++;
            printf("%-*s", maxlen, namelist[i]);
        
            if ((cols == col) && (i != taken- 1))
            {
              cols = 0;
              printf("\n");
            }
          }
         
          printf("\n");
        }
        
        void list_finish()
        {
          int i;
        
          for (i=0; i<taken; i++)
            free(namelist[i]);
          free(namelist);
        }
        
        
        void *emalloc(unsigned n)
        {
          void *rv = malloc(n);
          if (rv)
            return rv;
          fatal("emalloc error", "");
        }
        
        char *newstring(char *s)
        {
          char *rv = emalloc(1 + strlen(s));
          strcpy(rv, s);
          return rv;
        }
        
        void *erealloc(void *er_str, unsigned er_n)
        {
          void *rv = realloc(er_str, er_n);
          if (rv)
            return rv;
          fatal("erealloc error", "");
        }
        
        int get_screen_width()
        {
          struct winsize size;
          
          if (isatty(STDOUT_FILENO) != 0)
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        
          return size.ws_col;
        }
        
        void fatal(char *s1, char *s2)
        {
          fprintf(stderr, "ls:1.c %s %s\n", s1, s2);
          exit(1);
        }