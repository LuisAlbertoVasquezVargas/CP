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
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<vi> vvi;

const int MAX_N=(int)1e5;
vi G[MAX_N+1];
vi C[MAX_N+1];
void add(int u,int v,int c){
	G[u].pb(v);
	C[u].pb(c);
}
void initGraph(int n){
	REP(i,n)G[i].clear(),C[i].clear();
}
vi bfs(int n,int target,bool &ok){
	vi color(n,-1);
	queue<int>Q;
	vi ans;
	REP(s,n){
		if(color[s]!=-1)continue;
		vvi myBuckets(2);
		color[s]=0;
		Q.push(s);
		myBuckets[color[s]].pb(s);
		while(!Q.empty()){
			int u=Q.front();
			Q.pop();
			REP(i,SZ(G[u])){
				int v=G[u][i];
				int myCol=C[u][i];
				if(color[v]==-1){
					color[v]=(color[u]^myCol^target);
					Q.push(v);
					myBuckets[color[v]].pb(v);
				}else{
					if(color[v]==(color[u]^myCol^target))continue;
					ok=0;
					return vi();
				}
			}
		}
		if(SZ(myBuckets[0])>SZ(myBuckets[1]))swap(myBuckets[0],myBuckets[1]);
		ans.insert(ans.end(),all(myBuckets[0]));
	};
	ok=1;
	return ans;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		initGraph(n);
		REP(i,m){
			int u,v;
			char s[5];
			scanf("%d%d%s",&u,&v,s);
			u--,v--;
			add(u,v,s[0]=='R');
			add(v,u,s[0]=='R');
		}
		bool found=0;
		vi best(n+1);
		REP(k,2){
			bool flag=1;
			vi temp=bfs(n,k,flag);
			if(flag){
				found=1;
				if(SZ(best)>SZ(temp))best=temp;
			}
		}
		if(!found){
			puts("-1");
			continue;
		}
		printf("%d\n",SZ(best));
		REP(i,SZ(best))printf("%d%c",best[i]+1,(i+1==SZ(best)?10:32));
	}
}


