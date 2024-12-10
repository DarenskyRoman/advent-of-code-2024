//Answer: 569
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct List {
	int length;
	int items[8];
};

int check(int a, int b){
	if(a == b || abs(a - b) > 3)
		return 0;
	if(a < b)
		return 1;
	else
		return -1;
}

int walk(struct List* a){
	int order = check(a->items[0], a->items[1]);

	if(order == 0)
		return 0;

	for (int i = 2; i < a->length; i++){
    	if(order != check(a->items[i - 1], a->items[i]))
     		return i;
    }

    return a->length;
}

void remove_at(struct List* a, int pos){
	for(int i = pos + 1; i < a->length; i++)
		a->items[i - 1] = a->items[i];

	a->length--;
}

void safe_copy(struct List* a, struct List* b){
	b->length = a->length;
	memcpy(b->items, a->items, sizeof(a->items));
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
		struct List l;
		char* token = strtok(buff, " ");
		l.length = 0;

		while(token != NULL && l.length < 8){
			int i = atoi(token);
			l.items[l.length] = i;
			l.length++;
			token = strtok(NULL, " ");
		}

		int i = walk(&l);

		if(i == l.length){
			safeReports++;
			continue;
		}
		else if(i == 0){
			struct List copyNoMiddle;
			safe_copy(&l, &copyNoMiddle);
			remove_at(&copyNoMiddle, i);

			if(walk(&copyNoMiddle) == copyNoMiddle.length){
				safeReports++;
				continue;
			}
			else{
				struct List copyNoRight;
				safe_copy(&l, &copyNoRight);
				remove_at(&copyNoRight, i + 1);

				if(walk(&copyNoRight) == copyNoRight.length)
					safeReports++;
			}

		}
		else {
			struct List copyNoMiddle;
			safe_copy(&l, &copyNoMiddle);
			remove_at(&copyNoMiddle, i);

			if(walk(&copyNoMiddle) == copyNoMiddle.length){
				safeReports++;
				continue;
			}
			else{
				struct List copyNoRight;
				safe_copy(&l, &copyNoRight);
				remove_at(&copyNoRight, i + 1);

				if(walk(&copyNoRight) == copyNoRight.length)
					safeReports++;
				else{
					struct List copyNoLeft;
					safe_copy(&l, &copyNoLeft);
					remove_at(&copyNoLeft, i - 1);

					if(walk(&copyNoLeft) == copyNoLeft.length)
						safeReports++;
					else{
						struct List copyNo2Left;
						safe_copy(&l, &copyNo2Left);
						remove_at(&copyNo2Left, i - 2);

						if(walk(&copyNo2Left) == copyNo2Left.length)
							safeReports++;
					}
				}
			}
		}
	}

	printf("%d\n", safeReports);
	return 0;
}
