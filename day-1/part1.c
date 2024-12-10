//Answer: 1603498
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparator(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	char buff[16];
	int leftArr[1000];
	int rightArr[1000];
	int diff = 0;

    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        perror("Error opening file");
        return 1;
    }

    int i = 0;
    while(fgets(buff, 16, input) != NULL){
	    char* token = strtok(buff, " ");
		leftArr[i] = atoi(token);
		token = strtok(NULL, " ");
		rightArr[i] = atoi(token);
		i++;
    }

    qsort(leftArr, 1000, sizeof(int), comparator);
    qsort(rightArr, 1000, sizeof(int), comparator);

    for(i = 0; i < 1000; i++){
    	diff += abs(leftArr[i] - rightArr[i]);
    }

    printf("%d\n", diff);
    return 0;
}
