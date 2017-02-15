#include <bits/stdc++.h>
using namespace std;
 
#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define clr( t , val ) memset( t , val , sizeof(t) )
 
#define all(v)  v.begin() , v.end()
#define pb push_back
#define SZ( v ) ((int)(v).size())
 
#define mp make_pair
#define fi first
#define se second
 
#define test() cerr << "hola que hace ?" << endl;
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;
 
typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Complex{
	ll a , b;
	Complex(){}
	Complex( ll a , ll b ) : a( a ) , b( b ){}
};
Complex operator + ( const Complex &c1 , const Complex &c2 ){
	return Complex( c1.a + c2.a , c1.b + c2.b );
}
Complex operator * ( const Complex &c1 , const Complex &c2 ){
	return Complex( c1.a * c2.a - c1.b * c2.b , c1.a * c2.b + c1.b * c2.a );
}
int main(){
	ll p;
	 while( cin >> p ){
	 	Complex C( 0 , 0 );
	 	Complex temp( 1 , 0 );
	 	REP( i , 32 ){
	 		if( p & (1LL << i) )
			 	C = C + temp;
			 temp = temp * Complex( -1 , 1 );
		}
		cout << C.a << " " << C.b << '\n';
	 }
}



