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

void impr(vi &v){
	printf("%d\n",SZ(v));
	REP(i,SZ(v))printf("%d%c",v[i],(i+1==SZ(v)?10:32));
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		if(!(n&1)){
			vi v(n>>1,2);
			impr(v);
		}else{
			vi v(n>>1,2);
			v.pop_back();
			v.pb(3);
			impr(v);
		}
	}
}



