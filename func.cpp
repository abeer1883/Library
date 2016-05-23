//Sadman Sakib Ahmed

#include<fstream>
#include <iostream>
#include<string.h>
#include<iomanip>
#include "user.cpp"
#include "func.h"

using namespace std;

//***************************************************************
//    	global declaration for stream object, object
//***************************************************************

fstream fp,fp1;
book bk;
student st;
dvd cd;
tape tp;

void write_book()
{
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        
        bk.create_book();
        fp.write((char*)&bk,sizeof(book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void write_student()
{
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do
    {
        st.create_student();
        fp.write((char*)&st,sizeof(student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void write_dvd()
{
    char ch;
    fp.open("dvd.dat",ios::out|ios::app);
    do
    {
        
        cd.create_dvd();
        fp.write((char*)&cd,sizeof(dvd));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void writeTape()
{
    char ch;
    fp.open("tape.dat",ios::out|ios::app);
    do
    {
        tp.create_tape();
        fp.write((char*)&tp,sizeof(tape));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_spb(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.retbno(),n)==0)
        {
            bk.show_book();
            flag=1;
        }
    }
    
    fp.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getchar();
}

void display_spd(char n[])
{
    cout<<"\nDVD DETAILS\n";
    int flag=0;
    fp.open("dvd.dat",ios::in);
    while(fp.read((char*)&cd,sizeof(dvd)))
    {
        if(strcmp(cd.retdvdno(),n)==0)
        {
            cd.show_dvd();
            flag=1;
        }
    }
    
    fp.close();
    if(flag==0)
        cout<<"\n\nDVD does not exist";
    getchar();
}
void display_sps(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if((strcmp(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }
    
    fp.close();
    if(flag==0)
        cout<<"\n\nStudent does not exist";
    getchar();
}

void printSpecificTape(char n[])
{
    cout << "\ntTAPE DETAILS\n";
    int flag = 0;
    fp.open("tape.dat",ios::in);
    while(fp.read((char*)&tp,sizeof(tape)))
    {
        if(strcmp(tp.rettapeno(),n) == 0)
        {
            tp.show_tape();
            flag = 1;
        }
    }
    
    fp.close();
    if(flag == 0)
        cout << "\n\nTape does not exist";
    getchar();
}



//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_book()
{
    char n[6];
    int found=0;
    
    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
    cout<<"\n\n\tEnter The book no. of The book";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0)
    {
        if(strcmp(bk.retbno(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(book));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getchar();
}

void modify_dvd()
{
    char n[6];
    int found=0;
    
    cout<<"\n\n\tMODIFY DVD REOCORD.... ";
    cout<<"\n\n\tEnter The dvd no. of The DVD";
    cin>>n;
    fp.open("dvd.dat",ios::in|ios::out);
    while(fp.read((char*)&cd,sizeof(dvd)) && found==0)
    {
        if(strcmp(cd.retdvdno(),n)==0)
        {
            cd.show_dvd();
            cout<<"\nEnter The New Details of DVD"<<endl;
            cd.modify_dvd();
            int pos=-1*sizeof(cd);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&cd,sizeof(dvd));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getchar();
}



void modify_student()
{
    char n[6];
    int found=0;
    
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter The admission no. of The student";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),n)==0)
        {
            st.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&st,sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
    
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getchar();
}

void modifyTape()
{
    char n[6];
    int found = 0;
    
    cout << "\n\n\tMODIFY TAPE REOCORD.... ";
    cout << "\n\n\tEnter The tape no. of The tape";
    cin >> n;
    fp.open("tape.dat",ios::in|ios::out);
    while(fp.read((char*)&tp,sizeof(tape)) && found == 0)
    {
        if(strcmp(tp.rettapeno(),n) == 0)
        {
            tp.show_tape();
            cout << "\nEnter The New Details of book" << endl;
            tp.modify_tape();
            int pos = -1*sizeof(tp);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&tp,sizeof(tape));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    
    fp.close();
    if(found == 0)
        cout << "\n\n Record Not Found ";
    getchar();
}



//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_student()
{
    char n[6];
    int flag=0;
    
    cout<<"\n\n\n\tDELETE STUDENT...";
    cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student)))
    {
        if(strcmp(st.retadmno(),n)!=0)
            fp2.write((char*)&st,sizeof(student));
        else
            flag=1;
    }
    
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
    else
        cout<<"\n\nRecord not found";
    getchar();
}


void delete_book()
{
    char n[6];
    
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book)))
    {
        if(strcmp(bk.retbno(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(book));
        }
    }
    
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getchar();
}

void delete_dvd()
{
    char n[6];
    
    cout<<"\n\n\n\tDELETE DVD ...";
    cout<<"\n\nEnter The DVD no. of the DVD You Want To Delete : ";
    cin>>n;
    fp.open("dvd.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&cd,sizeof(dvd)))
    {
        if(strcmp(cd.retdvdno(),n)!=0)
        {
            fp2.write((char*)&cd,sizeof(dvd));
        }
    }
    
    fp2.close();
    fp.close();
    remove("dvd.dat");
    rename("Temp.dat","dvd.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getchar();
}

void deleteTape()
{
    char n[6];
    
    cout << "\n\n\n\tDELETE TAPE...";
    cout << "\n\nEnter The Tape no. of the Tape You Want To Delete : ";
    cin >> n;
    fp.open("tape.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&tp,sizeof(tape)))
    {
        if(strcmp(tp.rettapeno(),n) != 0)
            fp2.write((char*)&tp,sizeof(tape));
    }
    
    fp2.close();
    fp.close();
    remove("tape.dat");
    rename("Temp.dat","tape.dat");
        cout << "\n\n\tRecord Deleted ..";
    getchar();
}

//***************************************************************
//    	function to display all students list
//****************************************************************

void display_alls()
{
    
    fp.open("student.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getchar();
        return;
    }
    
    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
    
    while(fp.read((char*)&st,sizeof(student)))
    {
        st.report();
    }
    
    fp.close();
    getchar();
}


//***************************************************************
//    	function to display Books list
//****************************************************************

void display_allb()
{
    
    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getchar();
        return;
    }
    
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=========================================================================\n";
    
    while(fp.read((char*)&bk,sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getchar();
}


//***************************************************************
//    	function to display DVD list
//****************************************************************

void display_alld()
{
    
    fp.open("dvd.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getchar();
        return;
    }
    
    cout<<"\n\n\t\tDVD LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"DVD Number"<<setw(20)<<"DVD Name"<<setw(25)<<"Director\n";
    cout<<"=========================================================================\n";
    
    while(fp.read((char*)&cd,sizeof(dvd)))
    {
        cd.report();
    }
    fp.close();
    getchar();
}


//***************************************************************
//    	function to display all Tape list
//****************************************************************

void displayAllTapes()
{
    
    fp.open("tape.dat",ios::in);
    if(!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        getchar();
        return;
    }
    
    cout << "\n\n\t\tTAPE LIST\n\n";
    cout << "==================================================================\n";
    cout << "\tTape No"<<setw(10)<<"Title"<<setw(20)<<"Author\n";
    cout << "==================================================================\n";
    
    while(fp.read((char*)&tp,sizeof(tape)))
    {
        tp.report();
    }
    
    fp.close();
    getchar();
}


//***************************************************************
//    	function to issue book
//****************************************************************

void book_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                cout<<"\n\n\tEnter the book no. ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmp(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current datein backside of book and submit within 15 days fine $1 for each day after 15 days period";
                    }
                }
                if(flag==0)
                    cout<<"Book no does not exist";
            }
            else
                cout<<"You have not returned the last book ";
            
        }
    }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}

//***************************************************************
//    	function to issue DVD
//****************************************************************


void dvd_issue()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    
    cout<<"\n\nDVD ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("dvd.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                cout<<"\n\n\tEnter the dvd no. ";
                cin>>bn;
                while(fp1.read((char*)&cd,sizeof(dvd))&& flag==0)
                {
                    if(strcmp(cd.retdvdno(),bn)==0)
                    {
                        cd.show_dvd();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t DVD issued successfully\n\nPlease Note: Write current datein backside of dvd and submit within 15 days fine $2 for each day after 10 days period";
                    }
                }
                if(flag==0)
                    cout<<"DVD no does not exist";
            }
            else
                cout<<"You have not returned the last dvd ";
            
        }
    }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}


//***************************************************************
//    	function to issue tape
//****************************************************************


void issueTape()
{
    char sn[6],bn[6];
    int found=0,flag=0;
    
    cout<<"\n\nTAPE ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("tape.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                cout<<"\n\n\tEnter the dvd no. ";
                cin>>bn;
                while(fp1.read((char*)&tp,sizeof(tape))&& flag==0)
                {
                    if(strcmp(tp.rettapeno(),bn)==0)
                    {
                        tp.show_tape();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t TAPE issued successfully\n\nPlease Note: Write current date in backside of dvd and submit within 20 days fine $3 for each day after 10 days period";
                    }
                }
                if(flag==0)
                    cout<<"TAPE no does not exist";
            }
            else
                cout<<"You have not returned the last TAPE ";
            
        }
    }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}



//***************************************************************
//    	function to deposit book
//****************************************************************

void book_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmp(bk.retbno(),st.retstbno())==0)
                    {
                        bk.show_book();
                        flag=1;
                        cout<<"\n\nBook deposited in no. of days";
                        cin>>day;
                        if(day>15)
                        {
                            fine=(day-15)*1;
                            cout<<"\n\nFine has to deposited $. "<<fine;
                        }
                        st.resettoken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book deposited successfully";
                    }
                }
                if(flag==0)
                    cout<<"Book no does not exist";
            }
            else
                cout<<"No book is issued..please check!!";
        }
	   }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}


