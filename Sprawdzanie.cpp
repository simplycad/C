/*Program wczytuje 3 liczby i
� je�li pierwsza nie jest r�wna 1 to wypisuje *,
� je�li druga jest r�wna 3 to wypisuje #,
� je�li trzecia jest mniejsza od 7 to wypisuje +++.*/

# include <iostream>
using namespace std;

int main(){
	
	int a,b,c;
	cout<<"Podaj dowolne trzy liczby \n";
	cin>>a>>b>>c;
	cout<<endl;
	if (a!=1)	
		cout<<"*"<<endl;
	if (b==3)
		cout<<"#"<<endl;
	if (c<7)
		cout<<"+++"<<endl;
	cout<<"Dziekuje \n";
	
	return 0;
	}
