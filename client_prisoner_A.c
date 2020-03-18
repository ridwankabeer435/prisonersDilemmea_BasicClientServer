#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORTNUM 8000

int main(){

	//get input and process it
	char userInput[250]; //this will serve as the input

	printf("Enter a value: ");
	fgets(userInput, sizeof(userInput), stdin);

	//validate user input
	while(userInput[0]!='B' && userInput[0]!='S'){
		printf("Wrong data entry. Please re-enter: ");
		fgets(userInput, sizeof(userInput), stdin);
	}

 	//if valid, then proceed to connect with server
  printf("You entered: ");
  puts(userInput);

  //while connected to server, listen for responses from server.

  //create the socket: use socket()

  int clientServerSocket = socket(PF_INET, SOCK_STREAM, 0);

  if(clientServerSocket < 0){
    fprintf(stderr, "%s", "Connection socket is not working...\n");
  }

  //like at server, assign address to server for socket to connect
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(PORTNUM);
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");



  //connect client via socket
  int clientConnect = connect(clientServerSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));



	if(clientConnect < 0){
    fprintf(stderr, "%s", "error connecting to server\n" );
  }
  //write the user's data to the server: use 'write()' functtion
  int n= write(clientServerSocket,userInput,strlen(userInput));
  if(n < 0){
    fprintf(stderr, "%s", "Error sending data to server\n");
  }

  bzero(userInput, sizeof(userInput));


  //read the server's responseL use 'read()' function
  n = read(clientServerSocket, userInput, sizeof(userInput));
  if(n < 1){
    fprintf(stderr, "%s", "Error receiving data from server\n");
  }
  //print out the response
  printf("%s", userInput);

  //terminate the connection
  close(clientServerSocket);

  return 0;
}
