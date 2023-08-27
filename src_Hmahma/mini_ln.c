#include <unistd.h>
#include "mini_lib.h"

int mini_ln(char* arg1, char* arg2)
{
	return symlink(arg1, arg2);
		
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("respectez cette forme ./mini_ln fichier_destination fichier_pointeur");
		mini_exit(0);
	}
	else{
		if(mini_ln(argv[1],argv[2])==-1){
			mini_perror("mini_ln");		
			
			_exit(1);}
	
	}

	return 0;
}
