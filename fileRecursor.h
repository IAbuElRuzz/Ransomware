#ifndef FILERECURSOR_H
#define FILERECURSOR_H

#include <errno.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encrypt.h"


/*preprocessor*/
void directory_handle(char * name,unsigned char * key, unsigned char * iv);
void file_handler(char * filepath, char * filename,unsigned char * key, unsigned char * iv);
void startEncrypting(char * start,unsigned char * key, unsigned char * iv);


#endif

