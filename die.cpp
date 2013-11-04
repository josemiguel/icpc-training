#include <iostream>
#include <string>

using namespace std;
int main ()
{
    int N, E, W, S, bot, top;
    int n;
    while (cin >> n && n){
        top = 1; bot = 6; N = 2;  S = 5;  W =  3; E = 4;
		for(int i = 0; i < n; i++){
        	string s;
			cin >> s;
	        int tmp;			
            switch (s[0]){
                case 'n':
                    tmp = N;
                    N = top;
                    
                    top = S;
                    S = bot;
                    
                    bot = tmp;
                break;
                case 's':
                    tmp = S;
                    S = top;
                    
                    top = N;
                    N = bot;
                    
                    bot = tmp;
                break;
                case 'e':
                    tmp = E;
                    E = top;
                    
                    top = W;
                    W = bot;
                    
                    bot = tmp;
                break;
                case 'w':
                    tmp = W;
                    
                    W = top;
                    top = E;
                    
                    E = bot;
                    bot = tmp;
                break;
            }
        }
		cout << top << endl;


    }
    return 0;
}
