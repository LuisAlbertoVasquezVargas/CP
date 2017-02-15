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

bool f(vi &v,int target){
	multiset<int>mySet(all(v));
	while(!mySet.empty()){
		auto first=mySet.begin();
		//DEBUG(*first);
		mySet.erase(first);
		
		auto second=mySet.lower_bound(target-*first);
		if(second==mySet.end())return 0;
		mySet.erase(second);
	}
	return 1;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		vi v(n);
		REP(i,n)scanf("%d",&v[i]);
		int lo=0,hi=2000000+1;
		while(hi-lo>1){
			int med=(lo+hi)>>1;
			if(f(v,med))lo=med;
			else hi=med;
		}
		printf("%d\n",lo);
	}
}



