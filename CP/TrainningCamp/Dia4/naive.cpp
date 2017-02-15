#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define N 25

using namespace std;

int main(){
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		
		vector<pair<int, int> >seg;
		int l, r;
		
		for(int i = 0; i < m; i++){
			
			scanf("%d%d", &l, &r);
			if(l < r)seg.pb(make_pair(l, r));// cout << l << " " << r << endl;
		}
		
		int ans = n + 1;
		
		if(seg.size() > 0){
			
			sort(all(seg));
			int ini = seg[0].first, fin = seg[0].second;
			
			
			for(int i = 1; i < seg.size(); i++){
				
				if(seg[i].first <= fin)fin = max(fin, seg[i].second);
				else{
					
					ans += 2 * (fin - ini);
					ini = seg[i].first;
					fin = seg[i].second;
					//cout << ini << " " << fin << endl;	
				}
			}
			
			ans += 2 * (fin - ini);// cout << ini << " " << fin << endl;
		}
		printf("%d\n", ans);
	}
	
	
	
}
