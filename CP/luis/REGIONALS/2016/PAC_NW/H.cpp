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

string getId(double s,double x, double y,int it=0){
	if(it==35)return "";
	if(x<=s/2.0&&y>=s/2.0)return "2"+getId(s/2.0,x,y-s/2.0,it+1);
	if(x>=s/2.0&&y>=s/2.0)return "3"+getId(s/2.0,x-s/2.0,y-s/2.0,it+1);
	if(x<=s/2.0&&y<=s/2.0)return "1"+getId(s/2.0,y,x,it+1);
	return "4"+getId(s/2,s/2.0-y,s-x,it+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,S;
	while(cin>>n>>S){
		vector<pair<string,string>>myVec;
		REP(i,n){
			int x,y;
			string cad;
			cin>>x>>y>>cad;
			myVec.pb({getId(S,x,y),cad});
		}
		sort(all(myVec));
		for(auto item:myVec)
			cout<<item.se<<'\n';
	}
}




