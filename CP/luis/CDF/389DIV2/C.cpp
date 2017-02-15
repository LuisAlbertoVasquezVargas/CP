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

int dist(pii p,pii q){
	return abs(p.fi-q.fi)+abs(p.se-q.se);
}
string cad="LRUD";
vi dx={-1,1,0,0};
vi dy={0,0,1,-1};
int main(){
	ios_base::sync_with_stdio(0);
	vi myMap(256);
	REP(i,4)myMap[cad[i]]=i;
	int n;
	string s;
	while(cin>>n>>s){
		pii last(0,0),P(0,0),nP(0,0);
		int ans=1;
		REP(i,n){
			int dir=myMap[s[i]];
			nP={P.fi+dx[dir],P.se+dy[dir]};
			if(dist(last,nP)==1+dist(last,P)){
				P=nP;
			}else{
				last=P;
				P=nP;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}



