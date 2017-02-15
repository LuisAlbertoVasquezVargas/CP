###################################################################
################# MATH - NUMBER THEORY #######################################
###################################################################

########################## FAST EXPONENTIATION ##################################
// Simple version O( log(n) ) - iterative
// UVA 374 - Big Mod
// agregar version recursiva
ll pow( ll a , ll b , ll c ){
    ll ans = 1;	
    while( b ){
        if( b&1 ) ans = ( ans * a )%c;
        a = ( a*a )%c;
        b >>= 1;
    }	
    return ans;
}
// Inverse modular de t es pow( t ,MOD - 2 ,  MOD )
// http://chococontest.wordpress.com/category/inverso-modular/

ll mod_inv( ll numa , ll mod ){	return pow( numa , mod - 2 , mod );	}

// A^B mod C Problem  (1<=A,B,C<2^63). 1752_FZU
// a += b   %c
void fix( ull &a , ull b , ull c ){
	a += b;
	if( a >= c ) a -= c;
}
ull prod( ull a , ull b , ull c ){
	a %= c;
	ull ans = 0;
	while( b ){
		if( b & 1 ) fix( ans , a , c );
		a <<= 1;
		if( a >= c ) a -= c;
		b >>= 1;
	} 
	return ans;
}
ull pow( ull a , ull b , ull c ){
	ull ans = 1;
	while( b ){
		if( b & 1 ) ans = prod( ans , a , c );
		a = prod( a  , a , c  );
		b >>= 1;
	}
	return ans;
}

#-----------------------------------------------------------------#
######################### PRIMALITY TEST ##################################

//	Simple - Deterministic ( O( sqrt(num) ) )
// UVA 10924 - Prime Words ... cuidado considera primo el 1 (buscar otro probl)
bool isPrime( int n ){
	if( n == 1 ) return 0;
	for( int i = 2 ; i * i <= n ; ++ i )
		if( n%i == 0 )return 0;
	return 1;
}
bool isPrime( int n )
{
	if( n <= 2 ) return n == 2;
	if( !( n&1 ) ) return 0;
	for( int i = 3 ; i*i <= n ; i += 2 )
		if( n%i == 0 ) return 0;
	return 1;
}

####################### Miller-Rabin ####################################

// Prime Gap http://en.wikipedia.org/wiki/Prime_gap  O( ln(n)^2 )
// By Chen : Test de primalidad para numeros grandes O(it*log(n)^3)

////////// Version 1 para n <= 10^9

int pow( int a , int b , int c ){
    int ans = 1;	
    while( b ){
        if( b&1 ) ans = ( 1LL*ans * a )%c;
        a = ( 1LL*a*a )%c;
        b >>= 1;
    }	
    return ans;
}
bool miller(ll p, int it = 10){
	if(p < 2) return 0;
	if(p != 2 && (p & 1) == 0) return 0;
	int s = p - 1;
	while( (s & 1) == 0) s >>= 1;
	while( it-- ){
		int a = rand() % (p - 1) + 1, temp = s;
		int mod = pow(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = ( 1LL* mod*mod )%p;
			temp <<= 1;
		}
		if(mod != p - 1 && (temp & 1) == 0) return 0;
	}
	return 1;
}
///// Version 2 con multiplicaciones eficientes( falta analizar ^^ )

ll mulmod(ll a, ll b, ll c){
	ll x = 0, y = a % c;
	while(b > 0){
		if(b & 1){
			x += y;
			if(x >= c) x -= c;
		}
		y = y + y;
		if(y >= c) y -= c;
		b >>= 1;
	}
	return x % c;
}
ll modulo(ll a, ll b, ll c){
	ll x = 1, y = a;
	while(b){
		if(b & 1) x = mulmod(x, y, c);
		y = mulmod(y, y, c);
		b >>= 1;
	}
	return x % c;
}
bool miller(ll p, int it = 20){
	if(p < 2) return 0;
	if(p != 2 && (p & 1) == 0) return 0;
	ll s = p - 1;
	while( (s & 1) == 0) s >>= 1;
	while( it-- ){
		ll a = rand() % (p - 1) + 1, temp = s;
		ll mod = modulo(a, temp, p);
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = mulmod(mod, mod, p);
			temp <<= 1;
		}
		if(mod != p - 1 && temp % 2 == 0) return 0;
	}
	return 1;
}
################## SIEVE O(nlglgn) #########################################
//replace this implementation with bitset and factoring primes i dont know :P
#define MAXN 100000

bool prime[MAXN + 1];

void sieve()
{
	memset( prime , true , sizeof( prime ) );
	prime[ 0 ] = false;
	prime[ 1 ] = false;
	for( int i = 2 ; i * i <= MAXN ; i++ )
		if( prime[ i ] )
			for( int j = i * i ; j <= MAXN ; j += i )
				prime[ j ] = false;
}

//http://apps.topcoder.com/forums/?module=Thread&threadID=594206&start=0&mc=25
//generate all divisors
p is an array of primes
e is the exponent on each of those primes
k is the number of elements in p and e

Basically the idea is to calculate all the previous divisors * p, then use those values to calculate all previous divisors * p^2, etc... I could just keep track of p[i]^j but this way ends up being a bit shorter/cleaner.
//////////////////////////////

int P[ N + 5 ];
void sieve(){
	clr( P , -1 );
	P[ 0 ] = P[ 1 ] = 0;
	for( int i = 2 ; i * i <= N ; ++i )
		if( P[ i ] == -1 )
			for( int j = i * i ; j <= N ; j += i ) P[ j ] = i;
}
void primefact( int n , vi &pr , vi &ex ){
	while( 1 ){
		int p = P[ n ];
		if( n == 1 ){
			return;
		}
		if( p == -1 ){
			pr.pb( n ) , ex.pb( 1 );
			break;
		}
		int exp = 0 ;
		while( n % p == 0 ) {
			exp ++;
			n /= p;
		}
		pr.pb( p ) , ex.pb( exp );
	}
}

vi getAllDivisors( vi pr , vi ex ){
	int k = pr.size();
	vi divisors( 1 , 1 );

	REP( i , k ){
		int m = divisors.size();
		REP( j , ex[ i ] )
			REP( a , m ) divisors.pb( pr[ i ] * divisors[ a + j * m ] );
	}
	return divisors;
}

