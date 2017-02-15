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
typedef unsigned long long ull;
typedef vector<ull> vull;
typedef pair< int , int > pii;
typedef vector< int > vi;

const int MAX_N=64;
vull myVec;
void add(string s){
	//DEBUG(s);
	ull ans=0;
	for(auto x:s)
		ans=(ans*2ULL)+(x-'0');
	myVec.pb(ans);
}
int main(){
	for(int N=1;N<=MAX_N;++N)
		for(int M=1;M<=MAX_N;++M){
			string cur=string(N,'1');
			int pos=0;
			add(cur);
			while(SZ(cur)<=MAX_N){
				if(pos==0)cur+=string(M,'0');
				else cur+=string(N,'1');
				if(SZ(cur)<=MAX_N)add(cur);
				pos^=1;
			}
		}
	sort(all(myVec));
	myVec.resize(unique(all(myVec))-myVec.begin());
	//for(auto x:myVec)DEBUG(x);
	ull X,Y;
	while(cin>>X>>Y)
		cout<<upper_bound(all(myVec),Y)-lower_bound(all(myVec),X)<<'\n';
}


