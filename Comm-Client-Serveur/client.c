#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){

      int d_l1 , d_e1 /* d_l1 : descripteur de lecture à partir du fifo2 */
                      /* d_e1 : descripteur d'écriture à partir du fifo1 */
      char reponse[20];
      char question[20];
      
      d_e1 = open("fifo1",O_WRONLY); 
      
      if(d_e1 == -1) {
          fprintf(stderr,"Impossible d'ouvrir fifo 1 %s \n " , "fifo1");
          fprintf(stderr,"Lancer serveur d\'abord ? \n");
          exit(2);
      }
      
      d_l1 = open("fifo2", O_RDONLY);
      
      if(d_l1 == -1) {
          fprintf(stderr,"Impossible d'ouvrir fifo 2 %s \n " , "fifo2");
          fprintf(stderr,"Lancer serveur d\'abord ? \n");
          exit(2);
      }
      
      /* traitement client */
      while(1){
          if (gets(question)==NULL){
               exit(2); }
          
          write(d_e1,question,sizeof(question));
          fprintf("Client > %s \n" ,question);
          read(d_l1,reponse,sizeof(reponse));
          fprintf("Serveur > %s \n",reponse);
          
          if(strcmp(reponse,"bye")==0){
              break ;}                  /* Communication terminée */      
      }   
return 0;
}



