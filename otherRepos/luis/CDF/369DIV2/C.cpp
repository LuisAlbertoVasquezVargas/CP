#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define test() cerr << "hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=100;
const int MAX_M=100;
const int MAX_K=100;
const ll INF=LLONG_MAX/2;
int n,m,K;
int C[MAX_N];
int P[MAX_N][MAX_M+1];
bool used[MAX_N+2][MAX_M+2][MAX_K+2];
ll memo[MAX_N+2][MAX_M+2][MAX_K+2];

ll dp(int pos,int lastColor,int cntBuckets){
	if(pos==n)return (cntBuckets==K)?0:INF;
	if(used[pos][lastColor][cntBuckets])return memo[pos][lastColor][cntBuckets];
	used[pos][lastColor][cntBuckets]=1;
	ll &ans=memo[pos][lastColor][cntBuckets]=INF;
	if(C[pos]==0){
		for(int i=1;i<=m;++i)
			ans=min(ans,P[pos][i]+dp(pos+1,i,cntBuckets+(i!=lastColor)));
	}else{
		ans=min(ans,dp(pos+1,C[pos],cntBuckets+(C[pos]!=lastColor)));
	}
	return ans;
}
int main(){
	while(scanf("%d%d%d",&n,&m,&K)==3){
		REP(i,n)scanf("%d",&C[i]);
		REP(i,n)REP(j,m)scanf("%d",&P[i][j+1]);
		clr(used,0);
		ll ans=dp(0,0,0);
		if(ans>=INF){
			puts("-1");
			continue;
		}
		printf("%I64d\n",ans);
	}	
}




