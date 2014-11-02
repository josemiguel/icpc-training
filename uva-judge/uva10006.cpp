#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
typedef long long ll;
int pre[] ={561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361};

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	int N = 16;
	while(cin>>n && n){
		if (binary_search(pre,pre+N,n)) cout<<"The number "<<n<<" is a Carmichael number."<<endl;
		else cout<<n<<" is normal."<<endl;
		
	}
	return 0;
}
