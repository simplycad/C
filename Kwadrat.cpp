//Program wczytuje bok kwadratu obliczaj¹c: pole, obwód i przek¹tn¹.

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main(){
	int bok, pole, obw;
	float przekatna;
	
	cout<<"Witaj! Program oblicza pole, obwod i przekatna kwadratu. Prosze podaj wymiar boku kwadratu: ";
	cin>>bok;
	pole=pow(bok,2);
	obw=bok*4;
	przekatna=bok*sqrt(2);
	
	cout<<"Pole kwadratu: "<<pole<<" Obwod kwadartu: "<<obw<<" Przekatna kwadratu: "<<przekatna<<endl;
	return 0;
}
