# -*- MakeFile -*-

tcp_server: tcp_server.o
	gcc -o tcp_server tcp_server.o
tcp_server.o: tcp_server.c
	gcc -Wall -g -c tcp_server.c
clean:
	rm -f tcp_server *.o
