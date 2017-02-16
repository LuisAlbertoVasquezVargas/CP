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
#define DEBUG3( x , y,z ) cerr << #x << "=" << x << " " << #y << "=" << y << " "<< #z << "=" << z <<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;
typedef vector<pii> vpii;

const int M=6;
int A[M];
struct item{
	int lo,hi,ind;
	item(){}
	item(int lo,int hi,int ind):lo(lo),hi(hi),ind(ind){}
};

bool operator <(const item a,const item b){
	if(a.lo!=b.lo)return a.lo<b.lo;
	return a.hi<b.hi;
}
int main(){
	ios_base::sync_with_stdio(0);
	map<string,int>myMap;
	vector<string> mySizes={"S", "M", "L", "XL", "XXL", "XXXL"};
	int id=0;
	for(auto cad:mySizes)
		myMap[cad]=id++;
	while(cin>>A[0]){
		REP(i,M){
			if(!i)continue;
			cin>>A[i];
		}
		int n;
		cin>>n;
		vector<item> v;
		REP(i,n){
			string s;
			cin>>s;
			int lo,hi;
			if(myMap.count(s)){
				lo=hi=myMap[s];
				v.pb(item(lo,hi,i));
			}else{
				for(auto &x:s)
					if(x==',')x=' ';
				istringstream in(s);
				string t;
				in>>s>>t;
				lo=myMap[s];
				hi=myMap[t];
				if(lo>hi)swap(lo,hi);
				v.pb(item(lo,hi,i));
			}
		}
		sort(all(v));
		bool ok=1;
		vi sol(n);
		for(auto x:v){
			//DEBUG3(x.lo,x.hi,x.ind);
			if(x.lo==x.hi){
				if(A[x.lo]){
					A[x.lo]--;
					sol[x.ind]=x.lo;
				}else{
					ok=0;
					break;
				}
			}else{
				if(A[x.lo]){
					A[x.lo]--;
					sol[x.ind]=x.lo;
				}else{
					if(A[x.hi]){
						A[x.hi]--;
						sol[x.ind]=x.hi;
					}else{
						ok=0;
						break;
					}
				}
			}
		}
		if(!ok){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		REP(i,n)cout<<mySizes[sol[i]]<<'\n';
	}
}

