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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=(1<<20);
int myMap[MAX_N];
int main(){
	clr(myMap,-1);
	for(int x=0;x<=255;++x){
		int y=(x<<1);
		if(y>255)y-=256;
		//DEBUG2(x,(x^y));
		if(myMap[x^y]!=-1)assert(0);
		myMap[x^y]=x;
	}
	for(int x=0;x<=255;++x)
		assert(myMap[x]!=-1);
	
	int n;
	while(scanf("%d",&n)==1){
		REP(i,n){
			int x;
			scanf("%d",&x);
			printf("%d%c",myMap[x],(i+1==n?10:32));
		}
	}
}


