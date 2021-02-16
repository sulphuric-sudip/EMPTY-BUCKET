#include <iostream>
#include <stdlib.h>
#include <fstream>	
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "header.h"

int logincheck=0;
int loginid;
string user;

void exit()
	{
		heading();
		changeColor(15);
		cout << "\n\n\t\t\tEXITING...\n\t\t\tSAVING DATA.";
		for(int i=0;i<9;i++){
			Sleep(300);
			cout << ".";
		}
		changeColor(46);
		cout<<"\n****************************************";
		cout<<"\n*                                      *";
		cout<<"\n*";changeColor(44);cout<<"	     HAVE A NICE DAY           ";changeColor(46);cout<<"*";
		cout<<"\n*                                      *";
		cout<<"\n****************************************";
		changeColor(15);
	}

//Creating a class with starting login and register function.

class start
{
	public:
		start()			//constructor asking to login.
		{	
			char choice1;
			heading();
			changeColor(15);
			gotoxy(10,13);cout<<"1.\tLOGIN";
			gotoxy(10,14);cout<<"2.\tREGISTER";
			gotoxy(10,15);cout<<"3.\tEXIT";
			gotoxy(15,16);cout<<"Press Your Choice: ";
			choice1=getch();
	
			switch(choice1)
			{
   				case ('1'): 
					login();
   					break;
				case ('2'):
		 			signin();
					break;
				case ('3'):
					exit();
					break;
				default:
					changeColor(12);
					cout<<"\n\n\t**********__Wrong input__**********\a\a";
					getch();
					system("cls");
					changeColor(15);
					start();
					break; 		
			}
		}
//	private:	
		//login function
		void login()
		{
			int idno,lchk=0;
			string username,password,u,p;
			gotoxy(15,20);cout<<"Provide username and password:";
			gotoxy(19,21);changeColor(14);cout<<"Username: ";
			gotoxy(19,22);changeColor(14);cout<<"Password: ";
			gotoxy(29,21);changeColor(10);cin>>username;
			gotoxy(29,22);changeColor(10);
			string passkey="";
			char ch1;
			ch1=getch();
			while(ch1!=13){
				passkey.push_back(ch1);
				cout<<ch1;
				Sleep(400);
				putch('\b');
				cout<<"*";
				ch1=getch();
			 }
			password=passkey;
			ifstream finlc;
			finlc.open("user_detail.txt");
			while(!finlc.eof())
			{
				finlc >>idno >>u >>p;
				if((u==username)&&(p==password))
				{
					lchk=1;
					break;
				}
			}
			if(lchk==1)
			{
				logincheck=1;
				loginid=idno;
				user=u;
			}
			else
			{	
				changeColor(12);
				cout<<"\n\n\t***_Wrong Login_***\n\a\a\tTry Again;";
				getch();
				changeColor(15);
				start();
			}
			
		}
		//signin
		void signin()
		{
			//taking input from user
			int idno=0;
			string username,password,u,p;
			cout<<"\nFill following details to signin.\nUsername: ";
			cin>>username;
			//checking if same username already exist.
			ifstream fin1;
			fin1.open("user_detail.txt");
			while(!fin1.eof())
			{					
				fin1 >>idno >> u >>p;				//read from file
				if(u==username)
				{	
					changeColor(12);
					cout<<"Same Username Already Exist!!\a\a";changeColor(15);cout<<" Give New Username: ";			
					cin>>username;
					fin1.seekg(0);
				}
			}	
			cout<<"\nPassword: ";
			string passkey="";
			char ch1;
			ch1=getch();
			while(ch1!=13){
				passkey.push_back(ch1);
				cout<<ch1;
				Sleep(400);
				putch('\b');
				cout<<"*";
				ch1=getch();
			}
			password=passkey;
			//giving serial no. for new user
			while(!fin1.eof())
			{					
			
				fin1 >>idno >> u >>p;
			}
			fin1.close();
			idno++;
			fstream fout;
			fout.open("user_detail.txt",ios::app);
			fout<<idno<<"\t";
			fout<<username<<"\t";
			fout<<password<<"\n";
			fout.close();
			
			stringstream ss;
			ss<<idno;
			string s,ffile;
			ss>>s;
			ffile="users_coin/"+s+".txt";
			ofstream coin;
		    coin.open(ffile.c_str());
		    coin<<"0\n";
		    coin.close();
			
			changeColor(10);
			cout<<"\n\t\tSignup Complete!! Login for further process::";
			changeColor(15);
			getch();
			system("cls");
			start();
		}
};

	//reads all user data after user just logged in
class users
{
private:
	int idno,coin,i,idn;
	string name,fnam,fdat,fst;
	vector <string> flim_date;
	vector <string> flim_seat;
	vector <string> booked_flim;
public:
	users()
	{
		i=0;
		idn=loginid;
		idno=loginid;
		stringstream ss;
		ss<<idn;
		string s;
		ss>>s;
		name = user;
		string fbn,fen,ffile;
		fbn="users_coin/";
		fen=".txt";
		ffile=fbn+s+fen;
		//for reading coin of user
		ifstream fincoin;
		fincoin.open(ffile.c_str(),ios::in);
		fincoin>>coin;
		fincoin.close();
		
		fbn="users_detail/";
		ffile=fbn+s+fen;
		//for reading booked flim of user
		fstream finuser1;
		finuser1.open(ffile.c_str(),ios::app);
		finuser1.close();
		ifstream finuser;
		finuser.open(ffile.c_str(),ios::in);
		while(!finuser.eof())
		{	
			getline(finuser,fnam);
			getline(finuser,fdat);
			getline(finuser,fst);
			booked_flim.push_back(fnam);
			flim_date.push_back(fdat);
			flim_seat.push_back(fst);
			i++;
		}
		finuser.close();
	}	
	friend class home;
	
};

class flimlist{
	public:
		string nam,dat,no;
		int i,j,price[4],seatav[4];
		vector <string> num;
		vector <string> name;
		vector <string> date;
		flimlist()
		{
			i=0;j=0;
			ifstream flimli;
			flimli.open("releasinglist.txt");
			while(!flimli.eof()){
				getline(flimli,no);
				num.push_back(no);
				getline(flimli,nam);
				name.push_back(nam);
				getline(flimli,dat);
				date.push_back(dat);
				j++;
			}		
			flimli.close();
			
			ifstream fp;
			fp.open("fprice.txt");
			while(!fp.eof()){
				fp>>price[i];
				i++;
			}
			fp.close();
			
			int l;
			for(int k=0;k<4;k++){
				l=k+1;
				stringstream ss;
				ss<<l;
				string s,fbe,fen,ffs;
				ss>>s;
				fbe="releasinglist/";
				fen=".txt";
				ffs=fbe+s+fen;
				int noo,pck;
				pck=-1;
				noo=100;			
				ifstream finst;
				finst.open(ffs.c_str(),ios::in);
				while(!finst.eof()){
					finst>>noo;
					pck++;
				}
				if(noo==100)
					pck=0;
				seatav[k]=96-pck;
				finst.close();
			}
		}
};
#include "payment.h"
#include "conformation.h"
#include "home.h"
//main function

int main()
{	
//	getch();
	welcome_anim();
	start s;	
	if(logincheck==1)
	{	
		changeColor(15);
		home h;
	}
	getch();
}
