/* Program podaje sredni wzrost uczniow na podstawie podanych danych */
#include <iostream>;

using namespace std;

int main(){
	int ucz;
	int wzrost;
	float srednia=0;
	int wyzsi=0;
	cout<<"Podaj liczbe uczniow"<<endl;
	cin>>ucz;
	cout<<"Podaj wzrost uczniow"<<endl;
	
	for (int i=1; i<=ucz; i++){
		cin>>wzrost;
		srednia=(wzrost+srednia);
		if(wzrost>=180){
			wyzsi++;
		}
		
	}
	cout<<"Sredni wzrost uczniow: "<<srednia/ucz<<endl;
	cout<<"Uczniowie majacy wzrost 180 i wiecej: "<<wyzsi;
	
	return 0;
}
