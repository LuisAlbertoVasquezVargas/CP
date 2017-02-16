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
typedef vector<vi> vvi;

const int MOD=(int)1e9+7;
const int MAXN=(int)1e6;
int F[MAXN+1];
void init(){
	F[0]=1;
	for(int i=1;i<=MAXN;++i)
		F[i]=((ll)F[i-1]*i)%MOD;
}
int main(){
	init();
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		int groups=0;
		vvi vectors(m);
		REP(i,n){
			int gi;
			scanf("%d",&gi);
			vi F(m);
			REP(j,gi){
				int x;
				scanf("%d",&x);
				x--;
				F[x]++;
			}
			map<int,vi>myMap;
			REP(j,m)
				myMap[F[j]].pb(j);
			
			for(auto item:myMap){
				auto vec=item.se;
				for(auto x:vec){
					vectors[x].pb(groups);
				}
				groups++;
			}
		}
		sort(all(vectors));
		ll ans=1;
		REP(i,m){
			int ind;
			for(int j=i;j<m;++j)
				if(vectors[i]==vectors[j])ind=j;
				else break;
			ans=(ans*(ll)F[ind-i+1])%MOD;
			i=ind;
		}
		printf("%d\n",(int)ans);
	}
}


