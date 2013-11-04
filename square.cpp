#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
int sum,n,T;
int usd[22],a[22];
bool res;
void F(int cur, int S, int g){
	if (res) return;

	if ( g > 3|| S > sum){
		return ;
	}
	if (g == 3){
		res = true;
		return;
	}
	
	if ( S == sum ) {
		F(0, 0 ,g + 1);
	}

	for(int i = cur; i < n; i++){
		if (!usd[i]){
			usd[i] = true;
			F( cur,S+a[i], g);
			usd[i]= false;
		}	
	}


	
}

int main(){
	int runs;
	cin >> runs;
	while( runs--){
		memset(usd,0,sizeof usd);
		cin >> n;
		sum = 0;
		for(int i = 0;i < n; i++){
			cin >> a[i];
			sum+=a[i];
		}
		if (sum % 4){
			cout<<"no"<<endl;
		}else{
			sum /= 4;
			res = false;
			F(0,0,0);
			if (res) cout << "yes"<< endl;
			else cout <<"no"<<endl;
		}

	}
	return 0;
}
