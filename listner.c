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

#define PORT 2343

void error(const char *msg)
{
    perror(msg);
    exit(0);
}


int doconnect(struct sockaddr_in adresse)
{
    int socketprim;
    int longueurstruct;
	 int connectionserveur;
    longueurstruct = sizeof (struct sockaddr_in);
	socketprim = socket (AF_INET, SOCK_STREAM, 0);
    if (socketprim == -1)
    perror ("creation socket sur le client");
	connectionserveur = connect (socketprim, (struct sockaddr *) &adresse, longueurstruct);
    if (connectionserveur == -1)
    perror ("liaison (par connect) du client");
	
    return socketprim;
}


void start(struct sockaddr_in adresse,char idSMA[20],char idAgent[20])
{
    int socketprim;
    char buffer[256];
	int erreur;
	socketprim = doconnect(adresse);
    bzero(buffer,256);
    sprintf(buffer,"005001002%s002002%s",idSMA,idAgent);
    printf("buffer=%s",buffer);
	erreur= write(socketprim,buffer,strlen(buffer));
	if(erreur!=-1)
	printf("\nInformation transmise au serveur avec succès!\n");
	else 
	printf("\nErreur d'ecriture dans la socketprim!\n");    
	sleep(2);
}



void end(struct sockaddr_in adresse,char idSMA[20],char idAgent[20])
{
    int socketprim;
    char buffer[256];
	int erreur;
	socketprim = doconnect(adresse);
    bzero(buffer,256);
    sprintf(buffer,"006001002%s002002%s",idSMA,idAgent);
    printf("buffer=%s",buffer);
	erreur= write(socketprim,buffer,strlen(buffer));
	if(erreur!=-1)
	printf("\nInformation transmise au serveur avec succès!\n");
	else 
	printf("\nErreur d'ecriture dans la socketprim!\n");    
}



  
  
