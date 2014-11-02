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
	string s;
	while(getline(cin,s)){
		int len = s.size();
		
		int p = 0;
		map<string,int> M;
		for(int ini = 0; ini < len; ini++){
			for(int fin = ini; fin < len; fin++){
				bool b = true;
				string pal = "";
				for(int k = ini; k <= fin; k++) pal+=s[k];
				if (!M[pal]){
					for(int i = ini, j = fin; i <= j ; i++,j--){
						if (s[i]!=s[j]){
							b = false;
							break;		
						}
					}
					if (b){
						M[pal]++;
						p++;
					}
				}
			} 
		}
		cout<<"The string '"<<s<<"' contains "<<p<<" palindromes."<<endl;
			
	}
	return 0;
}
