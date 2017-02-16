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

#define N 100005

using namespace std;

int main(){
    
    
    int tc;
    cin>>tc;
    
    while(tc--){
        int n;
        scanf("%d",&n);
        
        
        map<int,int>m;
        int maxi=0;
        int aux;
        
        for(int i=0;i<n;i++){
            scanf("%d",&aux);    
            m[aux]++;
            maxi=max(maxi,m[aux]);
        }
        
        int cant=n/2+1;
        cout<<max(0,cant-maxi)<<endl;
    }
    
    
    return 0;
}
