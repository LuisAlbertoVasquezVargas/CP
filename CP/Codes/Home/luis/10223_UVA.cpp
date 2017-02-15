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

int n ;

long long comb(int n, int m){
    if(m>n-m) m = n-m;
    
    long long C = 1;
    //C^{n}_{i} -> C^{n}_{i+1}
    for(int i=0;i<m;++i) C = C*(n-i)/(1+i);
    return C;
}
long long Cat[22];
void init()
{
	
	for( long long i = 0 ; i < 21 ; ++i )
		Cat[i] = comb(2*i,i)/(i+1);
}
int main()
{
	init();
	while( cin >> n )
		cout << upper_bound( Cat , Cat + 21 , n ) - Cat - 1<< "\n";
}
