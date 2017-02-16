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

int main(){
	string s;
	while(cin>>s){
		int n=SZ(s);
		vi myMap(256,-1),cnt(256,0);
		REP(i,n)
			if(s[i]!='!')
				myMap[i%4]=s[i];
		
		REP(i,n)
			if(s[i]=='!')
				cnt[myMap[i%4]]++;
		string cad="RBYG";
		REP(k,4)
			cout<<cnt[cad[k]]<<' ';
		cout<<'\n';
	}
}

