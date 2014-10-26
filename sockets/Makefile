CC     = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall
FILES1 = a.out server1 client1 server2 client2 udp_server1 udp_client1 udp_server2
FILES2 = udp_client2 udp_server3 udp_client3 socket_client1 socket_server1
FILES2 = server_tcp client_tcp socket_client1 socket_server1
FILES3 = tcp_client1 tcp_server1 tcp_client2 tcp_server2 udp_client3 udp_server3 server_udp_packets client_udp_packets
FILES4 = udp_client_with_sendto udp_server_with_sendto

s1: server1.c
	$(CC) server1.c -o server1

c1: client1.c
	$(CC) client1.c -o client1

s2: server2.c
	$(CC) server2.c -o server2

c2: client2.c
	$(CC) client2.c -o client2

us1: udp_server1.c
	$(CC) udp_server1.c -o udp_server1

uc1: udp_client1.c
	$(CC) udp_client1.c -o udp_client1

us2: udp_server2.c
	$(CC) udp_server2.c -o udp_server2

uc2: udp_client2.c
	$(CC) udp_client2.c -o udp_client2


us3: udp_server3.c
	$(CC) udp_server3.c -o udp_server3

uc3: udp_client3.c
	$(CC) udp_client3.c -o udp_client3

u3: udp_client3.c
	$(CC) udp_client3.c -o udp_client3
	$(CC) udp_server3.c -o udp_server3

s3: socket_client1.c
	$(CC) socket_client1.c -o socket_client1
	$(CC) socket_server1.c -o socket_server1

t1: server_tcp.c
	$(CC) server_tcp.c -o server_tcp
	$(CC) client_tcp.c -o client_tcp

t2: tcp_client1.c
	$(CC) tcp_client1.c -o tcp_client1
	$(CC) tcp_server1.c -o tcp_server1

t3: tcp_client2.c
	$(CC) tcp_client2.c -o tcp_client2
	$(CC) tcp_server2.c -o tcp_server2

t4: client_udp_packets.c
	$(CC) client_udp_packets.c -o client_udp_packets
	$(CC) server_udp_packets.c -o server_udp_packets

m1: udp_client_with_sendto.c
	$(CC) udp_client_with_sendto.c -o udp_client_with_sendto
	$(CC) $(CFLAGS) udp_server_with_sendto.c -o udp_server_with_sendto


all: client1.c
	$(CC) client1.c -o client1 
	$(CC) server1.c -o server1 
	$(CC) socket_client1.c -o socket_client1
	$(CC) socket_server1.c -o socket_server1
	$(CC) server_tcp.c -o server_tcp
	$(CC) client_tcp.c -o client_tcp

clean:
	rm -f $(FILES1) $(FILES2) $(FILES3)
