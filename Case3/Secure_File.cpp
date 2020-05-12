/*  Program Name    :    Secure_File.cpp
    Description     :    Program to display the Encrypt and Decrypt text using key by using Command line Arguments
    Creation Author  :   Swargam Bhavyasri
    */
#include <iostream>
#include <fstream>
#include <string.h>
#include<sstream>
#include<algorithm>
using namespace std;
//creating class
class folder 
{
//variables declaration
public:	
       string sLine;
       string sSentence;
       string sWord;
/* Funtion Name   : Encrypt()
   Return type    :  void*/
   public:void Encrypt()
{
   fstream myfile ("Secure.txt",ios::in);
   ofstream ofile("Encoded.txt", ios::out); 
   //opening a file
   if (myfile.is_open())
{
	  int iLen=0;
	  while ( getline (myfile,sLine) )
	  {
	  	 istringstream iss(sLine);
	  	  while (iss >> sWord)
	  	  {  
	  	   //Reverse the sentence from begining to end
	   std::reverse(sWord.begin(), sWord.end());
	   iLen+=sWord.length()+1;
	   //Reversed sentence and spaces replaced with *
	    cout<<sWord<<"*";
        // writing the data to a new file
         ofile<<sWord;
         //condition to check the lenght of the line
         if(iLen<sLine.length())
          ofile<<"*";
          	}
     cout<<endl;
     }
      //file closing
   myfile.close();
   ofile.close();
   }  
   else
 cout << "Unable to open file";
}
/* function Name  : decrypt()
   Return Type    : void*/
public : void decrypt()
{
	 fstream ifile("Encoded.txt", ios::in);
	 ofstream odfile("Decode.txt", ios::out);
	 if (ifile.is_open())
    {
  	while ( getline (ifile,sSentence,'*') )
    {
	    //Reverse the sentence from begining to end
	   std::reverse(sSentence.begin(), sSentence.end());
            //Reversed sentence and spaces replaced with *
            cout<<sSentence<<" ";
            // writing the data to a new file
            odfile<<sSentence<<"  ";
        }
    //file closing
   ifile.close();
   odfile.close();

    }
else
 cout << "Unable to open file";
}
};
int main(int argc,char *argv[])
{   
   //creating the object for folder class
    folder f;
    //condition for the arguments to display -h file
	if(argc==2)   
	{
	 if(strcmp(argv[1],"-h")==0)
		{
		cout<<"\\Usage of the program:\\"<<endl;
		cout<<"f filename -e encryption / -d decryption -k key"<<endl;
   }
else if(argc>=2)
   { 
   //condition for the arguments to display -e   
  	if(strcmp(argv[1],"-e")==0)
	 	   {
	 		cout<<"Encrption ::"<<endl;
	 		f.Encrypt();
		    }
	//conditon for the argumeents to diplay -d
	 if(strcmp(argv[1],"-d")==0)
	   {
	 	cout<<"Decryption ::"<<endl;
	 	f.decrypt();
	    }
   }
}
else
return 0;
}

