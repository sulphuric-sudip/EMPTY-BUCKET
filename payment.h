payment(int id){
	system("cls");
	heading();
	gotoxy(4,15);
	cout<<"Please Press 6-Digit Coupen To Recharge Your Account::";
	gotoxy(15,16);changeColor(14);
	cout<<"::-Please Don't Press '";
	changeColor(12);cout<<"Enter";changeColor(14);cout<<"' Key, Auto Completion After 6-Digit";
	gotoxy(17,17);changeColor(10);
	int num,addcoin,crtcoin,newcoin,idno;
	idno=id;
	char input;
	num=0;
	for(int i=1;i<=6;i++){
		input=getch();
		cout<<input;
		stringstream ss;
		ss<<input;
		int nm;
		ss>>nm;
		num=num*10+nm;
	}
	changeColor(15);cout<<"\n\t\t\tPROCESSING";
	for(int i=0;i<3;i++){
		Sleep(500);
		cout<<".";
	}
	changeColor(15);
	num=num/100;
	num=num%100;
	if((num%6==0)&&(num/6!=0)){
		num=num/6;
		addcoin=50*num;

		stringstream ss;
		ss<<id;
		string h,ff;
		ss>>h;
		ff="users_coin/"+h+".txt";
		ifstream coin;
		coin.open(ff.c_str(),ios::in);
		coin>>crtcoin;
		coin.close();
		newcoin=crtcoin+addcoin;
		ofstream coin1;
		coin1.open(ff.c_str(),ios::out);
		coin1<<newcoin;
		coin1.close();
	
		changeColor(15);cout<<"\n\tRs."<<addcoin<<" is added to your wallet.Your new coin is RS."<<newcoin;
		cout<<".\nAdd More";changeColor(10);cout<<"(y/n)";
		input=getch();
		if(input=='y'){
			payment(idno);
		}
	}else{
		changeColor(12);cout<<"\nWrong pin\a\a";
		changeColor(15);cout<<"\nTry Again";changeColor(10);cout<<"(y/n)";
		input=getch();
		if(input=='y'){
			payment(idno);
		}
	}
}
