#include <stdio.h>
#define MAX 1000
                           // i % 3 == 0 est équivalent à !(i % 3)
int main(){
	int i;

	for (i = 0;i < MAX;i++){
		if (i % 3 == 0){
			printf("fizz");
		}
		if (i % 5 == 0){
			printf("buzz");
		}
		if ((i % 3 != 0) && (i % 5 != 0)){
			printf("%d", i);
		}

		printf("\n");
	}

	return 1;
}
