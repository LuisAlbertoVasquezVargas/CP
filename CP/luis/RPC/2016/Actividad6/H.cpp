#include<bits/stdc++.h>
using namespace std;

#define REP(i , n) for(int i = 0 ;i < n; ++i)
#define clr(t , val) memset(t , val , sizeof(t))

#define mp make_pair
#define fi first
#define se second

#define pb push_back

typedef long long ll;
typedef vector< int > vi;

const int N = 1000 , INF = INT_MAX/3;
int n , posx , x;
int A[ N + 5 ];
bool used[ N + 5 ][ N + 5 ][ 2 ][ 7 ];
int memo[ N + 5 ][ N + 5 ][ 2 ][ 7 ];
int d(int a , int b){
	if(a >= b) swap(a , b);
	if(a < 0) return 0;
	if(b > n + 1) return 0;
	assert(a <= b);
	assert(a >= 0 && a <= n + 1);
	assert(b >= 0 && b <= n + 1);
	return A[ b ] - A[ a ];
}
int dp( int left , int right , int dir , int cnt ){
	//cout << left << " " << right << " " << dir << " " << cnt << endl;
	if( left == 0 && right == n + 1 ) return 0;
	if( used[ left ][ right ][ dir ][ cnt ] ) return memo[ left ][ right ][ dir ][ cnt ];
	used[ left ][ right ][ dir ][ cnt ] = 1;
	
	int &ret = memo[ left ][ right ][ dir ][ cnt ] = INF;
	vi cond = { left >= 1 , right <= n };
	vi dist = { d(left - 1,left) , d(right , right + 1) };
	vi L = {left - 1,left};
	vi R = {right , right + 1};
	vi side = {left , right};
	if( cond[ dir ] ) ret = min(ret , dist[dir] + 2 * abs(A[side[dir]] - x) + dp(L[dir] , R[dir] , dir , 4) );
	if( cnt && cond[dir] ) ret = min(ret , dist[dir] + dp(L[dir] , R[dir] , dir , cnt - 1) );
	if( cond[dir ^ 1] ) ret = min(ret , dist[dir ^ 1] + d(left , right) + dp(L[dir ^ 1] , R[dir ^ 1] , dir ^ 1 , 4) );
	return ret;
}
int main(){
	while( scanf( "%d" , &n ) == 1 ){
		assert(n < 50);
		REP( i , n ) scanf( "%d" , &A[ i ] );
		scanf( "%d" , &x );

		sort(A , A + n);
		A[ n ] = A[ n - 1 ];
		A[ n + 1 ] = A[ 0 ];
		sort( A , A + n + 2 );
		clr( used , 0 );
		
		A[ 0 ] = INT_MIN;
		A[ n + 1 ] = INT_MAX;
		/*
		for(int i = 0 ; i <= n + 1 ; ++i) cout << A[ i ] << " ";
		cout << endl;
		for(int i = 0 ; i <= n + 1 ; ++i) cout << i << " ";
		cout << endl;
		*/
		int R = upper_bound( A , A + n + 2 , x ) - A;
		int L = lower_bound( A , A + n + 2 , x ) - A;
		L --;
		
		A[ 0 ] = A[ 1 ];
		A[ n + 1 ] = A[ n ];
		//if( posx == 0 ) posx ++;
		//cout <<  max(0 , posx - 1) << " " << min(posx + 1, n + 1) <<endl;
		//cout << L << " " << R << endl;
		int ans = dp(L , R , 0 , 5) + abs(A[L] - x) + n;
		ans = min(ans , dp(L , R , 1 , 5) + abs(A[R] - x) + n);
		printf( "%d\n" , ans );
	}
}


