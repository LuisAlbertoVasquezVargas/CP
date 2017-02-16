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

string suma(const string &a, const string &b)  
{  
    int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0; 
      
    string x = string(L, '0');  
      
    while(L--) 
    { 
        LA--; LB--; 
          
        if(LA >= 0) carry += a[LA] - '0';  
        if(LB >= 0) carry += b[LB] - '0';  
          
        if(carry < 10) x[L] = '0' + carry, carry = 0; 
        else x[L] = '0' + carry - 10, carry = 1; 
    } 
      
    if(carry) x = '1' + x;  
    return x; 
}  
  
string prod(string a, string b) 
{ 
    if(a=="0" || b=="0") return "0"; 
    else if(a.size()==1) 
    { 
        int m = a[0] - '0'; 
          
        string ans = string(b.size(), '0'); 
          
        int lleva = 0; 
          
        for(int i=b.size()-1; i>=0; i--) 
        { 
            int d = (b[i] - '0') * m + lleva; 
            lleva = d/10; 
            ans[i] += d%10; 
        } 
        if(lleva) ans = (char)(lleva + '0') + ans; 
        return ans; 
    } 
    else if(b.size()==1) return prod(b, a); 
    else
    { 
        string ans = "0"; 
        string ceros = ""; 
        for(int i=a.size()-1; i>=0; i--) 
        { 
            string s = prod(string(1, a[i]), b) + ceros; 
            ceros += "0"; 
            ans = suma(ans, s); 
        } 
        return ans; 
    } 
} 

int main()
{
	string s ,t ;
	while( cin >> s >> t )
		cout << prod(s , t ) << endl;
}
