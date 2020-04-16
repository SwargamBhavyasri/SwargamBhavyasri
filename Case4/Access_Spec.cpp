/* filename :Access_Spec.cpp
   Author : Swargam Bhavyasri*/
#include<iostream>
#include<string.h>
using namespace std;
//Base class
class shape                  
{
    //private members
   	int iArea;
	public: int area(int iLength,int iBreadth)
		{
			iArea=iLength*iBreadth;
			cout<<  "Area :"         <<iArea<<endl;
		}
	//using protected access specifier
	protected : int iPerimeter;     
};
//derived class
class Rectangle : private shape      
{
	// public members
	public: int iP;                   
	   int per(int iLen, int iWidth)
	   {
	   	iP=iLen+iWidth;
	   	iPerimeter= 2*iP;
	   	cout<< "Perimeter :"      <<iPerimeter<<endl;
	   }
};

int main(int argc,char* argv[])
{
   if(argc>=2) //condition for the arguments to display -h file
   {
   	if(strcmp(argv[1],"-h"))
   	{
	cout<<"\\Usage of the program:\\"<<endl<<"Access Specifiers :::"<<endl;
   	cout<<"Input : Integer Values"<<endl;
   	cout<<" "<<endl;
   }
}
   else
   {
   	//objects creation for classes
   	shape s;          
   	Rectangle r;
   	s.area(5,5);
   	r.per(5,5);
   	return 0;
   }
}

   
   

