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

using namespace std;
vector<pair<int,int> >v;
pair<int,int> p;
map<pair<int,int> ,int>M;

bool f( pair<int,int> a,pair<int,int> b )
{
	if( a.first < b.first && a.second > b.second )return 1;
	return 0;
}
vector< pair<int,int> > LIS(vector< pair<int,int> > X){
    int n = X.size(),L = 0,M[n+1],P[n]; 
    int lo,hi,mi;
    
    L = 0;
    M[0] = 0;
    
    for(int i=0,j;i<n;i++){
        lo = 0; hi = L;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(f(X[M[mi]],X[i])) lo = mi;
            else hi = mi-1;
        }
        
        j = lo;
        
        P[i] = M[j];
        
        if(j==L || f(X[i],X[M[j+1]]) ){
            M[j+1] = i;
            L = max(L,j+1);
        }
    }
    
    pair<int,int>  a[L];
    
    for(int i=L-1,j=M[L];i>=0;i--){
        a[i] = X[j];
        j = P[j];
    }
    
    return vector< pair<int,int> >(a,a+L);
}
bool cmp( pair<int,int> a,pair<int,int> b)
{
	if( a.second >= b.second )return 1;
	return 0;	
}
int main()
{
	int i = 0;
     while( cin >> p.first >> p.second )
     {
		v.push_back(p);
		M[p] = ++i;
     }
     sort(v.begin(),v.end(),cmp);
	vector<pair<int,int> > w = LIS(v);
	int nw = w.size();
	cout<<nw<<endl;
	for( int i = 0 ; i < nw ; ++i )
		cout << M[w[i]] <<endl;
}
