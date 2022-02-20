#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main() 
{ 
   int tube[2];   
   char cl , ch[20] ="";
   pipe(tube);
   if(fork()==0) 
                {
                close(tube[1]);
                close(STDIN_FILENO);  
                dup(tube[0]);  
                execlp("wc","wc","-l",NULL);    
                close(tube[0]);                
                }
      else      { 
                close(tube[0]);
                close(STDOUT_FILENO);
                dup(tube[1]);
                execlp("ls","ls","-l",NULL); 
                close(tube[1]);   
                }    
 return 0 ;
}







