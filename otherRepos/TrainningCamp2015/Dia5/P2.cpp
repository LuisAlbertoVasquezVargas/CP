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


long long P;
set<int>s;
//20
int primes[] = { 2 , 3 , 5 , 7 , 11  , 13  , 17 , 19 , 23 ,  29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 };
void back(int n , int prod , int pos ){
  if( n == 0 ){
  	s.insert( prod );
  	return;
  }
  for( int i = pos ; i < 20 ; ++i )
  	if( primes[ i ] <= n )
		back( n - primes[ i ] , ((ll)prod * primes[ i ])%P , i );  
}

int main(){
  int T , N;
  scanf("%d",&T);
  while( T-- ){
    scanf("%d%lld",&N,&P);
    s.clear();
    for(int i=0; i<=N; ++i)
	  back(N-i,1,0);
    printf("%d\n",s.size());
  }
}
