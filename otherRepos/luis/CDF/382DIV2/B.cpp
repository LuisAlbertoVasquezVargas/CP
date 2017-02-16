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
typedef long double ld;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	int n,n1,n2;
	while(scanf("%d%d%d",&n,&n1,&n2)==3){
		priority_queue<int>Q;
		REP(i,n){
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		if(n1>n2)swap(n1,n2);
		ld sum=0;
		for(auto len:{n1,n2}){
			REP(k,len){
				sum+=Q.top()/(double)len;
				Q.pop();
			}
		}
		printf("%.15f\n",(double)sum);
	}
}



