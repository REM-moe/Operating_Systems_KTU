#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int id, fact;
	id = shmget(1328, 1024, 0666);
	int *addr_SM = shmat(id, NULL, 0); 	
	printf("Process is attached at Address: %p\n", addr_SM);
	printf("Data Written In Shared Memory is %d\n", *addr_SM);
	fact = 1;
	for(int i = 1; i<= *addr_SM; i++){
		fact *= i;
	}
	printf("Factorial of %d is %d\n", *addr_SM, fact);
	return 0;
}
