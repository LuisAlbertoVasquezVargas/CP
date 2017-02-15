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

#define MAXN 30

using namespace std;

struct team
{
	int point_earn;
	int wins;
	int goal_dif;
	int goal_scored;
	int goal_against;
	int games_played;
	int ties;
	int losses;
	string team_name;
	team(){};
	team(string s)
	{
		team_name = s;
		point_earn = wins = goal_dif = goal_scored = goal_against = games_played = ties = losses = 0;
	}
};

bool cmp(team a,team b)
{
	if( a.point_earn > b.point_earn )return 1;
	if( a.point_earn < b.point_earn )return 0;	
	if( a.wins > b.wins )return 1;
	if( a.wins < b.wins )return 0;	
	if( a.goal_dif > b.goal_dif ) return 1;
	if( a.goal_dif < b.goal_dif ) return 0;	
	if( a.goal_scored > b.goal_scored ) return 1;		
	if( a.goal_scored < b.goal_scored ) return 0;
	if( a.games_played < b.games_played ) return 1;			
	if( a.games_played > b.games_played ) return 0;					
	if( strcasecmp(a.team_name.c_str(),b.team_name.c_str() ) < 0 )return 1;
	return 0;
}
int n,m,tc;
string dumm,tit,S[MAXN],game;
map<string,int>M;
team T[MAXN];
bool ok = 0;
int toi(string s){istringstream is(s);int x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}

void proc()
{
	int pos1 = game.find("#");
	int pos2 = game.find("#",pos1+1);
	int pos = game.find("@");
	string s1 = game.substr(0,pos1);
	string s2 = game.substr(pos2+1);
	string goal1 = game.substr(pos1+1,pos-1-pos1);
	string goal2 = game.substr(pos+1,pos2-1-pos);
	int g1 = toi(goal1);
	int g2 = toi(goal2);
	int it1 = M[s1];
	int it2 = M[s2];

	T[it1].goal_dif+=g1-g2;
	T[it1].goal_scored+=g1;
	T[it1].games_played++;
	T[it1].goal_against+=g2;
	
	T[it2].goal_dif+=g2-g1;
	T[it2].goal_scored+=g2;
	T[it2].games_played++;
	T[it2].goal_against+=g1;		
	if( g1 > g2 )
	{
		T[it1].point_earn+=3;
		T[it1].wins++;
		T[it2].losses++;
	}
	else if( g1 < g2 )
	{
		T[it2].point_earn+=3;
		T[it2].wins++;
		T[it1].losses++;		
	}
	else
	{
		T[it1].point_earn++;
		T[it2].point_earn++;
		T[it1].ties++;		
		T[it2].ties++;				
	}
}
int main()
{
	cin >> tc;
	getline(cin,dumm);
     while( tc-- )
     {
		if( !ok )
			ok = 1;
		else cout<<endl;
		M.clear();
		getline(cin,tit);
		cin >> n;
		getline(cin,dumm);
		for( int i = 0 ; i < n ; ++i )
			getline(cin,S[i]),M[S[i]] = i,T[i] = team(S[i]);
		cin >> m;
		getline(cin,dumm);
		for( int i = 0 ; i < m ; ++i )
			getline(cin,game),proc();
		sort(T,T+n,cmp);
		cout<<tit<<endl;
		for( int i = 0 ; i < n ; ++i )
			cout<<i + 1<<") "<<T[i].team_name<<" "<<T[i].point_earn<<"p, "<<T[i].games_played<<"g ("<<T[i].wins<<"-"<<T[i].ties<<"-"<<T[i].losses<<"), "<<T[i].goal_dif<<"gd ("<<T[i].goal_scored<<"-"<<T[i].goal_against<<")"<<endl;
     }
}
