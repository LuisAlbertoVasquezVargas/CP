#include<bits/stdc++.h>
using namespace std;

const int MAX_N=8,MAX_M=8;

int n,m;
int R[MAX_N+1],D[MAX_N+1],P[MAX_N+1],S[MAX_N+1][MAX_N+1];
int lastTimeOnMachine[MAX_M];
int lastJobOnMachine[MAX_M];
int C[MAX_N+1];
int best;
void init(){
	best=INT_MAX;
	for(int j=0;j<m;++j){
		lastTimeOnMachine[j]=-1;
		lastJobOnMachine[j]=-1;
	}
}
int getNewTime(int machine,int job){
	if(lastTimeOnMachine[machine]==-1)
		return max(S[0][job],R[job])+P[job];
	return max(lastTimeOnMachine[machine]+S[lastJobOnMachine[machine]][job],R[job])+P[job];
}
void backTrack(int pos){
	if(pos==n+1){
		int sum=0;
		for(int i=1;i<=n;++i)
			sum+=C[i]-D[i];
		/*
		for(int i=1;i<=n;++i)
			cout<<C[i]<<" "<<D[i]<<endl;
		cout<<endl;
		*/
		best=min(best,sum);
		return;
	}
	for(int j=0;j<m;++j){
		int oldTime=lastTimeOnMachine[j];
		int oldJob=lastJobOnMachine[j];
		int oldC=C[pos];
		
		int newTime=getNewTime(j,pos);
		int newJob=pos;
		int newC=newTime;
		//cout<<"new:"<<newTime<<endl;
		lastTimeOnMachine[j]=newTime;
		lastJobOnMachine[j]=newJob;
		C[pos]=newC;
		
		backTrack(pos+1);
		
		lastTimeOnMachine[j]=oldTime;
		lastJobOnMachine[j]=oldJob;
		C[pos]=oldC;
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;++i)
			cin>>R[i]>>D[i]>>P[i];
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				cin>>S[i][j];
		init();
		backTrack(1);
		/*
		for(int i=1;i<=n;++i)
			cout<<D[i]<<" "<<C[i]<<endl;
		*/
		printf("%d\n",best);
	}
}


