/*filename      : Modif_Types.cpp
  Author        :  Swargam Bhavyasri 
  Description    :  Program to display modifier types ,scope of the variables and storage classes
  Requirements   :  #include<iostream>,#include<string.h>*/
#include<iostream>
#include<string.h>
using namespace std;
//Declared Global variable
 int age=16; 
void display()                 
{
	//Local Variable Declaration which will be used for this particulor function
    int age=18;
    //Global variable is accessed
    cout << "Value of global Variable " << ::age <<endl;
   //age can be accessed by global declared variable
  cout<<"Any Indian can eligible for Right to Vote:"<<age<<endl;
}
void display1()      
{
    unsigned char a='c'; //unsigned character Modifier
    signed char b='a'; //signed character Modifier
    unsigned int c=2500;//unsigned integer Modifier
    signed int d= -2500;//signed integer Modifier
    unsigned short int e=2500;//unsigned shor integer Modifier
    signed short int f= -5000;//signed short integer Modifier
    unsigned long int g=5000;//unsigned long integer Modifier
    signed long int h=-2500;//signed long integer Modifier
    long double i=6000;//Long double Modifier 
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i;
}
void type_storage()
{
	{
    long double lValue;         
    cout<<"Enter the double value:";
    cin>>lValue;
    static int iStatic_No;    
    register int iRegister_N;    
    cout<<"Enter the Register ";
    cin>>iRegister_N;
    cout<<"Enter Static ";
    cin>>iStatic_No;
    cout<<endl;
    cout<<"Storage classes"<<endl;
    cout<<"Static   =     "<<iStatic_No<<" "<<"Size:"<<sizeof(iStatic_No)<<endl;
    cout<<"Register =     "<<iRegister_N<<" "<<"Size:"<<sizeof(iRegister_N)<<endl;
    cout<<"Double Value:  "<<lValue<<" "<<"Size of Double:"<<sizeof(lValue)<<endl;
    cout<<endl;
}
}
int main(int argc,char *argv[])
{
	//comments for displaying -h file 
     if(argc >= 2 ) 
     {
     	if(strcmp(argv[1],"-h"))
     	{
	    cout<<"Usage:"<<endl;
        cout<<" Input : Values "<<endl;
    }
}
    else
    {
    	//displaying the function
         display();
        //Here age is taken globally
        cout<<"Not Eligible :"<<age<<endl;
        type_storage();
        display1();
     }
    return 0;
}
