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

#define MAXN 100
#define MAXP 9

using namespace std;

int tc,cont,prob,tim;
string s,dum;
char L;
int a[MAXN][MAXP][3];
int vis[MAXN];
//0:#WA 1:AC?  2:Penalty
bool ok = 0;

void doit()
{
	istringstream in(s);
	in >> cont >> prob >> tim >> L ;
	cont--;prob--;
	vis[cont] = 1;
	if( a[cont][prob][1] == 1 )
		return;
	if( L == 'C' )
	{ 
		a[cont][prob][1] = 1;
		a[cont][prob][2] = 20*a[cont][prob][0] + tim;
		
	}else if( L == 'I' )
		a[cont][prob][0]++;
}

void present()
{//cont #prob #penalt
	vector< pair<int,pair<int,int> > >v;
	for( int i = 0 ; i < MAXN ; ++i )
		if( vis[i] )
		{
			int cnt = 0,totpen = 0;
			for( int j = 0 ; j < MAXP ; ++j )
				if( a[i][j][1] )
					cnt++,totpen+=a[i][j][2];
			v.push_back(make_pair(-cnt,make_pair(totpen,i+1)));	
		}
	sort(v.begin(),v.end());
	int nv = v.size();
	for( int i = 0 ; i < nv ; ++i )
		cout << v[i].second.second  << " " << -v[i].first << " " << v[i].second.first << endl;
}

int main()
{
	cin >> tc;
	getline( cin , dum);
	getline( cin , dum);
		
     while( tc-- )
     {
		if( !ok )
			ok = 1;
		else cout<<endl;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));		
		while( getline( cin , s ) && s!="" )
			doit();
		present();
     }
}
