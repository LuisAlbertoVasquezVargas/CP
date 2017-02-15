#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

void shift( string s , string &ret , int &ind ){
	s += s;
	int n = s.size();
	int i = 0 , ans = 0;
	while( i < (n>>1) ){
		ans = i;
		int j = i + 1 , k = i;
		while( j < n && s[ k ] <= s[ j ] ){
			if( s[ k ] < s[ j ] ) k = i;
			else ++k;
			++j;
		}
		while( i <= k ) i += j - k;
	}
	ind = ans;
	ret = s.substr( ans , n>>1 );
}
int main(){
	sync
	int n , i , j;
	string s1 , s2 , t1 , t2;
	while( cin >> n ){
		cin >> s1 >> s2;
		shift( s1 , t1 , i );
		shift( s2 , t2 , j );
		//cout << i << " " << j << endl;
		//cout << t1 << endl;
		if( t1 == t2 ) cout << ( n + j - i )%n << '\n';
		else cout << "-1\n";
	}
}


