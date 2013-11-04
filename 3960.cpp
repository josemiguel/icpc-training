#include<iostream>
#include<map>
using namespace std;
map<string,int> h;
int f[5][5];
void pre(){
	h["Kamen"] = 1;
	h["Rock"] = 1;
	h["Pierre"] = 1;
	h["Stein"] = 1;
	h["Ko"] = 1;
	h["Koe"] = 1;
	h["Sasso"] = 1;
	h["Roccia"] = 1;
	h["Guu"] = 1;
	h["Kamien"] = 1;
	h["Piedra"] = 1;

	h["Nuzky"] = 2;
	h["Scissors"] = 2;
	h["Ciseaux"] = 2;
	h["Schere"] = 2;
	h["Ollo"] = 2;
	h["Olloo"] = 2;
	h["Forbice"] = 2;
	h["Choki"] = 2;
	h["Nozyce"] = 2;
	h["Tijera"] = 2;

	h["Papir"] = 3;
	h["Paper"] = 3;
	h["Feuille"] = 3;
	h["Papier"] = 3;
	h["Papir"] = 3;
	h["Carta"] = 3;
	h["Rete"] = 3;
	h["Paa"] = 3;
	h["Papier"] = 3;
	h["Papel"] = 3;

	f[1][1] = f[2][2] = f[3][3] = 0;
	f[1][2] = f[2][3] = f[3][1] = 10;
	f[2][1] = f[3][2] = f[1][3] = -10;
	
}
#include<cstdio>
int main(){
	pre();
	bool sale = true;
	int r = 1;
	string a,b,tmp;
	while(sale){
		cin >> tmp >> a;
		cin >> tmp >> b;
		int winA = 0, winB = 0;
		string ja,jb;
		while(cin >> ja && ja != "-"){
			if (ja == ".") {sale = false; break;}
			cin >> jb;
			int res = f[h[ja]][h[jb]];
			if (res > 0) winA++;
			else if (res < 0 ) winB++;
		}

		printf("Game #%d:\n",r++);

		string sa = winA != 1 ? "s" : "";
		string sb = winB != 1 ? "s" : "";

		cout << a << ": " << winA << " point" << sa << endl;
		cout << b << ": " << winB << " point" << sb << endl;

		if (winA == winB) cout<<"TIED GAME"<<endl;
		else{
			cout<<"WINNER: ";
			if ( winA > winB ){
				cout<<a<<endl;
			}else {
				cout<<b<<endl;
			}
		
		}
		cout<<endl;

	}
}
