// opendir() return daratype of DIR* struct. opendir(), clodedir(), header = dirent.h
#include<stdio.h>
#include<dirent.h> 

/* opendir() - opens Specified directory and return DIR* pointer 
   readdir() - Reads Content of directory*/

int main(){
	DIR *D; // Directory String (struct DIR*)
	D = opendir("."); // name of direct.
	struct dirent *DR; // Access the Structure For reading
	if(D != NULL){
		while(DR = readdir(D)){
			printf("%s \n", DR->d_name); // d_name id from dirent header
		}
		closedir(D); // closing the Directory
		return 0;
	}
	printf("Could Not Open The Directory\n");
	return 0;
} 
