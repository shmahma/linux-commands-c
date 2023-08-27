#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "mini_lib.h"
#include <sys/stat.h>
int mini_rmdir(char* arg){




        return rmdir( arg );




}




int main(int argc,char** argv){

        
        if(argc<2){

                mini_printf("respectez: /mini_rmdir f1 f2..\n");


        }
	else{
	
	for(int i=1; i<argc ; i++){
	 	if(mini_rmdir(argv[i])==-1){
                	mini_perror("mini_rmdir");
			_exit(1);
		}

	
	}

	}



        return 0;

}

