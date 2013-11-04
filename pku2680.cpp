#include <stdio.h>

int main(){
    short a[1024][400];
    int i,j,c,n,f,an[1002];
    a[0][0]=0;an[0]=1;
    a[1][0]=0;an[1]=1;
    for(i=2;i<=1001;i++){
        j=c=0;
        while(j<an[i-1] || c){
            a[i][j]=a[i-1][j]*2+c;
            c=a[i][j]/10;
            a[i][j]%=10;
            j++;
        }
        an[i]=j;
        c=1;j=0;
        if(i&1){
            while(c){
                a[i][j]--;
                if(a[i][j]<0){
                    c=1;
                    a[i][j]+=10;
                }else c=0;
                j++;
            }
            if(!a[i][an[i]-1])an[i]--;
        }else{
            while(c){
                if(j==an[i]){
                    a[i][j]=0;
                    an[i]++;
                }
                a[i][j]++;
                if(a[i][j]>=10){
                    c=1;
                    a[i][j]-=10;
                }else c=0;
                j++;
            }
        }
    }
    while(scanf("%d",&n)!=EOF){
        f=0;
        for(i=an[n]-1;i>=0;i--){
            if(a[n][i] || n<2)f=1;
            if(f)putchar(a[n][i]+48);
        }
        putchar('\n');
    }
    return 0;
}

