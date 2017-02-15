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

void solve(int n,string &s){
	vi F(256);
	for(auto c:s)
		F[c]++;
	n/=4;
	for(auto c:"ACGT"){
		if(F[c]<=n)continue;
		cout<<"===\n";
		return;
	}
	for(auto c:"ACGT")F[c]=n-F[c];
	for(auto &c:s){
		if(c=='?'){
			for(auto c2:"ACGT")
				if(F[c2]>0){
					F[c2]--;
					c=c2;
					break;
				}
		}
	}
	cout<<s<<'\n';
}
int main(){
	//ios_base::sync_with_stdio(0);
	string s;
	int n;
	while(cin>>n>>s){
		if(n%4){
			cout<<"===\n";
			continue;
		}
		solve(n,s);
	}
}


