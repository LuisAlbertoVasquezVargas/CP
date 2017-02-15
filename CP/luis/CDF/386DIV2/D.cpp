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

string T="GB";
bool solve(int n,int K,int a,int b,int flag){
	for(int G=1;G<=n;++G){
		int G0=(G-1)/2+1;
		int G1=G/2;
		if(G0<=a&&G1<=b){
			if(a<=(ll)G0*K&&b<=(ll)G1*K){
				//DEBUG2(G0,G1);
				//DEBUG2(a,b);
				a-=G0;
				b-=G1;
				vi F(G,1);
				REP(i,G){
					if(!(i&1)){
						int cur=min(a,K-1);
						F[i]+=cur;
						a-=cur;
						REP(k,F[i])cout<<T[flag];
					}else{
						int cur=min(b,K-1);
						F[i]+=cur;
						b-=cur;
						REP(k,F[i])cout<<T[flag^1];
					}
				}
				cout<<'\n';
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,K,a,b;
	while(cin>>n>>K>>a>>b){
		if(solve(n,K,a,b,0))continue;
		if(solve(n,K,b,a,1))continue;
		cout<<"NO\n";
	}
}



