#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()

#define N 100000
#define MOD 1000000009
#define IT 10

typedef long long ll;

bool P[ N + 5 ];
int Prime[] = { 99401 , 99409 , 99431 , 99439 , 99469 , 99487 , 99497 , 99523 , 99527 , 99529 , 99551 , 99559 , 99563 , 99571 , 99577 , 99581 , 99607 , 99611 , 99623 , 99643 , 99661 , 99667 , 99679 , 99689 , 99707 , 99709 , 99713 , 99719 , 99721 , 99733 , 99761 , 99767 , 99787 , 99793 , 99809 , 99817 , 99823 , 99829 , 99833 , 99839 , 99859 , 99871 , 99877 , 99881 , 99901 , 99907 , 99923 , 99929 , 99961 , 99971 , 99989 , 99991 };
//{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
string fix( string &s ){
	transform( all( s ) , s.begin() , :: tolower );
	string t;
	int ns = s.size();
	REP( i , ns ) if( s[ i ] != ' ' ) t.pb( s[ i ] );
	return t;
}
string S;
ll f( int a , int b ){
	int cntL = 0 , cntR = 0;
	for( int i = b ; i >= a ; --i ){
		if( S[ i ] == '(' ) cntL ++;
		if( S[ i ] == ')' ) cntR ++;
		char c = S[ i ];
		if( cntL == cntR ){
			ll val1 = f( a , i - 1 ) , val2 = f( i + 1 , b );
			if( c == '*' ) return ( val1 * val2 )%MOD;
			if( c == '+' ) return ( val1 + val2 )%MOD;
			if( c == '-' ) return ( val1 - val2 + MOD ) %MOD;
		}
	}
	if( S[ a ] == '(' ) return f( a + 1 , b - 1 );
	if( isdigit( S[ a ] ) ) return S[ a ] - '0';
	return Prime[ S[ a ] - 'a' ];
}
ll eval( string &s ){
	int ns = s.size();
	S = s;
	return f( 0 , ns - 1 );
}

int main()
{
	/*clr( P , 1 );
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] ) for( int j = i * i ; j <= N ; j += i ) P[ j ] = 0;
	for( int i = 99400 ; i <= N  ; ++i )
		if( P[ i ] ) cout << i << " , " ;
	*/
	int cases;
	cin >> cases;
	string dummy ,s , t;
	getline( cin , dummy );
	while( cases -- )
	{
		getline( cin , s );
		getline( cin , t );
		s = fix( s ) , t = fix( t );
		/*cout << "FIXED " << endl;
		cout << s << " " << t << endl;*/
		bool solve = 1;
		REP( it , IT ){
			random_shuffle( Prime , Prime + 26 );
			ll val1 = eval( s ) , val2 = eval( t );
			/*cout << "iteration : " << it << endl;
			cout << val1 << " " << val2 << endl;*/
			if( val1 != val2 ) solve = 0;
		}
		puts( solve ? "YES" : "NO" );
	}
}
