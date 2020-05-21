/*  Program Name    :    Secure_File.cpp
    Description     :    Program to display the Encrypt and Decrypt text using key by using Command line Arguments
    Creation Author  :   Swargam Bhavyasri
    */

#include"Secure_Class.h"
using namespace std;
/*function name  :  Encrypt
  Return type    :  void*/
void Secure :: Encrypt(char *filename,char *key)
{
	
    ifstream myfile (filename) ;
    ofstream outfile("Encoded.txt") ; 
    outfile<<key ;
    outfile<<endl ;
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
        	       outfile<<(sWord)<<"*";
                    //condition to check the lenght of the line
                    if(iLen<sLine.length())
                     outfile<<"*";
         }
         	
           cout<<endl;
        }
        
        //file closing
         myfile.close();
         outfile.close();
         
        }  
   else
 cout << "Unable to open file";
    }
/* function Name  : decrypt()
   Return Type    : void*/
 void Secure :: decrypt(char *filename,char * key)
{
	Key = key;
	 fstream ifile(filename, ios::in);
	 ofstream odfile("Decode.txt", ios::out);
	 if (ifile.is_open())
    {
    	 while ( getline (ifile,kline) )
 	     {
 	     	 //if condition to check the key is same 
	 	     if(Key.compare(kline)==0)
	 	     {
	 	     	//if condition true then read the data in a file
	 	     	while ( getline (ifile,sSentence,'*') )
	 	     	{
	 	    
	 	     	         //Reverse the sentence from begining to end
	 	     	          std::reverse(sSentence.begin(), sSentence.end());
	                     //Reversed sentence and spaces replaced with " " 
	                       cout<<sSentence<<" ";
	                      // writing the data to a new file
                           odfile<<sSentence<<"  ";
                           odfile<< endl;
                         
                 }
                 
                 cout<<endl ;
                  
              } 
		    else
		    {
        	
            cout << "Wrong Key Entered";
            }
         }
	//file closing
   	ifile.close();
   	odfile.close();
   }
   
     else
      cout << "Unable to open file";
   }

int main(int argc,char *argv[])  
{
	//creates object for a secure class
	Secure s ;
	// checking arguments to display -h
    if((argc==2) && (strcmp(argv[1],"-h")==0))
	{
		cout << " usage of"<< argv[0] <<endl;           
		cout << "-e||d -f Secure.txt -k key " << endl ; 		
	}
	else if(argc>=2)
	{
			if (strcmp(argv[1],"-e")==0)
			{
				if ((strcmp(argv[2],"-f")==0 ) )
					
					s.Encrypt(argv[3], argv[5]) ;
				
			}
					
			else if (strcmp(argv[1],"-d")==0)
			{
				if ((strcmp(argv[2],"-f")==0 ) )
					
					s.decrypt(argv[3], argv[5]) ;
				
			}
	}
	
}

