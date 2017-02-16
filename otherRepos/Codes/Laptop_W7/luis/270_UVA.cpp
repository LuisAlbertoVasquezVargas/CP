#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>

#define sync ios_base::sync_with_stdio(false);
#define REP(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct Point
{
	int x , y;
	Point(){}
	Point( int x , int y ):x(x) , y(y) {}
};

Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ) ; }
int cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x ; }

Point P[ 705 ];
string s , dummy;

int main()
{
	sync
	int tc;
	cin >> tc;
	getline( cin , dummy );
	getline( cin , dummy );
	REP( cases , tc )
	{
		int n = 0;
		while( 1 )
		{
			getline( cin , s );
			if( s.empty() )break;
			int x , y;
			istringstream in( s );
			in >> x >> y;
			P[n++] = Point( x,  y );
		}
		int maxi = 1;
		REP( i , n )
			for( int j = i + 1 ; j < n ; ++j )
			{
				int cnt = 2;
				for( int k = j + 1 ; k < n ; ++k )
				{
					if( k != j && k != i && cross( P[i] - P[k] , P[j] - P[k] ) == 0 )cnt++;
					if( cnt + n - k - 1 < maxi )break;
				}
				maxi = max( maxi , cnt );
			}
		if( cases )printf( "\n" );
		printf( "%d\n" , maxi );
	}
}


