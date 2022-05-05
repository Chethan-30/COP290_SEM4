// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#include "server.h"
#include <vector>
using namespace std;
vector<int> sendHPdataserver(vector<int> hp_score)
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	
		const void *hello=(void*)malloc(sizeof(int)*sizeof(hp_score));
	*((int*)hello)=hp_score[0];
		*((int*)hello+1)=hp_score[1];
			*((int*)hello+2)=hp_score[2];
			*((int*)hello+3)=hp_score[3];
			*((int*)hello+4)=hp_score[4];
	//printf("%d\n",*((int*)hello+3));
	//printf("%d\n",*((int*)hello+4));
	char buffer[20] = { 0 };

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
		== 0) {
		exit(1);
	}

	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		exit(1);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		exit(1);
	}
	printf("Listening to the client\n");
	if (listen(server_fd, 1) < 0) {
		exit(1);
	}
	if ((new_socket
		= accept(server_fd, (struct sockaddr*)&address,
				(socklen_t*)&addrlen))
		< 0) {
		exit(1);
	}
	valread = read(new_socket, buffer,20);
	send(new_socket, hello, 20, 0);
		vector<int> hp_score_return;
	hp_score_return.push_back(*((int*)buffer));
	hp_score_return.push_back(*((int*)buffer+1));
	hp_score_return.push_back(*((int*)buffer+2));
	hp_score_return.push_back(*((int*)buffer+3));
	hp_score_return.push_back(*((int*)buffer+4));

printf("%d\n",*((int*)buffer+3));
printf("%d\n",*((int*)buffer+4));
	close(server_fd);
	close(new_socket);
			return hp_score_return;
}

