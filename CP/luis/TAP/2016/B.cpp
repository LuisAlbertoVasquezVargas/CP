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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef long double ld;

const int MAX_N=4000;
const ld INF=1e6;
bool used[MAX_N+1][MAX_N+1][2];
ld memo[MAX_N+1][MAX_N+1][2];
vi L(MAX_N+1),R(MAX_N+1);
int X[MAX_N],Y[MAX_N];
ld dist(int a, int b){
	return hypot((double)(X[a]-X[b]),(double)(Y[a]-Y[b]));
}
ld dp(int curL,int curR,bool onLeft){
	//DEBUG2(curL,curR);
	if(curL==0&&curR==0)return 0;
	if(used[curL][curR][onLeft])return memo[curL][curR][onLeft];
	used[curL][curR][onLeft]=1;
	ld &ans=memo[curL][curR][onLeft]=INF;
	ld cross=dist(L[curL],R[curR]);
	if(onLeft){
		if(curL-1>=0)
			ans=min(ans,dp(curL-1,curR,1)+dist(L[curL],L[curL-1]));
		ans=min(ans,dp(max(0,curL-1),curR,0)+cross);
	}else{
		if(curR-1>=0)
			ans=min(ans,dp(curL,curR-1,0)+dist(R[curR],R[curR-1]));
		ans=min(ans,dp(curL,max(0,curR-1),1)+cross);
	}
	return ans;
}
int get(int s,int t,int op,int n,vi &myMap){
	vi v(1,s);
	while(s!=t){
		s=(s+op+n)%n;
		v.pb(s);
	}
	reverse(all(v));
	REP(i,SZ(v)){
		//DEBUG(v[i]);
		myMap[v[i]]=i;
	}
	//DEBUG("");
	return SZ(v);
}
int main(){
	int n,S,T;
	while(scanf("%d%d%d",&n,&S,&T)==3){
		S--,T--;
		REP(i,n){
			int x,y;
			scanf("%d%d",&x,&y);
			X[i]=x;
			Y[i]=y;
		}
		clr(used,0);
		int lenL=get(S,T,-1,n,L);
		int lenR=get(S,T,+1,n,R);
		ld ans=dp(lenL-1,lenR-1,1);
		//ans=min(ans,dp(lenL-2,lenR-1,0));
		//ans=min(ans,dp(lenL-1,lenR-1,1));
		printf("%.6f\n",(double)ans);
	}
}


