#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string> 
#include <cstring> 
#include <cstdlib> 
#include <cassert> 
#include <climits> 
#include <cctype> 

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

#define N 25
#define Vector Point

using namespace std;

struct Point
{
    int x , y;
    Point(){};
    Point( int _x , int _y )
    {
        x = _x , y = _y;
    }
};
 
Point operator -( const Vector &A , const Vector &B ){ return Point( A.x - B.x , A.y - B.y );}
int cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; } 
int area(const Point &A, const Point &B, const Point &C) { return abs( cross(B - A, C - A) ); } 

char S[ N ][ 5 ] , T[5];
int n , maxi;
Point P[N];

void doit()
{
    maxi = -1;
    for( int i = 0 ; i < n ; ++i )
        for( int j = i + 1 ; j < n ; ++j )
            for( int k = j + 1 ; k < n ; ++k )
            {
                int ct = 0;
                int s = area( P[i] , P[j] , P[k] );
                for( int I = 0 ; I < n ; ++I )
                {
                    if( I == i || I == j || I == k ) continue;
                    int s1 = area( P[I] , P[j] , P[k] ) , s2 = area( P[i] , P[I] , P[k] ) , s3 = area( P[i] , P[j] , P[I] );
                    if( s == s1 + s2 + s3 )
                    {
                        ct++;
                        break;
                    }
                }
                if( !ct && maxi < s )
                {
                    maxi = s;
                    T[0] = S[i][0] , T[1] = S[j][0] , T[2] = S[k][0];
                    sort( T, T + 3 );
                }
            }
    printf( "%s\n" , T );
    return;
}
int main()
{
    T[3] = 0;
    while( sc( n ) == 1 && n )
    {
        REP( i,  n )scanf( "%s%d%d" , S[i] , &P[i].x , &P[i].y );
        doit();       
    }
}
