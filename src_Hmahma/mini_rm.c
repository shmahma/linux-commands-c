#include <unistd.h>
#include "mini_lib.h"

int mini_rm(char *path)
{
	return unlink(path);
	
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		mini_printf("respectez ./mini_rm file\n");
		mini_exit(0);
	}

	for(int i=1; i<argc ; i++)
	{
		if(mini_rm(argv[i]) == -1)
			mini_perror("mini_rm");
	}
	return 0;
}
