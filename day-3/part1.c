//Answer: 188116424
#include <stdio.h>
#include <string.h>


int main(){
	char* pBuff;
	char* dBuff;
	char buff[20000];
	char len[13];
	int a = 0;
	int b = 0;
	int result = 0;
	len[12] = '\0';

	FILE *input = fopen("input.txt", "r");

	if (input == NULL) {
		perror("Error opening file");
		return 1;
	}

	while (fgets(buff, sizeof(buff), input) != NULL) {
		pBuff = &buff[0];

		while(*pBuff != '\0'){

			if(*pBuff == 'm'){
				memcpy(len, pBuff, sizeof(char) * 12);

				if(strstr(len, "mul(") != NULL && strstr(len, ",") != NULL &&
				 	strstr(len, ")") != NULL && strstr(len, ",") < strstr(len, ")")){

					sscanf(len, "mul(%d,%d)", &a, &b);

					if(a > 0 && b > 0 && a < 1000 && b < 1000){
						result += a * b;
						a = 0;
						b = 0;
						pBuff += 8;
					}
					else{
						pBuff += 4;
					}
				}
				else {
					pBuff++;
				}
			}
			else{
				pBuff++;
			}

		}
	}

	printf("%d\n", result);
	return 0;
}
