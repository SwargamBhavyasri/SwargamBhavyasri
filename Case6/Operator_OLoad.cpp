/*filename : Operator_Oload.cpp
Author     : Swargam Bhavyasri
*/  
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class Employee
{
private:
    int *iD_no;               //declaration of variables in private 
    char cName[20]; 
public:
    Employee()   
    {
        cout<<"Default Constructor :"<<endl;
    }
    Employee(int *i_no,char *cname)  
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iD_no=i_no;
        strcpy(cName,cname);
    }
 void Assign_Value(int *ino,char cname[])
    {
        iD_no=ino;
        strcpy(cName,cname);
    }

    void display()
    {
        cout<<"ID Number :"<<*iD_no<<endl<<"Name:"<<cName<<endl;
        cout<<endl;
    }

    void operator ++()  
    {
        ++(*iD_no);
    }
    ~Employee()
    {
        cout<<"Destructor is Invoked"<<endl;
    }
};
int main(int argc,char* argv[])
{
    if(argc==2)        // condition for the arguments to display -h file
    {
     cout<<"Usage :"<<endl;
     cout<<"Enter the integer and char variables "<<endl;
        }
    else
    {
        Employee e;              //object creation for class 
        int iNum;
        char cNme[20];
        cout<<"Enter ID of the Employee:";
        cin>>iNum;
        cout<<"Enter Name of the Employee:";
        getchar();
        cin.get(cNme,100,'\n');
        cout<<endl<<"Using Parameterized Constructor :"<<endl;
        Employee e2(&iNum,cNme);    
        e2.display();
        cout<<"After Operator Overloading"<<endl;
        ++e2;     
        cout<<"Using Member Function"<<endl;
        e.Assign_Value(&iNum,cNme);    
        e.display();
    }
    return 0;
}
