#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<numeric>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define mp make_pair 
#define All(v) v.begin(),v.end()
#define pq priority_queue

#define INF 1<<30
#define to first
#define we second

/*typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef greater<pair<int,int> > gpii;
*/

int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		int d;
		cin>>s>>d;
		for(int i = 0; i < s.size(); i++){
			cout<<(char)( (s[i]+d) % 'z' + (s[i]+d>'z')*('a'-1));
		}
		cout<<endl;
	}
	
	return 0;
}
