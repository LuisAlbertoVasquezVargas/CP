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
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<string> vs;

const int INF=INT_MAX/2;
int main(){
	int cases;
	scanf("%d",&cases);
	REP(tc,cases){
		int n;
		scanf("%d",&n);
		vi F(50);
		REP(i,6*n){
			int x;
			scanf("%d",&x);
			F[x]++;
		}
		vpii v;
		for(int i=1;i<=49;++i)
			v.pb({-F[i],(i==7?-INF:i)});
		sort(all(v));
		vi vec;
		REP(i,6)
			vec.pb((v[i].se==-INF?7:v[i].se));
		sort(all(vec));
		REP(i,6)
			printf("%d%c",vec[i],(i+1==6?10:32));
	}
}


