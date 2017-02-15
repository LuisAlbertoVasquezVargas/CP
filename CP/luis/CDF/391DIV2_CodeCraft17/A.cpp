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

vi get(string s){
	vi T(256);
	for(auto c:s)T[c]++;
	return T;
}
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	while(cin>>s){
		vi a=get(s);
		vi b=get("Bulbasaur");
		int ans=INT_MAX;
		REP(i,256){
			if(!b[i])continue;
			ans=min(ans,a[i]/b[i]);
		}
		cout<<ans<<'\n';
	}
}


