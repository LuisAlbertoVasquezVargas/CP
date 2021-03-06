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

int getPosMedian(int n){
	if(n&1)return n/2;
	return n/2-1;
}
int main(){
	int n;
	string s;
	while(cin>>n>>s){
		vi index(n);
		REP(i,n)index[i]=i;
		vi newIndex;
		REP(i,n){
			int pos=getPosMedian(SZ(index));
			//DEBUG(pos);
			newIndex.pb(index[pos]);
			index.erase(index.begin()+pos);
		}
		//test();
		string ans(n,'*');
		REP(i,n)ans[newIndex[i]]=s[i];
		cout<<ans<<'\n';
	}
}



