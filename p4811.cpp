#include<algorithm>
#include <cstring>
#include <cstdio>
#define MAXNP 1002
using namespace std;

int fail[MAXNP];
char p[10002][1002]; 
bool usd[10002];
int d[10002]; 
int g[10002][10002];
int len[10002];

void buildFail(char *p)
{
      int m=strlen(p);
      int j=fail[0]=-1;
      for(int i=1; i<=m; i++)
      {
          while(j>=0 && p[j]!=p[i-1]) j=fail[j];
          fail[i]=++j;        
      }     
}
 

bool kmp(char *p,char *t)
{
      int m=strlen(p), n=strlen(t);
      buildFail(p);
      for(int i=0,k=0; i<n; i++)
      {
          while(k>=0 && p[k]!=t[i]) k=fail[k];
          if(++k>=m)
          {
               return true;
          }        
      }  
      return false;         
}
 


void dfs(int u, int w, int n){
	d[u] = w;
	printf("%d\n",w);
	usd[u] = true;
	for(int v = 0;v < n;v++){
		if (g[u][v]){
			printf("w = %d, g[u][v] = %d \n", w, g[u][v]);
			if (!usd[v]){
				printf("w = %d, g[u][v] = %d \n", w, g[u][v]);
				dfs(u,w+g[u][v],n);
			}
		}
	}
}
  
 int main()
 {   
     int n;
     int q;
     while(scanf("%d",&n) && n){
		for(int i=0;i<n;i++){
			scanf("%s",p[i]);
			len[i] = strlen(p[i]);
			d[i] = 0;
			memset(g[i],0,sizeof(g[i]));
			usd[i] = false;
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if (i == j) continue;
				if (len[i] < len[j]){
					g[i][j] = kmp(p[i],p[j]);
				}else{
					g[i][j] = 0;
				}
			}
		}
		int b = -1;
		for(int i = 0;i<n;i++){
			//printf("%d\n",d[i]);			
			b = max(b,d[i]);
		}
		printf("%d\n",b);
     }        
     return 0;
 }

