#include<iostream>
#include<string>
using namespace std;


int main(){
	int q;
	while(cin>>q && q){
		int n,m;
		cin>>n>>m;
		for(int i = 0; i < q; i++){
			int x,y;
			cin>>x>>y;
			x -= n;
			y -= m;
			if (x == 0 || y == 0){
				cout<<"divisa"<<endl;
			}else if (x < 0 && y < 0) {
				cout<<"SO"<<endl;
			}else if (x < 0 && y > 0){
				cout<<"NO"<<endl;
			}else if (x > 0 && y < 0){
				cout<<"SE"<<endl;			
			}else if (x > 0 && y > 0){
				cout<<"NE"<<endl;			
			}
		}
	}
	return 0;
}
