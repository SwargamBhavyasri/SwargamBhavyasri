/*filename             : Operator_Oload.cpp
Author                 : Swargam Bhavyasri
Requirements           :  #include<iostream>,#include<string.h>
*/  
#include<iostream>
#include<string.h>
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
    }
    //parameterised constructor
    bank(int *i_no,char *cname)  
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iAc_No=i_no;
        strcpy(cName,cname);
    }
    /*function name : Acc_Details
     parameters     : *ino,cname[]
     */
 void Acc_Details(int *ino,char cname[])
    {
        iAc_No=ino;
        strcpy(cName,cname);
    }

    void display()
    {
        cout<<"ID Number :"<<*iAc_No<<endl<<"Name:"<<cName<<endl;
        cout<<endl;
    }

    void operator ++()  
    {
        ++(*iAc_No);
    }
    ~bank()
    {
        cout<<"Destructor is Invoked"<<endl;
    }
};
int main(int argc,char* argv[])
{
	// condition for the arguments to display -h file
    if(argc>=2) //condition for the arguments to display -h file
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
        bank b1; 
		int iNum;
        char cNme[20];
        cout<<"Enter Acc No of the A/C Holder:";
        cin>>iNum;
        cout<<"Enter Name of the A/c Holder:";
        getchar();
        cin.get(cNme,100,'\n');
        cout<<endl<<"Using Parameterized Constructor :"<<endl;
        bank b2(&iNum,cNme);    
        b2.display();
        cout<<"After Operator Overloading"<<endl;
        ++b2;     
        cout<<"Using Member Function"<<endl;
        b1.Acc_Details(&iNum,cNme);    
        b1.display();
        //shallow copy 
        bank b3=b1;
        b1.display();
		b3.display(); 
        }
    return 0;
}

 

