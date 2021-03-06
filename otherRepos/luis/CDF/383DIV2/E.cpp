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

const int N=200000;
vi G[N];
void initGraph(int n){
	REP(i,n)G[i].clear();
}
void add(int u,int v){
	G[u].pb(v);
	G[v].pb(u);
}
vi bfs(int n){
	vi color(n,-1);
	queue<int>Q;
	REP(s,n){
		if(color[s]!=-1)continue;
		Q.push(s);
		color[s]=0;
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			for(auto v:G[u])
				if(color[v]==-1){
					Q.push(v);
					color[v]=color[u]^1;
				}
		}
	}
	return color;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		initGraph(2*n);
		vi X(n),Y(n);
		REP(i,n){
			scanf("%d%d",&X[i],&Y[i]);
			X[i]--,Y[i]--;
			add(X[i],Y[i]);
		}
		REP(i,n)add(2*i,2*i+1);
		vi color=bfs(2*n);
		REP(i,n)
			printf("%d %d\n",color[X[i]]+1,color[Y[i]]+1);
	}
}




