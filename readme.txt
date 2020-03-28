CSCI 3171 Assignment 3 (Winter 2020)

**Members**
- Ridwan Kabeer (B00849394)
- Abdullah Al Mukaddim (B00804319)

**Contributions**
Abdullah:
- Input validation for server and client
- Created Makefile
- Debugged code to ensure client and server runs properly on different devices

Ridwan:
- Set up skeleton for creating the client and socket files.
- Built up the means for client and server to connect over local I.P address.
- Set up the data transmission mechanism between client and server.
- Added code to allow user to try again after receiving verdict.
- Modified client and server code to take port number as input upon execution.


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

...where 8080 is port number (this can be replaced by any port number as long as
it's not well known/reserved by the TCP/IP protocol or by Bluenose/Timberlea servers)

(Note: the server code is executed first to make it online)
(Note_2: The connection can be made even though the client and server are on different devices. However, both the devices must have the same IP address. An ideal scenario would be two different devices which are both connected on the Bluenose server.)
