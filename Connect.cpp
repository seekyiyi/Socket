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
	DLLVSERION = MAKEWORD(2, 1); //Winsocket-DLL 版本

	//用 WSAStartup 開始 Winsocket-DLL
	r = WSAStartup(DLLVSERION, &wsaData);
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

}


void Server::setting() {
	memset(&addr, 0, sizeof(addr)); // 清空,將資料設為 0

	//設定位址資訊的資料
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 設定 IP,後面解釋 inet_addr()
												   // addr.sin_addr.s_addr = INADDR_ANY; // 若設定 INADDR_ANY 表示任何 IP
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234); // 設定 port,後面解釋 htons()

	//設定 Listen
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

			//傳送訊息給 client 端
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

	//設定 addr 資料
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(1234);

}

void Client::cl_print()
{
    connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));

	//接收 server 端的訊息
	ZeroMemory(message, 200);
	r = recv(sConnect, message, sizeof(message), 0);
	cout << message << endl;
 
	//設定 closesocket 時，不經過 TIME-WAIT 過程,直接關閉socket
	//BOOL bDontLinger = FALSE;
	//setsockopt(sConnect,SOL_SOCKET,SO_DONTLINGER,(const char*)&bDontLinger,sizeof(BOOL));
             
	//若之後不再使用，可用 closesocket 關閉連線
	closesocket(sConnect);         
	getchar();

}

