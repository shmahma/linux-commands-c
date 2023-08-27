#include "mini_lib.h"
#include <stdlib.h>//pour utiliser atoi()
#include <unistd.h>
#include <stdio.h>


#define BUFFER_SIZE 3000

int mini_quickdiff(char *fi1, char *fi2)
{
	MYFILE *f1 = mini_fopen(fi1,'r');
	MYFILE *f2 = mini_fopen(fi2,'r');

	if(f1 == NULL || f2 == NULL)
	{
		mini_printf("Fichier introuvable :");
		return -1;
	}
	int i = 0;int c = 0;int j = 0;int k=0;int compare = 0;int n=0;


	char *buff1 = mini_calloc(1, BUFFER_SIZE);
	char *buff2 = mini_calloc(1, BUFFER_SIZE);
	char *line1 = mini_calloc(1, BUFFER_SIZE);

	
	if(mini_fread(buff1, sizeof(char), BUFFER_SIZE, f1)==-1)
		return -1;

	

	if(mini_fread(buff2, sizeof(char), BUFFER_SIZE, f2) ==-1)
		return -1;
	
	int start1 = 0;int end1 = 0;
	int ind[20];
	
	while(i<20){
		ind[i]=0;
		i++;
	}
	
	i=0;
	
	j=1;
	while(buff2[i] != '\0'){
	
		if(buff2[i]=='\n'){
		
			ind[j]=i+1;
			j++;
		
		}
		i++;
	
	
	}
	i=0;
	j=0;

	while(buff1[i] != '\0')
	{
		if(buff1[i] == '\n')
		{
			start1 = end1;
			end1 = i;
			j = 0;
			if(start1==0){
				k=0;

			}
			else
				k=start1+1;
			for(k=k;k<=end1;k++)
			{
				line1[j] = buff1[k];
				j++;
			}
			compare = 1;
		}
		
		if(compare)
		{
			
			k=0;
			while(line1[k]!='\0'){

				if(line1[k]!=buff2[ind[n]+k])
					{mini_printf(line1);
					break;}
				k++;
			
			}
			for(k=0 ; k<BUFFER_SIZE ; k++)
			{

				line1[k] = '\0';
			}
			compare = 0;
			n++;
		}

		c++;i++;
	}
	
	mini_fclose(f1);
	mini_fclose(f2);

	return 0;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		mini_printf("respectez  quick_diff f1 f2\n");
		mini_exit(0);
	}

	mini_quickdiff(argv[1], argv[2]);

	return 0;
}
