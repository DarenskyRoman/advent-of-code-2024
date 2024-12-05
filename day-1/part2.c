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
	int similarity = 0;

    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        perror("Error opening file");
        return 1;
    }

    int i = 0;
    while(fgets(buff, 15, input) != NULL){
	    char* token = strtok(buff, " ");
		leftArr[i] = atoi(token);
		token = strtok(NULL, " ");
		rightArr[i] = atoi(token);
		i++;
    }

    //probably you can do it without sorting, but i'm lazy
    qsort(leftArr, 1000, sizeof(int), comparator);
    qsort(rightArr, 1000, sizeof(int), comparator);

    int j = 0;
    int t = 0;
    for(i = 0; i < 1000; i++){
    	for(j = 0; j < 1000; j++){
     		if(rightArr[j] == leftArr[i])
       			t++;
       		if(rightArr[j] > leftArr[i])
         		break;
     	}
    	similarity += leftArr[i] * t;
     	t = 0;
    }

    printf("%d\n", similarity);
    return 0;
}
