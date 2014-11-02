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
	int n,r;
	cin>>r;
	while(r--){
		cin>>n;
		map<unsigned char,int> mp;
		while(n--){
			unsigned char c;
			int v;
			cin>>c>>v;
			mp[c] = v;
		}
		int l;
		cin>>l;
		cin.ignore();
		long long cost = 0;
		while(l--){
			string linea;
			getline(cin,linea);
			int len = linea.size();
			for(int i = 0;i < len; i++) cost+=mp[linea[i]];
		}
		long long dol = cost / 100;
        long long cent = cost % 100;
	    cout << dol << "." << (cent < 10 ? "0": "") << cent << "$" << endl; 
	}
	return 0;
}
