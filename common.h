// if Old C Function Used Warning disabled.
#define _CRT_SECURE_NO_WARNINGS

// if Old Socket API Used Warning disabled.
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h> // Main header in WinSock2
#include <WS2tcpip.h>  // Plus header in WinSock2

#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib,"ws2_32") // ws2_32.lib Link

// if Error -> Program Ended.
void err_quit(const char* msg)
{
	LPVOID IpMsgBuf;

	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&IpMsgBuf, 0, NULL);

	MessageBoxA(NULL, (const char*)IpMsgBuf, msg, MB_ICONERROR);
	LocalFree(IpMsgBuf);
	exit(1);
}

// if error debuging message display printed.
void err_display(const char* msg)
{
	LPVOID IpMsgBuf;

	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&IpMsgBuf, 0, NULL);

	printf("[ERROR!] %s\n", (char*)IpMsgBuf);
	LocalFree(IpMsgBuf);
}

// if error debuging message display printed. (error code printed.)
void err_display(int errorCode)
{
	LPVOID IpMsgBuf;

	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(char*)&IpMsgBuf, 0, NULL);

	printf("[ERROR!] %s\n", (char*)IpMsgBuf);
	LocalFree(IpMsgBuf);
}