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

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);
#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;
string D[] = { "","Lunes" , "Martes" , "Miercoles" , "Jueves" , "Viernes" , "Sabado" , "Domingo"};
string M[] = { "","Enero" , "Febrero" , "Marzo" , "Abril" , "Mayo" , "Junio" , "Julio" , "Agosto" , "Setiembre" ,"Octubre" , "Noviembre" , "Diciembre"};
int Tot[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

///En days Lunes  == 1 , Martes == 2 ..etc
bool is_leap_year( int _year ){ return  ( ( (_year % 4 == 0 ) && (_year % 100 != 0) ) || ( _year % 400 == 0) ); }
int tot( int mes , int year ){ return ( ( mes == 2 && is_leap_year(year) ) ? 29:Tot[mes] );}	
int dayCount(int day, int month, int year ) {
	int days = 0;
	for ( int a = 1900; a < year ; a++) days += ( is_leap_year(a) ? 366 : 365 );
	for ( int m = 1; m < month; m++) days += tot( m , year ) ;
	return days + day ;
}

struct MyDate
{
	int day , month , year;
	bool leap_year;
	string day_name, month_name;
	
	MyDate(){	day = 1 ; month = 1 ; year = 1900;	leap_year = is_leap_year(year);day_name = D[1];month_name = M[1];}
	MyDate(int _day, int _month, int _year ) { day = _day; month = _month; year = _year; leap_year = is_leap_year( _year ); /*day_name = getDiaNombre( _day, _month, _year ); mesNom = getMesNombre( _month );*/ }
	bool compareDate(MyDate f1){ return  ( year*10000 + month*100 + day ) <= ( f1.year*10000 + f1.month*100 + f1.day );}
	int dayOfWeekCount(int r){ if( day == 31 && month == 12 && year == 1899 )return 0;return dayCount(day, month, year )/7 + ( (dayCount(day, month, year)%7) >= r); }	
	bool validate() { return ( year >= 1900 ) && ( month >= 1 && month <= 12) && ( day >= 1 && day <= tot( month , year ) ); }	
	MyDate nextDate(){
		MyDate f2 = MyDate(day+1, month, year);
		if( f2.validate() ) return f2;
		f2 = MyDate(1, month+1, year);
		if( f2.validate() ) return f2;
		f2 = MyDate(1, 1, year+1);
		return f2;
	}
	MyDate prevDate(){
		MyDate f2 = MyDate(day-1, month , year);
		if( f2.validate() ) return f2;
		f2 = MyDate(day, month-1, year );
		f2 = MyDate(tot(f2.month,f2.year), month-1, year);
		if( f2.validate() ) return f2;
		f2 = MyDate(31, 12, year-1);
		return f2;
	}
};
bool operator ==( MyDate u , MyDate v )
{
	return u.day == v.day && u.month == v.month && u.year == v.year;	
}
bool operator !=( MyDate u , MyDate v )
{
	return !(u==v);	
}
int dayOfWeekCountBetweenDates(MyDate f1,MyDate f2,int days){	return f2.dayOfWeekCount(days)-(f1.prevDate()).dayOfWeekCount(days);}

int main()
{
	// dia mee año
	// dia mes año
	// 1 0 1 0 1 0 0
	int diaI , diaF , mesI , mesF , anoI , anoF;
	int v[7];
	while( cin >> diaI >> mesI >> anoI )
	{
		cin >> diaF >> mesF >> anoF;
		for( int i = 0 ; i < 7 ; ++i ) cin >> v[i];
		MyDate I = MyDate( diaI , mesI , anoI ), F = MyDate( diaF , mesF , anoF ) ;
		while( I != F )
		{
			int r = dayCount( I.day, I.month, I.year );
			int k = ( r - 1 )%7;
			if( v[k] )
				cout << I.day << " " << I.month << " " << I.year << endl;
			I = I.nextDate();	
		}
	}
}
