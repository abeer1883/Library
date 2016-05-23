#include <iostream>
#include <string.h>
#include <fstream>
#include<iomanip>
#include "func.h"

using namespace std;

class student
{
    char admno[6];
    char name[20];
    char stbno[6];
    int token;

	public:
	
		void create_student()
		{
        
        cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>admno;
        cout<<"\n\nEnter The Name of The Student ";
		cin >> name;
        token=0;
        stbno[0]='\0';
        cout<<"\n\nStudent Record Created..";
		}
    
		void show_student()
		{
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nStudent Name : ";
        cout << name;
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<stbno;
		}
    
		void modify_student()
		{
        cout<<"\nAdmission no. : "<<admno;
        cout<<"\nModify Student Name : ";
        cin >> name;
		}	
    
		char* retadmno()
		{
        return admno;
		}
    
		char* retstbno()
		{
        return stbno;
		}
    
		char* retname()
		{
		return name;
		}
	
		int rettoken()
		{
        return token;
		}
	
    
		void addtoken()
		{token=1;}
    
		void resettoken()
		{token=0;}
    
		void getstbno(char t[])
		{
        strcpy(stbno,t);
		}
    
		void report()
		{cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;}
		
};
	
	class book
{

    char bno[6];
    char bname[20];
    char aname[20];
	
	public:
		
		
		void create_book()
		{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>bno;
        cout<<"\n\nEnter The Name of The Book ";
        cin >> bname;
        cout<<"\n\nEnter The Author's Name ";
        cin >> aname;
        cout<<"\n\n\nBook Created..";
		}
    
		void show_book()
		{
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        cout << bname << endl;
        cout<<"Author Name : ";
        cout << aname << endl;
		}
    
		void modify_book()
		{
        cout<<"\nBook no. : "<<bno;
        cout<<"\nModify Book Name : ";
        cin >> bname;
        cout<<"\nModify Author's Name of Book : ";
        cin >> aname;
		}
    
		char* retbno()
		{
        return bno;
		}
	
		char* retbname()
		{
		return bname;
		}
	
		char* retaname()
		{
		return aname;
		}
    
		void report()
		{cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}
    
};

class dvd
{

    char dvdno[6];
    char dvdname[20];
    char dirname[20];
	
	public:
		
		
		void create_dvd()
		{
        cout<<"\nNEW DVD ENTRY...\n";
        cout<<"\nEnter The DVD no.";
        cin>>dvdno;
        cout<<"\n\nEnter The Title of The DVD ";
        cin >> dvdname;
        cout<<"\n\nEnter The Director Name ";
        cin >> dirname;
        cout<<"\n\n\nDVD Created..";
		}
    
		void show_dvd()
		{
        cout<<"\nDVD no. : "<<dvdno;
        cout<<"\nDVD Name : ";
        cout << dvdname << endl;
        cout<<"Director Name : ";
        cout << dirname << endl;
		}
    
		void modify_dvd()
		{
        cout<<"\nDVD no. : "<<dvdno;
        cout<<"\nModify DVD Name : ";
        cin >> dvdname;
        cout<<"\nModify Director's Name of Book : ";
        cin >> dirname;
		}
    
		char* retdvdno()
		{
        return dvdno;
		}
	
		char* retdvdname()
		{
		return dvdname;
		}
	
		char* retdirname()
		{
		return dirname;
		}
    
		void report()
		{cout<<dvdno<<setw(30)<<dvdname<<setw(30)<<dirname<<endl;}
    
};


class tape
{

    char tapeno[6];
    char tapename[20];
    char author[20];
	
	public:
		
		
		void create_tape()
		{
        cout<<"\nNEW TAPE ENTRY...\n";
        cout<<"\nEnter The TAPE no.";
        cin>>tapeno;
        cout<<"\n\nEnter The Title of The TAPE ";
        cin >> tapename;
        cout<<"\n\nEnter The Author's Name ";
        cin >> author;
        cout<<"\n\n\nTAPE Created..";
		}
    
		void show_tape()
		{
        cout<<"\nTAPE no. : "<<tapeno;
        cout<<"\nTAPE Name : ";
        cout << tapename << endl;
        cout<<"Author Name : ";
        cout << author << endl;
		}
    
		void modify_tape()
		{
        cout<<"\nTAPE no. : "<<tapeno;
        cout<<"\nModify TAPE Name : ";
        cin >> tapename;
        cout<<"\nModify Author's Name of Book : ";
        cin >> author;
		}
    
		char* rettapeno()
		{
        return tapeno;
		}
	
		char* rettapename()
		{
		return tapename;
		}
	
		char* retauthorname()
		{
		return author;
		}
    
		void report()
		{cout<<tapeno<<setw(30)<<tapename<<setw(30)<<author<<endl;}
    
};

