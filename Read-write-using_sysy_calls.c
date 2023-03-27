#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <unistd.h>

int main(){
	int FD = open("TO_test.txt", O_RDWR); // txt name, mode returns int filediscripter
	char message[90] = "IO Operation Using System Calls\n";
	char read_buffer[100];
	printf("%d\n", FD);
	if(FD != -1){
		printf("*** FILE OPENED ***\n");
		write(FD, message, sizeof(message)); // file descripter, message, size of message
		lseek(FD, 0, SEEK_SET); // man lseek for info
		read(FD, read_buffer, sizeof(message));
		printf("%sWas returned from reading\n ",read_buffer);	
		close(FD);
	}
	return 0;
}

// FD = -1 | couldnt create file
