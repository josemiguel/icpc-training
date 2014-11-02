#include<iostream>
using namespace std;
int main(){
	int n;
	while( cin >> n  && n ){
		long long cagao = 0;
		for(int i = 0; i < n; i++){
			long long t;
			cin >> t;
			cagao ^= t;
		}
		if (cagao == 0){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
		}
	}

	return 0;
}
