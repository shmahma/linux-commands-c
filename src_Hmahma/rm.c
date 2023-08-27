#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include "mini_lib.h"
#include <stdio.h>
#include <sys/stat.h>
int mini_chmod(char* arg,char* mode){




        int mod = strtol(mode, NULL, 8);
	if(chmod(arg, mod) == -1)
		return -1;
	return 0;



}




int main(int argc,char** argv){

        int result;
        if(mini_strlen(argv[1]) != 3)
	{
		mini_printf("respectez cette struct: ./mini_chmod mod file_name\n");
		mini_exit(0);
	}

	if(mini_chmod(argv[2], argv[1]) == -1)
		mini_perror("chmod");





        return 0;

}

