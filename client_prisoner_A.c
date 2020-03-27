#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdbool.h>

//#define PORTNUM 8080

int main(int argc, char *argv[]){

	char intro[800]="";
	//introduce the program to the user
	strcat(intro, "Welcome prisoner A. You and your inmate (prisoner B) have a chance to either\nescape or reduce your sentence in jail.\nYour options are to stay silent or betray your inmate\n");
	printf("%s", intro);

	//get input and process it
	char userInput[500]; //this will serve as the input
	char tryAgainPrompt[200];
	int portno = atoi(argv[1]);
	
	//a while loop to allow user to try again
	while(1){
		printf("Betray(B) or silence(S): ");
		fgets(userInput, sizeof(userInput), stdin);

		//validate user input
		while(strlen(userInput) != 2){
			printf("Your choice is too wordy. Please enter one character: ");
			fgets(userInput, sizeof(userInput), stdin);
		}

		while(userInput[0]!='B' && userInput[0]!='S'){
			printf("Choose between silence(S) and betray(B): ");
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
		serverAddress.sin_port = htons(portno);
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

		//ask the user if they want to continue
		printf("Would you like to try again (Y/N): ");
		fgets(userInput, sizeof(userInput), stdin);

		while(strlen(userInput) != 2){
			printf("Your choice is too wordy. Please enter 'Y' or 'N': ");
			fgets(userInput, sizeof(userInput), stdin);
		}

		while(userInput[0]!='Y' && userInput[0]!='N'){
			printf("Try Again. Yes or N (Y/N) Enter one character: ");
			fgets(userInput, sizeof(userInput), stdin);
		}

		if(userInput[0] == 'Y'){

		}
		else{
			//terminate the connection
			printf("Best of luck with your choice\n");
			close(clientServerSocket);
			break;
		}
	}
	
  return 0;

}
