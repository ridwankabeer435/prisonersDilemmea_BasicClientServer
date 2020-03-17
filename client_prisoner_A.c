#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORTNUM 3030;

int main(){

	//get input and process it
	char userInput; //this will serve as the input

	printf("Enter a value: ");
	scanf("%s", userInput);

	//validate user input
	while(userInput!='B' && userInput!='S'){
		printf("Wrong data entry. Please re-enter: ");
		scanf("%s", userInput); 
	}

 	//if valid, then proceed to connect with server


  //while connected to server, listen for responses from server.

  //create the socket: use socket()
  /*
  int clientServerSocket = socket(PF_INET, SOCKET_STREAM, 0);

  //like at server, assign address to server for socket to connect
  struct sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = PORTNUM;
  serverAddress.sin_addr.s_addr = INADDR_ANY;

  //connect client via socket
  int clientConnect = connect(clientServerSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

  //write the user's data to the server: use 'write()' functtion


  //read the server's responseL use 'read()' function

  //print out the response

  //terminate the connection
  close(clientServerSocket);
  */
  return 0;
}
