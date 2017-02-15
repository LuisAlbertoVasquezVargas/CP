#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vvi vector< vector<int> >
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define clr(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

using namespace std;

#define ld long double
#define CO 1.0/sqrt(2.0)
#define SO 1.0/sqrt(2.0)

struct Point
{
	ld x , y;
	Point(){}
	Point( ld x , ld y ):x(x) , y(y){}
	void read(){ cin >> x >> y ;}
	ld norm(){ return sqrt( x*x + y*y ); }
};
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld k ){ return Point( A.x*k, A.y*k ); }

Point rot( Point P )
{
	return Point( CO*P.x -SO*P.y , SO*P.x + CO*P.y );
}
Point p[9];
string T[] = { "E" , "NE" , "N" , "NW" , "W" , "SW" , "S" , "SE"};
int main()
{
	Point u( 1 , 0 );
	//map< string , int >M;
	REP( i , 8 )
	{
		p[i] = u , u = rot(u);
		//M[T[i]] = i;
	}
	//REP( i , 8 )cout <<p[i].x << " " << p[i].y << endl;
	string s;
	int cases = 1;
	while( getline( cin , s ) )
	{
		if( s == "END" )break;
		int ns = s.size();
		REP( i , ns )if( s[i] == ',' || s[i] == '.' )s[i] = ' ';
		string r;
		r += s[0];
		for( int i = 1 ; i < s.size() ; ++i )
			if( isdigit( s[i-1] ) && isalpha(s[i]) ) r+= " " , r += s[i] ;
			else r += s[i];
		//cout << r << endl;
		Point A( 0 , 0 );
		istringstream in( r );
		string t;
		ld x;
		int ind;
		//{ "E" , "NE" , "N" , "NW" , "W" , "SW" , "S" , "SE"};
		while( in >> x >> t )
		{
			if( t == "E" ) ind = 0;
			else if( t == "NE" ) ind = 1 ;
			else if( t == "N" ) ind = 2;
			else if( t == "NW" ) ind = 3;
			else if( t == "W" ) ind = 4;
			else if( t == "SW" )ind = 5;
			else if( t == "S" )ind = 6;
			else if( t == "SE" )ind = 7;
			A = A + (p[ind]*x);
		}
		printf( "Map #%d\n" , cases++ );
		printf( "The treasure is located at (%.3lf,%.3lf).\n" , double( A.x ) , double( A.y ) );
		printf( "The distance to the treasure is %.3lf.\n" , double( A.norm() ) );
		puts("");
	}
}


