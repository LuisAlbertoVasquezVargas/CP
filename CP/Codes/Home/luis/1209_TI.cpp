
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
#define MAXN 100000

using namespace std;

long long n,x;
bool is_trian(long long x)
{
    double t = (sqrt(1.0+8*x)-1)/2.0;
    long long k = (long long )(t+0.2);
    return (k*(k+1))== 2*x;
}
int main()
{
    while( cin >> n )
    {
        cin >> x ;
        if(is_trian(x-1))
        {
           cout<<"1";    
        }else cout<<"0";
        for( int i = 1 ; i < n ; ++i )
        {
            cin >> x ;
            if(is_trian(x-1))
            {
                cout<<" 1";    
            }else cout<<" 0";
        }
        cout<<endl;
    }
}
