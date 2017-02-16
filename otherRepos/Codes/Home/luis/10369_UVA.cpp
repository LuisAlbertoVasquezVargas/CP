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
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

#define MAXN 505
#define MOD 1000000007

using namespace std;

int n , s ;
pair< int , int >P[MAXN];
int PP[MAXN];
void init(){ for( int i = 0 ; i < n ; ++i )PP[i] = i;}
int F(int x) {return x == PP[x] ? x : (PP[x] = F(PP[x]));}
void U(int x, int y) {PP[F(x)] = F(y);}
struct edge
{
     int u,v;double w;
     edge(){};
};
bool cmp( edge e1 , edge e2 )
{
     return e1.w < e2.w;     
}
double dist( int i , int j )
{
	return sqrt( (P[i].first - P[j].first)*(P[i].first-P[j].first) + (P[i].second-P[j].second)*(P[i].second-P[j].second) );
}
int main()
{
	int tc;
	sc( tc );
	while( tc-- )
	{
		sc( s ) , sc( n );
		for( int i = 0 ; i < n ; ++i )
			sc( P[i].first ) , sc( P[i].second );
		edge E[ (n*(n-1))/2 ];
		int it = 0 ;
		for( int i = 0 ; i < n ; ++i )
			for( int j = i + 1 ; j < n ; ++j )
				E[it].u = i , E[it].v = j , E[it++].w = dist( i , j );
		sort( E , E + (n*(n-1))/2 , cmp );							
		init();
		int j = n;	
		for( int i = 0 ; i < it ; ++i )
			if( F(E[i].u) != F(E[i].v) )
			{
				j--;
				U(E[i].u,E[i].v);
				if( j == s )
				{
					printf( "%.2lf\n" , E[i].w );
					break;	
				}
			}
	}
}
