#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	char c;
	int A = 0, a = 0, N = 0, spec_s = 0;
	while (1) {
		int i = 0;
		char password[21] = { NULL };
		printf("Enter your peassword\n");
		while (i < 20) {
			c = _getch();
			if (c == 13)
			{
				break;
			}
			if (c == 8)
			{
				printf("\b");
				printf(" ");
				printf("\b");
				if (password[i - 1] != NULL)
				{
					i--;
				}
			}
			else
			{
				if (c > '0' && c < '9')
				{
					N++;
				}
				if (c > 'a' && c < 'z')
				{
					a++;
				}
				if (c > 'A' && c < 'Z')
				{
					A++;
				}
				if (c > 32 && c < 48 || c>'9' && c < 'A' && c>'z' && c < 'a' || c>'z' && c < 127)
				{
					spec_s++;
				}
				printf("*");
				password[i] = c;
				i++;
			}
		}
		for (int j = 0; j < 18; j++)
		{
			if (password[j] > '0' && password[j] < '9' && password[j + 1]>'0' && password[j + 1] < '9' && password[j + 2]>'0' && password[j + 2] < '9') {
				N = 0;
				break;
			}
			if (password[j] > 'A' && password[j] < 'Z' && password[j + 1]>'A' && password[j + 1] < 'Z' && password[j + 2]>'A' && password[j + 2] < 'Z') {
				A = 0;
				break;
			}
			if (password[j] > 'a' && password[j] < 'z' && password[j + 1]>'a' && password[j + 1] < 'z' && password[j + 2]>'a' && password[j + 2] < 'z') {
				a = 0;
				break;
			}
			if ((password[j] > 32 && password[j] < 48 || password[j]>'9' && password[j] < 'A' || password[j]>'z' && password[j] < 'a' || password[j]>'z' && password[j] < 127)
				&&(password[j+1] > 32 && password[j+1] < 48 || password[j+1]>'9' && password[j+1] < 'A' || password[j+1]>'z' && password[j+1] < 'a' || password[j+1]>'z' && password[j+1] < 127)
				&&(password[j+2] > 32 && password[j+2] < 48 || password[j+2]>'9' && password[j+2] < 'A' || password[j+2]>'z' && password[j+2] < 'a' || password[j+2]>'z' && password[j+2] < 127)) {
				spec_s = 0;
				break;
			}
		}
		if (N && a && A && spec_s)
		{
			printf("\nYour password - %s\n",password);
			break;
		}
		else
		{
			printf("\nBad password. Try again!!!\n");
			continue;
		}
	}
	return 0;
}