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

bool f(string s,int n,int posG,int posT,int dir){
	while(1){
		if(posG==posT)return 1;
		if(!(posG>=0&&posG<n))break;
		if(s[posG]=='#')break;
		posG+=dir;
	}
	return 0;
}
int main(){
	int n,K;
	while(cin>>n>>K){
		string s;
		cin>>s;
		int posG=s.find('G');
		int posT=s.find('T');
		int gap;
		if(posG<posT)gap=K;
		else gap=-K;
		
		puts(f(s,n,posG,posT,gap)?"YES":"NO");
	}
}



