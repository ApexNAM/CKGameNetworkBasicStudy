// �̸� �������� ��� ������ ����.
#include "..\..\common.h"

#define SERVERPORT 9000
#define BUFSIZE	   512

int main(int argc, char* argv[])
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	// Winsock Ended.
	WSACleanup();
	return 0;
}