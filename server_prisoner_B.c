#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

//declare a port number to communicate server
#define PORTNUM 8080
#define MAXBACKLOG 5


int main(){

  //have a struct to store IPv4 address (for server: maybe use the local address)
  struct sockaddr_in serverAddress;
//  socklen_t clientDataLen;

  //create the  'socket()' system call
  // we are using TCP stream for client-sercer commumication, default protocol
  int serverSocket = socket(PF_INET, SOCK_STREAM, 0);
  if(serverSocket < 0){
    fprintf(stderr, "%s","ERROR opening socket\n");
  }
  //assign values to the server address
  bzero((char *) &serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET; //IPv4 family of addresses
  serverAddress.sin_port = htons(PORTNUM); //assign port number to listen for connection
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); //evaluates to local IP address: 0.0.0.0


  //bind the socket 'serverSocket' with IP address specified in serverAddress struct
  //use 'bind()' function
  int binding = bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
  if(binding < 0){
    fprintf(stderr, "%s","Can't bind socket\n");
  }


  //make server open for listening to requests
  //use 'listen()': params ==> 'socket' to listen at for connection requests
  //, backlog ==> max length of pending connections
  listen(serverSocket, MAXBACKLOG);

  //a server shold always be listening for connections requests

  while(1){

    //store the client's address details
    struct sockaddr_in clientAddress;
    socklen_t clientAddrSize = sizeof(clientAddress);

    //finally, create the socket to establish connectionint) (rand() / (double) (RAND_MAX + 1) between server and client
    //use the 'accept()' function
    int connectionSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddrSize);
    if(connectionSocket < 0){
      fprintf(stderr, "%s","Can't accept client request\n");
    }

    //wil need an input buffer to store client's data
    char clientInput[800];
    //memset(clientInput, '\0', sizeof(clientInput));
    bzero(clientInput, sizeof(clientInput));

    //so the server will need to read data from connectionSocket
    //use the read() function
    int readData = read(connectionSocket, clientInput, sizeof(clientInput));
    if(readData < 0){
      fprintf(stderr, "%s","can't read data\n");
    }

    //check user's data

	 char *serverResponse;


   //generate server's response randomly.
   //if serverDecision == 1 then the server stays silent, else the server betrays

   //rand generator ref: https://www.geeksforgeeks.org/generating-random-number-range-c/
  int serverDecision = rand() % 2;
  printf("%d\n", serverDecision);
   if(serverDecision < 0.5){ //server stays silent
     if(clientInput[0]=='B'){ //but client betrays
         serverResponse = "Prisoner B stays in jail for 3 years.\n Prisoner A is released\n";
       }
        else{ //client is also silent
            serverResponse = "Both prisoners A and B stay in jail for 1 year\n";
        }
   }
   else{ //server betrays
     if(clientInput[0]=='B'){ //client also betrays
         serverResponse = "Both prisoners A and B stay in jail for 2 years.\n";
       }
        else{ //but client stays silent
            serverResponse = "Prisoner A stay in jail for 3 years\nPrisoner B is released\n";
        }
   }
    /*

         */
    //process the server's response to the client
    printf("This is what I got %s \n", clientInput);
    int response =  write(connectionSocket,serverResponse,500);
    if(response < 0){
      fprintf(stderr, "%s","Error responding to data\n");
    }
    //once done with everything close the connection socket
    close(connectionSocket);
  }

  //if loop terminates ==> terminate server operation
  close(serverSocket);

  return 0;
}
