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

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

using namespace std;


struct Point
{
    double x, y,z;
    Point(){}
    Point(double a, double b,double c ) { x = a; y = b;z = c; }
    double mod()  { return sqrt(x*x + y*y + z*z); }
    Point unit()  { double k = mod(); return Point(x/k, y/k,z/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y,a.z+b.z); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y,a.z-b.z); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k,a.z/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k,a.z/k); }

bool operator ==(const Point &a, const Point &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS && fabs(a.z - b.z) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}

//### FUNCIONES BASICAS #############################################################
double volume (const Vector &A, const Vector &B , const Vector &C ) 
{ 
     double a = A.x,b = A.y,c = A.z;
     double d = B.x,e = B.y,f = B.z;
     double g = C.x,h = C.y,i = C.z ;
     return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h ; 
}
double xi,yi,zi;
int a[6];
Point Q;
int main()
{
     while( cin >> Q.x >> Q.y >> Q.z >> xi >> yi >> zi )
     {
          for( int k = 0 ; k < 6 ; ++k )
               cin >> a[k];
          Point P[8];             // 0    1   2    3    4    5
          P[0] = Point(0,0,0);   //+ZOX       +XOY       YOZ  
          P[1] = Point(0,0,zi);  //2*ZOX            +XOY' YOZ
          P[2] = Point(0,yi,0);  //     +ZOX' 1*XOY       YOZ
          P[3] = Point(xi,0,0);  //1*ZOX      2*XOY            YOZ'
          P[4] = Point(0,yi,zi); //     *1ZOX'      XOY' YOZ
          P[5] = Point(xi,yi,0); //     *2ZOX' XOY            YOZ'
          P[6] = Point(xi,0,zi); //ZOX              XOY'      YOZ'
          P[7] = Point(xi,yi,zi);//     ZOX'        XOY'      YOZ'
          int sum = 0;
          if( volume(P[3]-P[0],P[1]-P[0],Q-P[0]) > 0 )
               sum+=a[0];
          if( volume(P[4]-P[2],P[5]-P[2],Q-P[2]) > 0 )
               sum+=a[1];
          if( volume(P[2]-P[0],P[3]-P[0],Q-P[0]) > 0 )
               sum+=a[2];               
          if( volume(P[6]-P[1],P[4]-P[1],Q-P[1]) > 0 )
               sum+=a[3];                              
          if( volume(P[1]-P[0],P[2]-P[0],Q-P[0]) > 0 )
               sum+=a[4];                             
          if( volume(P[5]-P[3],P[6]-P[3],Q-P[3]) > 0 )
               sum+=a[5];                                                    
          cout<<sum<<endl;
     }
}
