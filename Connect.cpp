#include "Connect.h"
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>

Server::Server()
{
	init();
	setting();
}	

Server::Server(int _ip)
{

}
void Server::createServer()
{
	Ser_connect();
}
void Server::init()
{
	DLLVSERION = MAKEWORD(2, 1); //Winsocket-DLL ����

	//�� WSAStartup �}�l Winsocket-DLL
	r = WSAStartup(DLLVSERION, &wsaData);
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

}


void Server::setting() {
	memset(&addr, 0, sizeof(addr)); // �M��,�N��Ƴ]�� 0

	//�]�w��}��T�����
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // �]�w IP,�᭱���� inet_addr()
												   // addr.sin_addr.s_addr = INADDR_ANY; // �Y�]�w INADDR_ANY ��ܥ��� IP
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234); // �]�w port,�᭱���� htons()

	//�]�w Listen
	sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);//SOMAXCONN: listening without any limit

}

void Server::Ser_connect()
{
	while (true)
	{
		cout << "waiting..." << endl;

		if (sConnect = accept(sListen, (SOCKADDR*)&clinetAddr, &addrlen))
		{
			cout << "a connection was found" << endl;
			printf("server: got connection from %s\n", inet_ntoa(addr.sin_addr));

			//�ǰe�T���� client ��
			char *sendbuf = "sending data test";
			send(sConnect, sendbuf, (int)strlen(sendbuf), 0);

		}
	}
}
/*---------------------------------------------------------------------------------*/


Client::Client()
{
	init();
	setting();
}

void Client::init()
{
	DLLVersion = MAKEWORD(2, 1);
	r = WSAStartup(DLLVersion, &wsaData);

	int addlen = sizeof(addr);
}

void Client::setting()
{
	//AF_INET: internet-family
	//SOCKET_STREAM: connection-oriented socket
	sConnect = socket(AF_INET, SOCK_STREAM, NULL);

	//�]�w addr ���
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

}

void Client::cl_print()
{
    connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));

	//���� server �ݪ��T��
	ZeroMemory(message, 200);
	r = recv(sConnect, message, sizeof(message), 0);
	cout << message << endl;
 
	//�]�w closesocket �ɡA���g�L TIME-WAIT �L�{,��������socket
	//BOOL bDontLinger = FALSE;
	//setsockopt(sConnect,SOL_SOCKET,SO_DONTLINGER,(const char*)&bDontLinger,sizeof(BOOL));
             
	//�Y���ᤣ�A�ϥΡA�i�� closesocket �����s�u
	closesocket(sConnect);         
	getchar();

}

