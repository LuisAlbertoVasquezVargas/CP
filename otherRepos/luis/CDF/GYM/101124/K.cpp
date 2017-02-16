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
#define DEBUG3( x , y , z ) cerr << #x << "=" << x << " " << #y << "=" << y << " " <<#z << "=" << z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

double get(string &s,int a,int b){
	return (s[a]-'0')*10+(s[b]-'0');
}
double parse(string s){
	return (get(s,0,1)*3600+get(s,3,4)*60+get(s,6,7))/3600.0;
}
void get1(string s,double &nTimer){
	nTimer=parse(s);
}
void get2(string s,double &nTimer,double &nSpeed){
	istringstream in(s);
	string myCad;
	in>>myCad;
	nTimer=parse(myCad);
	in>>nSpeed;
}
void impr(double num){
	printf("%.2f km\n",num);
}
int main(){
	double speed=0,timer=0,dist=0;
	string s;
	while(getline(cin,s)){
		double nTimer,nSpeed;
		if(SZ(s)>8){
			get2(s,nTimer,nSpeed);
			//DEBUG3(s,nTimer,nSpeed);
			//assert(timer<=nTimer);
			//DEBUG2(timer,nTimer);
			//DEBUG(speed*(nTimer-timer));
			dist+=speed*(nTimer-timer);
			speed=nSpeed;
			timer=nTimer;
		}else{
			get1(s,nTimer);
			//DEBUG(s);
			//DEBUG2(timer,nTimer);
			assert(timer<=nTimer);
			dist+=speed*(nTimer-timer);
			//DEBUG2(timer,nTimer);
			timer=nTimer;
			cout<<s<<" ";
			impr(dist);
		}
	}
}


