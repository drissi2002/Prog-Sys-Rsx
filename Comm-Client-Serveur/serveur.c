#include<fcntl.h>
#include<string.h>
#include<stdio.h>

int main(){

      int d_l2 , d_e2 /* d_l2 : descripteur de lecture à partir du fifo1 */
                      /* d_e2 : descripteur d'écriture à partir du fifo2 */
      char reponse[20];
      char question[20];
      char cl ;
      
      /* creation des fifos */
      
      if( mkfifo("fifo1",0644) == -1 || mkfifo("fifo2",0644)== -1)){
           perror("Impossible de créer les fifos");
           exit(2);
      }
      
      d_l2 = open("fifo1",O_RDONLY);
      d_e2 = open("fifo2",O_WRONLY);      
      /* traitement serveur */
      
      while(1){
          read(d_l2,question,sizeof(question));
          scanf(question,"%s",&cl);
          if (strcmp(question ,"ciao") == 0){
               strcpy(reponse,"bye");
               write(d_e2,reponse,sizeof(reponse));
               break;          
          }
      fprintf(reponse,"%d");
      write(d_e2,reponse,sizeof(reponse));
      }
      
      close(d_l2);
      close(d_e2);
return 0;
}

