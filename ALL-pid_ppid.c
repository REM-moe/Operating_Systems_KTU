#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t a;
	a = fork();
	if(a == 0){
		printf("Child process !!! [id:%d] \n", getpid());
		exit(0);
		printf("parent of Child Process: %d \n", getppid());
	}
	else if(a > 0){
		wait(NULL);
		printf("Parent process !!! [id:%d]\n", getpid());
		printf("Parent of Parent Process: %d \n", getppid());
	}else{
		printf("child Process Creation Failed !!! [id:%d] \n", getpid());
	}
	return 0;
}
