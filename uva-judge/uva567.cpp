#include <iostream>

#define M 9999

using namespace std;

int g[21][21];

void FW()
{
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= 20; j++)
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
}

int main()
{
    int counter = 0, n;
   
    while(cin >> n)
    {
        for(int i = 1; i <= 20; i++)
            for(int j = 1; j <= 20; j++)
                g[i][j] = M;
       
        for(int i = 0, t; i < n; i++)
        {
            cin >> t;
            g[1][t] = g[t][1] = 1;
        }
       
        for(int j = 2; j < 20; j++)
        {
            cin >> n;
           
            for(int i = 0, t; i < n; i++)
            {
                cin >> t;
                g[j][t] = g[t][j] = 1;
            }
        }
       
        FW();
       
        cout << "Test Set #" << ++counter << endl;
        cin >> n;
       
        for(int i = 0, p, q; i < n; i++)
        {
            cin >> p >> q;
            cout <<  p << " to "<< q << ": " << g[p][q] << endl;
        }
       
        cout << endl;
    }
   
    return 0;
}
