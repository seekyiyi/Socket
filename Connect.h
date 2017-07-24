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
	//初始化 Windows Sockets DLL [server端] [client端] 
	int r;
	WSAData wsaData = WSAData();
	WORD DLLVSERION = WORD();

	//宣告 socket 位址資訊(不同的通訊,有不同的位址資訊,所以會有不同的資料結構存放這些位址資訊)
	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);

	//建立 socket
	SOCKET sListen = SOCKET(); //listening for an incoming connection
	SOCKET sConnect = SOCKET(); //operating if a connection was found


	//等待連線
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

	//宣告給 socket 使用的 sockadder_in 結構
	SOCKADDR_IN addr;

	//設定 socket
	SOCKET sConnect;
};
