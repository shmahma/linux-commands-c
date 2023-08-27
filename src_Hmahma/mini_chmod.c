#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "mini_lib.h"

int mini_chmod(char *filename, char *mode)
{
	int mod = strtol(mode, NULL, 8);
	return chmod(filename, mod) == -1;
		
}

int main(int argc, char **argv)
{
	if(mini_strlen(argv[1]) != 3)
	{
		mini_printf("respectez ./mini_chmod mod file\n");
		mini_exit(0);
	}

	if(mini_chmod(argv[2], argv[1]) == -1)
		mini_perror("mini_chmod");
	return 0;
}
