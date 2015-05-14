//============================================================================
// Name        : md5cipher.cpp
// Author      : Hilbert Taylor Nzia
// Version     :
// Copyright   : Created Mar 15, 2015
// Description : !!!Encryption using Hash function!!!
//============================================================================

#include <iostream>
#include<sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <algorithm>
#include <stdexcept>


using namespace std;

#define BUFSIZE 1024
#define MD5LEN  16


const char *string = "The quick brown fox jumped over the lazy dog's back";



std::string text_to_hex(const std::string& myText)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = myText.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = myText[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

std::string hex_to_text(const std::string& myText)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = myText.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = myText[i];
        const char* p = std::lower_bound(lut, lut + 16, a);
        if (*p != a) throw std::invalid_argument("not a hex digit");

        char b = myText[i + 1];
        const char* q = std::lower_bound(lut, lut + 16, b);
        if (*q != b) throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
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
        snprintf(&(out[n]), 16, "%c", (unsigned int)digest[n]);
    }
    return out;
}

//char *text_to_hex(char *myText)
//{
//	FILE *fp;
//	char *command; //perl -e 'print, unpack("H*", "some string"), "\n"'
//	command="perl -e " & quote & "print unpack("& doublequote & "H*" & doublequote & ", " & doublequote & &myText & doublequote & ")" & quote;
//	fp = popen(command,"r");
//	fscanf(fp,&command);
//	fclose(fp);
//	return command;
//}
//
//char *hex_to_text(char *myText)
//{
//	FILE *fp;
//	char *command;//perl -e 'print pack("H*", "736f6d6520737472696e67"), "\n"'
//	command="perl -e " & quote & "print pack("& doublequote & "H*" & doublequote & ", " & doublequote & &myText & doublequote & ")" & quote;
//	fp = popen(command,"r");
//	fscanf(fp,command);
//	fclose(fp);
//	return command;
//}
