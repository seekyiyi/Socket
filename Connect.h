#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Server {
public:
	Server();
	Server(int);

	void createServer();
	void init();
	void setting();
	void Ser_connect();

private: 
	//��l�� Windows Sockets DLL [server��] [client��] 
	int r;
	WSAData wsaData = WSAData();
	WORD DLLVSERION = WORD();

	//�ŧi socket ��}��T(���P���q�T,�����P����}��T,�ҥH�|�����P����Ƶ��c�s��o�Ǧ�}��T)
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);

	//�إ� socket
	SOCKET sListen = SOCKET(); //listening for an incoming connection
	SOCKET sConnect = SOCKET(); //operating if a connection was found


	//���ݳs�u
	SOCKADDR_IN clinetAddr;
};

/*---------------------------------------------------------------------------------*/

class Client 
{
public:
	Client();
	Client(int);

	void init();
	void setting();
	void cl_print();

	string confirm;
	char message[200];
	int r;

private:

	WSAData wsaData;
	WORD DLLVersion = WORD();

	//�ŧi�� socket �ϥΪ� sockadder_in ���c
	SOCKADDR_IN addr;

	//�]�w socket
	SOCKET sConnect;
};
