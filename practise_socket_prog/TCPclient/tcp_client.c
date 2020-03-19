/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket, newSocket;
  char bufferChoice;
  char bufferMess[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage clientStorage;
  socklen_t addr_size;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*---- Connect the socket to the server using the address struct ----*/
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
  newSocket = accept(clientSocket, (struct sockaddr *) &clientStorage, &addr_size);

  //get input and process it
  char userInput; //this will serve as the input
  
  printf("Enter a value: ");
  scanf("%c", &userInput);
 
  //validate user input
  while(userInput!='B' && userInput!='S'){
  	printf("Wrong data entry. Please re-enter: ");
  	scanf("%c", &userInput); 
  }
  
  bufferChoice = userInput;
  send(newSocket,bufferChoice,1024,0); 
 
  /*---- Read the message from the server into the buffer ----*/
  recv(clientSocket, bufferMess, 1024, 0);

  /*---- Print the received message ----*/
  printf("Data received: %s",bufferMess);   

  return 0;
}
