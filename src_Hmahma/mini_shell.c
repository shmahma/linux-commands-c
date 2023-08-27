#include"mini_lib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define SIZE_BUF 100

extern char** environ;



int read_commande(char* command, char** arg){

	char* ligne_command=mini_calloc(1,SIZE_BUF);
	int i=0,k=0,j=2,size_argi=1000;
	mini_scanf(ligne_command,SIZE_BUF);
	command[0]='.';
	command[1]='/';
	while(ligne_command[i]==' '){
		i++;
	}
	for( i=i;ligne_command[i]!=' '&&ligne_command[i]!='\n'&&ligne_command[i]!='\0';i++){
		command[j]=ligne_command[i];
		j++;
	}

	if (mini_strcmp(command,"./exit")==0) {
		return -1;
	}
	

	arg[k]=command;

	k++;
	while(ligne_command[i]!='\n'){

		if(ligne_command[i]!=' '){

			char *argi=mini_calloc(1,size_argi);

			j=0;
			while(ligne_command[i]!=' ' && ligne_command[i]!='\n'){
				argi[j]=ligne_command[i];
				j++;
				i++;
			}
			arg[k]=argi;

			k++;
		}
		if(ligne_command[i]!='\n')
			i++;


	}
	arg[k]=NULL;	



	return k;

}



int main(int argc, char ** argv) {
	
	int nb,stat=1,bol_exit=0,i=0;

	if(argc==1){
		mini_printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n		$$Debut mini_shell$$: !!entrez votre commande sans ./ ou bien avec ./!!\n		$$!!sous cette forme : mini_commande arguments ou ./mini_commande arguments!!\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");

		while(stat!=0&&!bol_exit) {

			char* command=mini_calloc(1,SIZE_BUF);
        		char* arg[50];


			
			mini_printf("$$entrez votre commande$$: ");
			nb=read_commande(command,arg);
			
			if(mini_strcmp(command,"./cd")==0) {
                		if(arg[1]!=NULL){
                        		if(chdir(arg[1])==-1)
                                		mini_perror("cd");
				}
				else{
					mini_printf("entrez le nom de repertoire\n");

				
				}
				continue;}

			if(mini_strcmp(command,"./mini_env")==0) {
                                
                                char **ptr=environ;
			       	while(*ptr!=NULL){
					mini_printf(*ptr);
					mini_printf("\n");
					ptr++;
				}
				continue;	
                                }


			if(mini_strcmp(command,"./mini_getenv")==0) {
				if(arg[1]!=NULL){
					char **ptr=environ;
					while(*ptr!=NULL){
						int i=0;
						int k=0;
						while(arg[1][i]!='\0'){
							if(arg[1][i]==(*ptr)[i]){
								k++;
							}

							i++;
						}
						if(k==mini_strlen(arg[1]))
							{mini_printf(*ptr);
							mini_printf("\n");
							break;}
						ptr++;
					}}
				else{

					mini_printf("entrez le nom de variable\n");
				}
				continue;
			}

			if(mini_strcmp(command,"./mini_export")==0) {
                                if(arg[1]!=NULL){
					 char **ptr=environ;
                                       	 while(*ptr!=NULL){
                                                
                                                ptr++;
                                       	}
					*ptr=mini_calloc(1,mini_strlen(arg[1])+1);
					 mini_strcpy(arg[1],*ptr);
					 ptr++;
					 *ptr=NULL;
				

                                       
                                }
                                else{
                                        mini_printf("entrez le nom de variable\n");


                                }
                                continue;}




			



			if(nb==-1) {
				mini_printf("$$fin mini_shell$$\n");
				bol_exit=1;
				break;
			}
			stat = fork();




			if(stat==-1){
				mini_perror("Failure\n");
				_exit(1);}
			else if(stat== 0){
				if(execvp(command,arg)==-1) {
					if(execvp(command+2,arg)==-1){
						mini_printf("$$Failure:commande non trouvable$$\n");
					}
				}}


			else{
				wait(0);
				mini_free(command);
				while(arg[i]!=NULL){
                        		mini_free(argv[i]);
                        		i++;
				}

			}




		}
	

		mini_exit();}

	else{

		_exit(1);}
}


