#include <bits/stdc++.h>
#define N 10000
#define ll long long
using namespace std;

string A[N+5];
ll R[20000000],POT[26];

int main(){
	POT[0]=1;
	for(int i=1;i<=25;++i){
		POT[i]=POT[i-1]*2;
	}
	
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>A[i];
		sort(A[i].begin(),A[i].end());
		A[i].resize( unique( A[i].begin(),A[i].end() ) - A[i].begin());
		//cout<<A[i]<<endl;
	}
	for(int i=0;i<n;++i){
		for(int j=1;j<(1<<3);++j){
			string res="";
			for(int k=0;k<3;++k){
				if( (j>>k) & 1){
					res+=A[i][k];
				}
			}
			//cout<<":: "<<res<<endl;
			int num=0;
			for(int k=0;k<3;++k){
				num = num + POT[res[k]-'a'];
			}
			R[num]++;
		}
	}
	ll sol=0LL;
	for(int i=1;i<(1<<24);++i){
		sol= ( sol xor ( R[i] * R[i]) );
	}
	cout<<sol<<endl;
	
}



