#include "mini_lib.h"
#include <unistd.h>

int mini_mv(char *src, char *dest)
{
	MYFILE *fsrc = mini_fopen(src,'r');
	MYFILE *fdest = mini_fopen(dest,'w');

	char readc;

	if(fsrc == NULL || fdest == NULL)
	{
		mini_perror("error");		
		return -1;
	}
	while((readc = mini_fgetc(fsrc)) != '\0')
                {
                        mini_fputc(fdest, readc);
                }



	mini_fclose(fsrc);
	mini_fclose(fdest);

	if(unlink(src) == -1)
		return -1;

	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("respectez ./mini_mv fsource fdest\n");
		mini_exit(0);
	}
	if(mini_mv(argv[1], argv[2]) == -1)
		mini_perror("mini_mv");
	return 0;
}
