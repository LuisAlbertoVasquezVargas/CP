#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N=3;
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	vvi X(N,vi(N));
	REP(i,N)REP(j,N)cin>>X[i][j];
	int best=0;
	REP(k,N)REP(j,N)REP(i,N){
		if(k==i||k==j||i==j)continue;
		best=max(best,X[0][i]*X[0][i]+X[1][j]*X[1][j]+X[2][k]*X[2][k]);
	}
	printf("%.10f\n",sqrt(best));
}
