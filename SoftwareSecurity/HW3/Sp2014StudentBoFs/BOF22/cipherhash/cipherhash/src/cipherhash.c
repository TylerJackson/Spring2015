/*
 ============================================================================
 Name        : cipherhash.c
 Author      : Hilbert Taylor Nzia
 Version     :
 Copyright   : Created on: Mar 15, 2015
 Description : Creating a cipher using openSSL hmac MD5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define BUFSIZE 256
#define MD5LEN  16

static const char* const lut = "0123456789ABCDEF";

void PressEnterToContinue(void)
{
	printf ( "Press [Enter] to continue . . ." );
	fflush ( stdout );
	getchar();
}
void myflush ( FILE *in )
{
	int ch;
	printf ( "\nPress [Enter] to continue . . ." );
	do
		ch = fgetc ( in );
	while ( ch != EOF && ch != '\n' );

	clearerr ( in );
}

int lowbound(int low, int high, char e)
{
	int i=low;
	while ((i<=high) && (lut[i]!=e)){
		++i;
	}
	return low-1;
}

char *text_to_hex(const char *myText)
{

	size_t len = sizeof(myText);

	char *output;
	output=(char *)malloc(2 * len);
	size_t i = 0;
	size_t ii = 0;
	do{
		const unsigned char c = myText[i];
		output[ii]=lut[c >> 4];
		output[ii+1]=lut[c & 15];
		++i;
		++ii;
	}while (i < len);
	return output;
}

char *hex_to_text(const char *myText)
{
	size_t len = sizeof(myText);
	char *output;
	output=(char *)malloc(len/2);
	size_t i = 0;
	do {
		char a = myText[i];
		const int p=lowbound(0,16,a);
		char b = myText[i + 1];
		const int q=lowbound(0,16,b);
		output[i]=((lut[p]<< 4)|lut[q]);
		i=i+2;
	}while (i < len);
	return output;
}

char *str2md5(const char *str, int length) {
	int n;
	MD5_CTX c;
	unsigned char digest[16];
	char *out = (char*)malloc(33);

	MD5_Init(&c);

	while (length > 0) {
		if (length > 512) {
			MD5_Update(&c, str, 512);
		} else {
			MD5_Update(&c, str, length);
		}
		length -= 512;
		str += 512;
	}

	MD5_Final(digest, &c);

	for (n = 0; n < 16; ++n) {
		snprintf(&(out[n]), 16,"%c", (unsigned int)digest[n]);
	}
	return out;
}

void concatenate(char p[], const char q[]) {
	int c, d;

	c = 0;

	while (p[c] != '\0') {
		c++;
	}

	d = 0;

	while (q[d] != '\0') {
		p[c] = q[d];
		d++;
		c++;
	}

	p[c] = '\0';
}

char *xor(const char string[MD5LEN],const char key[MD5LEN]){

	char xorout[MD5LEN];
	int x=0;
	while (x<MD5LEN)
	{
		xorout[x]=string[x]^key[x];
		x++;
	}
	return xorout;
}


int main() {

	FILE *fp1, *fp2, *fp3;

	char buf[BUFSIZE];
	char *a;
     char *filename;
	char plaintext[]={'\0'};
	char *hmacMd5;
	system("clear");
	printf("\n Enter the  of the file to encrypt : ");

	scanf("%s",filename);

	fp1 = fopen(filename, "r");

	if (fp1 == NULL) {

		printf("cannot open this file: %s \n", filename );

		exit(1);
	}

	fp2 = fopen("transit.txt", "r+");

	if (fp2 == NULL) {

		puts("Not able to open this file: transit.txt \n");

		fclose(fp1);

		exit(1);

	}

	fp3 = fopen("cipher.txt", "w");

	if (fp3 == NULL) {

		puts("Not able to open this file : cipher.txt \n");

		fclose(fp1);
		fclose(fp2);

		exit(1);

	}
	while (fgets (buf, sizeof(buf), fp1)){
		a = text_to_hex(buf);
		fputs(&a, fp2);
		concatenate(plaintext,buf);
	}
	fseek(fp2, 0L, SEEK_SET);
	hmacMd5=str2md5(plaintext, MD5LEN);

	while (fgets (buf, MD5LEN, fp2)){
		a=xor(buf,hmacMd5);
		hmacMd5=str2md5(hmacMd5, MD5LEN);
		fputs(&a, fp3);
	}
	puts("completed cipher.txt \n");
	fcloseall();
	myflush(stdin);
	PressEnterToContinue;
	return  (EXIT_SUCCESS);
}
