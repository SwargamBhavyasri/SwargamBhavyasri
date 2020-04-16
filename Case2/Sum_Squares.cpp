/* Filename            :      Sum_Squares.cpp
   Creation Author     :      S.Bhavyasri
   */
#include<iostream>
#include<string.h>
using namespace std;
int squaresum(int iNum) 
{ 
    return (iNum * (iNum + 1) * (2 * iNum + 1)) / 6; 
} 
int main(int argc, char *argv[])
{
	//checking arguments to display -h
	if(argc>=2)             
	{
		if(strcmp(argv[1],"-h"))
		cout<<"Usage :"<<endl;
		cout<<"Input : Integer"<<endl;
		}
	else
	{
		// declaration of variable using integer data type
		int iNum;               
		cout<<"Enter Number"<<endl;
		cin>>iNum;
		//function call
		squaresum(iNum);                 
		cout<<squaresum(iNum)<<endl;
		
	}
}

