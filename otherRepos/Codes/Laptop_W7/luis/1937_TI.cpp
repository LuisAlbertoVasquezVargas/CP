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
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
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

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;


#define SIZE 2
#define B 27

ll Mod[ SIZE ] = { 1000000007 , 1000000009 };
ll Inv[ SIZE ] = { 370370373 , 296296299 } ; // = { mod_inv( B , Mod[0]) , mod_inv( B , Mod[1] ) };
int Map( char c ){ return c - 'a' + 1; }

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
bool operator == ( Hash hash1 , Hash hash2 ){ 
	for( int k = 0 ; k < SIZE ; ++k )
		if( hash1.H[k] != hash2.H[k] )return 0;
	return 1;
}
bool operator < ( Hash hash1 , Hash hash2 ){ 
	for( int k = 0 ; k < SIZE ; ++k )
		if( hash1.H[k] != hash2.H[k] )return hash1.H[k] < hash2.H[k];
	return 0;
}

int main()
{
	sync
	string s , t;
	while( cin >> s >> t )
	{
		int nt = t.size() , ns = s.size() ;
		Hash HH[ns][2];
		string u = s.substr( 0 , nt ) , h = s.substr( nt );
		HH[0][0] = Hash( u ) , HH[0][1] = Hash( h );
		Hash temp[2];
		for( int i = 0 ; i + 1 < ns ; ++i )
		{
			temp[0] = HH[i][0];
			temp[1] = HH[i][1];
			temp[0].del_L( Map(s[i]) );
			temp[0].add_R( Map(s[(i+nt)%ns]) );
			temp[1].del_L( Map(s[(i+nt)%ns]) );
			temp[1].add_R( Map(s[i]) );			
			HH[i+1][0] = temp[0];
			HH[i+1][1] = temp[1];
		}
		vector< pair< pll , int > >v( nt );
		Hash Temp = Hash( t );
		v[0] = mp( mp( Temp.H[0] , Temp.H[1] ) , 0 );
		for( int i = 1 ; i < nt ; ++i )
		{
			Temp.del_L( Map(t[i-1]) );
			Temp.add_R( Map(t[i-1]) );
			v[i] = mp( mp( Temp.H[0] , Temp.H[1] ) , i );
		}
		sort( all( v ) );
		vector< pll > V( nt );
		for( int i = 0 ; i < nt ; ++i )V[i] = v[i].fi;
		bool solve = 0;
		int p , q ;
		for( int i = 0 ; i < ns ; ++i )
			if( HH[i][1].H[0] == HH[i][1].HR[0] && HH[i][1].H[1] == HH[i][1].HR[1] )
			{
				pll key = mp( HH[i][0].HR[0] , HH[i][0].HR[1] );
				if( binary_search( all(V) , key ) )
				{
					int Ind = lower_bound( all(V) , key ) - V.begin();
					solve = 1;
					p = i ; q = v[Ind].se;
					break;
				}
			}
		if( solve )cout << "Yes\n" << ++p << " " << ++q << "\n";
		else cout << "No\n";
	}
}
