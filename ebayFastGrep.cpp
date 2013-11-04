#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <algorithm>

using namespace std;

int main(int nargs, char ** arg)
{
    ifstream fcin (arg[2]); 
    string pal = arg[1];
    
    string tmp;
    int r=1;
    bool found=false;
    while(fcin>>tmp){
        if(tmp.compare(pal)==0){
			found=true;
			break;                        
        }
        r++;                  
    }
    cout<<(found?r:0)<<endl;
    return 0;    
}
