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
#define MAX 55
int n,m;
char g[MAX][MAX];

bool busca(string s, int x, int y, int r){
	if (r == 0){
		int i,j;
		for(i = x, j = 0; j < s.size() && i < n && s[j] == g[i][y] ; i++, j++);
		if (j == s.size()) return true;
	}else if (r == 1){
		int i,j;
		for(i = x, j = 0; j < s.size() && i >= 0 && s[j] == g[i][y] ; i--, j++);
		if (j == s.size()) return true;
	}else if (r == 2){
		int i,j;
		for(i = y, j = 0; j < s.size() && i < m && s[j] == g[x][i] ; i++, j++);
		if (j == s.size()) return true;
	}else if (r == 3){
		int i,j;
		for(i = y, j = 0; j < s.size() && i >= 0 && s[j] == g[x][i] ; i--, j++);
		if (j == s.size()) return true;
	}else if (r == 4){
		int i,j,k;
		for(i = x , j = y, k = 0; i < n && j < m && g[i][j] == s[k]; i++, j++,k++);
		if (k == s.size()) return true;
	}else if (r == 5){
		int i,j,k;
		for(i = x , j = y, k = 0; i >= 0 && j < m && g[i][j] == s[k]; i--, j++,k++);
		if (k == s.size()) return true;
	}else if (r == 6){
		int i,j,k;
		for(i = x , j = y, k = 0; i < n && j >= 0 && g[i][j] == s[k]; i++, j--,k++);
		if (k == s.size()) return true;
	}else if (r == 7){
		int i,j,k;
		for(i = x , j = y, k = 0; i >= 0 && j >= 0 && g[i][j] == s[k]; i--, j--,k++);
		if (k == s.size()) return true;
	}
	
	return false;
}

int main(){
	int runs;
	scanf("%d",&runs);
	
	for(int r = 1 ; r <= runs ; r++){
		if (r>1) cout<<endl;
		scanf("%d%d",&n,&m);
		cin.ignore();
		for(int i = 0 ; i < n ;i++){
			for(int j = 0; j < m; j++){
				g[i][j] = tolower(getchar());
			}
			getchar();
		}
		int q;
		scanf("%d",&q);
		while(q--){
			string s;
			cin>>s;
			for(int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					for(int K = 0; K < 8; K++){
						if (busca(s,i,j,K)) { cout<<i+1<<" "<<1+j<<endl; goto sale; }
					}
				}
			}
			sale: ;
		}
	}
	
	return 0;
}
