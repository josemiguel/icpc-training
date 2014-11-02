#include<iostream>
#include<string>
using namespace std ;

int main(){
	string p,t;
	cin >> p >> t;
	int sz = 0, id = 0;
	for( int i = 0; i < p.size(); i++){
		int j = 0,k = 0;
		int id_tmp = -1;
		if ( p[i] == t[j] ) id_tmp = i;
		while( p[i] == t[j] && j < t.size() && i < p.size()){
			j++;
			i++;
			k++;
		}
		if ( id_tmp == -1 ) continue;
		if ( k > sz ){
			sz = k;
			id = id_tmp;
		}
	}

	cout << t.size() - sz << endl;


	

	return 0;
}



