#include<iostream>
#include <algorithm>
using namespace std;

char A[15];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>A[i];
	}	
	sort(A,A+n);
	do{
		for(int i=0;i<n;++i){
			cout<<" "<<A[i];
		}
		cout<<endl;
		
	}while(next_permutation(A,A+n));
}
