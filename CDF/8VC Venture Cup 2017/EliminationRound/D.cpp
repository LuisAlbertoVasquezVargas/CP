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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

#define MAXVAL 2000000

int bit[ MAXVAL + 5 ];
void upd( int pos , int val ){
	while( pos <= MAXVAL ){
		bit[ pos ] += val;
		pos += (pos & -pos); 
	}
}
void update( int pos , int val ){
	upd( pos + 1 , val );
}
int qry( int pos ){
	int sum = 0;
	while( pos ){
		sum += bit[ pos ];
		pos -= ( pos & -pos );
	}
	return sum;
}
int Query( int pos ){ return qry( pos + 1 ); }
int fix(int x,int mod){
	if(x>=mod)x-=mod;
	return x;
}
int get(int a,int b){
//	if(a>b)swap(a,b);
	return Query(b)-Query(a-1);
}
int main(){
	int n,K;
	while(scanf("%d%d",&n,&K)==2){
		clr(bit,0);
		ll ans=1;
		int cur=0;
		REP(i,n){
			ans+=1+get(cur+1,cur+K-1);
			int a=cur;
			int b=cur+K;
			//DEBUG2(a,b);
			update(a,+1);
			update(b,+1);
			if(b+n<2*n){
				update(a+n,+1);
				update(b+n,+1);
			}
			cur=b%n;		
			printf("%lld%c",ans,i+1==n?10:32);
		}
	}
}



