#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<queue>

using namespace std;

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

#define N 1003
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-9)
#define PI acos(-1) 
#define Vector Point 

struct Point 
{ 
    int x, y; 
    Point(){} 
    Point(int a, int b) { x = a; y = b; } 
    double arg()  { return atan2(y, x); }
    void read(){ scanf( "%d%d" , &x , &y );}
}; 
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); } 
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); } 
Point operator *(const Point &a, int k) { return Point(a.x*k, a.y*k); } 
bool operator ==(const Point &a, const Point &b){ return a.x == b.x && a.y == b.y;} 
bool operator !=(const Point &a, const Point &b){ return !(a==b);} 
bool operator <(const Point &a, const Point &b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y;} 
int cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; } 
int dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; } 
int area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); } 
  
double get_angle( Point P ) 
{ 
    double ang = P.arg();  
    if( ang < EPS )ang += 2*PI;
    return ang;
}
bool between(const Point &A, const Point &B, const Point &P) 
{ 
    return  P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) && 
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y) ; 
} 
  
bool onSegment(const Point &A, const Point &B, const Point &P) 
{ 
    return abs(area(A, B, P)) == 0 && between(A, B, P); 
} 
  
//### DETERMINA SI EL SEGMENTO P1Q1 SE INTERSECTA CON EL SEGMENTO P2Q2 ##################### 
bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4) 
{ 
    double A1 = area(P3, P4, P1); 
    double A2 = area(P3, P4, P2); 
    double A3 = area(P1, P2, P3); 
    double A4 = area(P1, P2, P4); 
      
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&  
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0)))  
            return true; 
      
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true; 
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true; 
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true; 
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true; 
    else return false; 
} 

int n ,r;
Point P,Q,O(0,0),R(1000,0);
vector< pair< double , double > > A;

int main()
{
    int tc;
    scanf( "%d" , &tc );
    REP( t , tc )
    {
        scanf( "%d%d" , &n , &r );
        A.clear();
        REP( i , n )
        {
            P.read() , Q.read();
            if( P.y == 0 && Q.y == 0 )continue;
            double angP = get_angle( P ), angQ = get_angle( Q );
            if( P.y == 0 && P.x > 0 )
            {
                if( cross( R , Q ) > 0 )
                    A.pb( mp( 0 , angQ ) );
                else
                    A.pb( mp( angQ , 2*PI ) );
            }
            else if( Q.y == 0 && Q.x > 0 )
            {
                if( cross( R , P ) > 0 )
                    A.pb( mp( 0 , angP ) );
                else
                    A.pb( mp( angP , 2*PI ) );
                
            }
            else if( intersects( P , Q , O , R ) )
            {
                if( cross( R , P ) > 0 )
                {
                    A.pb( mp( 0 , angP ) );
                    A.pb( mp( angQ , 2*PI ) );
                }
                else
                {
                    A.pb( mp( 0 , angQ ) );
                    A.pb( mp( angP , 2*PI ) );
                }
            }
            else
            {
                if( angP < angQ )swap( angP , angQ );
                A.pb( mp( angQ , angP ) );                 
            }
        }
        sort( all( A ) );
        int m = A.size();
        /*REP( i , m )
            cout << A[i].fi/PI*180 << " " << A[i].se/PI*180 << endl;
        test*/
        if( !m )
        {
            printf( "Case %d: 100.00" , t + 1 );
            puts( "%" );
            continue;
        }
        double cover = A[0].se - A[0].fi , ini = A[0].fi , end = A[0].se;
        
        for(int i = 1 ; i < m ; i++)
        {
            
            if( A[i].fi > end - EPS )
                cover += A[i].se - A[i].fi;
            else if( A[i].se > end )
                cover += A[i].se - end;
            end = max( end , A[i].se );
        }
        double ans = (1 - cover/(2*PI))*100;
        //cout << cover << endl;
        printf( "Case %d: %.2lf" , t + 1 , ans );
        puts( "%" );
    }
}
