#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

using namespace std;

int main(){
	
	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		
		vector<pair<int, int> >I;
		int a, s, ct = 0;
		
		for(int i = 0; i < n; i++){
		
			scanf("%d%d", &a, &s);
			I.push_back(make_pair(a + s, a));
		}
		
		sort(all(I));
		multiset<int>S;
		int best;
		multiset<int>::iterator it;
		
		for(int i = 0; i < I.size(); i++){
			
			if(S.size() == 0)S.insert(I[i].first), ct++;
			else{
				
				best = *S.begin();
				if(best > I[i].second)S.insert(I[i].first), ct++;
				else{
					
					it = S.lower_bound(I[i].second - m);
					if(it != S.end() && *it <= I[i].second)S.erase(it), S.insert(I[i].first);
					else S.insert(I[i].first), ct++;	
				}
			}
		}
		
		printf("%d\n", n - ct);
		
	}
}
