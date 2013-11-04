#include <cstdlib>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
void imprime(vector <string> pal,int i,string p1){
    cout << i << endl;
    for (int j= 0; j < i; j++)
        cout << pal[j]<<endl;
    
}

bool compara(char a[], char b[]){
	int M[27] = {0};
	int len = strlen(a);
	int lenb = strlen(b);
	if (len !=lenb) return false;
	for(int i = 0; i < len; i++){
		M[a[i]-'A']++;
		M[b[i]-'A']--;
	}
	for(int i = 0; i < 27;i++) if (M[i]) return false;
	return true;	
}
int main(int numArg, char** arg) {
   
    //FILE *file = fopen(arg[1],"r");
     FILE *file1 = fopen(arg[2],"r");
	int n;
    vector <string> pal;
    string p,p1;
    char bus[1000],bus1[1000];
    int i = 0;
    map<string,bool> mapa;
	while(fscanf(file1,"%s",bus)!=-1)
        {
            //bus = pal a biuscar
            p1 = string (bus);
            i = 0;
            //sort(bus,bus + strlen(bus));
            FILE *file = fopen(arg[1],"r");
            while(fscanf(file,"%s",bus1)!=-1)
            {
                p =string (bus1);
                //sort(bus1,bus1 + strlen(bus1));
                if (mapa[p]==false){
		            if (compara(bus,bus1)==true){
		                pal.push_back(p);
		                mapa[p]=true;
		                i++;
		            }
                }
            }
            //termina y ordeno
            sort(pal.begin(),pal.begin()+i);
            imprime(pal,i,p1);
            pal.clear();
            fclose(file);
	}

    return 0;
}

