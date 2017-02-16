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

ll getValue(string s){
	bool multiply=1;
	if(SZ(s)-3>=0&&s[SZ(s)-3]=='.')multiply=0;
	ll num=0;
	for(auto x:s)
		if(isdigit(x))
			num=num*10LL+(x-'0');
		
	if(multiply)num*=100LL;
	return num;
}
string addPoints(ll x){
	if(x==0)return "0";
	deque<char>ans;
	while(x){
		ans.push_front('.');
		ans.push_front('0'+(x)%10);
		ans.push_front('0'+(x/10LL)%10);
		ans.push_front('0'+(x/100LL)%10);
		x/=1000LL;
	}
	ans.pop_back();
	while(!ans.empty()&&ans[0]=='0')ans.pop_front();
	return string(all(ans));
}
string getFormat(ll x){
	if(x%100==0){
		x/=100LL;
		return addPoints(x);
	}else{
		string suffix;
		suffix+=string(1,'0'+(x/10LL)%10);
		suffix+=string(1,'0'+x%10);
		return addPoints(x/100LL)+"."+suffix;
	}
}
int main(){
	//DEBUG(addPoints(10009));
	string s;
	while(cin>>s){
		for(auto &x:s)
			if(isalpha(x))x=' ';
		istringstream in(s);
		ll cents=0;
		while(in>>s)cents+=getValue(s);
		//DEBUG(cents);
		cout<<getFormat(cents)<<'\n';
	}
}

