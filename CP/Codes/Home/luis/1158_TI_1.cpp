#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d\n" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define MAXNODES 100
#define ALP 256
#define N 50

typedef unsigned char tint;

int next[ MAXNODES + 5 ][ ALP + 1 ],  term[ MAXNODES + 5 ] , T[ MAXNODES + 5 ];
int nAlp , n , nodes;
string alp;
void init(){
	nodes = 1;
	clr( next , 0 );
	clr( term , 0 );
}
void add( string &s ){
	int ns = s.size() , p = 0;
	REP( i , ns ){
		tint c = s[ i ];
		if( next[ p ][ c ] ) p = next[ p ][ c ];
		else p = next[ p ][ c ] = nodes ++;
	}
	term[ p ] = 1;
}
void aho(){
	queue< int > Q;
	REP( i , nAlp ){
		tint c = alp[ i ];
		int u = next[ 0 ][ c ];
		if( u ) T[ u ] = 0 , Q.push( u );
	}
	while( !Q.empty() ){
		int u = Q.front() ; Q.pop();
		REP( i , nAlp ){
			tint c = alp[ i ];
			int v = next[ u ][ c ] , x = next[ T[ u ] ][ c ];
			if( v == 0 ) next[ u ][ c ] = x;
			else Q.push( v ) , T[ v ] = x , term[ v ] |= term[ T[ v ] ];
		}
	}
}

string suma(string a,  string b)  
{  
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0; 
    string x = string(L, '0');  
    while(L--) 
    { 
        LA--; LB--; 
        if(LA >= 0) carry += a[LA] - '0';  
        if(LB >= 0) carry += b[LB] - '0';      
        if(carry < 10) x[L] = '0' + carry, carry = 0; 
        else x[L] = '0' + carry - 10, carry = 1; 
    } 
    if(carry) x = '1' + x;  
    return x; 
}

bool used[ N + 5 ][ MAXNODES + 5 ];
string memo[ N + 5 ][ MAXNODES + 5 ];
string dp( int pos , int u ){
	if( pos == n ) return "1";
	if( used[ pos ][ u ] ) return memo[ pos ][ u ];
	used[ pos ][ u ] = 1;
	string &dev = memo[ pos ][ u ] = "0";
	REP( i , nAlp ){
		tint c = alp[ i ];
		int v = next[ u ][ c ];
		if( !term[ v ] ) dev = suma( dev , dp( pos + 1 , v ) );
	}
	return dev;
}
int main(){
	ios_base :: sync_with_stdio( 0 );
	string s;
	int dic;
	while( cin >> nAlp >> n >> dic ){
		init();
		cin >> alp;
		REP( i , dic ){
			cin >> s;
			add( s );
		}
		aho();
		clr( used , 0 );
		cout << dp( 0 , 0 ) << '\n';
	}
}
