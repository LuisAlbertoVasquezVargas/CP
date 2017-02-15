#include<bits/stdc++.h>
using namespace std;

int main(){
	string course , section , type , day;
	int hBegin , hEnd;
	/*
	while( cin >> course >> section >> type >> day >> hBegin >> hEnd ){
		cout << course << " " << section << " " << type << " " << day << " " << hBegin << " " << hEnd << '\n';
	}
	*/
	cout << '"';
	while( cin >> course >> section >> type >> day >> hBegin >> hEnd ){
		cout << course << " " << section << " " << type << " " << day << " " << hBegin << " " << hEnd << ' ';
	}
	cout << '"';
}
