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
typedef vector<string> vs;

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
		vs A(n),B(m);
		REP(i,n)cin>>A[i];
		REP(i,m)cin>>B[i];
		sort(all(A));
		sort(all(B));
		int both=0;
		REP(i,n)
			if(binary_search(all(B),A[i]))both++;
		n-=both;
		m-=both;
		if(both&1)n++;
		if(n>m)cout<<"YES\n";
		else cout<<"NO\n";
	}
}


