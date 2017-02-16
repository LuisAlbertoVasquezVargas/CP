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
#define DEBUG(x) cerr<<#x<<"="<<x<<endl;
#define DEBUG2(x,y) cerr<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define PI acos(-1)
#define Vector Point

struct Point{
	
	double x, y, z;
	Point(){}
	Point(double _x, double _y, double _z){ x = _x; y = _y; z = _z; }
	double mod(){ return sqrt(x * x  + y * y + z * z); }
};

double R = 6371.0;
double dot(const Vector &v1, const Vector &v2){ return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
double getAngle(Vector &v1, Vector &v2){ return acos(dot(v1, v2)/(v1.mod() * v2.mod())); }

double to_rad(double angle){ return angle * PI/180.0; }

double getH(double lat){
	
	double teta = PI/2.0 - to_rad(fabs(lat));
	double h = R * cos(teta);
	if(lat >= 0)return h;
	return -h;
}

#define cout2(x, y) cout << x << " " << y << endl

Point getCord(double lat, double lon, double r){
	
	double teta = to_rad(lon);
	double x = r * cos(teta);
	double y = r * sin(teta);
	double z = getH(lat);
	return Point(x, y, z);	
}


int main(){
	
	double lat1, lat2, lon1, lon2;
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%lf%lf%lf%lf", &lat1, &lon1, &lat2, &lon2);
		
		double teta1 = to_rad(fabs(lat1 - lat2));
		double vert = teta1 * R;
	
		double teta2 = min(2 * PI - to_rad(fabs(lon1 - lon2)), to_rad(fabs(lon1 - lon2)));
		
		double h1 = getH(lat1);
		double h2 = getH(lat2);
		
		double r1 = R * sin(PI/2.0 - to_rad(fabs(lat1)));
		double r2 = R * sin(PI/2.0 - to_rad(fabs(lat2)));
		
		double hor = teta2 * r1;
		double ans1 = hor + vert;
		
		Vector v1 = getCord(lat1, lon1, r1);
		Vector v2 = getCord(lat2, lon2, r2);
		double teta3 = getAngle(v1, v2);

		double ans2 = teta3 * R;
		printf("%.10lf %.10lf\n", ans2, ans1);
	}
}


