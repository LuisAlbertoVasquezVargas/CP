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

int main(){
	int n;
	while(scanf("%d",&n)==1){
		int best=INT_MAX;
		int A,B;
		for(int a=1;a<=n;++a){
			if(n%a==0){
				int b=n/a;
				if(a<=b){
					if(b-a<best){
						best=b-a;
						A=a;
						B=b;
					}
				}
			}
		}
		printf("%d %d\n",A,B);
	}
}


