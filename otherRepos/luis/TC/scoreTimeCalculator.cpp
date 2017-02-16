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
typedef vector<pii> vpii;
typedef vector< int > vi;

//PT problem time on minutes, for example 30.5 30 minutes and half
//TT total time allocated for coding all problems on minutes, for example 75
//MP maximum points, for example 250,500,100
double getScore(double PT,double TT,double MP){
	return MP*(.3+(.7*TT*TT)/(10*PT*PT+TT*TT));
}
//TT 75 minutes

double getTime(double score,double TT,double MP){
	double lo=0,hi=TT;
	REP(it,50){
		double med=(lo+hi)/2.0;
		if(getScore(med,TT,MP)>=score)lo=med;
		else hi=med;
	}
	return lo;
}
double getTime2(double score,double TT,double MP){
	return sqrt(((.7*TT*TT)/(score/MP-0.3)-TT*TT)/10);
}
int main(){
	printf("%.4f\n",getScore(22.7,60,500));
	
	printf("%.4f\n",getScore(36+02.468/60,75,222));
	
	printf("%.10f\n",getTime(117.46,75,300));
	printf("%.10f\n",getTime2(134.03,75,250));
}



