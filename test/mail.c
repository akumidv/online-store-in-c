#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  char *szTmp, *szTmp1;
  pid_t child_pid;
  FILE *fh;

          szTmp="Hi ist,test";
/*          fh=fopen("/tmp/kr-ord_mail.tmp","w");*/
/*          fh=fopen("| sendmail @.ru","w");*/
          fh=fopen("cat html.h","r");
          if(fh!=NULL)
          {
/*            fprintf(fh,szTmp);*/
printf("%c",fgetc(fh));
            fclose(fh);
/*            child_pid=fork();
            if(child_pid==0)
            {
              execl("/bin/sh","sh","-c","sendmail @.ru < /tmp/kr-ord_mail.tmp",0);
              exit(1);
            }*/
          }
          else 
            printf("Error");
         return 0;
}

