#include <stdio.h>

int main(){

	char o;
	float n1;
	float n2;

	printf("Donner une opération utilisant 2 nombres (mettre des espaces entre les nombres et le signe): ");
	scanf("%f %c %f", &n1, &o, &n2);

	printf("Résultat (précision : 2 chiffres après la virgule) : ");

	switch(o){
		case '+' : printf("%1.2f\n", n1 + n2);
			   break;

		case '-' : printf("%1.2f\n", n1 - n2);
			   break;

		case '*' : printf("%1.2f\n", n1 * n2);
			   break;

		case '/' : if (n2 != 0){
				   printf("%1.2f\n", n1 / n2);
			   } else {
				   printf("???\nErreur : division par 0 !!!\n");
			   }
			   break;

		case '%' : if (n2 != 0){
				   printf("%d\n",((int) n1) % ((int) n2));
			   } else {
				   printf("???\nErreur : division pas 0 !!!\n");
			   }
			   break;

		default : printf("???\nErreur : signe inconnu ou espace(s) oublié(s) !!!\n");
			  break;
	}

	return 1;
}