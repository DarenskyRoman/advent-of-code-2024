//Answer: 4939
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
	char map[132][132];
	char row[132];
	int dirs[4][2] = {
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1}
	};
	int dir[2] = {-1, 0};
	int pos[2];
	int distinct = 1;

	FILE *input = fopen("input.txt", "r");

	if(input == NULL){
		perror("Error opening file");
		return 1;
	}

	int i = 0;
	while(fgets(row, sizeof(row), input) != NULL){
		memcpy(&map[i], &row, sizeof(row));

		if(strstr(row, "^")){
			pos[0] = i;
			pos[1] = strstr(row, "^") - &row[0];
			map[pos[0]][pos[1]] = 'X';
		}

		i++;
	}

	i = 0;

	while(1){

		if(pos[0] + dir[0] < 0|| pos[1] + dir[1] < 0 ||
			pos[0] + dir[0] > sizeof(map[1]) - 1 ||
			pos[1] + dir[1] > sizeof(map[1]) - 1){

				break;
			}

		if(map[pos[0] + dir[0]][pos[1] + dir[1]] == '#'){
			i++;
			dir[0] = dirs[i % 4][0];
			dir[1] = dirs[i % 4][1];
		}
		else if(map[pos[0] + dir[0]][pos[1] + dir[1]] == 'X'){
			pos[0] += dir[0];
			pos[1] += dir[1];
		}
		else{
			if(map[pos[0] + dir[0]][pos[1] + dir[1]] == '.')
				distinct++;
			pos[0] += dir[0];
			pos[1] += dir[1];
			map[pos[0]][pos[1]] = 'X';
		}

	}

	printf("%d\n", distinct);
	return 0;
}