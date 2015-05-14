Here is how to compile my program don't forget to disable ASLR.

gcc -o abbasp abbasp.c -fno-stack-protector -g

My program is like if you want to reset your password in facebook. 
You need to answer three questions to get an access to reset your passwaord.
Therefore, you have to answer each question correctlly otherwise you won't get an access.
The successful exploit is to get an access withouut answering the right answer. 
It doesn't matter if you answer the first question or the second right