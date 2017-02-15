#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair< int , int >
#define pll pair< ll , ll >
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vi >
#define vpii vector< pii >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define PI acos( -1.0 )

typedef long double ld;

int main()
{
	ld a , b , c , S , r , R , p ;
	while( cin >> a >> b >> c )
	{
		p = ( a + b + c )/2;
		S = sqrt( p*( p - a )*( p - b )*( p - c ) );
		r = S / p , R = a * b * c /( 4 *S );
		ld S1 = PI*r*r , S2 = S - S1 , S3 = PI*R*R - S ;
		printf( "%.4lf %.4lf %.4lf\n" , double( S3 ) , double( S2 ) , double( S1 ) );
	}
}

