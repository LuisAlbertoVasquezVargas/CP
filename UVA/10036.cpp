#include <bits/stdc++.h>
using namespace std;
#define REP( i , n ) for( int i=0 ; i < n ; i++ )
#define all( v ) v.begin(),v.end()
#define pb push_back
#define pi acos(-1.0)
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define N 10000
typedef vector<int> vi ;
typedef vector<pair<int,int>> vpii ;
typedef long long ll ;

int n , k ;
int v[ N + 5 ] ;
bool memo[ N + 5 ][ 100 + 2 ] ;
bool used[ N + 5 ][ 100 + 2 ] ;

bool dp( int pos , int modu ){
	if( pos == n ){
		if( !( modu ) ) return true ;
		else return false ;
	}
	if( used[ pos ][ modu ] ) return memo[ pos ][ modu ] ;
	used[ pos ][ modu ] = 1 ;
	bool &ans = memo[ pos ][ modu ] = 0 ;
	
	ans |= dp( pos + 1 , (( modu +  v[ pos ] )%k + k)%k ) ;
	ans |= dp( pos + 1 , (( modu -  v[ pos ] )%k + k)%k ) ;
	
	return ans ;
}

int main()
{
	int t ;
	cin >> t ;
	REP( tc , t ){
		cin >> n >> k ;
		
		REP( i , n )
			REP( j , k )
				used[ i ][ j ] = 0 ;
		
		REP( i , n )
			cin >> v[ i ] ;	
			
		cout << ( dp( 0 , 0 ) ? "Divisible" : "Not divisible" ) << '\n';
		
	}
	
	return 0;
}


