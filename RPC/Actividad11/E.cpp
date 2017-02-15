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

#define MOD 1000000007
#define N 100000
#define MAXN 200000
#define LOGN 20

ll inv = 500000004LL;
char a[MAXN],b[MAXN];
char s[MAXN];
int suf[MAXN],lcp[MAXN];
int n;
void counting(int* a,int *b,int *val,int n,int k){
        int* c=new int[1+k];
        memset(c,0,sizeof(int)*(1+k));
        for(int i=0;i<n;++i)c[val[a[i]]]++;
        for(int i=1;i<=k;++i)c[i]+=c[i-1];
        for(int i=n-1;i>=0;--i)b[--c[val[a[i]]]]=a[i];
        delete[] c;
}
 
void suffix(int* val,int* suf,int n,int k){
        val[n]=val[n+1]=val[n+2]=0;
        int n0=(n+2)/3,n2=n/3,n02=n0+n2;
        int *val12=new int[n02+3];
        int *suf12=new int[n02+3];
        for(int i=0,j=0;i<n+(n%3==1);++i)if(i%3)val12[j++]=i;
        counting(val12,suf12,val+2,n02,k);
        counting(suf12,val12,val+1,n02,k);
        counting(val12,suf12,val,n02,k);
        int a=-1,b=-1,c=-1,ct=0;
        for(int i=0;i<n02;++i){
                int ind=suf12[i];
                if(val[ind]!=a or val[ind+1]!=b or val[ind+2]!=c)++ct;
                val12[(ind%3==1)?ind/3:ind/3+n0]=ct;
                a=val[ind],b=val[ind+1],c=val[ind+2];
        }
        if(ct==n02){
                val12[n02]=0;
                for(int i=0;i<n02;++i){
                        suf12[val12[i]-1]=i;
                }
        }
        else{
                suffix(val12,suf12,n02,ct);
                for(int i=0;i<n02;++i){
                        int ind=suf12[i];
                        val12[ind]=i+1;
                }
        }
        int *val0=new int[n0];
        int *suf0=new int[n0];
        for(int i=0,j=0;i<n02;++i){
                int ind=suf12[i];
                if(ind<n0)val0[j++]=ind*3;
        }
        counting(val0,suf0,val,n0,k);
        a=0,b=(n%3==1),c=0;
        #define comp1(a1,b1,a2,b2) (((a1)!=(a2))?((a1)<(a2)):((b1)<(b2)))
        #define comp2(a1,b1,c1,a2,b2,c2) (((a1)!=(a2))?((a1)<(a2)):(((b1)!=(b2))?((b1)<(b2)):((c1)<(c2))))
        #define get(i) ((i)<n0?(3*i+1):(3*(i-n0)+2))
        while(a<n0&&b<n02){
                int ind0=suf0[a],ind12=get(suf12[b]);
                if(ind12%3==1?comp1(val[ind0],val12[ind0/3],val[ind12],val12[suf12[b]+n0]):
                comp2(val[ind0],val[ind0+1],val12[ind0/3+n0],val[ind12],val[ind12+1],val12[suf12[b]-n0+1]))suf[c++]=ind0,a++;
                else suf[c++]=ind12,b++;
        }
        while(a<n0)suf[c++]=suf0[a++];
        while(b<n02)suf[c++]=get(suf12[b]),b++;
        delete [] val12; delete [] suf12; delete [] val0; delete [] suf0;
}
void lcp1(int *lcp,int *pos,int n){
     int *rank = new int[n+3];
     for(int i=0;i<n;++i)rank[pos[i]]=i;
     	int h=0;
     	for(int i=0;i<n;++i)if(rank[i]){
     		int j=pos[rank[i]-1];
     		while(s[i+h]==s[j+h])++h;
     		lcp[rank[i]-1]=h;
     		if(h)h--;
     	}
     lcp[n-1] = 0;
     delete [] rank;
} 
void _suffix(){
        int *val=new int[n+3];
        for(int i=0;i<n;++i)val[i]=s[i];
        suffix(val,suf,n,127);     
} 
void _lcp(){
     lcp1(lcp,suf,n);
}
int rmq[ LOGN + 1 ][ N + 5 ];
void RMQ(){
	REP( i , n ) rmq[ 0 ][ i ] = lcp[ i ];
	for( int k = 1 ; k <= LOGN ; ++k )
		for( int i = 0 ; i + (1<<k) <= n ; ++i )
			rmq[ k ][ i ] = min( rmq[ k - 1 ][ i ] , rmq[ k - 1 ][ i + (1<<(k-1)) ] );
}
int query( int i , int j ){
	int r = 31 - __builtin_clz( j - i + 1 );
	return min( rmq[ r ][ i ] , rmq[ r ][ j - ( 1 << r ) + 1 ] );
}
ll L[ N + 5 ] , AC[ N + 5 ];
int LCP( int i , int j ){
	return query( i , j - 1 );
}

//i , n - 1
int search( int a , int b , int target ){
	int lo = a , hi = b;
	if( LCP( a - 1 , b ) > target ) return hi;
	if( LCP( a - 1 , a ) <= target ) return -1;
	while( hi - lo > 1 ){
		int med = (lo + hi) >>1;
		if( LCP( a - 1 , med ) > target ) lo = med;
		else hi = med;
	}
	return lo;
}
ll gett( int lo , int hi ){
	if( lo > hi ) return 0;
	ll ans = AC[ hi + 1 ] - AC[ lo ];
	if( ans < 0 ) ans += MOD;
	return ans;
}
ll comb2( ll n ){
	ll ans = (n * (n - 1)) % MOD;
	ans = (ans * inv)%MOD;
	return ans;
}
ll solve( int K ){       
    _suffix();
    _lcp();
	RMQ();
	ll ans = 0;
	for( int L = 1 ; L <= n ; ++L ){
		if( L <= K ) ans = (ans + comb2( L ))%MOD;
		else ans = (ans + (ll) K * L - comb2( K + 1 ))%MOD;
		if( ans < 0 ) ans += MOD;
	}
	REP( i , n ) L[ i ] = n - suf[ i ];
	REP( i , n ) {
		AC[ i + 1 ] = AC[ i ] + L[ i ];
		if( AC[ i + 1 ] >= MOD ) AC[ i + 1 ] -= MOD;
	}
	REP( i , n - 1 ){
		int pos = search( i + 1 , n - 1 , K );
		if( pos == -1 ){
			ans = (ans + (ll) L[ i ] * gett( i + 1 , n - 1 ))%MOD;
			if( ans >= MOD ) ans -= MOD;
		}else{
			ans = (ans + (ll) L[ i ] * gett( pos + 1 , n - 1 ))%MOD;
			if( ans >= MOD ) ans -= MOD;
			ll l = (pos - i);
			ans = (ans + l * ((ll)L[ i ] * K - K * K) + (ll) K * gett( i + 1 , pos ))%MOD;
			if( ans >= MOD ) ans -= MOD;
		}
	}
	return ans;
}

int main(){
	int cases;
	sc( cases );
	REP( tc , cases ){
		int K;
		scanf( "%s%d" , s , &K );
		n = strlen( s );
		ll p = comb2( n + 1 );
		ll ans = (comb2( p ) - solve( K - 1 ))%MOD;
		if( ans < 0 ) ans += MOD;
		printf( "Case #%d: %d\n" , tc + 1 , (int)ans );
	}
}


