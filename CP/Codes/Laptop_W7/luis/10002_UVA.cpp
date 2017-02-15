#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)


#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point
{
    int x, y;
    Point(){}
    Point(int a, int b) { x = a; y = b; }

};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
bool operator ==(const Point &a, const Point &b){ return a.x == b.x && a.y == b.y;}
bool operator !=(const Point &a, const Point &b){ return !(a==b);}
bool operator <(const Point &a, const Point &b){ if(a.x != b.x) return a.x < b.x; return a.y < b.y;}

double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }

double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

vector <Point> ConvexHull(vector <Point> Poly)
{
    sort(Poly.begin(),Poly.end());
    int nP = Poly.size(),k = 0;
    Point H[2*nP];
    
    for(int i=0;i<nP;++i){
        while(k>=2 && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    for(int i=nP-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],Poly[i]) <= 0) --k;
        H[k++] = Poly[i];
    }
    if( k == 0 )return vector <Point>();
    return vector <Point> (H,H+k-1);
}

int main()
{
	int n ;
	while( sc( n ) == 1 && n >= 3 )
	{
		vector< Point >Poly( n );
		REP( i , n )scanf( "%d%d" , &Poly[i].x , &Poly[i].y ) ;
		Poly = ConvexHull( Poly );
		n = Poly.size();
		long long A = 0;
		long long Cx = 0 , Cy = 0;
		REP( i , n )
		{
			int ind = (i+1)==n?0:(i+1);
			long long cte = (Poly[i].x*Poly[ind].y - Poly[ind].x*Poly[i].y);
			A += cte;
			Cx += (Poly[i].x + Poly[ind].x)*cte;
			Cy += (Poly[i].y + Poly[ind].y)*cte;
		}
		printf( "%.3lf %.3lf\n" , 1.0*Cx/(3.0*A) , 1.0*Cy/(3.0*A) );
	}
}


