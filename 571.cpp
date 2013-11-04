#include<cstdio>
int Ca, Cb, N;
void F(){
    int i, j, k, a, b;
    a = b = 0;
	while( true ){
        if(b == N){
            printf("success\n");
            break;
        }
        else if(b == Cb){
            printf("empty B\n");
            b = 0;
        }
        if(!a){
            printf("fill A\n");
            a = Ca;
        }
        
        printf("pour A B\n");
        
        if(a + b > Cb){
            a = a + b - Cb;
            b = Cb;
        }
        else{
            b += a;
            a = 0;
        }
    }
}
int main(){
    while(scanf("%d%d%d", &Ca, &Cb, &N) != -1){
        F();
    }
    return 0;
}
