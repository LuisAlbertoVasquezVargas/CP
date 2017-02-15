#include<bits/stdc++.h>
#define N 28
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define K 3
#define ones(x)
using namespace std;

char T[N][N], board[N][N];
int dx[] = {-2, -2, 2, 2};
int dy[] = {2, -2, 2, -2};

typedef unsigned long long _hash;
int n;

_hash getHash(const vector<int> &v){
	
	_hash h = 0;
	for(int i = 0; i < v.size(); i++)h = h * K + v[i];
	return h;
}

bool check(int fil, int col){ return fil >= 0 && fil < n && col >= 0 && col < n; }

bool valid(int f1, int c1, int f2, int c2){
	
	if(!check(f2, c2))return false;
	return board[f2][c2] == '_' && board[(f1 + f2)/2][(c1 + c2)/2] == 'W';
}

int ID[N][N];
bool found;

struct data{
	
	int fil, col;
	_hash h;
	
	data(){}	
	data(int _fil, int _col, _hash _h){fil = _fil; col = _col; h = _h; }
};

bool operator <(const data &d1, const data &d2){
	
	if(d1.h != d2.h)return d1.h < d2.h;
	if(d1.fil != d2.fil)return d1.fil < d2.fil;
	return d1.col < d2.col;
}

int mod = 100000, cuenta = 0;
map<data, bool>mapa[100000];
vector<int>my_id;

bool back(int fil, int col, vector<int>&mask, int ct){
	
	if(found || ct == 0){
		
		found = true;
		//for(int j = 0; j < path.size(); j++)printf("%d %d\n", path[j].first, path[j].second);
		return true;
	}
	
	if(cuenta > 50000)return false;
	cuenta++;
	
	_hash h = getHash(mask);
	data d = data(fil, col, h);
	
	if(mapa[h%mod].find(d) != mapa[h%mod].end())return mapa[h%mod][d];
	//cout << fil << " " << col << endl;
	
	int ff, cc, fm, cm, id;
	random_shuffle (my_id.begin(), my_id.end());
	
	for(int j = 0, i; j < 4; j++){
		
		i = my_id[j];
		ff = fil + dx[i];
		cc = col + dy[i];
		
		if(!valid(fil, col, ff, cc))continue;
		
		fm = (fil + ff)/2;
		cm = (col + cc)/2;
		
		id = ID[fm][cm];
		mask[id] = 0;
		
		board[fil][col] = board[fm][cm] = '_';
		board[ff][cc] = 'B';
		
		found = back(ff, cc, mask, ct - 1);
		if(found)return true;
		
		mask[id] = 1;
		board[fil][col] = 'B', board[fm][cm] = 'W';
		board[ff][cc] = '_';
	}
	return mapa[h%mod][d] = false;
}

bool seen[N][N];

void DFS(int fil, int col){
	
	if(seen[fil][col])return;
	seen[fil][col] = true;
	
	int ff, cc;
	cuenta++;
	
	for(int i = 0; i < 4; i++){
		
		ff = fil + dx[i];
		cc = col + dy[i];
		
		if(!check(ff, cc))continue;
		DFS(ff, cc);
	}
}

int main(){
	
	
	for(int i = 0; i < 4; i++)my_id.pb(i);
	
	while(scanf("%d", &n) == 1)	{
		
		vector<pair<int, int> > black;
		vector<int>white;
		
		int top = 0;
		memset(ID, 0, sizeof ID);
		bool invalid = false;
		
		for(int i = 0; i < mod; i++)mapa[i].clear();
		vector<pair<int, int> >res;
		
		for(int i = 0; i < n; i++){
		
			scanf("%s", T[i]);
			for(int j = 0; j < n; j++){
				
				board[i][j] = T[i][j];
				if((i == 0 || j == 0 || i == n - 1 || j == n - 1) && T[i][j] == 'W')invalid = true;
				if(T[i][j] == 'B')black.pb(make_pair(i, j));
				if(T[i][j] == 'W'){
					
					white.pb(1), ID[i][j] = top++;
					res.pb(make_pair(i&1, j&1));
				}
			}
		}
		
		sort(all(res));
		if(res[0] != res.back())invalid = true;
		//cout << (res[0].first&1) << " " << (res[0].second&1) << endl;
		
		if(!invalid){
			
			int ct = 0, ff, cc;
			found = false;
			
			for(int i = 0; i < black.size(); i++){
				
				found = false;
				//cout << (black[i].first&1) << " " << (black[i].second&1) << endl;
				if((black[i].first&1) == res[0].first && (black[i].second&1) == res[0].second)continue;
				for(int j = 0; j < top; j++)white[j] = 1;
				cuenta = 0;
				
				if(back(black[i].first, black[i].second, white, top)){
					
					ct++;
					ff = black[i].first;
					cc = black[i].second;
				}
				
				if(found){
					
					for(int j = 0; j < n; j++)
						for(int l = 0; l < n; l++)board[j][l] = T[j][l];
				}
					
				if(ct == 2)break;
			}
			
			if(ct == 1)printf("%c%d\n", char('a' + cc), n - ff);
			else{
				
				if(ct == 0)puts("None");
				else  puts("Multiple");	
			}
		}
		else puts("None");
		
		
	}
	
}
