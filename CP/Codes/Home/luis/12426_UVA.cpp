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

#define inf (1<<30)
#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define EPS 1e-6
#define PI acos(-1)
#define Vector Point

using namespace std;

struct Point
{
    ll x, y;
    Point(){}
    Point(ll a, ll b) { x = a; y = b; }
};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator *(const Point &a, ll k) { return Point(a.x*k, a.y*k); }
ll cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
ll area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

int n , tc;
Point P[ 10000 ];
int S;

int ternary( int i , int j )
{
	ll maxi = -1 ;
	int pos ;
	if( j - i <= 7 )
	{
		for( int k = i ; k <= j ; ++k )
		{
			ll s = abs( area( P[i] , P[j] , P[k] ) );
			if( s > maxi )
				maxi = s,pos = k;
		}
		return pos;
	}
	int lo = i , hi = j ;
	while( hi - lo > 6 )
	{
		int med1 = ( 2*lo + hi )/3;
		int med2 = ( 2*hi + lo )/3;
		ll fmed1 = abs( area( P[i] , P[j] , P[med1] ) );
		ll fmed2 = abs( area( P[i] , P[j] , P[med2] ) );
		if( fmed1 >= fmed2  )
			hi = med2;
		else	lo = med1; 
	}
	for( int k = lo ; k <= hi ; ++k )
	{
		ll s = abs( area( P[i] , P[j] , P[k] ) );
		if( s > maxi )
			maxi = s,pos = k;		
	}
	return pos;
}
int BS1( int i , int pos , int j )
{
	//estrictamente creciente 1111 000000 f(x) <= S
	int lo = i , hi = pos ;
	ll fhi = abs( area( P[i] , P[j] , P[hi] ) );	
	if( fhi <= 2*S )	
		return hi - i ;
	while( hi - lo > 1 )
	{
		int med = ( hi + lo )/2;
		ll fmed = abs( area( P[i] , P[j] , P[med] ) );
		if( fmed <= 2*S )
			lo = med;
		else 	hi = med;
	}
	return lo - i ;
}
int BS2( int i , int pos , int j )
{
	//no creciente 0000111111
	int lo = pos , hi = j;
	ll flo = abs( area( P[i] , P[j] , P[lo] ) );
	if( flo <= 2*S )	
		return hi - lo - 1 ;
	while( hi - lo  > 1 )
	{
		int med = ( hi + lo )/2;
		ll fmed = abs( area( P[i] , P[j] , P[med] ) );		
		if( fmed <= 2*S )
			hi = med;
		else 	lo = med;		
	}	
	return j - hi ;	
}
int f( int i , int j )
{
	int pos = ternary( i , j );
	return BS1( i , pos , j ) + BS2( i , pos , j );
}
int main()
{
	scanf( "%d" , &tc );
	while( tc-- )
	{
		scanf( "%d%d" , &n , &S );
		for( int i = 0 ; i < n ; ++i )
		{
			int u , v;
			scanf( "%d%d" , &u , &v );
			P[i].x = u , P[i].y = v;
		}
		int cnt = 0;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				cnt += f( i , j );
		printf( "%d\n" , cnt );
	}
}
