/* Program w p�tli wczytuje liczby i je�li s� parzyste sumuje je. Program ko�czy
dzia�anie, gdy suma przekroczy 50 lub dodane zostanie 10 liczb.*/

# include <iostream>

using namespace std;

int main(){
	
	int a,b,e,k=0;
	
	do{
		cout<<e<<endl;
	cout<<"Podaj liczbe"<<endl;
	cin>>a>>b;
	if(a%2==0 && b%2==0)
	
	e=e+a+b;
	k++;

	}
	while(e<50 && k<10);
	cout<<"Suma: "<<e<<" ilosc petli: "<<k<<endl;
	
	return 0;
}
