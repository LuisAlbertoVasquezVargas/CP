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

#define test() cerr<<"hola que hace ?" << endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

ll get(string s,string p,string t){
	ll ans=0;
	map<int,int>myMap;
	for(auto c:p)myMap[c]=0;
	for(auto c:t)myMap[c]=1;
	//reverse(all(s));
	for(auto x:s)
		ans=ans*2LL+myMap[x];
	return ans;
}
int main(){
	string s;
	while(cin>>s){
		ll y=get(s,"01","23");
		ll x=get(s,"02","13");
		cout<<SZ(s)<<" "<<x<<" "<<y<<'\n';
	}
}



