#ifndef SERVER_H
#define SERVER_H
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#define PORT 8080
using namespace std;

vector<int>sendHPdataserver(vector<int> hp_score);

#endif