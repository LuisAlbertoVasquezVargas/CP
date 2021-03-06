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
typedef vector<string> vs;

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		vs S(n);
		REP(i,n)cin>>S[i];
		int loX=INT_MAX,loY=INT_MAX;
		int hiX=INT_MIN,hiY=INT_MIN;
		REP(i,n)REP(j,m){
			if(S[i][j]=='X'){
				loX=min(loX,i);
				loY=min(loY,j);
				hiX=max(hiX,i);
				hiY=max(hiY,j);
			}
		}
		bool ok=1;
		for(int i=loX;i<=hiX;++i)
			for(int j=loY;j<=hiY;++j)
				if(S[i][j]!='X'){
					ok=0;
					break;
				}
		cout<<(ok?"YES":"NO")<<'\n';
	}
}


