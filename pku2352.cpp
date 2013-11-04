#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct p{
	int x, int y, int id;
	p(){}
	p(int x, int y, int id) : x(x), y(y) , id(id){}
	operator < (const &p a){
		if ( x == a.x ){
			if ( y == a.y ){
				return id < a.id;
			}
			return y < a.y;
		}
		return x < a.x;
	}
};

int main(){
	cin >> n;
	vector<p> v(n);
	for(int i = 0; i < n; i++){
		int x,y;
		cin>>x>>y;
		v[i] = p(x,y,i);
	}
	sort(v.begin(),v.end());


	for(int i = 0; i <= n-1; i++){
		
	}
	
	

	return 0;
}
