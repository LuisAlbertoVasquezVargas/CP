#include<bits/stdc++.h>
#define INF 1000000000000
using namespace std;

#define REP( i , n ) for( int i = 0 ; i < n ; ++i )
#define sc( x ) scanf( "%d" , &x )

#define pb push_back
#define all( v ) v.begin() , v.end()

typedef long long ll;
typedef vector< ll > vll;
set<ll> S;
int sz;

vll L;
void dfs( ll n ){
	if( n > 1e12 ) return;
	if( n > 1 ){
		L.pb( n );
	}
	dfs( n*10 + 4 );
	dfs( n*10 + 7 );
}


/*void back(ll prod){
	//S.insert(prod);
	set<ll>:: iterator it= S.lower_bound(prod);
	//cout<<"valor: "<<*it<<endl;
	for( it=S.begin();it!=S.end();++it){
		ll val=prod* (*it);
		//cout<<val<<endl;
		long double a=prod, b=(*it);
		if(a*b>1e12)break;
		if(val>=0 && val<=INF){
			S.insert(val);
			back(val);
			
		}
		else break;
	}
}*/

void back(ll prod){
	if(S.count(prod))return ;
	if(prod!=1)S.insert(prod);
	for(int i=0;i<sz;++i){
		long double a=prod, b=L[i];
		if(a*b>1e12)break;
		ll val=prod*L[i];
		if(val>=0 && val<=INF){
			back(val);
		}
		else break;
	}
}






int main()
{
	dfs( 4 );
	dfs( 7 );
	sort( all( L ) );
	L.resize( unique( all( L ) ) - L.begin() );
	sz=L.size();
	back(1);
	vector<ll>v(all(S));
	int nL=v.size();
	/*for(int i=0;i<v.size();++i){
		cout<<"pos: "<<v[i]<<endl;
	}*/
	int cases;
	cin >> cases;
	ll A , B;	
	while( cases -- ){
		cin >> A >> B;
		//cout<<A<<" "<<B<<endl;
		ll ans = 0;
		cout<<(upper_bound(all(v),B) -lower_bound(all(v),A))<<endl;
	}
}
