#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int id, n;
	id = shmget(1328, 1024, 0666);
	char *addr_SM = shmat(id, NULL, 0); 	
	printf("Process is attached at Address: %p\n", addr_SM);
	printf("Data Written In Shared Memory is %s\n", addr_SM);
	int k = 0;
	int flag = 0;
	n = strlen(addr_SM);
	for(int i = 0; i< strlen(addr_SM); i++){
		if(addr_SM[i] != addr_SM[n-i-1]){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("%s, Is A Palindrome\n", addr_SM);
	}
	else{
		printf("%s, Is Not A Palindrome\n", addr_SM);
	}
	return 0;
}
