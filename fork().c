#include<stdio.h>
#include<unistd.h>
int main(){
	fork();
	fork();	
	fork();
	printf("Hello World \n");
	fork();
	fork();
	printf("Welcome \n");
	return 0;
}
