#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define oo (1<<30)
#define FOR(i,x,y) for(int i=x;i<y;i++)
int A[MAXN],I[MAXN],D[MAXN];
int T,N;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		D[0]=0,I[0]=0;
		FOR(i,0,N){
			scanf("%d",&A[i]);
			D[(i+1)%N]=D[i]+A[i];	
		}
		FOR(i,0,N){
			I[(N-1-i+N)%N]=I[(N-i+N)%N]+A[N-i-1];
		}
		D[0]=0,I[0]=0;
		int mini = oo;
		FOR(i,1,N){
			//cout<<D[i]<<" "<<I[i]<<" "<<D[i]+2*I[(i+1)%N]<<" "<<I[i]+2*D[i-1]<<endl;
			mini=min(mini,min(D[i]+2*I[(i+1)%N],I[i]+2*D[i-1]));
		}
		printf("%d\n",mini);
	}

}
