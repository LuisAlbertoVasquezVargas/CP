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

#define MAXN 4

using namespace std;

pair<pair<int,int> , pair<int,int> > P[MAXN],Q[MAXN];
int minix,maxix,miniy,maxiy;
bool ok;
bool eq(pair<pair<int,int> , pair<int,int> > a,pair<pair<int,int> , pair<int,int> > b )
{
	if( a == b )return 1;
	swap( a.first , a.second );
	if( a == b )return 1;
	return 0;	
}
int main()
{
     while( cin >> P[0].first.first >> P[0].first.second >> P[0].second.first >> P[0].second.second )
     {
		for( int  i = 1 ; i < MAXN ; ++i )
			cin >> P[i].first.first >> P[i].first.second >> P[i].second.first >> P[i].second.second;			
		minix = miniy = INT_MAX;
		maxix = maxiy = INT_MIN;
          for( int i = 0 ; i < MAXN ; ++i )
		{
			minix = min( minix , P[i].first.first ) ;
			minix = min( minix , P[i].second.first ) ;			
			maxix = max( maxix , P[i].first.first ) ;
			maxix = max( maxix , P[i].second.first ) ;
			
			miniy = min( miniy , P[i].first.second ) ;
			miniy = min( miniy , P[i].second.second ) ;			
			maxiy = max( maxiy , P[i].first.second ) ;
			maxiy = max( maxiy , P[i].second.second ) ;									
		}
		if( minix == maxix || miniy == maxiy )
		{
			cout<<"NO"<<endl;
			continue;	
		}
		Q[0] =  make_pair( make_pair( minix , miniy ) , make_pair( minix , maxiy ) );
		Q[1] =  make_pair( make_pair( minix , miniy ) , make_pair( maxix , miniy ) );
		Q[2] =  make_pair( make_pair( minix , maxiy ) , make_pair( maxix , maxiy ) );
		Q[3] =  make_pair( make_pair( maxix , miniy ) , make_pair( maxix , maxiy ) );
		sort(Q,Q+MAXN);
		ok = 0;
		do
		{
			if( eq(P[0],Q[0]) && eq(P[1],Q[1]) && eq(P[2],Q[2]) && eq(P[3],Q[3]) )
			{
				ok = 1;
				break;
			}
		}while(next_permutation(Q,Q+MAXN));
		if( ok )
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
     }
}
