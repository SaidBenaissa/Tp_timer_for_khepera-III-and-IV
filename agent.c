#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "listner.c"

#define PORT 2343

int main (int argc, char *argv[]) // @IP port
{ 
  int socketprim;
  int taille;
  int longueurstruct;
  int connectionserveur;
  int arretserveur;
  int choixmenu;
  int erreur;
  char buffer[256];
  char idSMA[20] = "01";
  char idAgent[20] = "01";
  
  struct sockaddr_in adresse;
  struct hostent *server;
  
  
  
/* creation du descripteur de socket */
  adresse.sin_family = AF_INET;	/* initialisation de l'adresse : le domaine */
  adresse.sin_port = htons(PORT);//htons(port);	/* initialisation de l'adresse : le port */
  adresse.sin_addr.s_addr =inet_addr("10.120.24.240");/*INADDR_ANY;	 initialisation de l'adresse : la machine (locale) */
  //adresse.sin_addr.s_addr =gethostbyname("127.0.0.1"); //Adresse distant -->tache 1
  
///////////////  Agent-1 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.1 0.1'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"02");
///////////////////////////////////////////////////////////  
  
///////////////  Agent-2 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.5 0'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"01");
///////////////////////////////////////////////////////////  

///////////////  Agent-1 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.1 0.1'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"02");
///////////////////////////////////////////////////////////  

///////////////  Agent-2 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.5 0'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"02");
///////////////////////////////////////////////////////////  

///////////////  Agent-2 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.5 0'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"01");
/////////////////////////////////////////////////////////// 

///////////////  Agent-1 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.1 0.1'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"02");
/////////////////////////////////////////////////////////// 

///////////////  Agent-2 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0.5 0'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"03");
/////////////////////////////////////////////////////////// 

///////////////  Agent-3 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0 0.3'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"03");
/////////////////////////////////////////////////////////// 

///////////////  Agent-3 /////////////////////////////////
  start(adresse,idSMA,idAgent);
  system("ssh root@192.168.1.2 './odometry_goto position 0 0.3'");
  end(adresse,idSMA,idAgent);
  snprintf(idAgent,3,"01");
/////////////////////////////////////////////////////////// 

return 0;
}	
