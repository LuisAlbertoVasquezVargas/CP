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
#define MAXN 50

using namespace std;

int na,ma,nb,mb;
string a[MAXN],b[MAXN];
int main()
{
     while( cin >> na >> ma )
     {
          for( int i = 0 ; i < na ; ++i )
               cin >> a[i];
          cin >> nb >> mb;
          for( int i = 0 ; i < nb ; ++i )
               cin >> b[i];
          int maxi = -1;
          int X,Y;
          for( int x = - na + 1 ; x < nb ; x++ )
          {
               for( int y = - ma + 1 ; y < mb ; y++ )
               {
                    int s = 0;
                    for( int i = 0 ; i < na ; ++i )
                         for( int j = 0 ; j < ma ; ++j )
                              if( i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb )
                                   s+=(a[i][j]-'0')*(b[i+x][j+y]-'0');
                    if( s > maxi )
                    {
                         maxi = s;
                         X = x;
                         Y = y;
                    }                                   
               }
          }
          cout<<X<<" "<<Y<<endl;
     }
}
