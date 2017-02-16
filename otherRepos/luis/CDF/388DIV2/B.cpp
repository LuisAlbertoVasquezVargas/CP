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

#define test() cerr<<"hola que hace ?"<<endl;
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#define DEBUG3(x,y,z) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl;

typedef long long ll;
typedef pair< int , int > pii;
typedef vector< int > vi;

struct Point{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
};
Point operator -(const Point &p,const Point &q){
	return Point(p.x-q.x,p.y-q.y);
}
Point operator +(const Point &p,const Point &q){
	return Point(p.x+q.x,p.y+q.y);
}
int main(){
	vector<Point>P(3);
	while(cin>>P[0].x>>P[0].y){
		REP(k,3){
			if(!k)continue;
			cin>>P[k].x>>P[k].y;
		}
		vi index(3);
		REP(k,3)index[k]=k;
		set<pii>mySet;
		do{
			Point A=P[index[0]];
			Point B=P[index[1]];
			Point C=P[index[2]];
			Point D=C+A-B;
			mySet.insert({D.x,D.y});
		}while(next_permutation(all(index)));
		cout<<SZ(mySet)<<'\n';
		for(auto x:mySet)
			cout<<x.fi<<" "<<x.se<<'\n';
	}
}



