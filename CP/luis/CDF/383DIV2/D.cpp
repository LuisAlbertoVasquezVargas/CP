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
typedef vector<vi> vvi;

const int MAX_N=1000;
const int MAX_W=1000;

int W[MAX_N],B[MAX_N];
int vis[MAX_N];
vi G[MAX_N];
void dfs(int u,vi &myW,vi &myB,int &sumW,int &sumB){
	vis[u]=1;
	myW.pb(W[u]);
	myB.pb(B[u]);
	sumW+=W[u];
	sumB+=B[u];
	for(auto v:G[u])
		if(!vis[v])
			dfs(v,myW,myB,sumW,sumB);
}
void initGraph(int n){
	clr(vis,0);
	REP(i,n)G[i].clear();
}
int len;
vvi TW,TB;
vi valW,valB;
bool used[MAX_N][MAX_W+1];
int memo[MAX_N][MAX_W+1];
int dp(int pos,int budget){
	//DEBUG2(pos,budget);
	if(pos==len)return 0;
	if(used[pos][budget])return memo[pos][budget];
	used[pos][budget]=1;
	int &ans=memo[pos][budget]=dp(pos+1,budget);
	if(budget-valW[pos]>=0)ans=max(ans,valB[pos]+dp(pos+1,budget-valW[pos]));
	REP(k,SZ(TW[pos])){
		int myW=TW[pos][k];
		int myB=TB[pos][k];
		if(budget-myW>=0)ans=max(ans,myB+dp(pos+1,budget-myW));
	}
	return ans;
}
void impr(vi &vec){
	REP(i,SZ(vec))printf("%d%c",vec[i],(i+1==SZ(vec)?10:32));
}
int solve(vvi &_TW,vvi &_TB,vi &_valW,vi &_valB,int limit){
	len=SZ(_TW);
	TW=_TW;
	TB=_TB;
	valW=_valW;
	valB=_valB;
	clr(used,0);
	/*
	DEBUG(limit);
	DEBUG(len);
	cout<<"TW\n";
	for(auto vec:TW)
		impr(vec);
	cout<<"TB\n";
	for(auto vec:TB)
		impr(vec);
	cout<<"valW\n";
	impr(valW);
	cout<<"valB\n";
	impr(valB);
	*/
	return dp(0,limit);
}
int main(){
	int n,m,WL;
	while(scanf("%d%d%d",&n,&m,&WL)==3){
		initGraph(n);
		REP(i,n)scanf("%d",&W[i]);
		REP(i,n)scanf("%d",&B[i]);	
		
		REP(i,m){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		vvi vecW,vecB;
		vi intW,intB;
		REP(i,n){
			if(vis[i])continue;
			vi myW,myB;
			int sumW=0,sumB=0;
			dfs(i,myW,myB,sumW,sumB);
			vecW.pb(myW);
			vecB.pb(myB);
			intW.pb(sumW);
			intB.pb(sumB);
		}
		printf("%d\n",solve(vecW,vecB,intW,intB,WL));
	}
}


