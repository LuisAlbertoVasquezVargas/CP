#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define clr(t,val) memset(t,val,sizeof(t))

#define all(v) v.begin(),v.end()

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
const int MAX_N=2000;
const int MOD=(int)1e9+7;
int a[MAX_N];
bool used[MAX_N+1][MAX_N+1];
int memo[MAX_N+1][MAX_N+1];
int n,H;
int dp(int pos,int cur){
	if(pos==n)return cur==0;
	if(used[pos][cur])return memo[pos][cur];
	used[pos][cur]=1;
	int &ans=memo[pos][cur]=0;
	if(a[pos]+cur==H){
		ans+=dp(pos+1,cur);
		if(ans>=MOD)ans-=MOD;
	}
	if(a[pos]+cur==H&&cur-1>=0){
		ans=(ans+(ll)cur*dp(pos+1,cur-1))%MOD;
	}
	if(a[pos]+cur+1==H){
		ans+=dp(pos+1,cur+1);
		if(ans>=MOD)ans-=MOD;
	}
	if(a[pos]+cur+1==H){
		ans=(ans+(ll)(cur+1)*dp(pos+1,cur))%MOD;
	}
	return ans;
}
int main(){
	while(scanf("%d%d",&n,&H)==2){
		REP(i,n)scanf("%d",&a[i]);
		clr(used,0);
		printf("%d\n",dp(0,0));
	}
}


