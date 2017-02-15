#include <algorithm>
#include<cstdio>
#include<map>

#define REP(i,n) for(int i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)

#define N 100005

using namespace std;

int n , ind , val , m ;
int T[4*N] , F[N] , A[N] , B[N];
map< int , int >M;
char s[4];
bool op[N];

int gcd( int a , int b )
{
	int r ;
	if( a > b )swap( a , b );
	while( a )
	{
		r = b%a;
		b = a;
		a = r;
	}
	return b;
}
void update( int node , int a , int b )
{
	if( ind > b || a > ind )return;
	if( a == b )
	{
		T[ node ] = val;
		return;
	}
	int v1 = (node<<1) + 1 , v2 = v1 + 1 , med = ( a + b )>>1;
	update( v1 , a , med );
	update( v2 , med + 1 , b );
	T[ node ] = gcd( T[v1] , T[v2] );
}
int main()
{
	sc( m );
	REP( i , m )
	{
		scanf( "%s%d" , s , &A[i] );
		op[i] = (s[0]=='+');
		B[i] = A[i];
	}
	sort( B , B + m );
	n = unique( B , B + m ) - B;
	REP( i , n )M[ B[i] ] = i;
	REP( i , m )
	{
		val = A[i] , ind = M[ val ];
		if( op[i] == 1 )
		{
			if( !F[ind] )
				update( 0 , 0 , n - 1 );
			F[ind]++;
		}
		else
		{
			if( F[ind] == 1 )
			{
				val = 0;
				update( 0 , 0 , n - 1 );
			}
			F[ind]--;
		}
		printf( "%d\n" , max( T[0] , 1 ) );
	}
}

