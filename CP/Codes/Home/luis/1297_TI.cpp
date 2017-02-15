#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )

#define N 100005
#define MOD1 1000000007
#define MOD2 1000000009
#define B 53

typedef long long ll;

int main(){
	ios_base :: sync_with_stdio( 0 );
	string s , t;
	while( getline( cin , s ) ){
		int n = s.size();
		t = s;
		REP( i , n ) 
			if( isupper( s[ i ] ) ) s[ i ] = 27 + s[ i ] - 'A';
			else s[ i ] = s[ i ] - 'a' + 1;
		int sz = 0 , a , b;
		for( int i = 0 ; i < n ; ++i ){
			ll H1 = 0 , HR1 = 0 , POT1 = 1;
			for( int j = i ; j < n ; ++j ){
				H1 = H1 * B + s[ j ];
				HR1 = POT1 * s[ j ] + HR1;
				POT1 = POT1 * B ;
				if( H1 == HR1 ){
					if( sz < j - i + 1 ) a = i , b = j , sz = j - i + 1;
				}
			}
		}
		cout << t.substr( a , b - a + 1 ) << '\n';
	}
}


