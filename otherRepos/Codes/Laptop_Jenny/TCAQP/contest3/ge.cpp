#include<bits/stdc++.h>

using namespace std;

int main(){
	srand(time(NULL));
	for(int i=0;i<10000;i++){
		cout<<rand()%(1000000000-2)+2<<endl;	
	}
}
