CSCI 3171 Assignment 3

**Members**
- Ridwan Kabeer (B00849394)
- Abdullah Al Mukaddim (B00804319)

**Contributions**
Abdullah:
- Input validation for server and client
- Created Makefile
- Debugged code to ensure client and server runs properly on different devices


Client file (prisonerA): client_prisoner_A.c
Server file (prisonerB): server_prisoner_B.c

**Commands to compile the files**

Server:
  make prisonerB

  OR

  gcc prisonerB -o server_prisoner_B.c

Client:
  make prisonerA

  OR

  gcc prisonerA -o client_prisoner_A.c


**Commands to execute the file**

Server (any valid port number should work):
  ./prisonerB 8080

Client (any valid port number should work):
  ./prisonerA 8080

...where 8080 is port number

(Note: the server code is executed first to make it online)
