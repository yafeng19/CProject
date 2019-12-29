#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int main()
{
	char strText[N], sortstr[200], strALine[200], strOutput[200];
	int spacesum = 0, printcolumnsum = 0;
	int numColumn, startChar = 0, endChar, textLen;
	printf("How many columns in a line?\n");
	scanf("%d", &numColumn);
	getchar();
	printf("Please input the text:\n");
	fgets(strText, N, stdin);
	printf("The result is:\n");
	textLen = strlen(strText);
	if (numColumn >= textLen)
	{
		puts(strText);
		exit(0);
	}
	else
	{
		do {
			endChar = startChar + numColumn - 1;
			int k;
			for (k = 0;k < numColumn;k++)
			{
				strALine[k] = ' ';
			}
			strALine[k] = '\0';
			switch (strText[endChar])
			{
			case ',':
			case '.':
			case '!':
			{
				strncpy(strALine, strText + startChar, endChar - startChar + 1);
				startChar = endChar + 1;
				break;
			}
			case ' ':
			{
				strncpy(strALine, strText + startChar, endChar - startChar);
				startChar = endChar + 1;
				break;
			}
			default:
			{
				if (strText[endChar + 1] != ' ')
				{
					do
					{
						endChar--;
					} while (strText[endChar] != ',' && strText[endChar] != '.' && strText[endChar] != '!' && strText[endChar] != ' ');
					if (strText[endChar] != ' ')
					{
						strncpy(strALine, strText + startChar, endChar - startChar + 1);
						startChar = endChar + 1;
					}
					else
					{
						strncpy(strALine, strText + startChar, endChar - startChar);
						startChar = endChar + 1;
					}
				}
				else
				{
					strncpy(strALine, strText + startChar, endChar - startChar + 1);
					startChar = endChar + 2;
				}
			}
			}
			int numSubstractLen = 0, numSpace = 0, numlnsert = 0, numlnsert1 = 0;
			int i = 0, j = 0;
			for (k = 0;k < numColumn;k++)
			{
				strOutput[k] = ' ';
			}
			strOutput[k] = '\0';
			for (i = 0; i < strlen(strALine); i++)
			{
				if (strALine[i] == ' ')
					numSpace++;
			}
			numSubstractLen = numColumn - strlen(strALine);
			spacesum = spacesum + numSubstractLen + numSpace;
			if (numSpace != 0)
			{
				numlnsert = numSubstractLen / numSpace;//平均每个空格处插入的空格数
				numlnsert1 = numSubstractLen % numSpace;//从第一个原空格处开始，计算需要在多少个原空格处多加一个空格
			}
			else
			{
				numlnsert = 0;
				numlnsert1 = 0;
			}
			for (i = 0, j = 0; i < strlen(strALine); i++)
			{
				if (' ' == strALine[i])
				{
					j = j + numlnsert;
					if (0 < numlnsert1)
					{
						j++;
						numlnsert1--;
					}
				}
				strOutput[j] = strALine[i];
				j++;
			}
			strOutput[j] = '\0';
			puts(strOutput);
			printcolumnsum++;
			if (printcolumnsum > 17)
			{
				exit(0);
			}
		} while (startChar <= textLen);
		getchar();
	}
	return 0;
}
