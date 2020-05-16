/* Filename         :    Mobile_keypad.cpp
   Description      :   Program to print all possible combinations of words for digits in a phone keypad
   Creation Author  :  Swargam Bhavyasri
   */
#include <iostream>
#include <map>
#include <string.h>
using namespace std;
string dial(int key)
{ 
    //creates a object for map is m
    map<int,string>m;
    m[0]=" ";
    m[1]=" ";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
   return m[key];
}
//class declaration
class Mobile
{
	public:
		/* function name   : phoneKey
		   Return Type     : void*/
    	void phoneKey(int iNum,string output)
       {
    	//condition to check if number is less than 0
        if(iNum<0)
        {
		  cout<<"Enter only Positive Numbers ::"<<endl;
       	}
       	//condition to check if number is 0 or 1
        else if(iNum==0||iNum==1)
        {
           	 cout<<output<<"  ";
              return;
         }
         else
         {
            string keypad=dial(iNum%10);
            for(int iIndex=0;iIndex<keypad.size();iIndex++)
             {
                phoneKey(iNum/10,keypad[iIndex]+output);
                  }
           }
}
/* function name   :  printKeypad
   Return type     : void */
public :void printKeypad(int iNum)
{
    
    //  Given an integer number print all the possible combinations of the keypad
     phoneKey(iNum," ");
    
}
};
int main(int argc,char *argv[])
{
	//create a object for class
	Mobile m;
	//used for help command 
	if((argc==2)&&strcmp(argv[1],"-h")==0)
    {
        cout<<"Usage  ::"<<endl;
        cout<<"Input :: Positive Integers from 2 to 9"<<endl;
     }
    else
    { 
	 //declaration of variable   
	 int iValue;
	 //Read the value
	 cin>>iValue;
	 //function call
	 m.printKeypad(iValue);
      return 0;

}
}

