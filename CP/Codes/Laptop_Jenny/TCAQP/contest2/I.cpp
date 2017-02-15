#include<bits/stdc++.h>
using namespace std;

string cad;
int sz;
string res;

void back(int pos){
	if(pos==sz){
		cout<<res<<endl;
		return;
	}
	string aux=res;
	for(int i=0;i<=pos;++i){
		if(i==0){
			res="";
			res+=cad[pos];
			res+=aux;
			back(pos+1);
			res=aux;
		}
		else {
			if(i==pos){
				res=aux;
				res+=cad[pos];
				back(pos+1);
				res=aux;
			}
			else{
				res=aux.substr(0,i);
				res+=cad[pos];
				res+=aux.substr(i);
				back(pos+1);
				res=aux;
			}
		}
	}
}



int main(){
	int tc=0;
	while(cin>>cad){
		tc++;
		if(tc>1)puts("");
		sz=cad.size();
		res="";
		res+=cad[0];
		back(1);
	}
}
