#include<bits/stdc++.h>

using namespace std;

#define MAXN 350
#define EPS 1e-8
#define PI acos(-1)
#define Vector Point 
#define FOR(i,x,y) for(int i=x;i<y;i++)
#define INF (1e100)

int N,H,W;

//inline max( int i , int j ){ return i > j ? i : j ; }
typedef double ld;


struct Point
{
    ld x , y;
    Point(){ x = y = 0; }
    Point( ld x , ld y ) : x( x ) , y( y ) {}
    ld arg(){ return atan2( y , x ); }  
    ld get_angle(){ 
        ld t = arg();
        if( abs( t - PI ) < EPS )return 0;
        if( t < -EPS ) return t + PI ; 
        return t;
    }
    ld dist2(){ return x*x +y*y; }
    ld dist(){  return sqrt( dist2() ); }
    Point unit(){ ld k  = dist() ; return abs( k ) < EPS ? Point():Point( x/k , y/k ); }
    Point ort(){ return Point( -y , x ); }
    void print(){ printf( "punto : %.4f %.4f\n" , double(x) , double(y) );}
}; 

Point P[MAXN];
Point operator -( const Point &A , const Point &B ){ return Point( A.x - B.x , A.y - B.y ); }
Point operator +( const Point &A , const Point &B ){ return Point( A.x + B.x , A.y + B.y ); }
Point operator *( const Point &A , const ld &k ){ return Point( A.x*k , A.y*k ); }
bool operator <( const Point &A , const Point &B ){ return abs( A.x - B.x ) < EPS ? A.y < B.y : A.x < B.y ; }
 
ld dot( const Point &A , const Point &B ){ return A.x*B.x + A.y*B.y ; }
ld cross( const Point &A , const Point &B ){ return A.x*B.y - A.y*B.x; }
ld area( const Point &A , const Point &B , const Point &C ){ return cross( B - A , C - A ); } 
ld dist( const Point &A , const Point &B ){ return sqrt( abs( dot( B - A , B - A ) ) ); } 


// INTERSECCION DE CIRCULOS
bool circleCircleIntersection(Point O1, double r1, Point O2, double r2){
    double d = dist(O1, O2);
    if(d > r1 + r2 || d < max(r2, r1) - min(r2, r1)) return 0;
   	return 1;
} 

bool vis[MAXN];

bool f(double r){

	FOR(i,0,N) vis[ i ] = 0;
	FOR(i,0,N){
		if(vis[i])continue;
		vis[i]=1;
		int last=i;
		ld left=P[i].x-r,dwn=P[i].y-r,right=P[i].x+r,up=P[i].y+r;
		
		FOR(j,i+1,N){
			if(circleCircleIntersection(P[last],r,P[j],r)){
				last = j - 1;
				right = P[ j ].x + r;
				if( P[j].y + r > up ) up = P[j].y+r;
				if( P[j].y - r > dwn ) dwn = P[j].y-r;
				vis[ j ] = 1;
				if(H < up + EPS && dwn< 0 + EPS)return 0;
				if(W < right  + EPS&&left<0 + EPS)return 0;
				if(H < up + EPS&& W < right + EPS)return 0;
				if(dwn<0 + EPS && left < 0 + EPS ) return 0;
			}
		}
		if(H < up + EPS && dwn< 0 + EPS)return 0;
		if(W < right  + EPS&&left<0 + EPS)return 0;
		if(H < up + EPS&& W < right + EPS)return 0;
		if(dwn<0 + EPS && left < 0 + EPS ) return 0;	
	}	
	return 1;
}
  
int main(){
	while(scanf("%d%d%d",&N,&W,&H)==3){
		if(N==-1)break;
		int x,y;
		ld best = INF;
		for(int i=0;i<N;i++){
			scanf("%d%d",&x,&y);
			P[i]=Point(x,y);
			best = min( best , P[ i ].dist() );
		}
		sort(P,P+N);
		ld lo=0,hi=best + 1;
		FOR(i,0,32){
			double mid=(lo+hi)/2;
			if(f(mid))lo=mid;
			else hi=mid;
		}
		printf("%.3f\n",(double(hi+lo)/2.0));
	}
}



