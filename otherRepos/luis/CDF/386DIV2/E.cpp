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
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		vi A(n);
		REP(i,n)scanf("%d",&A[i]);
		
		map<int,int>myMap;
		for(auto x:A)myMap[x]++;
		
		//test();
		int current=m;
		int odd=0,even=0;
		vi O,E;
		for(auto x:myMap){
			current-=x.se-1;
			if(x.fi&1)odd++,O.pb(x.fi);
			else even++,E.pb(x.fi);
		}
		//DEBUG(current);
		if(current<0){
			puts("-1");
			continue;
		}
		while(1){
			if(current==0)break;
			if(odd==even)break;
			current--;
			if(odd>even)odd--;
			else even--;
		}
		int moves=n-(odd+even);
		
	}
}



