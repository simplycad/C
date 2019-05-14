/*Program podaje wpisana cyfre w postaci tekstowej*/
#include <iostream>
#include <math.h>
using namespace std; 

const string mld[]={"miliard","miliardy","miliardow"};
const string mln[]={"milion","miliony","milionw"};
const string tsc[]={"tysiac","tysiace","tysiecy"};
const string s[]={"sto","scie","sta","set"};
const string d[]={"dziesiat","dziescia","dziesci","dziesiat"};
const string j[]={"zero","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};

// Ta funkcja zwraca dan¹ cyfrê z liczby w celu przypisania jej cyfr do tablicy 
long long cyfra(long long l, double c){
		//Wyci¹gamy cyfrê o indeksie c z danej liczby l
	long long tymcz=l/pow(10,c);
	return tymcz%10;
}
/* Ta funkcja tworzy tablice 12 elem w kazdym miejscu konkretna cyfra z danej liczby. Ka¿da z cyfr jest 
teraz traktowana osobna*/
long long *liczbaNaTab(long long l, long long* zwrot){
	for(int i=0;i<12;i++)
	{
		zwrot[i]=cyfra(l,i);
	}
	return zwrot;
}

const int JEDNOSCI=0;
const int TYSIACE=1;
const int MILIONY=2;
const int MILIARDY=3;

string czesciDoStu(const long long lTab[], int czesc)
{
	int indeks=3*czesc;
	string tekst=""; // 
	//setki
	switch(lTab[indeks+2])
	{
		case 0:
		break;
		case 1:
			tekst+=s[0];
		break;
		case 2:
			tekst+="dwie"+s[1];
		break;
		case 3:
		case 4:
			tekst+=j[lTab[indeks+2]]+s[2];
		break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			tekst+=j[lTab[indeks+2]]+s[3];
		break;
	}	
	//dziesiatki
	switch(lTab[indeks+1])
	{
		case 0:
		break;
		case 1:
			if(!lTab[indeks==0])
				tekst+=" "+d[0];
			else
			{
				switch(lTab[indeks])
				{
					case 2:
					case 3:
					case 7:
					case 8:
						tekst+=" "+j[lTab[indeks]];
					break;
					case 5:
					case 9:
						tekst+=" "+j[lTab[indeks]];
						tekst.erase(tekst.length()-1,1);
						tekst+="t";
					break;
					case 1:
					case 4:
						tekst+=" "+j[lTab[indeks]];
						tekst.erase(tekst.length()-1,1);					
					break;
				}
				tekst+="nascie";
			}
		break;
		case 2:
			tekst+=" "+j[2]+d[1];
		break;
		case 3:
		case 4:
			tekst+=" "+((lTab[indeks+1]!=4)?j[lTab[indeks+1]]:"czter")+d[2];
			/*
			tekst+=" ";
			if (j[lTab[indeks+1]])
				tekst+=j[lTab[indeks+1]];
			else
				tekst+="czter"
			tekst+=d[2];
			
			*/
		break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			tekst+=" "+j[lTab[indeks+1]]+d[3];
		break;
	}
	//jednosci
	if(lTab[indeks+1]!=1&&((lTab[indeks]==0&&lTab[indeks+1]==0&&lTab[indeks+2]==0)||lTab[indeks]!=0))
			tekst+=" "+j[lTab[indeks]];
	return tekst;
}
//  czêœæ jednoœci, tys, mln etc - linijka 28 
long long liczbaZTrojki(long long lTab[],int czesc)
{
	int indeks=3*czesc;
	long long trojka=0;
	trojka+=lTab[indeks+2];
	trojka=trojka*10+lTab[indeks+1]; // do której cyfry z tablicy sie odwolac
	trojka=trojka*10+lTab[indeks];	// system dziesietny 
	return trojka; // zwraca liczbe 3 cyfrowa 
}

string liczNaTekst(long long l)
{
	long long *lTab=new long long[12];
	lTab=liczbaNaTab(l, lTab);
	string lTekst="";
	for (int i=3;i>=0;i--)
	{
		int trojka=liczbaZTrojki(lTab,i);
		if(trojka>0) //bo nie mowi siê zero mld itd.
		{
			lTekst+=czesciDoStu(lTab,i);	
			switch(i)
			{
				case MILIARDY: // wyciaganie konkretnych s³ówc
					lTekst+=" mld ";
				break;
				case MILIONY:
					lTekst+=" mln ";
				break;
				case TYSIACE:
					lTekst+=" tys ";
				break;
				case JEDNOSCI:
				break;
			}
		}
	}
	return lTekst;
}

int main(){
	
	cout<<"Podaj liczbe, maksymalnie dwunastocyfrowa"<<endl;
	long long liczba;
	cin>>liczba;
	cout<<liczNaTekst(liczba);
	
	return 0;
}
