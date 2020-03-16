# -*-MakeFile -*-

prisonerB: server_prisoner_B.o
	gcc -o server_prisoner_B server_prisoner_B.o
server_prisoner_B.o: server_prisoner_B.c
	gcc -Wall -g -c server_prisoner_B.c
prisonerA: client_prisoner_A.o
	gcc -o prisonerA client_prisoner_A.o
client_prisoner_A.o: client_prisoner_A.c
	gcc -Wall -g -c client_prisoner_A.c
clean:
	rm -f prisoner* *.o
