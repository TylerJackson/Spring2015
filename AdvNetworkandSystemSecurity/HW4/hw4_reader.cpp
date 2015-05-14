#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
  //char str[256];

  //std::cout << "Enter the name of an existing text file: ";
  //std::cin.get (str,256);    // get c-string

  std::ifstream is("A16-070524-2000UTC_modified.txt");     // open file

  char a[3];
  char b[3];
  char c[3];
  string line;
  if(1 == 1)
  {
  	getline(is,line);
  }
  cout << line<<endl;
  /*
  while (is.get(a[0])) 
  {        // loop getting single characters
  	if(a[0] == ' ')
  		is.get(a[0]);
    is.get(a[1]);
   	if(a[1] == ' ')
  		is.get(a[1]);
    is.get(b[0]);
  	if(b[0] == ' ')
  		is.get(b[0]);
    is.get(b[1]);
  	if(b[1] == ' ')
  		is.get(b[1]);
    is.get(c[0]);
  	if(c[0] == ' ')
  		is.get(c[0]);
    is.get(c[1]);
  	if(c[1] == ' ')
  		is.get(c[1]);
    //if( strcmp(a,b)!=0 || strcmp(a,c)!=0)
		std::cout << "------" << a << " " <<b<<" "<<c<<std::endl;

  }
  is.close();                // close file
  char  s[10] = "h";
  strcat(s,"d");
  char ac[3];
  ac[0] = 'a';
  ac[1] = 'b';
  char ad[3];
  ad[0] = 'a';
  if(strcmp(ac,ad)==0)
  	cout<<"balls";
  cout <<s<<endl;*/
  return 0;
}