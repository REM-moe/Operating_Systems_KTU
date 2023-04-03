#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include<string.h>
#include<unistd.h>

int main(){
	int id = shmget(1328, 1024, 0666 | IPC_CREAT); // a key(any int.), memory space, flag bit, (if shared seg dosent exist we use IPC_CREAT)
	printf("Shared Memeory id: %d \n", id);
	void *addr_SM = shmat(id, NULL, 0); 	/* [attach]The third parameter is ‘0’ 
											   if the second parameter is NULL, otherwise, 
											   the value specified by SHM_RND. */
	printf("Process is attached at Address: %p\n", addr_SM);
	char buffer[100];
	printf("Enter The Data: \n");
	read(0, buffer, 100);
	strcpy(addr_SM, buffer);
	printf("Data Written In Shared Memory!! %s\n", (char *)addr_SM);
	return 0;
}
