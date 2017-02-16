#include<bits/stdc++.h>
#define pb(x) push_back(x)


using namespace std;

string s[] = {
"black pawn",
"black knight",
"black rook",
"black bishop",
"black king",
"black queen",

"white pawn",
"white knight",
"white rook",
"white bishop",
"white king",
"white queen"
};

int frec[] = {8, 2, 2, 2, 1, 1, 8, 2, 2, 2, 1, 1};

map<string, int>mapa1, mapa2;

int main(){
	
	int k1, k2;
	cin >> k1 >> k2;
	
	string cad;
	getline(cin, cad);
	
	for(int i = 0; i < k1; i++)getline(cin, cad), mapa1[cad]++;
	for(int i = 0; i < k2; i++)getline(cin, cad), mapa2[cad]++;
	
	bool ok = true;
	vector<string>ans;
	
	for(int i = 0; i < 12 && ok; i++){
		
		if(mapa1[s[i]] == frec[i])continue;
		if(mapa1[s[i]] + mapa2[s[i]] < frec[i]){
			
			ok = false;	
			//cout << i << " " << s[i]  << endl;
		}
		else{
			
			for(int j = 0; j < frec[i] - mapa1[s[i]]; j++)ans.pb(s[i]);
		}
	}
	
	if(!ok)puts("impossible");
	else{
		
		for(int i = 0; i < ans.size(); i++)printf("%s\n", ans[i].c_str());	
	}
}


