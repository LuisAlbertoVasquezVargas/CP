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

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		vi a(n);
		REP(i,n)scanf("%d",&a[i]);
		vi AC(n+1);
		REP(i,n)AC[i+1]=AC[i]+a[i];
		int ans=0;
		REP(k,m){
			int lo,hi;
			scanf("%d%d",&lo,&hi);
			lo--,hi--;
			ans+=max(0,AC[hi+1]-AC[lo]);
		}
		printf("%d\n",ans);
	}
}



