#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<list>
#include<set>
#include<map>
#include<climits>
#define ff(i,a,b) for (int i=a;i<b;i++)
#define ffd(i,a,b) for (int i=a;i>=b;i--)
#define f(i,n) ff(i,0,n)
#define In(i,a,b) (i>=a && i<=b)
#define offset 200
#define ll long long int
using namespace std;
char linea[2010];
int dp[2010][2010],dp_l[2010],dp_r[2010];
bool is_palindrome(int left,int right){
    if (left>=right) return 1;
    int &res=dp[left][right];
    if (res!=-1)return res;    
    return is_palindrome(left+1,right-1)&&linea[left]==linea[right];

}
int main(){
int cont=0;
memset(dp,-1,sizeof(dp));
memset(dp_l,0,sizeof(dp_l));
memset(dp_r,0,sizeof(dp_r));


gets(linea);
int len=strlen(linea),tmp=0;
f(i,len){
    ff(j,i,len){
        tmp=is_palindrome(i,j);
        cont+=tmp;
        dp_l[j]+=tmp;
        dp_r[i]+=tmp;
    }
}
ll total=0;
ff(i,1,len){
    dp_r[len-i-1]+=dp_r[len-i];
}
f(i,len-1){
    total+=dp_l[i]*dp_r[i+1];

}
cout<<total<<endl;

return 0;}

