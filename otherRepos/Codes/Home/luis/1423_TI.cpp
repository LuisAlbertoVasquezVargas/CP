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

#define N 250005
#define MOD1 1000000007
#define MOD2 1000000009
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

using namespace std;


int shift(char *s,int n){
	int i = 0, j = 1, k = 0;
	char a,b;
	while( j<n && i+k+1<n ){
		a = s[i+k]; b = s[(j+k)%n];
		if( a==b ) k++;
		else if( a<b ) j=j+k+1, k = 0;
		else i = max(i+k+1,j), j = i+1, k = 0;
	}
	return i;
}
char s[N] , t[N];

int main()
{
	int n;
	sc( n );
	scanf( "%s %s" , s , t );
	n = strlen( s ) ;
	int ks = shift( s , n ), kt = shift( t , n );
	int match = 0;
	for( int L = 0 ; L < n ; ++L )
		if( s[ (ks + L)%n ] == t[ (kt + L)%n ] )
			match ++;
	if( match == n )
	{
		if( kt >= ks )
			printf( "%d\n" , kt - ks );
		else	printf( "%d\n" , kt + n - ks );
	}
	else	puts( "-1" );
		
}
