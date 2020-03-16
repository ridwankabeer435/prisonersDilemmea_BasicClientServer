# -*-Makefile-*-

tcp_client: tcp_client.o
	gcc -o tcp_client tcp_client.o
tcp_client.o: tcp_client.c
	gcc -Wall -g -c tcp_client.c     
clean:
	rm -f tcp_client *.o
