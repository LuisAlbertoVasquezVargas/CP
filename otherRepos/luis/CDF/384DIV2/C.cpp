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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

//const int N=1200;
const int N=15000;
void solve(int n){
	for(int x=1;x<=N;++x)
		for(int y=x+1;y<=N;++y){
			if((2*x*y)%n==0){
				int den=((2*x*y)/n-(x+y));
				if(den&&(x*y)%den==0){
					int z=(x*y)/den;
					if(y<z){
						cout<<x<<" "<<y<<" "<<z<<'\n';
						return;
					}
				}
			}
		}
	cout<<-1<<'\n';
}
int main(){
	/*
	for(int x=1;x<=N;++x)
		for(int y=x+1;y<=N;++y)
			for(int z=y+1;z<=N;++z)
				if(x*y+x*z+y*z==2*x*y*z){
					cout<<x<<" "<<y<<" "<<z<<'\n';
				}
	*/
	/*
	for(int x=1;x<=N;++x)
		for(int y=x+1;y<=N;++y){
			if((x*y)%(2LL*x*y-(x+y))==0){
				ll z=((ll)x*y)/(2LL*x*y-(x+y));
				DEBUG((2LL*x*y-(x+y)));
				cout<<x<<" "<<y<<" "<<z<<'\n';
			}
		}
	*/
	int n;
	while(cin>>n)
		solve(n);
}


