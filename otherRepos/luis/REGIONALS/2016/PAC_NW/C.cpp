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

const int MAX_LEN=52;
map<string,int>myMap;
void process(string s,vi &v,string &name){
	istringstream in(s);
	in>>name;
	name.pop_back();
	vi ans(MAX_LEN,+1);
	int pos=0;
	string cad;
	while(in>>cad){
		if(cad=="class")continue;
		//DEBUG(cad);
		ans[pos++]=myMap[cad];
	}
	//DEBUG("");
	reverse(ans.begin(),ans.begin()+pos);
	v=ans;
}
int main(){
	myMap["upper"]=0;
	myMap["middle"]=1;
	myMap["lower"]=2;
	int n;
	while(cin>>n){
		string dummy;
		getline(cin,dummy);
		vector<pair<vi,string>>myList;
		REP(i,n){
			string s;
			getline(cin,s);
			vi myVec;
			string name;
			process(s,myVec,name);
			myList.pb(mp(myVec,name));
			//DEBUG(name);
		}
		sort(all(myList));
		for(auto items:myList)
			cout<<items.se<<'\n';
		//DEBUG("");
	}
}


