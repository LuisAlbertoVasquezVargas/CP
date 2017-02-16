#include<bits/stdc++.h>
using namespace std;
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
	int start,target;
	while(cin >> start >> target){
		vi vec;
		bool found=0;
		while(target>=start){
			vec.pb(target);
			if(target==start){
				found=1;
				break;
			}
			if(!(target&1)){
				target>>=1;
			}else{
				target--;
				if(target%10)break;
				target/=10;
			}
		}
		if(!found){
			cout<<"NO\n";
			continue;
		}
		reverse(all(vec));
		cout<<"YES\n";
		cout<<SZ(vec)<<'\n';
		REP(i,SZ(vec))cout<<vec[i]<<char(i+1==SZ(vec)?10:32);
	}
}

