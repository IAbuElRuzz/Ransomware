# RANSOMWARE
	
## Summary
- 
	This is ransomware implemented in C with a corresponding C&amp;C created with Java Spring Boot. This ransomware is purely for educational purposes. Use of this program may be illegal in some countries. This software is currently not finished. It will encrypt and decrypt, but I cannot guarentee that my test server will hold or keep any keys/ids. Do not run without risking permanently encrypting your disk's content.


## WARNING 
  - Use this tool at your own risk. Author is not responsible or liable if you damage your own system or others. Follow all local, state, federal, and international laws as it pertains to your geographic location. Do NOT use this tool maliciously as it is being released for educational purposes. This tools intended use is in cyber exercises or demonstrations of adversarial tools.
  
##Explanation

 - The Encrypt / Decrypt folders contain two separate programs. This was done intentionally in order to reduce the encrypt payload size and at the time I was going to attempt to "self-destruct" the encrypt program once it was finished then make the decrypt program downloadable. If I ever get time, I will probably merge encrypt/decrypt back together because they both only work if you know the key/iv. 
	
 - Encrypt: Makes a curl request to the Java Spring REST api in order to get the "clients" key,iv, and id for encryption. The REST server will save the associated information for release when paid. Then the filerecursor.c will go through each file and encrypt every file ending with a certain extension. IT doesn't encrypt every file because we want the computer to boot. It also creates a .txt file stating the ransom demands in each directory
	
 - Decrypt: Same as encrypt but reverse.
