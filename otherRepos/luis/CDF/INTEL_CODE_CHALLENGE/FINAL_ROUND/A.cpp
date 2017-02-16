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

vector<string> days={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
vi months={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool solve(int a,int b){
	REP(start,7){
		REP(k,SZ(months)-1){
			if((start+months[k])%7==a&&(start+months[k+1])%7==b)return 1;
		}
	}
	return 0;
}
int main(){
	for(int k=1;k<SZ(months);++k)months[k]+=months[k-1];
	map<string,int>myMap;
	REP(k,SZ(days))myMap[days[k]]=k;
	string s,t;
	while(cin>>s>>t){
		int a=myMap[s],b=myMap[t];
		cout<<(solve(a,b)?"YES":"NO")<<'\n';
	}
}


