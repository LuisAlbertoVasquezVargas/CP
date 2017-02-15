#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF (1<<30)

#define all(v)  v.begin() , v.end()
#define pb push_back
#define cout2(x, y) cout << x << " " << y << " " << endl
#define interval pair<int, int> 
#define l first
#define r second

string toString(int n){
	
	string ans = "";
	while(n > 0){
		
		ans += char(n%10 + '0');
		n /= 10;
	}
	
	reverse(all(ans));
	return ans;
}


string optimal(int l, int r, int id){

	if(l > r)return "";
	string ans = "", car;
	
	if(id == 0)car = "-";
	else if(l&1)car = "#";
	else  car = "%";
	
	if(r - l > 2)return toString(l) + car + toString(r) + ",";
	for(int i = l; i <= r; i++)ans += toString(i) + ",";
	return ans;	
}

int a[N];

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)scanf("%d", &a[i]);
	sort(a, a + n);
	
	vector<int>pares, impares;
	vector<pair<int, int> >v;
	
	for(int i = 0; i < n; i++){
		
		if(a[i]&1)impares.pb(a[i]);
		else pares.pb(a[i]);	
	}
	
	for(int i = 0, l; i < pares.size(); i++){
		
		l = i + 1;
		while(l < n && pares[l] - pares[l - 1] == 2)l++;
		//cout2(pares[i], pares[l - 1]);
		v.pb(make_pair(pares[i], pares[l - 1]));
		i = l - 1;
	}
	
	for(int i = 0, l; i < impares.size(); i++){
		
		l = i + 1;
		while(l < n && impares[l] - impares[l - 1] == 2)l++;
		//cout2(impares[i], impares[l - 1]);
		v.pb(make_pair(impares[i], impares[l - 1]));
		i = l - 1;
	}
	
	sort(all(v));
	string ans = "";
	
	int m = v.size(), l, r;
	for(int i = 0; i < m; i++){
		
		if(i + 1 < m){
			
			if(v[i + 1].l - v[i].l <= 1 && abs(v[i + 1].r - v[i].r) <= 1){
				
				ans += optimal(v[i].l, max(v[i].r, v[i].r), 0);
				i++;
			}
			else{
				
				if(v[i + 1].l - v[i].l <= 2 && abs(v[i + 1].r - v[i].r) <= 2){
				
					l = v[i].l;
					r = max(v[i].r, v[i + 1].r);
					
					if(v[i + 1].l - v[i].l == 2)ans += toString(l) + ",", l++;
					if(abs(v[i + 1].r - v[i].r) == 2)ans += toString(r) + ",", r--;
					
					ans += optimal(l, r, 0);
					i++;
				}
				else ans += optimal(v[i].l, v[i].r, 1);	
			}
		}
		else ans += optimal(v[i].l, v[i].r, 1);
	}
	
	for(int i = 0; i < ans.size() - 1; i++)putchar(ans[i]);
	puts("");
}
