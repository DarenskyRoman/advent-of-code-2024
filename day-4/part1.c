//Answer: 2575
#include <stdio.h>
#include <string.h>


int main(){
	char array[140][142];
	char row[142];
	char mas[4];
	mas[3] = '\0';
	int count = 0;

	int dir[8][2] = {
		{1, 0},
		{1, -1},
		{0, -1},
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, 1},
		{1, 1}
	};

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

	for(i = 0; i < sizeof(array)/sizeof(array[0]); i++){
		for(int j = 0; j < sizeof(array[0]); j++){

			if(array[i][j] == 'X'){

				for(int k = 0; k < 8; k++){
					if(i + dir[k][0] * 3 < sizeof(array)/sizeof(array[0]) && i + dir[k][0] * 3 >= 0 &&
						j + dir[k][1] * 3 < sizeof(array[0]) && j + dir[k][1] * 3 >= 0){

							mas[0] = array[i + dir[k][0]][j + dir[k][1]];
							mas[1] = array[i + dir[k][0] * 2][j + dir[k][1] * 2];
							mas[2] = array[i + dir[k][0] * 3][j + dir[k][1] * 3];

							if(strcmp("MAS", mas) == 0){
								count++;
							}
					}
				}
			}
		}
	}

	printf("%d\n", count);
	return 0;
}
