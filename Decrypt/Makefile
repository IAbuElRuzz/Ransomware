CC = gcc
CFLAGS = -g -Wall -o
DEPS = decrypt.c fileRecursor.c curlHelper.c
OBJECTS =decrypt.o curlHelper.o fileRecursor.o
EXECS = decrypt

all:
	$(CC) -c decrypt.c
	$(CC) -c fileRecursor.c -lcrypto
	$(CC) -c curlHelper.c -lcmurl

	$(CC) $(CFLAGS) decrypt decryptDriver.c $(OBJECTS) -lcrypto -lcurl


clean:
	rm *.o $(EXECS)