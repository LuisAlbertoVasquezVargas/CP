#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,1,-1};
string f(string cad , vector< string > vec){
	int x = 0 , y = 0 , n = (int)vec.size() , m = (int)vec[0].size();
	for(int it = 0 ; it < (int)cad.size() ; ++it){
		int direction;
		if(cad[ it ] == 'U') direction = 0;
		else if(cad[ it ] == 'A') direction = 1;
		else if(cad[ it ] == 'D') direction = 2;
		else if(cad[ it ] == 'I') direction = 3;
		
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		
		if(nx >= 0 && nx < n && ny >= 0 && ny < m ){
			if(vec[ nx ][ ny ] == '0'){
				x = nx;
				y = ny;
				continue;
			}
			if(vec[ nx ][ ny ] == '1'){
				continue;
			}
			return "Muerto";
		}else{
			return "Muerto";
		}	
	}
	return "Vivo!";
}
int main(){
	string cad = "DDU";
	vector< string > vec = {{"001"},{"000"},{"202"}};
	cout << f(cad , vec) << endl;
}


