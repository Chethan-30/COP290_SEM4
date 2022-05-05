// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#define PORT 8080
using namespace std;
vector<int> sendHPdataClient(vector<int>hp_score)
{int sock = 0, valread;
	struct sockaddr_in serv_addr;
	
	const void *hello=(void*)malloc(sizeof(int)*sizeof(hp_score));
	*((int*)hello)=hp_score[0];
		*((int*)hello+1)=hp_score[1];
		*((int*)hello+2)=hp_score[2];
		*((int*)hello+3)=hp_score[3];
		*((int*)hello+4)=hp_score[4];
	// printf("%d\n",*((int*)hello+3));
	// printf("%d\n",*((int*)hello+4));

	//char* hello = "Hello from client";
	char buffer[20] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
	exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
	 exit(1);
	}

	while(1)
	{if (connect(sock, (struct sockaddr*)&serv_addr,
				sizeof(serv_addr))
		< 0) {
		printf("\nConnection Failed \n");
		
	continue;}
	else
	break;
	}
	send(sock, hello, 20, 0);

	valread = read(sock, buffer, 20);
	vector<int> hp_score_return;
	hp_score_return.push_back(*((int*)buffer));
	hp_score_return.push_back(*((int*)buffer+1));
	hp_score_return.push_back(*((int*)buffer+2));
		hp_score_return.push_back(*((int*)buffer+3));
			hp_score_return.push_back(*((int*)buffer+4));
			printf("%d\n",*((int*)buffer+3));
printf("%d\n",*((int*)buffer+4));
	close(sock);
	return hp_score_return;

}



















