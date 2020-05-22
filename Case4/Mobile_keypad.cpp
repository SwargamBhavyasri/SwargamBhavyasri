/* Filename       :    Mobile_keypad.cpp
   Description      :   Program to print all possible combinations of words for digits in a phone keypad
   Creation Author  :  Swargam Bhavyasri
   */
#include"Mobile_Class.h"
using namespace std;
    
	/*function name     :   generateHelper
      Return type       :   void*/
      void Mobile :: generateHelper(string letter_combinations[],string& sCurrent,int iIndex,string& sDigits,vector<string> &output)
    {
            if (iIndex == sDigits.size())
            {
            	//if equal push the answer to current digit
                output.push_back(sCurrent);
            }
            else
            {
			
            //storing the digit in int form
            int digit = sDigits[iIndex] - '0';
                //for looop runs until the value less than the digit size
                for (int i = 0; i < letter_combinations[digit].size(); i++)
                {
                    	
                  sCurrent.push_back(letter_combinations[digit][i]);
                  //generate the combinations of digits
                 generateHelper(letter_combinations,sCurrent,iIndex + 1,sDigits,output);
                 sCurrent.pop_back();
                }   
            }
        }
    
       vector<string> Mobile ::letterCombinations(string digits)
        {
        	
            string sCurrent="";
            //letter combinations
            string digits_letter_combination_map [10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            generateHelper(digits_letter_combination_map,sCurrent,0,digits,output);
            return output;
        }

int main(int argc,char *argv[])
{  
    //help command 
 	if((argc==2)&&strcmp(argv[1],"-h")==0)
    {
        cout<<"Usage  ::"<<endl;
        cout<<"Input :: Positive Integers from 2 to 9"<<endl;
     }
    else
    { 
     //object creation for class
   	Mobile m;
   	//variable declaration
   	string digits;
	//Reading the digits
	cin>>digits;
	vector<string> final_result=m.letterCombinations(digits);
	//for loop used for final result
	for (int i = 0; i < final_result.size(); i++)
	//Printing the final result 
    cout << final_result[i] << " ";
    cout<<endl;
   return 0;
   }
}
