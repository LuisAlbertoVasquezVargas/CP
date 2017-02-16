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
#define DEBUG( x ) cerr <<  #x << "=" << x << endl;
#define DEBUG2( x , y ) cerr << #x << "=" << x << " " << #y << "=" << y << endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

int main(){
	vi v(3),w(v);
	while(cin>>v[0]){
		REP(i,3){
			if(i==0)continue;
			cin>>v[i];
		}
		REP(i,3){
			cin>>w[i];
		}
		sort(all(v));
		sort(all(w));
		
		if(v!=w){
			cout<<"NO\n";
			continue;
		}
		if(v[0]*v[0]+v[1]*v[1]!=v[2]*v[2]){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
}


