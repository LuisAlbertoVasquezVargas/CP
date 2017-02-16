#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

using namespace std;

#define N 4

int mod = 10007;

struct Matrix
{
	int M[ N ][ N ];
	Matrix()
	{
		clr( M , 0 );
		REP( i , N ) M[i][i] = 1;
	}
	void print()
	{
		REP( i , N )REP( j , N ) cout << setw(6) << M[i][j] << (j+1==N?"\n":"" );
	}
};
Matrix operator *( const Matrix &A , const Matrix &B )
{
	Matrix Mat;
	clr( Mat.M , 0 );
	REP( i , N )REP( j , N )
	{
		int sum = 0;
		REP( k , N ) sum = ( sum + (A.M[i][k]*B.M[k][j])%mod )%mod;
		Mat.M[i][j] = sum;
	}
	return Mat;
}
Matrix pow( Matrix &A , int n )
{
	Matrix M;
	while( n > 0 )
	{
		if( n%2 == 1 )
			M = M*A;
		n /= 2;
		A = A*A;
	}
	return M;
}
int M[4][4] = {
	{ 2 , 1 , 1 , 0 },
	{ 1 , 2 , 0 , 1 },
	{ 1 , 0 , 2 , 1 },
	{ 0 , 1 , 1 , 2 }
};
int main()
{
	int n , tc;
	sc( tc );
	while( tc-- )
	{
		sc( n );
		Matrix Mat;
		REP( i , N )REP( j , N ) Mat.M[i][j] = M[i][j];
		Mat = pow( Mat , n - 1 );
		/*Mat.print();
		test*/
		printf( "%d\n" , (2*Mat.M[0][0] + Mat.M[0][1] + Mat.M[0][2])%mod );
	}
}


