#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define MUL 1
#define ADD 0
#include <stdio.h>
#include <string.h> 

int parseCmd(char* cmd)
{
	int len = strlen(cmd);
	char* token;
	char X[32], Y[32];
	int result, op;
	token = strtok(cmd, "*");
	if (strlen(token) != len)
		op = MUL;
	else
	{
		token = strtok(cmd, "+");
		op = ADD;
	}
	strcpy(X, token);
	token = strtok(NULL, "");
	strcpy(Y, token);

	result = op ? (atoi(X)*atoi(Y)) : (atoi(X) + atoi(Y));
	return result;
}

int main(int argc, char *argv[])
{
	return parseCmd(argv[1]);
}
