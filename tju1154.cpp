#include<cstdio>

int main(){

  int r = 0;
  while(1){
  	int n,m;
    scanf("%d%d",&n,&m);
    if(n == 0 && m == 0) break;
    int res=0;
    for(int a=1;a<n;a++)
    {
      for(int b=1;b<n;b++)
      {
        if(((a*a+b*b+m)%(a*b))==0)
        {
         ++res;
         if(a==b) res--;

        }
      }
    }

    printf("Case %d: %d\n",++r,res/2);
  }

return 0;
}
