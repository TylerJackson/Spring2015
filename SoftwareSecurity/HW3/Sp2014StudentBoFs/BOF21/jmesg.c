#include <string.h>
#include <stdio.h>

#define SMALLBUFFER 20
#define LARGEBUFFER 80

// draft concept code for JMESG, a brand-new
// private messaging tool! Huzzah!

// short helper "trim trailing newline" function
void trimnewline(char *text) {
	int i = strlen(text);
	if(i > 1 && text[i-1] == '\n')
		text[i-1] = '\0';
}

// main function
int main(int argc, char *argv[]) {

	// user input/buffers
	char username[SMALLBUFFER];
	char buffer[LARGEBUFFER];
	char password[SMALLBUFFER]; // TODO make this more secure?

	// internal buffers
	char message[LARGEBUFFER];
	char recipient[SMALLBUFFER];

	// file pointers
	FILE *userfile;
	FILE *msgfile;

	// file-open helpers
	char * line;
	char * temp;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	// misc vars
	int login = 0;

	// get user input
	printf("Welcome to JMesg! Please log in:\n");
	printf("Username: ");
	fgets(username, SMALLBUFFER, stdin);
	trimnewline(username);

	printf("Password: ");
	fgets(password, SMALLBUFFER, stdin);
	trimnewline(password);

	// read userfile
	userfile = fopen("jmesg_users", "r");
	if (userfile == NULL) {
		perror("ERR: could not open user file");
		return 0;
	}

	// attempt login
	while (read = getline(&line, &len, userfile) != -1) {
		temp = strtok (line, ":\n");
		if(strcmp(temp, username) == 0) {
			//username matches one in the userfile; check password
			temp = strtok (NULL, ":\n");
			if(strcmp(temp, password) == 0) {
				login = 1;
				break;
			}
		}
	}
	fclose(userfile);

	// if logged in, enter main loop
	if (login) {
		printf("Login successful! Welcome, %s!\n", username);
		while (login) {
			printf("\nWhat would you like to do, %s?\n", username);
			printf("(w) - write a message\n");
			printf("(r) - read your messages\n");
			printf("(x) - exit JMesg\n");
			printf("> ");

			fgets(buffer, LARGEBUFFER, stdin);
			trimnewline(buffer);

			if(strcmp(buffer, "w") == 0) {
				// write 'em up
				printf("Who would you like to send a message to?\n");
				printf("Enter username: ");
				fgets(recipient, SMALLBUFFER, stdin);
				trimnewline(recipient);

				// get message text from user
				printf("Enter message (%d chars max): ", LARGEBUFFER);
				fgets(message, LARGEBUFFER, stdin);
				trimnewline(message);
				
				// add message header
				sprintf(buffer, "\n[From %s]\n%s", username, message);

				// "send" (save) message
				sprintf(temp, "jmesg_msg_%s", recipient);
				msgfile = fopen(temp, "w");
				if (msgfile == NULL) {
					perror("ERR: could not write to message file");
					return 0;
				}
				fputs(buffer, msgfile);
				fclose(msgfile);

				printf("Message sent successfully!\n");
			}

			else if (strcmp(buffer, "r") == 0) {
				// check yo' mail, foo'
				
				sprintf(temp, "jmesg_msg_%s", username);
				msgfile = fopen(temp, "r");
				if (msgfile == NULL) {
					printf("No new messages.\n");
				} else {
					printf("\n- - -\n");
					while (read = getline(&line, &len, userfile) != -1) {
						printf("%s", line);
					}
					printf("\n- - -\nEnd of messages.\n");
				}
			}

			else if (strcmp(buffer, "x") == 0) {
				// adios, mate
				printf("Goodbye, %s. Thanks for using JMesg!\n", username);
				login = 0;
			}

			else {
				printf("Invalid command. Please try again.\n");
			}
		}

	}
	else {
		// your creds ain't credible, man!
		printf("Login unsuccessful. Please try again.\n");
	}

	// all done
	return 0;
}
