void changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void welcome_anim(){
	cout<<"    E\n";Sleep(400);
	cout<<"  B   M\n";Sleep(400);
	cout<<"U       P\n\n";Sleep(400);
	cout<<"C       T\n";Sleep(400);
	cout<<" K     Y\n";Sleep(400);
	cout<<"   E T\n\n";Sleep(1000);
	system("cls");
	
	cout<<"    M\n";
	cout<<"  E   P\n";
	cout<<"B       T\n\n";
	cout<<"U       Y\n";
	cout<<" C     T\n";
	cout<<"   K E\n\n";Sleep(1000);
	system("cls");
	
	cout<<"    P\n";
	cout<<"  M   T\n";
	cout<<"E       Y\n\n";
	cout<<"B       T\n";
	cout<<" U     E\n";
	cout<<"   C K\n\n";Sleep(1000);
	system("cls");
	
	changeColor(12);
	cout<<"    P\n";
	cout<<"  M   T\n";
	cout<<"E       Y\n\n";
	cout<<"B       T\n";
	cout<<" U     E\n";
	cout<<"   C K\n\n";Sleep(1000);
	system("cls");
	
	changeColor(9);
	cout<<"    P\n";
	cout<<"  M   T\n";
	cout<<"E       Y\n\n";
	cout<<"B       T\n";
	cout<<" U     E\n";
	cout<<"   C K\n\n";Sleep(1000);
	system("cls");
	
	changeColor(14);
	cout<<"    P\n";
	cout<<"  M   T\n";
	cout<<"E       Y\n\n";
	cout<<"B       T\n";
	cout<<" U     E\n";
	cout<<"   C K\n\n";Sleep(1000);
	system("cls");
	
	changeColor(13);cout<<"    P\n";
	changeColor(10);cout<<"  M";		changeColor(11);cout<<"   T\n";
	changeColor(12);cout<<"E";			changeColor(14);cout<<"       Y\n\n";
	changeColor(9);cout<<"B";			changeColor(13);cout<<"       T\n";
	changeColor(14);cout<<" U";			changeColor(9);cout<<"     E\n";
	changeColor(12);cout<<"   C";		changeColor(10);cout<<" K\n";	
	Sleep(1000);
	system("cls");
	//last and final
	cout<<"\n";
	changeColor(47);
	cout.fill('=');
	cout.width(80);
	cout<<"=";
	gotoxy(0,10);
	cout.fill('=');
	cout.width(80);
	cout<<"=";
	
	Sleep(500);
	gotoxy(29,5);changeColor(15);cout<<"-------------";
	Sleep(800);
	
	gotoxy(35,2);changeColor(13);cout<<"P";
	gotoxy(33,3);changeColor(10);cout<<"M";	 		gotoxy(37,3);changeColor(11);cout<<"T";
	gotoxy(31,4);changeColor(12);cout<<"E";			gotoxy(39,4);changeColor(14);cout<<"Y";
	
	gotoxy(31,6);changeColor(9);cout<<"B";			gotoxy(39,6);changeColor(13);cout<<"T";
	gotoxy(32,7);changeColor(14);cout<<"U";			gotoxy(38,7);changeColor(9);cout<<"E";
	gotoxy(34,8);changeColor(12);cout<<"C";			gotoxy(36,8);changeColor(10);cout<<"K";	
	Sleep(700);
	gotoxy(38,9);changeColor(249);cout<<" A COMPLETE DIGITAL SEAT BOOKING SYSTEM \n\n";
	Sleep(400);
	changeColor(15);
}

void heading(){
	system("cls");
	gotoxy(0,1);
	changeColor(47);cout.fill('=');cout.width(80);cout<<"=";

	gotoxy(35,2);changeColor(13);cout<<"P";
	gotoxy(33,3);changeColor(10);cout<<"M";	 		gotoxy(37,3);changeColor(11);cout<<"T";
	gotoxy(31,4);changeColor(12);cout<<"E";			gotoxy(39,4);changeColor(14);cout<<"Y";
	gotoxy(29,5);changeColor(15);cout<<"-------------";
	gotoxy(31,6);changeColor(9);cout<<"B";			gotoxy(39,6);changeColor(13);cout<<"T";
	gotoxy(32,7);changeColor(14);cout<<"U";			gotoxy(38,7);changeColor(9);cout<<"E";
	gotoxy(34,8);changeColor(12);cout<<"C";			gotoxy(36,8);changeColor(10);cout<<"K";	
	
	gotoxy(38,9);changeColor(249);cout<<" A COMPLETE DIGITAL SEAT BOOKING SYSTEM ";
	gotoxy(0,10);changeColor(47);
	cout.fill('=');cout.width(80);cout<<"=";
	changeColor(15);
}

void printEB(){
	changeColor(15);cout<<"EMPTY";changeColor(496);cout<<"BUCKET";changeColor(15);
}
