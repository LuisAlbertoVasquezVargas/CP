#include<bits/stdc++.h>

using namespace std;

#define MAXN 10100
#define FOR(i,x,y) for(int i=x;i<y;i++)

int N;

int X[MAXN],Y[MAXN],XX[MAXN];

int main(){
	while(scanf("%d",&N)&&N!=-1){
		double ans=0.0;
		FOR(i,0,N)
			scanf("%d",&X[i]);
		FOR(i,0,N){
			scanf("%d",&Y[i]);
		}
		sort(Y,Y+N);
		XX[0]=X[1]-X[0];
		XX[N-1]=X[N-1]-X[N-2];
		FOR(i,1,N-1){
			XX[i]=X[i+1]-X[i-1];
		}
		sort(XX,XX+N);
		FOR(i,0,N)
			ans+=(XX[i]*Y[i])/2.0;
		printf("%.1f\n",ans);
	}
}
