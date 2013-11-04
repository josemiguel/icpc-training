#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main(){
	string a;
	while(getline(cin,a) && a!="0"){
		int tt = 0,aa,bb;
		map<int,int> M;
		int chain = 0;
		cout<<"Original number was "<<a<<endl;
		while(M[tt]!=2){
			int len = a.size();
			sort(a.begin(),a.end());
			string b = a;
			reverse(b.begin(),b.end());
			istringstream is1(a),is2(b);
			is1>>aa; is2>>bb;
			tt = bb-aa;
			printf("%d - %d = %d\n",bb,aa,tt);
			ostringstream os;
			os<<tt;
			a = os.str();

			M[tt]++;
			chain++;
		}
		cout<<"Chain length "<<chain<<endl<<endl;
	}
	return 0;
}
