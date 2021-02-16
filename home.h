class home
{
public:
	home()
	{
		char cin1;
		users u;
		system("cls");
		heading();
		gotoxy(4,12);cout<<"Hello ";changeColor(14);cout<<u.name;
		changeColor(15);cout<<". You have";changeColor(11);cout<<" NRP Rs."<<u.coin;
		changeColor(15);cout<<" in your ";printEB();cout<<" Wallet."<<endl;
		gotoxy(10,14);cout<<"Do you want to add money to your account?(press 'y' for yes)";
		cin1=getch();
		if(cin1=='y'){
			payment(u.idno);
		}
		system("cls");
		homeswitch();
	}
	
	void homeswitch()
	{
		char cin2;
		heading();
		gotoxy(10,12);cout<<"1.\tBook Seat For Movie";
		gotoxy(10,13);cout<<"2.\tView your Booked Seat";
		gotoxy(10,14);cout<<"3.\tExit:";
		gotoxy(20,15);cout<<"Press your choice:";
		cin2=getch();
		
		switch(cin2)
		{
	 		case ('1'): 
				seatbook();
	  			break;
			case ('2'):
				my_detail();
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
				homeswitch();
				break;
		}
	}
	
	my_detail(){
		system("cls");
		heading();
		users u;
		gotoxy(0,12);cout.fill('-');cout.width(80);cout<<"";
		gotoxy(5,13);changeColor(249);cout<<" S.N. ";
		gotoxy(19,13);cout<<" MOVIE NAME ";
		gotoxy(47,13);cout<<" SHOW TIME ";
		gotoxy(62,13);cout<<" SEAT NO. ";
		gotoxy(0,14);changeColor(15);cout.fill('-');cout.width(80);cout<<"";
		int k;
		k=0;
		for(k=0;k<u.i-1;k++){
			gotoxy(7,15+k);cout<<k+1;
			gotoxy(16,15+k);cout<<u.booked_flim[k];
			gotoxy(43,15+k);cout<<u.flim_date[k];
			gotoxy(66,15+k);cout<<u.flim_seat[k];
		}
		gotoxy(0,16+k);cout.fill('-');cout.width(80);cout<<"";
		cout<<"\n\t\t\t\tPress any key to go back ";
		getch();
		homeswitch();
	}

	seatbook()
	{
		system("cls");
		heading();
		flimlist flim;
		gotoxy(0,12);cout.fill('-');cout.width(80);cout<<"";
		
		gotoxy(5,13);changeColor(249);cout<<" CHOICE ";
		gotoxy(19,13);cout<<" FLIM NAME ";
		gotoxy(47,13);cout<<" SHOW TIME ";
		gotoxy(62,13);cout<<" PRICE ";
		gotoxy(70,13);cout<<" SEAT REM ";changeColor(15);
		gotoxy(0,14);cout.fill('-');cout.width(80);cout<<"";
		int k;
		k=0;
		for(k=0;k<4;k++){
			gotoxy(8,15+k);cout<<flim.num[k];
			gotoxy(16,15+k);cout<<flim.name[k];
			gotoxy(43,15+k);cout<<flim.date[k];
			gotoxy(62,15+k);cout<<"Rs."<<flim.price[k];
			gotoxy(74,15+k);cout<<flim.seatav[k];
		}
		gotoxy(0,16+k);cout.fill('-');cout.width(80);cout<<"";
		gotoxy(25,17+k);cout<<"Enter your choice no.";
		int ch;
		ch=0;
		cin>>ch;
		if((ch>k)||(ch<1)){
			gotoxy(20,18+k);changeColor(12);cout<<"*****Wrong Input*****\a\a  TRY AGAIN";changeColor(15);
			getch();
			seatbook();
		}
		else{
			bookpage(ch);
		}		
	}
	
	bookpage(int no){
		heading();
		string flimname,showtime;
		int flimprice,seatavs,seatpck;
		flimlist flim;
		flimname=flim.name[no-1];
		showtime=flim.date[no-1];
		flimprice=flim.price[no-1];
		stringstream ss;
		ss<<no;
		string s,fbe,fen,ffs;
		ss>>s;
		fbe="releasinglist/";
		fen=".txt";
		ffs=fbe+s+fen;
		int noo,pck;
		noo=100;
		pck=0;
		ifstream finst;
		finst.open(ffs.c_str(),ios::in);
		while(!finst.eof()){
			finst>>noo;
			pck++;
		}
		if(noo==100)
			pck=0;
		seatpck=pck;
		seatavs=96-pck;
		finst.close();
		//flimname  showtime  flimprice    seatavs   seatpck
//////////////////////////////////////////////////////////////////////////////////////////////////////////
		users u;
		int userid;
		userid=u.idno;
		gotoxy(65,11);cout<<"USER: "<<u.name;
		gotoxy(65,12);cout<<"COIN: "<<u.coin;
		gotoxy(1,11);cout<<"MOVIE: "<<flimname;
		gotoxy(1,12);cout<<"SHOWTIME: "<<showtime;
		gotoxy(1,13);cout<<"SEAT RATE: Rs."<<flimprice;
		gotoxy(30,11);cout<<"BOOK FROM ";printEB();
		gotoxy(32,13);cout<<"SEAT REVIEW PAGE";
		gotoxy(55,14);changeColor(11);cout<<"[ 1]";cout<<": Seat Available";
		gotoxy(55,15);changeColor(12);cout<<"( 1)";cout<<": Seat Unavailable";
		gotoxy(0,16);changeColor(15);cout.fill('-');cout.width(80);cout<<"";
////////////////////////////////////////seat show/////////////////////////////////////////////////////////////
		int a,b,c,d,e[96];
		fbe="releasinglist/";
		fen=".txt";
		ffs=fbe+s+fen;
		ifstream finch;
		finch.open(ffs.c_str(),ios::in);
		for(d=1;d<=seatpck;d++){
			finch>>e[d];
		}
		finch.close();
		pck=0;
		gotoxy(0,17);
		for(a=0;a<=7;a++){
			for(b=1;b<=12;b++){
				c=a*12+b;
				for(d=1;d<=seatpck;d++){
					if(c==e[d])
						pck=1;
				}
				if(pck==1){
					changeColor(12);cout<<" (";cout.fill(' ');cout.width(2);cout<<c<<") ";
				}
				else{
					changeColor(11);cout<<" [";cout.fill(' ');cout.width(2);cout<<c<<"] ";
				}
				pck=0;		
			}
			cout<<"\n";
		}
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
		gotoxy(0,25);changeColor(15);cout.fill('-');cout.width(80);cout<<"";
		gotoxy(2,26);cout<<"1. Back To Home";
		gotoxy(2,27);cout<<"2. Buy Seat";
		gotoxy(2,28);cout<<"3. Exit";
		gotoxy(10,29);cout<<"Press Your Choice:";
		int cin4,stno,nforw;
		cin>>cin4;
		nforw=0;
		if(cin4==1)
			homeswitch();
		else if(cin4==2){
			gotoxy(50,26);cout<<"Give Seat No:";
			cin>>stno;
			for(d=1;d<=seatpck;d++){
					if(stno==e[d])
						nforw=1;
			}
			if((nforw==0)&&(stno>0)&&(stno<97)){
				if(u.coin>=flimprice){
					buyseat(stno,no,userid,flimprice,flimname,showtime);
					conform_slip(stno,no,userid,flimprice,u.name,flimname,showtime);
					bookpage(no);
				}else{
					gotoxy(50,27);changeColor(12);cout<<"UnSufficient Coin:\a\a ";
					getch();
					bookpage(no);
				}
			}else{
				gotoxy(50,27);changeColor(12);cout<<"Seat Not Available\a\a ";
				getch();
				bookpage(no);
			}
		}
		else if(cin4==3)
			exit();
		else{
			changeColor(12);cout<<"******Wrong Input*******\a\a";
			getch();
			bookpage(no);
		}
	}
	buyseat(int stno,int no,int userid,int flimprice,string flimname,string showtime){
		stringstream ss,sts;
		ss<<no;
		string s,ffs;
		ss>>s;
		ffs="releasinglist/"+s+".txt";
		fstream finst;
		finst.open(ffs.c_str(),ios::app);
		finst<<stno<<"\n";
		finst.close();
		//-------------------
		int stav;
		ffs="releasinglist/seat_available/"+s+".txt";
		ifstream fins;
		fins.open(ffs.c_str(),ios::in);
		fins>>stav;
		fins.close();
		stav--;
		ofstream fins1;
		fins1.open(ffs.c_str(),ios::out);
		fins1<<stav;
		fins1.close();
		//-------------------
		sts<<userid;
		string h,ff;
		sts>>h;
		ff="users_detail/"+h+".txt";
		fstream fin1;
		fin1.open(ff.c_str(),ios::app);
		fin1<<flimname<<"\n";
		fin1<<showtime<<"\n";
		fin1<<stno<<"\n";
		fin1.close();
		//---------------------
		ff="users_coin/"+h+".txt";
		int mn;
		ifstream coin;
		coin.open(ff.c_str(),ios::in);
		coin>>mn;
		coin.close();
		mn=mn-flimprice;
		ofstream coin1;
		coin1.open(ff.c_str(),ios::out);
		coin1<<mn;
		coin1.close();
	}
};
