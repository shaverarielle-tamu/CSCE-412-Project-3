CC = g++
CFLAGS = -Wall -Werror -std=c++11

all: myprogram

myprogram: main.o Web_servers.o Load_balancer.o Requests.o
	$(CC) $(CFLAGS) -o myprogram main.o Web_servers.o Load_balancer.o Requests.o

main.o: main.cpp Web_servers.h Load_balancer.h Requests.h
	$(CC) $(CFLAGS) -c main.cpp

Web_servers.o: Web_servers.cpp Web_servers.h Load_balancer.h Requests.h
	$(CC) $(CFLAGS) -c Web_servers.cpp

Load_balancer.o: Load_balancer.cpp Load_balancer.h Web_servers.h Requests.h
	$(CC) $(CFLAGS) -c Load_balancer.cpp

Requests.o: Requests.cpp Requests.h
	$(CC) $(CFLAGS) -c Requests.cpp

clean:
	rm -f myprogram *.o
