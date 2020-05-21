#include <iostream>
#include <fstream>
#include <string.h>
#include<sstream>
#include<algorithm>
using namespace std;
class Secure
{

//variables declaration
private:
       string sLine;
       string sSentence;
       string sWord;
       string kline;
       string Key;
       
       //public members
      public: 	
		void Encrypt(char* filename, char* key) ;
		void decrypt(char* filename, char* key) ;
};
		
