#ifndef _TIME_SERVER_
#define _TIME_SERVER_
#include <sys/socket.h>
#include <string.h>

int time_server(int port);
char* get_time(int ip, int port);


#endif