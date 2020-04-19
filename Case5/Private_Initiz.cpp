/* 
filename          :     Private_Initiz.cpp
Author            :     Swargam Bhavyasri
Description       :     The main purpose of this program is to how to use & Declare Different way to initialize the private member variables in a class
Requirements      :     #include<iostream>, #include<string.h>
*/
#include<iostream>
#include<string.h>
using namespace std;
//class Declaration
class employee
{
	//private data member
    private:  
    int iNum,iAge;
    double dWage;
    public:
    employee() 
	{ 
	  cout<<"Default Constructor Employee is invoked ::"<<endl;
	  //directly initialize our member variables*/
	   iNum=101;
       dWage=15000;
	   iAge =28; 
}

    employee(int iId,double dSal,int iAg)
	{  
	  cout<<"Parameterised Constructor Employee ::"<<endl;
	   iNum= iId;
	   dWage= dSal;
	    iAge=iAg;
}
     //member functions
	   public: void init();
	           void display();
    };
    //using scope resolution operator accessing the private data members
    void employee ::  init()                                                             
    {
        cout<<endl;
	    cout<<"Using Member Function"<<endl;
        cout<<"Enter Id of the Employee :"<<endl;
        cin>>iNum;
        cout<<"Enter the Salary of the Employee ::"<<endl;
        cin>>dWage;
        cout<<"Enter the Age of the Employee ::"<<endl;
        cin>>iAge;
     }
     /*function name  : display()
       Usage          : display the private members */
    void employee :: display()
    {
    	cout<<"\n";
    	cout<<"Id of the Employee       =        "<<iNum<<endl;
    	cout<<"Salary of the Employee   =        "<<dWage<<endl;
    	cout<<"Age of the Employee      =        "<<iAge<<endl;
}

int main(int argc,char *argv[])
{
    //help command
    if(argc == 2 && strcmp(argv[1], "-h")==0)  
   
    { 
    	cout<<"Usage :"<<endl;
        cout<<"Input : Positive Values "<<endl;
    }
    else
    {   
        //creating object for a class
        employee e; 
		//default constructor  
        e.display();
        e.init();
        // trying to access private data member directly outside the class
        e.display();
        //parameterized constructors
        employee e1(101,20000,30);
         e1.display();
         }
     
    return 0;
}
