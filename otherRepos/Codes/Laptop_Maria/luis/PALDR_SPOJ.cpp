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
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 1000005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

#define SIZE 2
#define B 56

ll Mod[ SIZE ] = { 1000000007 , 1000000009 };
ll Inv[ SIZE ] = { 370370373 , 296296299 } ; // = { mod_inv( B , Mod[0]) , mod_inv( B , Mod[1] ) };
int Map( char c )
{ 
	if( c <= 'z' ) return c - 'a' + 1;
	return  28 + c - 'A';
}

struct Hash
{
	ll H[ SIZE ] , HR[ SIZE ] , Pot[ SIZE ];
	Hash(){};
	Hash( string &s )
	{
		me( H , 0 ); me( HR , 0 );fill( Pot , Pot + SIZE , 1 );
		FOR( o , s )
			add_R( Map(*o) );
	}
	void add_R( int c )
	{
		for( int k = 0 ; k < SIZE ; ++k )
		{
			H[k] = (H[k]*B)%Mod[k] + c ;H[k]%=Mod[k];
			HR[k] = HR[k] + (Pot[k]*c)%Mod[k] ; HR[k]%=Mod[k];
			Pot[k]*=B ; Pot[k]%=Mod[k];
		}	
	}
	void del_L( int c )
	{
		for( int k = 0 ; k < SIZE ; ++k )
		{
			Pot[k]*=Inv[k] ; Pot[k]%=Mod[k];			
			H[k] = H[k] - ((c*Pot[k])%Mod[k]) ;H[k]%=Mod[k];H[k]+= Mod[k];H[k]%=Mod[k];
			HR[k] = HR[k] - c;HR[k]%=Mod[k];HR[k]+= Mod[k];HR[k]%=Mod[k];HR[k]*= Inv[k] ; HR[k]%=Mod[k];
		}		
	}
};
bool f( Hash hash1 ){ 
	for( int k = 0 ; k < SIZE ; ++k )
		if( hash1.H[k] != hash1.HR[k] )return 0;
	return 1;
}
int tc;
char s[ N ];
int main()
{
	sc( tc );
	while( tc -- )
	{
		scanf( "%s" , s );
		int n = strlen( s ); 
		string S; 
		Hash H(S);
		int SZ = 0;
		for( int i = 0 ; i < n ; ++i )
		{
			H.add_R( Map(s[i]) );
			SZ++;
			if( SZ%2 == 0 && f(H) )SZ = 0, H = Hash(S);
		}
		puts( !SZ ? "YES":"NO");
	}
}