//***************************************************************
//    	function to deposit dvd
//****************************************************************

void dvd_deposit()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    
    cout<<"\n\nDVD DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("dvd.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
                while(fp1.read((char*)&cd,sizeof(dvd))&& flag==0)
                {
                    if(strcmp(cd.retdvdno(),st.retstbno())==0)
                    {
                        cd.show_dvd();
                        flag=1;
                        cout<<"\n\nDVD deposited in no. of days";
                        cin>>day;
                        if(day>10)
                        {
                            fine=(day-10)*2;
                            cout<<"\n\nFine has to deposited $. "<<fine;
                        }
                        st.resettoken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t DVD deposited successfully";
                    }
                }
                if(flag==0)
                    cout<<"DVD no does not exist";
            }
            else
                cout<<"No dvd is issued..please check!!";
        }
	   }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}


//***************************************************************
//    	function to deposit tape
//****************************************************************

void depositeTape()
{
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    
    cout<<"\n\nTAPE DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("tape.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
    {
        if(strcmp(st.retadmno(),sn)==0)
        {
            found=1;
            if(st.rettoken()==1)
            {
                while(fp1.read((char*)&tp,sizeof(tape))&& flag==0)
                {
                    if(strcmp(tp.rettapeno(),st.retstbno())==0)
                    {
                        tp.show_tape();
                        flag=1;
                        cout<<"\n\nTAPE deposited in no. of days";
                        cin>>day;
                        if(day>20)
                        {
                            fine=(day-20)*3;
                            cout<<"\n\nFine has to deposited $. "<<fine;
                        }
                        st.resettoken();
                        int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t TAPE deposited successfully";
                    }
                }
                if(flag==0)
                    cout<<"TAPE no does not exist";
            }
            else
                cout<<"No tape is issued..please check!!";
        }
	   }
    if(found==0)
        cout<<"Student record not exist...";
    getchar();
    fp.close();
    fp1.close();
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************

void intro()
{
  cout <<("+----------------------------------------------------------+\n");
  cout <<("|              Computer Science and Engineering            |\n");
  cout <<("|                	CSCE 1040                                |\n");
  cout <<("|Sadman Sakib Ahmed   sa0617  sadmansakibahmed@my.unt.edu  |\n");
  cout <<("+----------------------------------------------------------+\n\n");
}



//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
    
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
	cout<<"\n\n\t11.CREATE DVD ";
    cout<<"\n\n\t12.DISPLAY ALL DVD ";
    cout<<"\n\n\t13.DISPLAY SPECIFIC DVD ";
    cout<<"\n\n\t14.MODIFY DVD ";
    cout<<"\n\n\t15.DELETE DVD ";
	cout<<"\n\n\t16.CREATE TAPE ";
    cout<<"\n\n\t17.DISPLAY ALL TAPE ";
    cout<<"\n\n\t18.DISPLAY SPECIFIC TAPE ";
    cout<<"\n\n\t19.MODIFY TAPE ";
    cout<<"\n\n\t20.DELETE TAPE ";
    cout<<"\n\n\t21.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-21) ";
    cin>>ch2;
    switch(ch2)
    {
        case 1:
            write_student();break;
        case 2: display_alls();break;
        case 3:
            char num[6];
            
            cout<<"\n\n\tPlease Enter The Admission No. ";
            cin>>num;
            display_sps(num);
            break;
      		case 4: modify_student();break;
      		case 5: delete_student();break;
        case 6:
            write_book();break;
        case 7: display_allb();break;
        case 8: {
            char num[6];
            
            cout<<"\n\n\tPlease Enter The book No. ";
            cin>>num;
            display_spb(num);
            break;
        }
      		case 9: modify_book();break;
      		case 10: delete_book();break;
			case 11:
            write_dvd();break;
        case 12: display_alld();break;
        case 13: {
            char num[6];
            
            cout<<"\n\n\tPlease Enter The dvd No. ";
            cin>>num;
            display_spd(num);
            break;
        }
      		case 14: modify_dvd();break;
      		case 15: delete_dvd();break;
			case 16:
            writeTape();break;
        case 17: displayAllTapes();break;
        case 18: {
            char num[6];
            
            cout<<"\n\n\tPlease Enter The Tape No. ";
            cin>>num;
            printSpecificTape(num);
            break;
        }
      		case 19: modifyTape();break;
      		case 20: deleteTape();break;
        case 21: return;
      		default:cout<<"\a";
   	}
   	admin_menu();
}
