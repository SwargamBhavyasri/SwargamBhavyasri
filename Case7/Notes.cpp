/*filename             :  Notes.cpp
  Creation Author      :  Swargam Bhavyasri
  Requirements         :  #include<iostream>,#include<fstream>,#include<string.h>,#include<map>*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;
class notes
{
        
 private: string key;
        string item;
        public:

    map<string,string>mp;
     map<string,string>::iterator it;
      void input()
     {
	 cout<<"Enter the key "<<endl;
    cin>>key;
    cout<<"Enter the Item "<<endl;
    cin>>item;
    mp.insert(pair<string,string>(key,item));
for (it=mp.begin(); it!=mp.end(); ++it);
}
   void ouput()
        {

for ( it=mp.begin(); it!=mp.end(); ++it);
    cout << it->first << " => " << it->second << '\n';
        }

}; notes fileobj;
void Create()           //Function to Create Data File
{
        fstream fil;
        char ch='y';
        fil.open("notes.txt",ios::out|ios::app);
        while(ch=='y' || ch =='Y')
        {
                fileobj.input();
                fil.write((char*)&fileobj, sizeof(fileobj));
                cout<<"Want to Continue.....";
                cin>>ch;
        }
        fil.close();
        }
void update()              //Function to Add New Record in Data File
{
        fstream fil;
        char ch='y';
        fil.open("notes.txt",ios::app| ios::out);
        while(ch=='y' || ch =='Y')
        {
                fileobj.input();
                fil.write((char*)&fileobj, sizeof(fileobj));
                cout<<"Want to Continue.....";
                cin>>ch;
        }
        fil.close();
}
 void read()
  {
    ifstream fil;
  fil.open("notes.txt",ios::in|ios::app);
  // Reding from file
  while(!fil.eof())
  {
        fil.read((char*)&fileobj, sizeof(fileobj));
        fileobj.ouput();
    }
  //closing the file
  fil.close();
}
 int main()
{
                int opt;
        while(1)
        {
                cout<<"1.Create Data File"<<endl;
                cout<<"2.Add New Record in Data File"<<endl;
                cout<<"3.Read from the record"<<endl;
                cin>>opt;
                 switch(opt)
        {
                case 1:
                        {
                                Create();
                                cout<<"Display Main Menu"<<endl;
                                getchar();
                                break;
                        }
                        case 2:
                        {
                                update();
                                cout<<"Display Main Menu"<<endl;
                                getchar();
                                break;
                                  }
                        case 3:
                        {
                                read();
                                cout<<"Display the main menu"<<endl;
                                getchar();
                                break;
                        }
                default:
                        cout<<"Wrong choice"<<endl;
        }
        }
}
