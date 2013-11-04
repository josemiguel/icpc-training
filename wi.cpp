#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct p{
	int x,y;
	p(int x,int y) : x(x), y(y) {}
	int operator %(p t){return x*t.y-y*t.x;}
};

void print(p a){
	cout<<a.x<<" "<<a.y<<endl;
}


bool nice(p a, p b, p c, p d){

	int area = a%b + b%c + c%d + d%a;

        return area % 2 ? false : true;
}
			    


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<p> A,B,C,D;
		for(int i = 0; i < n; i++){
			int x,y;
			cin>>x>>y;
			if (x > 0 && y > 0) A.push_back(p(x,y));		
			if (x > 0 && y < 0) B.push_back(p(x,y));		
			if (x < 0 && y < 0) C.push_back(p(x,y));		
			if (x < 0 && y > 0) D.push_back(p(x,y));		
		}
		int res = 0, it = 0;
		for(int i = 0; i < A.size(); i++){
			for(int j = 0; j < B.size(); j++){
				for(int k = 0; k < C.size(); k++){
					for(int l = 0; l < D.size(); l++){
						p a = A[i], b = B[j], c = C[k], d = D[l];
						it++;
						if (nice(a,b,c,d)) res++;
						
					}
				}
			}
		}
		printf("%d\n",res); 
	}
	return 0;
}
