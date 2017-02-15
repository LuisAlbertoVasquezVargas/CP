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

#define N 10000005
#define MOD 10000019
#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )

using namespace std;

int sz;
bitset<N> F[6];
bitset<N> DP,memo;
/*
bool F[6][N];
bool DP[N];
bool memo[N];*/
char cad[N];
char t[6][10] = { "puton" , "out" , "output", "in" , "input" , "one" };
int Sz[] = { 5 , 3 , 6 , 2 , 5 , 3 };
int H[6];

int mulmod(int a, int b, int c){
    int x = 0,y = a%c;
	
    while(b>0){
        if(b&1) x = (x+y)%c;
        y = (y<<1)%c;
        b >>= 1;
    }
	
    return x;
}

int pow(int a, int b, int c){
    int x = 1, y = a;
	
    while(b>0){
        if(b&1) x = mulmod(x,y,c);
        y = mulmod(y,y,c);
        b >>= 1;
    }
	
    return x;
}
int dp( int pos )
{
	if( pos == sz )return 1;
	if( memo[pos] )return DP[pos];
	memo[pos] = 1;
	bool ok = 0;
	for( int k = 0 ; k < 6 ; ++k )
		if( F[k][pos] )
			ok |= dp( pos + Sz[k] );
	return DP[pos] = ok;	
}
void init()
{
	for( int k = 0 ; k < 6 ; ++k )
	{
		int Hash = 0;
		for( int i = 0 ; i < Sz[k] ; ++i )
			Hash = ( Hash*27 + (t[k][i] - 'a'+1) )%MOD;
		H[k] = Hash;		
	}
}
void rabin_karp()
{
	for( int k = 0 ; k < 6 ; ++k )
	{
		if( Sz[k] > sz )continue;
		int Hash = 0;
		for( int i = 0 ; i < Sz[k] ; ++i )
			Hash = ( Hash*27 + (cad[i] - 'a'+1) )%MOD;
		if( H[k] == Hash )
			F[k][0] = 1; 
		for( int i = Sz[k] ; i < sz ; ++i )
		{			
			Hash -= ( cad[i-Sz[k]] - 'a' + 1 )*pow(27,Sz[k]-1,MOD);
			Hash %= MOD;			
			Hash += MOD;
			Hash %= MOD;
			Hash = ( Hash*27 + (cad[i] - 'a' + 1) )%MOD;
			if( H[k] == Hash )
				F[k][i-Sz[k]+1] = 1;
		}
	}	
}
void doit()
{
	scanf( "%s" , cad );
	for( int k = 0 ; k < 6 ; ++k )
		F[k].reset();
	sz = strlen( cad );	
	rabin_karp();
	for( int i = 0 ; i <= sz ; ++i )
		memo[i] = 0 , DP[i] = 0;
	if( dp( 0 ) )
		puts("YES");
	else	puts("NO");
}
int main()
{
	init();
	int m;
	sc( m );
	while( m-- )
		doit();
}
