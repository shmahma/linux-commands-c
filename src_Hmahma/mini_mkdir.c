
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "mini_lib.h"
#include <stdio.h>
#include <sys/stat.h>
int mini_mkdir(char* arg){

	
	

	return mkdir( arg, 0755 );
	



}




int main(int argc,char** argv){

	if(argc < 2)
	{
		mini_printf("respectez ./mini_mkdir f1 f2...'\n");
		mini_exit(0);
	}

	for(int i=1; i<argc ; i++)
	{
		if(mini_mkdir(argv[i]) == -1)
			mini_perror("mini_mkdir");
	}	


	return 0;

}
