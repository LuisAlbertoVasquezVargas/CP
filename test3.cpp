#include <bits/stdc++.h>
using namespace std;
#define REP( i , n ) for( int i=0 ; i < n ; i++ )
#define all( v ) v.begin(),v.end()
#define pb push_back
#define pi acos(-1.0)
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
typedef vector<int> vi ;
typedef vector<pair<int,int>> vpii ;
typedef long long ll ;

ll memo[ 45 + 5 ] ;
bool vis[ 45 + 5 ] ;

ll dp( int n ){
	if( n <= 1 ) return 1 ;
	if( vis[ n ] ) return memo[ n ] ;
	vis[ n ] = 1 ;
	ll &ans = memo[ n ] ;
	ans = dp( n - 1 ) + dp( n - 2 ) ;
	return ans ;
}

int main()
{
	int n ;
	cin >> n ;
	
	cout<< (ll)2*dp( n - 1 )  ;
	
	
	return 0;
}


