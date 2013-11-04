#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
	int a[] = {8,4,23,4,1,2,3,5,6};
	
	sort(a,a+9);
	
		cout<<"arreglo : "<<endl;
	for(int i = 0; i < 9; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;	
	
	
	vector<int> b; 
	b.push_back(1);
	b.push_back(9);
	b.push_back(6);
	b.push_back(2);
	b.push_back(8);
	
	sort(b.begin(),b.end());
	
	cout<<"vector(int) : "<<endl;
	for(int i = 0; i < b.size(); i++){
		cout<<b[i]<<" ";
	}
	cout<<endl<<endl;	

	string c;
	
	c = "abn91naca01nal29csz10...%#";
	
	sort(c.begin(),c.end());
	
	cout<<"string : "<<endl;
	for(int i = 0; i < c.size(); i++){
		cout<<c[i]<<" ";
	}
	cout<<endl<<endl;		


	vector<string> d; 
	d.push_back("bcdz");
	d.push_back("abbcde");	
	d.push_back("bdzc");
	d.push_back("abcde");
	d.push_back("zxzas");
	
	sort(d.begin(),d.end());
	
	cout<<"vector(string) : "<<endl;
	for(int i = 0; i < d.size(); i++){
		cout<<d[i]<<" ";
	}
	cout<<endl<<endl;	

	
}
