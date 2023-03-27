#include<stdio.h>
#include<unistd.h>
// only one cmd will be executed
int main(){
	printf("ls -l Result/n");
	execl("/bin/ls", "/bin/ls", "-l", ".", NULL); // containg path of cmd, specify path again, sub-cmd, folder name to execute, NULL
	printf("/n ls Result/n");
	execl("/bin/ls", "/bin/ls", NULL, ".", NULL); // containg path of cmd, specify path again, sub-cmd, folder name to execute, NULL
	printf("Result using execlp\n");
	execlp("ls", "ls", "-l", ".", NULL); //  cmd, cmd again, sub-cmd, folder name to execute, NULL
	printf("Result using execv\n");
	char *a[] = {"/bin/ls", "-l", ".", NULL};
	execv("/bin/ls", a);
	return 0;
}
