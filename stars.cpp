//#pragma comment(linker,"/STACK:256000000")
#include<iostream>
#include<cstdio>
#include <stdio.h>
using namespace std;
 
int n;
long long fenwick[140][140][140];
inline void update(int x,int y,int z,int by){

  for(int xx = x; xx <= n; xx += xx &- xx)
    for(int yy = y; yy <= n; yy += yy &- yy)
      for(int zz = z; zz <= n; zz += zz&- zz)
         fenwick[xx][yy][zz]+=by;
}

inline long long sum(int x,int y,int z){
 long long r=0;
 for(int xx = x; xx > 0; xx -= xx &- xx)
    for(int yy = y; yy >0 ; yy -= yy &- yy)
      for(int zz = z; zz >0 ; zz -= zz&- zz)
           r+=fenwick[xx][yy][zz];  
 return r;
} 

 int main(){
    
    freopen ("stars.in","r",stdin);
    freopen ("stars.out","w",stdout);
    scanf("%d",&n);
    int q,x,y,z,k,x1,x2,y1,y2,z1,z2;
    long long r;
    while(scanf("%d",&q) && q!=3){
         if(q==1){
            scanf("%d %d %d %d",&x,&y,&z,&k);
            update(x+1,y+1,z+1,k);
         }
         else{
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            r=0;
            x1++;y1++;x2++;y2++;z1++;z2++;
            //consulta en 3D
            r=(sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)+sum(x1-1,y1-1,z2)-(sum(x2,y2,z1-1)-sum(x1-1,y2,z1-1)-sum(x2,y1-1,z1-1)+sum(x1-1,y1-1,z1-1)));
            cout<<r<<'\n';
         }
    }        
 }
