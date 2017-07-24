#include <iostream> 
#include <stdio.h>
#include "Connect.h"
#include <string>

using namespace std;

int main()
{
	Server server1 =NULL;
	Client client1;
	string confirm = "";
	cout << "create to server?[Y] or [N]" << endl;

	cin >> confirm;

	if (confirm == "Y") {
		server1 = Server();
		server1.createServer();
	} else {
	 client1 = Client();
	 client1.cl_print();
	}
	system("PAUSE");
	
}