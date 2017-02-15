#include<bits/stdc++.h>
using namespace std;

const int MAX_N=100;
int memo[MAX_N+1][MAX_N+1];
bool used[MAX_N+1][MAX_N+1];
int dp(int n,int m){
	if(n==1)return m;
	if(m==1)return n;
	if(used[n][m])return memo[n][m];
	used[n][m]=1;
	int &ans=memo[n][m]=1;
	for(int i=1;i<=m;++i)
		ans+=dp(i,n-1);
	return ans;
}
int main(){
	for(int i=1;i<=10;++i){
		for(int j=1;j<=10;++j)
			cout<<setw(8)<<dp(i,j)<<' ';
		cout<< endl;
	}
}
