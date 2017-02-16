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

ll LCM(ll a,ll b){
	return a*(b/__gcd(a,b));
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]),A[i]--;
		vi ind(n),out(n);
		REP(u,n){
			int v=A[u];
			ind[v]++;
			out[u]++;
		}
		bool ok=1;
		REP(i,n){
			if(ind[i]==1&&out[i]==1)continue;
			ok=0;
			break;
		}
		if(!ok){
			puts("-1");
			continue;
		}
		ll ans=1;
		vi vis(n);
		REP(i,n){
			if(vis[i])continue;
			if(A[i]==i)continue;
			int cnt=0,u=i;
			while(1){
				if(vis[u])break;
				vis[u]=1;
				cnt++;
				u=A[u];
			}
			if(cnt&1)ans=LCM(ans,cnt);
			else ans=LCM(ans,cnt>>1);
		}
		cout<<ans<<'\n';
	}
}


