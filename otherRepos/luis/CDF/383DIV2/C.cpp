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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int getNext(int tries,int x,vi &A){
	int y=x;
	REP(k,tries)
		y=A[y];
	return y;
}
bool possible(int tries,vi &A,int n){
	REP(x,n){
		int y=getNext(tries,x,A);
		if(getNext(tries,y,A)==x)continue;
		return 0;
	}
	return 1;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]),A[i]--;
		int ans=-1;
		REP(k,){
			if(possible(k+1,A,n)){
				ans=k+1;
				break;
			}
		}
		printf("%d\n",ans);
	}
}


