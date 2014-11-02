#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
using namespace std;


int f[1005],dp[10005];

struct pal{
	char *s;int sz,dp;
	pal(){ s = new char[1005];}
	bool operator <(const pal &a) const{
		return sz<a.sz;
	}
}dic[10005];

bool kmp(char p[],int n, char t[], int m){
	for(int i = 1, j = f[0] = -1; i <= n; f[i]=++j,i++) while(j>=0 && p[j] != p[i-1]) j = f[j];
	for(int i = 0,j = 0; i < m; i++) {
		while(t[i]!=p[j] && j >= 0) j=f[j];
		if (++j>=n) return true;
	}
	return false;
}

int main(){
	int n;
    while(scanf("%d",&n) && n){
	    for(int i = 0; i < n; i++) scanf("%s",dic[i].s),dic[i].sz = strlen(dic[i].s),dic[i].dp = 1;
    	sort(dic,dic+n);
    	int res = 1;
	    for(int i = 0; i < n; i++){
	    	for(int j = i+1; j < n; j++){
	    		if (dic[i].sz > dic[j].sz || dic[j].dp >= dic[i].dp+1) continue;
	    		if (kmp(dic[i].s,dic[i].sz,dic[j].s,dic[j].sz)) {
	    			dic[j].dp =  dic[i].dp + 1;;
	    		}
	    	}
	    	res = res > dic[i].dp ? res : dic[i].dp;
	    }
	    
		printf("%d\n",res);
    }
	return 0;
}

