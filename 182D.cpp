#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
#include<iostream>

using namespace std;

#define maxn 1000005
int next[maxn],len;
string S;
void makenext()
{    int i,j=0;

     for(next[1]=0,i=2;i<=len;i++)

     {    while(j&&S[j+1]!=S[i]) j=next[j];

          if(S[j+1]==S[i]) j++;

          next[i]=j;

     }

}

int div(string a){
	S ="$" + a ;
        len= a.size();
        for(int i=1;i<=len;i++) next[i]=0; 
	makenext();
	if(len%(len-next[len])!=0)  return 1; 
	return len/(len-next[len]);
}
#define All(x) x.begin(),x.end()
vector<string> Q[2];
void push( string a, int k){
	
	int da = div(a);
	if ( da % 2 ){
		Q[k].push_back(a.substr(0, a.size() / da));
		Q[k].push_back( a );
	}else{
		int prev = 0;
		for( int i = a.size()/da;  i <= a.size(); i *=2 ){
			Q[k].push_back( a.substr( 0, i ));
		}
	}

}

int main(){
	string a, b;
	cin >> a >> b;
	push(a,0);push(b,1);
	for( int i = 0; i < 2; i++){
		sort(All(Q[i]));
		Q[i].resize(unique( All(Q[i])) - Q[i].begin());
	}

	vector<string> v( Q[0].size() + Q[1].size());

	vector<string>::iterator it = set_intersection( All(Q[0]), All(Q[1]), v.begin());
		

	cout << int(it-v.begin()) << endl;

}
