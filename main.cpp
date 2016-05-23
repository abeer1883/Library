//Sadman Sakib Ahmed
//CSCE 1040

#include<fstream>
#include <iostream>
#include<string.h>
#include<iomanip>
#include "func.h"

using namespace std;

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
    char ch;
    intro();
	
	cout << "******************************************************\n\n";
	cout << "          Welcome To Bacchu Library                   \n\n";
    do
    {
        
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
		cout<<"\n\n\t03. DVD ISSUE";
        cout<<"\n\n\t04. DVD DEPOSIT";
		cout<<"\n\n\t05. TAPE ISSUE";
        cout<<"\n\n\t06. TAPE DEPOSIT";
        cout<<"\n\n\t07. ADMINISTRATOR MENU";
        cout<<"\n\n\t08. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-4) ";
        ch=getchar();
        switch(ch)
        {
            case '1':
                book_issue();
                break;
            case '2':book_deposit();
                break;
			case '3':
                dvd_issue();
                break;
            case '4':dvd_deposit();
                break;
			case '5':
                issueTape();
                break;
            case '6':depositeTape();
                break;
            case '7':admin_menu();
                break;
            default :cout<<"\a";
        }
    }while(ch!='8');
}