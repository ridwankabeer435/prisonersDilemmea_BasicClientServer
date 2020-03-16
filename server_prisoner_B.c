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
#define PORTNUM 3030;
#define MAXBACKLOG 5;

/*Process server's response inside this function*/
void dilemmaOutcome(){

}

int main(){

  //have a struct to store IPv4 address (for server: maybe use the local address)
  struct sockaddr_in serverAddress;

  //create the  'socket()' system call
  // we are using TCP stream for client-sercer commumication, default protocol
  int serverSocket = socket(PF_INET, SOCKET_STREAM, 0);

  //assign values to the server address
  serverAddress.sin_family = AF_INET; //IPv4 family of addresses
  serverAddress.sin_port = htons(PORTNUM); //assign port number to listen for connection
  serverAddress.sin_addr.s_addr = INADDR_ANY; //evaluates to local IP address: 0.0.0.0


  //bind the socket 'serverSocket' with IP address specified in serverAddress struct
  //use 'bind()' function
  bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

  //make server open for listening to requests
  //use 'listen()': params ==> 'socket' to listen at for connection requests
  //, backlog ==> max length of pending connections
  listen(serverSocket, MAXBACKLOG);

  //a server shold always be listening for connections requests

  while(1){

    //store the client's address details
    struct sockaddr_in clientAddress;
    socklen_t clientAddrSize = sizeof(clientAddress);

    //finally, create the socket to establish connection between server and client
    //use the 'accept()' function
    int connectionSocket = accecpt(serverSocket, (struct sockaddr *) &clientAddress, &clientAddrSize);


    //wil need an input buffer to store client's data
    char clientInput[800];
    memset(clientInput, '\0', sizeof(clientInput));

    //so the server will need to read data from connectionSocket
    //use the read() function
    read(connectionSocket, clientInput, sizeof(clientInput));

    //check user's data

    //process the server's response to the client

    //send the response back to the client
    write(connectionSocket, "You sent me something", sizeof(clientInput));
    //once done with everything close the connection socket
    close(connectionSocket);
  }

  //if loop terminates ==> terminate server operation
  close(serverSocket);

  return 0;
}
