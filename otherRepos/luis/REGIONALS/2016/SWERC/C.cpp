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


int main(){
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);
		
		multiset<long long>s;
		long long x;
		
		for(int i = 0; i < n; i++){
			
			scanf("%lld", &x);
			s.insert(x);
		}
		
		long long ans = 0, aux;
		multiset<long long>::iterator it1, it2;
		
		while(s.size() > 1){
			
			it1 = s.begin();
			s.erase(it1);
			
			it2 = s.begin();
			s.erase(it2);
				
			aux = (*it1) + (*it2);
			s.insert(aux);
			
			ans += aux;
		}
		
		//if(n == 1)ans += (*s.begin());
		printf("%lld\n", ans);
			
	}
	
	
		
	
}
