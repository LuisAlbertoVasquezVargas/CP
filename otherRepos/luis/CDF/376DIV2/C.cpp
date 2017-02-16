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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isOn(int mask,int bit){
	return mask&(1<<bit);
}
int main(){
	ll a[3];
	while(cin>>a[0]){
		REP(i,3){
			if(!i)continue;
			cin>>a[i];
		}
		ll mini=LLONG_MAX;
		for(auto m1:{0,4,6})
			for(auto m2:{0,1,3}){
				ll Y=LLONG_MIN;
				REP(k,3)
					Y=max(Y,a[k]+isOn(m1,k)+isOn(m2,k));
				ll S=0;
				REP(k,3)
					S+=Y-isOn(m1,k)-isOn(m2,k)-a[k];
				mini=min(mini,S);
			}
		cout<<mini<<'\n';
	}
}



