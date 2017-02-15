#include<bits/stdc++.h>
using namespace std;

struct User{
	string id;
	string name;
	vector< string > ap;
	string birthday;
	vector< string > interestList;
	User(){}
	User( string id , string name , vector< string > ap , string birthday ,
	vector< string > interestList ) : id( id ) , name( name ) , ap( ap ) ,
	birthday( birthday ) , interestList( interestList ) {}
	int getAge(){
	
	}
};

vector< string > getList( string &s ){
	istringstream in( s );
	string cad;
	vector< string > ans;

	while( in >> cad ) ans.push_back( cad );	
	
	return ans;
}
int toi( string s ){
	istringstream in( s );
	int x;
	in >> x;
	return x;
}
int similitude( User a , User b ){
	int ans = 0;
	for( int i = 0 ; i < (int)a.id.size() ; ++i )
		if( a.id[ i ] == b.id[ i ] ) ans ++;
	return ans;
}
void showUsersForSimilitude( vector< User > &V , User &user ){
	cout << "showing users for similitude of : " << user.id << '\n';
	for( int i = 0 ; i < (int)V.size() ; ++i )
		if( similitude( V[ i ] , user ) ){
			cout << V[ i ].id << '\n';
		}
}
bool compareYearOfBirth( User a , User b ){
	int ya = toi( a.birthday.substr( 6 ) ) , yb = toi( b.birthday.substr( 6 ) );
	return ya >= yb && ya <= yb + 5;
}
void showUsersForYearOfBirth( vector< User > &V , User &user ){
	cout << "showing users for year of birth of : " << user.id << '\n';
	for( int i = 0 ; i < (int)V.size() ; ++i )
		if( compareYearOfBirth( V[ i ] , user ) ){
			cout << V[ i ].id << '\n';
		}
	
}

int compareInterests( User &a , User &b ){
	int cnt = 0;
	for( int i = 0 ; i < (int)a.interestList.size() ; ++i )
		for( int j = 0 ; j < (int)b.interestList.size() ; ++j )
			if( a.interestList[ i ] == b.interestList[ j ] ) cnt ++;
	return cnt;
}
void showUsersForInterests( vector< User > &V , User &user ){
	cout << "showing users for interests of : " << user.id << '\n';
	for( int i = 0 ; i < (int)V.size() ; ++i )
		if( compareInterests( V[ i ] , user ) >= 3 ){
			cout << V[ i ].id << '\n';
		}	
}

int main(){
	srand( time( NULL ) );
	string temp;
	while( getline( cin , temp ) ){
		string name = temp;
		
		getline( cin , temp );
		vector< string > ap = getList( temp );
		
		getline( cin , temp );
		string date = temp;
		
		getline( cin , temp );
		vector< string > interestList = getList( temp );
		
		string id = name.substr( 0 , 3 );
		for( int i = 0 ; i < (int)ap.size() ; ++i )
			id += ap[ i ].substr( 0 , 3 );
		for( int i = 0 ; i < 2 ; ++i ) 
			id += (char)('0' + rand()%10);
		id += (char)('A' + rand()%26);
		cout << id << endl;
	}
}




