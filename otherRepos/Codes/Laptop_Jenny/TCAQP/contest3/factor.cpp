#include<bits/stdc++.h>

using namespace std;

#define clr( t , val ) memset( t , val , sizeof( t ) )

#define all( v ) v.begin() , v.end()
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

#define IT 8



vi primefact( int n ){
	vi ans;
	for( int i = 2 ; i * i <= n ; ++i )
		if( n % i == 0 ){
			while( n % i == 0 ) n /= i , ans.pb( i );			
		}
	if( n > 1 ) ans.pb( n );
	return ans;
}
vi D;


void impr(vi P){
	for(int i=0;i<P.size();i++)
			cout<<P[i]<<" ";
		puts("");
}



void getdiv(int cur,vi &fact,int s,int e){
	if(s==e)D.push_back(cur);	
	else{
		int m;
		for(m =s+1;m<e&&fact[m]==fact[s];m++);
		for(int i=s;i<=m;i++){
			getdiv(cur,fact,m,e);
			cur*=fact[s];
		}
	}
}

vi fact;
int nD;
ll memo[ 1000 ];
ll DP[ 1000 ];
//map<int, ll>memo;
int hash( int n ){ 
	return lower_bound( all( D ) , n ) - D.begin();
}/*
ll f(int n){
	if( binary_search( all( fact ) , n ) ) return 1;
	int HASH = hash( n );
	if( memo[ HASH ] != -1 ) return memo[ HASH ];
	ll ans=0;

	for(int i=0; i < nD;i++){
		if( D[ i ] == 1 ) continue;
		if( D[ i ] >= n ) break;
		if( 1LL * D[ i ] * D[ i ] > n ) break;
		if( n % D[ i ] == 0 ){
			if( D[ i ] * D[ i ] == n ){
				ans += f( D[ i ] ) * f( D[ i ] );
				break;
			}
			else{
				ans += ( ( f( D[ i ] )*f( n/D[ i ] ) )<<1);
			}
		}
	}
	return memo[ HASH ] = ans;
}
*/

int ct=0;

int main(){
	int n;
	while(scanf("%d",&n)==1){
		//memo.clear();
		//clr( memo , -1 );
		
		D.clear();
		fact = primefact(n);
		int nF=fact.size();
		getdiv(1,fact,0,nF);
		sort( all( D ) );
		nD=D.size();
		for( int i = 0 ; i < nD ; ++i ) memo[ i ] = -1;
		sort( all( fact ) );
		int nf = unique( all( fact ) ) - fact.begin();
		fact.resize( nf );
		//impr(D);
		for( int i = 0 ; i < nD ; ++i ){
			int num = D[ i ];
			ll &dev = DP[ i ] = 0;
			if( binary_search( all( fact ) , n ) ) return 1;
			if( D[ i ] == 1 ) continue;

			for( int i = 1 ; i < nD ; ++i ){
				if( D[ i ] == 1 ) continue;
				if( D[ i ] >= num ) break;
				if( D[ i ] >= num/D[ i ] ) break;
				if( n % D[ i ] == 0 ){
					if( D[ i ] * D[ i ] == n ){
						dev += DP[ i ] * DP[ i ];
						break;
					}
					else{
						int d = hash( n /D[ i ] );
						dev += ( ( DP[ i ] * DP[ d ] ) << 1 );
					}
				}
			}
		}
		cout << DP[ nD - 1 ] << '\n';
		//cout << f( n ) << '\n';
	}
}
