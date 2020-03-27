CSCI 3171 Assignment 3

Members:
  -Ridwan Kabeer (B00849394)
  -Abdullah Al Mukaddim (B00804319)

Contributions:



Client file (prisoner A): client_prisoner_A.c
Server file (prisoner B): server_prisoner_B.c

Commands to compile the files

Server:
  make

  OR

  gcc server_prisoner_B.c -o server_prisoner_B

Client:
  gcc client_prisoner_A.c -o client_prisoner_A


Commands to execute the file

Server:
  ./server_prisoner_B 8080

Client:
  ./client_prisoner_A 8080

...where 8080 == port number

(Note: the server code is executed first to make it online).
