/*Program wczytuje od u¿ytkownika znak. Nastêpnie u¿ytkownik próbuje zgadn¹æ
jaki jest jego kod ASCII. Program podpowiada, czy kod jest wiêkszy, czy mniejszy.
Program mówi u¿ytkownikowi za którym razem uda³o mu siê zgadn¹æ*/

# include <iostream>
# include <windows.h>
using namespace std;

int main (){
int kod=1, t=0, f=0,s;
char znak;

cout<<"Witaj Wpisz dowolny znak z klawiatury"<<endl;
	cin>>znak;
	system("cls");
	while(!(kod==znak)){
		cout<<"Witaj podaj przewidywany kod ASCI znaku"<<endl;
		cin>>kod;
		if (kod>znak)
		{
			cout<<"Niestety nie odgadles kodu, sprobuj jeszcze raz!"<<endl;
			cout<<"Podpowiedz - liczba mniejsza"<<endl;
			Sleep(1000);
			system("cls");
			t++;
		}
		else if (kod<znak)
		{
			cout<<"Niestety nie odgadles kodu, sprobuj jeszcze raz!"<<endl;
			cout<<"Podpowiedz - wieksza"<<endl;
			Sleep(1000);
			system("cls");
			f++;
		}
		else {
			s=f+t;
		cout<<"Odgadles kod za: "<<s<<" razem"<<endl;
		cout<<"Podales "<<f<<" mniejszych oraz "<<t<<" wiekszych liczb"<<endl;
	
		}
	}
	return 0;
}
	
	

