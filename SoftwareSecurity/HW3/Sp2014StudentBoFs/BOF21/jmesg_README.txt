	JAEMEN MOORE's SILLY BUFFER-OVERFLOW DEMO APP: JMESG

Welcome to JMESG, a brand-new private messaging tool...

...with a particularly unfortunate security vulnerability!

	COMPILATION

JMESG is a vanilla c application, which can be compiled on Kali Linux with gcc using the following command:

gcc -g -fno-stack-protector -z execstack -o jmesg jmesg.c

Note that you need to disable Kali's ASLR in order to exploit this program (or any others in the class, for this matter). Enter this into the terminal:

echo 0 | sudo tee /proc/sys/kernel/randomize_va_space

	WHAT IS THIS?

JMESG is a simple private messaging application. Once you log in with your username and password, you can write messages to other users and/or view messages other users have left for you. It uses an extremely simple text-based interface, and should be fairly easy to figure out. 

Now, this proof-of-concept .c file simply stores messages as plaintext files (jmesg_msg_[username]) and the userfile in plain text (jmesg_users)... but pretend, for the sake of exploitation n' argument, that you cannot read these files for whatever reason.

	YOUR MISSION, SHOULD YOU CHOOSE TO ACCEPT IT

You are the ghost of George Takei, and you're fairly certain that the president of the local Star Trek fan club, Pizza Man, has been chatting with a nefarious goon about recruiting the Ghostbusters to trap you and put you on display in a museum or something.

Obviously, this cannot stand; the trouble is, you require definitive proof of their misdeeds before you can get Starfleet Command involved.

You know Pizza Man has a JMESG account under the username "pizzaman", and an incriminating message hides somewhere within. Without snooping at the raw messages or password file (or using pizzaman's password at all), can you trick JMESG itself into showing you pizzaman's message history so you can get the evidence you need?

For the record, your login credentials are:

username: georgetakei
password: iamsulu

The goal, restated: Get JMESG to list pizzaman's private messages without actually logging in as pizzaman. Success should net you a very nefarious message...

Happy hacking!
