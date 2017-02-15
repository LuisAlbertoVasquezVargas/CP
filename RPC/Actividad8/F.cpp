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
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector< ll > vll;
typedef vector< ull > vull;

struct Pollard_Rho
{
	ull q;
	vull v;	
	Pollard_Rho(){}
	Pollard_Rho( ull x ) {
		q = x;
	}
	ull gcd(ull a, ull b){
	    if(b == 0) return a;
	    return gcd( b , a % b );
	}
	ull mul(ull a,ull b,ull c){
	    ull x = 0, y = a % c;
	    while(b > 0){
	        if(b%2 == 1){
	            x = (x+y)%c;
	        }
	        y = (y*2)%c;
	        b /= 2;
	    }
	    return x%c;
	}
	ull modd(ull a,ull b,ull c){
	    ull x=1,y=a; 
	    while(b > 0){
	        if(b%2 == 1){
	            x=mul(x,y,c);
	        }
	        y = mul(y,y,c); 
	        b /= 2;
	    }
	    return x%c;
	}
	bool Miller(ull p,int iteration){
	    if(p<2){
	        return false;
	    }
	    if(p!=2 && p%2==0){
	        return false;
	    }
	    ull s=p-1;
	    while(s%2==0){
	        s/=2;
	    }
	    for(int i=0;i<iteration;i++){
	        ull a=rand()%(p-1)+1,temp=s;
	        ull mod=modd(a,temp,p);
	        while(temp!=p-1 && mod!=1 && mod!=p-1){
	            mod=mul(mod,mod,p);
	            temp *= 2;
	        }
	        if(mod!=p-1 && temp%2==0){
	            return false;
	        }
	    }
	    return true;
	}
	ull rho(ull n){
	    if( n % 2 == 0 ) return 2;
	    ull x = 2 , y = 2 , d = 1;
	    int c = rand() % n + 1;
	    while( d == 1 ){
	        x = (mul( x , x , n ) + c)%n;
	        y = (mul( y , y , n ) + c)%n;
	        y = (mul( y , y , n ) + c)%n;
	        if( x - y >= 0 ) d = gcd( x - y , n );
	        else d = gcd( y - x , n );
	    }
	    return d;
	}
	void factor(ull n){
	    if (n == 1) return;
	    if( Miller(n , 10) ){
	        if(q != n) v.push_back(n);
	        return;
	    }
	    ull divisor = rho(n);
	    factor(divisor);
	    factor(n/divisor);
	}
	ull f( ull num ){
		if( num == 1 ) return 1;
		v.clear();
		q = num;
		factor( num );
		sort( all(v) );
		if( v.empty() ) return 2;
		map< ll , ll > mapa;
		for( auto x : v ) mapa[ x ] ++;
		ll ans = 1;
		for( auto p : mapa )
			ans *= p.se + 1;
		return ans;
	}
}obj;
int main(){
	ll n;
	while( cin >> n )
		cout << obj.f( n ) << '\n';
}


