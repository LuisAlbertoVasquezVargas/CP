#include<bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int  i = 0 ; i < (n) ; ++i )
#define clr( t , val ) memset( t , val , sizeof( t ) )

#define pb push_back
#define all( v ) v.begin() , v.end()
#define SZ( v ) ((int)(v).size())

#define mp make_pair
#define fi first
#define se second

#define DEBUG( x ) cout << #x << " " << (x) << endl;
#define N 30
#define INF (1<<28)

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
typedef long long ll;
typedef vector< ll > vll;

int n;
//vi G[ N + 5 ] , C[ N + 5 ];
ll M[ N + 5 ][ N + 5 ];
void add( int u , int v , ll w ){
	M[ u ][ v ] = M[ v ][ u ] = w;
/*
	G[ u ].pb( v );
	C[ u ].pb( w );
	
	G[ v ].pb( u );
	C[ v ].pb( w );
*/
}
/*
struct Node{
    int id ;
    long long dist;
    Node( int id , long long dist ) : id( id ) , dist( dist ) {}
};
bool operator < ( const Node &a , const Node &b ){ return a.dist > b.dist; }

void dijkstra( ll s , ll &t , ll &diam ){
	vll dist( 2 * n , INF );
	priority_queue< Node > Q;
	dist[ s ] = 0;
    Q.push( Node( s , 0 ) );
    while( !Q.empty() ){
        Node U = Q.top() ; Q.pop();
        int u = U.id ;
        REP( i , SZ( G[ u ] ) ){
            int v = G[ u ][ i ];
            ll w = C[ u ][ i ];
            if( dist[ u ] + w < dist[ v ] ){
                dist[ v ] = dist[ u ] + w;
                Q.push( Node( v , dist[ v ] ) );
            }
        }
    }
    diam = -1;
    REP( i , 2 * n ){
    	if( dist[ i ] > diam ){
    		diam = dist[ i ];
    		t = i;
    	}
    }
}
*/
void clear(){
	//REP( i , N ) G[ i ].clear() , C[ i ].clear();
	REP( i , N ) REP( j , N ) M[ i ][ j ] = INF;
	REP( i , N ) M[ i ][ i ] = 0;
}

ll getDiam(){
	ll ans = 0;
	REP( k ,  2 * n ) REP( i , 2 * n ) REP( j , 2 * n )
		M[ i ][ j ] = min( M[ i ][ j ] , M[ i ][ k ] + M[ k ][ j ] );
	REP( i , 2 * n ) REP( j , 2 * n ){
		if( M[ i ][ j ] >= INF ) continue;
		ans = max( ans , M[ i ][ j ] );
	}
	return ans;
	/*
	ll u = 0, v , w = -1;
	dijkstra( u , v , w );
	u = v;
	dijkstra( u , v , w );
	//cout << w << endl;
	*/
	//return w;
}
class BridgeBuildingDiv2 {
public:
	int minDiameter(vector <int> a, vector <int> b, int K) {
		n = SZ( a ) + 1;
		ll ans = INT_MAX;
		
		REP( mask , 1 << n ){
			if( __builtin_popcount( mask ) == K ){
				clear();
				REP( i , n - 1 ) add( i , i + 1 , a[ i ] );
				REP( i , n - 1 ) add( n + i , n + i + 1 , b[ i ] );
				REP( i , n ) 
					if( mask & (1 << i) ) add( i , n + i , 0 );
				ans = min( ans , getDiam() );
			}
		}
		
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	BridgeBuildingDiv2 *obj;
	int answer;
	obj = new BridgeBuildingDiv2();
	clock_t startTime = clock();
	answer = obj->minDiameter(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {2,1,1,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,9,1,9,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,50,1,50,1,50,1,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {50,1,50,1,50,1,50,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	p3 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {50,10,15,31,20,23,7,48,5,50};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,5,1,8,3,2,16,11,9,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3;
	p3 = 124;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {2,4,10,2,2,22,30,7,28};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {5,26,1,2,6,2,16,3,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	p3 = 54;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!