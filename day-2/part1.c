//Answer: 524
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check(int a, int b){
	if(a == b || abs(a - b) > 3)
		return 0;
	if(a < b)
		return 1;
	else
		return -1;
}

int main(){
	char buff[32];
	int safeReports = 0;

	FILE *input = fopen("input.txt", "r");

	if (input == NULL) {
		perror("Error opening file");
		return 1;
	}

	while(fgets(buff, sizeof(buff), input) != NULL){
		char* token = strtok(buff, " ");
		int a = atoi(token);
		token = strtok(NULL, " ");
		int b = atoi(token);
		int order = check(a, b);

		while(token != NULL && order != 0){
			int b = atoi(token);

			if(check(a, b) == order){
				a = b;
				token = strtok(NULL, " ");
			}
			else {
				order = 0;
				break;
			}
		}
		if(order != 0){
			safeReports++;
		}
	}

	printf("%d\n", safeReports);
	return 0;
}
