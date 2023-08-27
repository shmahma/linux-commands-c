
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "mini_lib.h"
#include <stdio.h>
void rights(char* rwx,char* nom)
{


        struct stat s;
        lstat(nom, &s);

      
        if(S_ISREG(s.st_mode))
                rwx[0] = '-';
        else if(S_ISDIR(s.st_mode))
                rwx[0] = 'd';
        else if(S_ISLNK(s.st_mode))
                rwx[0] = 'l';

        if(s.st_mode & S_IRUSR) rwx[1]= 'r'; else rwx[1]= '-';
        if(s.st_mode & S_IWUSR) rwx[2]='w'; else rwx[2]='-';
        if(s.st_mode & S_IXUSR) rwx[3]='x'; else rwx[3]='-';

        if(s.st_mode & S_IRGRP) rwx[4]= 'r'; else rwx[4]= '-';
	if(s.st_mode & S_IWGRP) rwx[5]= 'w'; else rwx[5]= '-';
        if(s.st_mode & S_IXGRP) rwx[6]= 'x'; else rwx[6]= '-';

        if(s.st_mode & S_IROTH) rwx[7]= 'r'; else rwx[7]= '-';
        if(s.st_mode & S_IWOTH) rwx[8]= 'w'; else rwx[8]= '-';
        if(s.st_mode & S_IXOTH) rwx[9]= 'x'; else rwx[9]= '-';
}

void mini_ls(char* arg){

       //ls -l 
	struct stat s;
        DIR* rep = NULL;
        struct dirent* read_file = NULL; 
        rep = opendir(arg);
        if(rep == NULL)
                _exit(1);
	while((read_file = readdir(rep)) != NULL){
                lstat(read_file->d_name, &s);
                char* rwx=mini_calloc(1,11);
                rights(rwx,read_file->d_name);
                struct tm *local=localtime(&s.st_mtime);
             
		printf("|%s|       |%d|        |%d|        |%ld|       |%d:%d:%d|         |%d/%d/%d|        |%s|\n",rwx, (int)s.st_nlink,s.st_gid,s.st_size,local->tm_hour,local->tm_min,local->tm_sec,local->tm_mday,local->tm_mon + 1,local->tm_year+1900,read_file->d_name);
		               
	       	mini_free(rwx);
        }

        if (closedir(rep)==-1)
                _exit(-1);

}


int main(int argc ,char** argv){

	
		
	
		mini_ls(".");
	
	return 0;

}
