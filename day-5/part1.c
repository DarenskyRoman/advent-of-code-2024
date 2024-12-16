//Answer: 4462
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct List {
	int length;
	int items[24];
};

int main(){
	int rules[1176][2];
	char row[69];
	int a = 0;
	int b = 0;
	int result = 0;

	FILE *input = fopen("input.txt", "r");

	if(input == NULL){
		perror("Error opening file");
		return 1;
	}

	int i = 0;
	while(fgets(row, sizeof(row), input) != NULL){
		if(row[0] == '\n')
			break;

		sscanf(row, "%d|%d", &a, &b);
		rules[i][0] = a;
		rules[i][1] = b;
		i++;
	}


	while(fgets(row, sizeof(row), input) != NULL){
		struct List l;
		char* token = strtok(row, ",");
		l.length = 0;

		while(token != NULL && l.length < 24){
			i = atoi(token);
			l.items[l.length] = i;
			l.length++;
			token = strtok(NULL, ",");
		}

		for (i = 0; i < l.length - 1; i++) {

			for(int j = i + 1; j < l.length; j++){

				a = 0;

				for (int k = 0; k < sizeof(rules)/sizeof(rules[0]); k++) {

					if((l.items[i] == rules[k][0] && l.items[j] == rules[k][1])){
						a = 1;
						break;
					}

				}

				if(a == 0)
					break;
			}

			if(a == 0)
				break;
		}

		if(a == 1)
			result += l.items[l.length/2];
	}

	printf("%d\n", result);
	return 0;
}
