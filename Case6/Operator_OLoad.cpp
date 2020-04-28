/*filename             : Operator_Oload.cpp
Author                 : Swargam Bhavyasri
Requirements           :  #include<iostream>,#include<string.h>,#include<stdlib.h>
*/  
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//class declaration
class bank
{
private:
//declaration of variables in private 
    int *iAc_No;               
    char cName[20]; 
public:
	//default constructor
    bank()   
    {
        cout<<"Default Constructor :"<<endl;
        iAc_No=new int;
        *iAc_No=0;
        *cName='\0';
    }
     
      //parameterised constructor                                                          
	   bank(int i_no,char cname[20])  
       {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iAc_No=new int;
        *iAc_No=i_no;
        strcpy(cName,cname);
    }
    //copy constructor
     bank(const bank& ob)
    {
        iAc_No=new int;
        strcpy(cName,ob.cName);
        //copying variables
        *iAc_No=*ob.iAc_No;
    }
     /*function name : Acc_Details
     parameters     : *ino,cname[]
     */
    void Acc_Details(int ino,char cname[])
    {   
       iAc_No=new int;
        *this->iAc_No=ino;
        strcpy(cName,cname);
    }
    void display()
    {
        cout<<"ID Number:"<<*iAc_No<<endl<<"Name:"<<cName<<endl;
        cout<<endl;
    }
     //Assignment Operator Overloading
    void operator =(const bank& t)
    {
        delete iAc_No;
        iAc_No=new int;
        strcpy(cName,t.cName);
        *iAc_No=*t.iAc_No;
    }
    // destructor
    ~bank()
    {
        cout<<"Deallocating Memory"<<endl;
        
    }
   
};
int main(int argc,char* argv[])
{
	// condition for the arguments to display -h file
    if(argc>=2) 
   {
   	if(strcmp(argv[1],"-h"))
   	        
    {
     cout<<"Usage :"<<endl;
     cout<<"Enter the integer and char variables "<<endl;
        }
    }
    else
    {
    	//object creation for class 
	int iNum;
        char cNme[20];
        //default constructor
        bank *b=new bank();
        b->display();
        //parameterised constructor
        bank *b1=new bank(19,"Bhavyasri");
        b1->display();
         //copy constructor invoked
        bank *b2= new  bank(*b1);
        cout<<"After using Copy Construcotr"<<endl;
        b2->display();
	cout<<"Enter Acc No of the A/C Holder:";
        cin>>iNum;
        cout<<"Enter Name of the A/c Holder:";
        cin>>cNme;
        b1->Acc_Details(iNum,cNme);
        cout<<"After Assigning the values ::"<<endl;
        b2->display();
        b1->display();
        cout<<"Assignment Operator Invoked ::"<<endl;
         b1=b2;
        b2->~bank();
        b1->display();
        b2=b;
        cout<<"After Assignment :: "<<endl;
        b2->display();
        b1->display(); 
        }
    return 0;
}
