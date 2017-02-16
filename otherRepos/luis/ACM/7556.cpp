#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define clr( t , val ) memset( t , val , sizeof(t) )

#define mp make_pair
#define fi first
#define se second

#define pb push_back

#define SZ(v) ((int)(v).size())
#define all(v) v.begin() , v.end()

typedef long long ll;
typedef vector< int > vi;
typedef pair< int , int > pii;
typedef vector< pii > vpii;

const int N = 5000;
vpii vec;
//bool used[ N + 5 ][ N + 5 ][ 2 ];
//int memo[ N + 5 ][ N + 5 ][ 2 ];
int DP[ N + 5 ][ 2 ][ 2 ];
int A[ N + 5 ] , ans[ N + 5 ];
int n;
/*
int dp( int pos , int len , int flag ){
	if( len == 1 ) return 1;
	if( used[ pos ][ len ][ flag ] ) return memo[ pos ][ len ][ flag ];
	used[ pos ][ len ][ flag ] = 1;
	
	int &dev = memo[ pos ][ len ][ flag ] = DP[ pos ][ len - 1 ][ flag ];
	int dir = (flag == 0 ? -1 : +1);
	int pos2 = pos + (len - 1) * dir;
	if( A[ pos ] > A[ pos2 ] )
		dev = max( dev , 1 + DP[ pos2 ][ len - 1 ][ flag ^ 1 ] );
	return dev;
}
*/
int main(){
	while( scanf( "%d" , &n ) == 1 ){
		REP( i , n ) scanf( "%d" , &A[ i ] );
		//clr( used , 0 );
		REP( i , n ) ans[ i ] = INT_MIN;
		REP( pos , N )REP( i , 2 )REP( j , 2 ) DP[ pos ][ i ][ j ] = INT_MIN;
		for( int len = 1 ; len <= n ; ++len ){
			REP( flag , 2 )REP( pos , n ){
				if( len == 1 ){
					DP[ pos ][ len & 1 ][ flag ] = 0;
					continue;
				}
				int dir = (flag == 0 ? -1 : +1);
				int pos2 = pos + (len - 1) * dir;
				if( !(pos2 >= 0 && pos2 < n) ) continue;
				DP[ pos ][ len & 1 ][ flag ] = DP[ pos ][ (len - 1) & 1 ][ flag ];
				if( pos2 >= 0 && pos2 < n && A[ pos ] > A[ pos2 ] )
					DP[ pos ][ len & 1 ][ flag ] = max( DP[ pos ][ len & 1 ][ flag ] , 1 + DP[ pos2 ][ (len - 1) & 1 ][ flag ^ 1 ] );
			}
			ans[ len - 1 ] = max( ans[ len - 1 ] , DP[ len - 1 ][ len & 1 ][ 0 ] );
			ans[ n - len ] = max( ans[ n - len ] , DP[ n - len ][ len & 1 ][ 1 ] );
		}
		//REP( i , n ) ans[ i ] = max( DP[ i ][ n - 1 - i + 1 ][ 1 ] , DP[ i ][ i + 1 ][ 0 ] );
		REP( i , n ) printf( "%d%c" , ans[ i ] , 32 );
		puts("");
	}
}




