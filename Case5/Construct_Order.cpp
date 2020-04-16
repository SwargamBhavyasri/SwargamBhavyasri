/*filename : Construct_Order.cpp
  Author   : Swargam Bhavyasri  */
#include<iostream>
#include<string.h>
using namespace std;
class car   //base class
{
	public : car()
	{
		cout<<"This is a car Constructor(Base)"<<endl;
	
	}
	~car()
	{
		cout<<"Destructing a car"<<endl;
	}
	//function with virtual keyword
	virtual void func1()
	{
		cout<<"Virtual Function"<<endl;
	}
};
class maruthi : public car  //derived class
{
	public : maruthi()
	{
		cout<<"This is maruthi Constructor (Derived)"<<endl;
	}
   	 void func1()
	{
		cout<<"maruthi(derived class)Virtual Function"<<endl;
	}
	 virtual  ~maruthi()
	{
		cout<<"Destructing class Maruthi"<<endl;
	}
};
int main(int argc,char *argv[])
{
	if(argc>=2)   //condition for the arguments to display -h file
	{
		if(strcmp(argv[1],"-h"))
		{
		cout<<"\\Usage of the program:\\"<<endl<<endl<<endl;
		cout<<"Order of constructors and Destructors"<<endl;
	}
}
	else
	{ 
	maruthi m;     //creation of object for derived class
	m.func1();     
	return 0;
	}
}
