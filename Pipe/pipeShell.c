
/* progarmmation de la commande " ls-l | wc -l " */
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main() 
{ 
   int fd[2];   
   char cl , ch[20] ="";
   pipe(fd);
   if(fork()==0) 
                {
                close(fd[1]);
                close(STDIN_FILENO);  
                dup(fd[0]);  
                execlp("wc","wc","-l",NULL);    
                close(fd[0]);                
                }
      else      { 
                close(fd[0]);
                close(STDOUT_FILENO);
                dup(fd[1]);
                execlp("ls","ls","-l",NULL); 
                close(fd[1]);   
                }    
 return 0 ;
}








