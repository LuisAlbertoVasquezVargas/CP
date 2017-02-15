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

const int MAXN=(int)1e4;
int id[MAXN];
void init(int n){
	REP(i,n) id[i]=i;
}
int Find( int x ){ return id[ x ] = (id[ x ] == x ? x : Find( id[ x ] ) );}
void Union(int x, int y){
	int px=Find(x),py=Find(y);
	if(px!=py)
		id[px]=py;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		init(n);
		REP(i,n){
			int x;
			scanf("%d",&x);
			x--;
			Union(x,i);
		}
		int ans=0;
		REP(i,n)
			if(Find(i)==i)ans++;
		printf("%d\n",ans);
		fflush(stdout);
	}
}



