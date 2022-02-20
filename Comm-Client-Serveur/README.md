##  communication client serveur 

Voici deux programmes, serveur.c et client.c, qui communiquent par deux tubes nommés
fifo1 et fifo2 . 
Le programme client.c envoie une requête de type string , dans le tube fifo1 , et le programme
serveur.c lui retourne la réponse dans le tube serv2cli. C'est le programme serveur.c qui crée 
les tubes (désignés par les variables fifo1 et fifo2 ) et qui les supprime en fin d'exécution. 
Il doit donc être lancé avant le programme client qui suppose les tubes existants. Les deux programmes
se synchronisent sur l'ouverture des tubes qui doit se faire dans le même ordre. L'arrêt de la communication
se fait quand le programme client envoi le message "bye" ; le serveur répond alors par "ciao". 

<p align="center">
  <img src="https://i.imgur.com/vRcUwjj.png"  alt="accessibility text">
</p>
