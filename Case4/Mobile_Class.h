#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//class declaration
class Mobile
{
private:
	//creates a object for vector 
   std:: vector<string>output;

 // methods declarations  
private:   void generateHelper(string letter_combinations[],string& sCurrent,int iIndex,string& sDigits,vector<string> &output) ;
public:    vector<string> letterCombinations(string digits);

};
