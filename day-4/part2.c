//Answer: 2041
#include <stdio.h>
#include <string.h>


int main(){
	char array[140][142];
	char row[142];
	char mas1[3];
	mas1[2] = '\0';
	char mas2[3];
	mas2[2] = '\0';
	int count = 0;

	FILE *input = fopen("input.txt", "r");

	if(input == NULL){
		perror("Error opening file");
		return 1;
	}

	int i = 0;
	while(fgets(row, sizeof(row), input) != NULL){
		memcpy(&array[i], &row, sizeof(row));
		i++;
	}

	for(i = 1; i < sizeof(array)/sizeof(array[0]); i++){
		for(int j = 0; j < sizeof(array[0]) - 1; j++){

			if(array[i][j] == 'A'){

				if(i < sizeof(array)/sizeof(array[0]) - 1 &&
					j < sizeof(array[0]) - 1 && i > 0 && j > 0 ){

					mas1[0] = array[i - 1][j - 1];
					mas1[1] = array[i + 1][j + 1];
					mas2[0] = array[i + 1][j - 1];
					mas2[1] = array[i - 1][j + 1];

					if( (strcmp("MS", mas1) == 0 || strcmp("SM", mas1) == 0) &&
					 (strcmp("MS", mas2) == 0 || strcmp("SM", mas2) == 0) ){
						count++;
					}
				}
			}
		}
	}

	printf("%d\n", count);
	return 0;
}
