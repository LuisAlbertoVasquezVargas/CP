#include<bits/stdc++.h>
using namespace std;

const int cte = 10;
vector< string > S[ 7 ][ 24 ];
vector< int > P , O;
//O = Obligatorio?
map< string , int > mapaCourse;
vector< map< string , vector< pair< int , int > > > > T;
map< string , set<string> > teachers;
vector< string > days = { "LU" , "MA" , "MI" , "JU" , "VI" , "SA" };
vector< string > courseName;

map<string,int> mapaCourseId;
int esc = 0;
int minCourses = 8 , maxCourses = 10;
int maxCred = 26;
/*
No permite cruces
Tope minimo para la cantidad de cursos
Tope maximo para la cantidad de creditos
*/
bool valid(int pos , int cnt , int cred){
	if(cnt < minCourses) return 0;
	if(cnt > maxCourses) return 0;
	if(cred > maxCred) return 0;
	for( int i = 8 ; i <= 22 ; ++i )
		for( int j = 0 ; j < 6 ; ++j ){
			int len = S[ j ][ i ].size();
			if( len > 1 ) return 0;
		}
	return 1;
}
//solo cursos de ing de sistemas
vector<string> coursesCode = { "CB-101","CB-121","CB-201","CB-501","HS-101","HS-111","ST-101","TP-301","CB-111","CB-131","HS-121","HS-141","HS-201","ST-103","ST-221","CB-112","CB-132","CB-302","CB-402","HS-131","ST-202","CB-122","CB-142","CB-312","CB-412","GP-202","ST-232","CB-143","CB-313","GP-102","GP-203","ST-113","ST-203","TP-113","GP-223","GP-403","ST-123","ST-133","ST-213","TP-123","GP-122","GP-233","ST-124","ST-204","ST-214","ST-314","ST-324","GP-235","GP-304","GP-314","HS-204","ST-334","ST-414","GP-515","GP-525","ST-205","ST-215","ST-235","HS-301","ST-236","ST-255","ST-275","ST-285","ST-295","XP-200","GP-134","GP-154","GP-234","GP-244","GP-245","GP-334","GP-514","GP-555","GP-575","HS-102","HS-144","HS-151","HS-161","HS-404","HS-405","ST-114","ST-224","ST-231","ST-234","ST-243","ST-244","ST-245","ST-253","ST-254","ST-265","ST-305","ST-344","ST-415","TP-254","TP-265","TP-313","XA-100","XA-200","XA-300","XA-400","XP-100","XP-300","XP-400","HS-302","HS-303","HS-402"};
vector<string> coursesName = { "GEOMETRIA ANALITICA","CALCULO DIFERENCIAL","QUIMICA GENERAL","DIBUJO DE INGENIERIA","DESARROLLO PERSONAL","TECNICAS DE COMUNICACION","INTRODUCCION A LA INGENIERIA DE SISTEMAS","DIBUJO DE INGENIERIA","ALGEBRA LINEAL","CALCULO INTEGRAL","METODOLOGIA DE LA INVESTIGACION CIENTIFICA","FILOSOFIA Y ETICA","CONSTITUCION Y DERECHOS HUMANOS","TEORIA GENERAL DE SISTEMAS","ALGORITMOS Y ESTRUCTURA DE DATOS","MATEMATICA DISCRETA","CALCULO MULTIVARIABLE","FISICA I","ESTADISTICA Y PROBABILIDADES","SOCIOLOGIA","LENGUAJES DE PROGRAMACION ESTRUCTURADO","CALCULO NUMERICO","ECUACIONES DIFERENCIALES","FISICA II","ESTADISTICA APLICADA","MICROECONOMIA","LENGUAJES DE PROGRAMACION ORIENTADOS A OBJETOS","MATEMATICA APLICADA","FISICA MODERNA","ORGANIZACION Y METODOS","MACROECONOMIA","INVESTIGACION DE OPERACIONES I","MODELAMIENTO DE DATOS","SISTEMAS ELECTRICOS Y ELECTRONICOS","CONTABILIDAD FINANCIERA","SISTEMAS PRODUCTIVOS","INVESTIGACION DE OPERACIONES II","DINAMICA DE SISTEMAS","ANALISIS Y DISE�O DE SISTEMAS","SISTEMAS DIGITALES","CREATIVIDAD EMPRESARIAL","CONTABILIDAD DE COSTOS Y PRESUPUESTOS","SIMULACION","TALLER DE INGENIERIA DE SOFTWARE I","ADMINISTRACION DE BASE DE DATOS","ARQUITECTURA DEL COMPUTADOR","SISTEMAS OPERATIVOS","GESTION FINANCIERA","LOGISTICA EMPRESARIAL","MERCADOTECNIA","LEGISLACION EMPRESARIAL","SISTEMAS DE COMUNICACION DE DATOS","INTELIGENCIA ARTIFICIAL","PLANEAMIENTO Y DIRECCION ESTRATEGICA","DISE�O Y EVALUACION DE PROYECTOS","TOPICOS DE INGENIERIA DE SISTEMAS","SEGURIDAD INFORMATICA","PROYECTO DE TESIS EN INGENIERIA DE SISTEMAS I","IDIOMAS I","PROYECTO DE TESIS EN INGENIERIA DE SISTEMAS II","GESTION DE PROYECTOS INFORMATICOS","AUDITORIA DE SISTEMAS","APLICACION DE NEGOCIOS ELECTRONICOS","INGENIERIA EMPRESARIAL","PRACTICAS PRE-PROFESIONALES II","MODELOS DE GESTION EMPRESARIAL","ADMINISTRACION DE RECURSOS HUMANOS","ANALISIS ECONOMICO EN INGENIERIA","SISTEMAS DE COSTOS","FINANCIAMIENTO CORPORATIVO","BOLSA DE VALORES Y MERCADO BURSATIL","COMERCIO INTERNACIONAL","GESTION DE NEGOCIOS I","DIAGNOSTICO EMPRESARIAL","IDEOLOGIAS CONTEMPORANEAS","COMPORTAMIENTO ORGANIZACIONAL","LITERATURA","PROTOCOLO","REALIDAD NACIONAL E INTERNACIONAL","TOPICOS DE NEGOCIACION","TEORIA DE DECISIONES","SISTEMAS ECONOMICOS","TALLER DE HERRAMIENTAS SOFTWARE I","TEORIA DE LENGUAJES","TALLER DE HERRAMIENTAS REALIDAD VIRTUAL","TALLER DE INGENIERIA DE SOFTWARE II","INGENIERIA DE SOFTWARE AVANZADO","TECNICAS DE DOCUMENTACION Y ARCHIVOS","ADMINISTRACION DE LA CALIDAD DE SOFTWARE","ADMINISTRACION DEL CONOCIMIENTO","SERVICIOS DE COMUNICACION DE DATOS","SISTEMAS HUMANOS","INTELIGENCIA ARTIFICIAL AVANZADA","AUTOMATIZACION Y CONTROL DE PROCESOS","ROBOTICA","DISE�O GRAFICO","ACTIVIDADES DIVERSAS I","ACTIVIDADES DIVERSAS II","ACTIVIDADES DIVERSAS III","ACTIVIDADES DIVERSAS IV","PRACTICAS PRE-PROFESIONALES I","PRACTICAS PRE-PROFESIONALES III","PRACTICAS PRE-PROFESIONALES IV","IDIOMAS II","IDIOMAS III","DEPORTE"};
vector<int> coursesCred = { 3,5,4,3,2,3,3,3,3,5,3,2,2,3,3,3,5,5,3,2,3,3,5,5,3,3,3,3,3,3,3,3,3,4,3,3,3,3,5,3,1,3,3,3,3,3,3,3,3,3,2,3,3,3,4,2,3,2,2,2,3,3,3,3,2,3,3,3,2,3,2,3,3,3,4,2,2,1,2,3,3,3,1,3,2,3,3,3,3,3,3,2,3,3,3,3,1,2,3,4,1,3,4,2,2,1};


vector<string> SEC;
set<string> SET;
void back( int pos , int cnt , int cred ){
	if( pos == (int)P.size() ){
		//print
		if( !valid(pos,cnt,cred) ) return;
		cout << setw( cte ) << "";
		for( int i = 0 ; i < 6 ; ++i )
			cout << setw( cte ) << days[ i ];
		cout <<  " esc " << ++esc << endl;
		vector<string> vec;
		for( int i = 8 ; i <= 22 ; ++i ){
			cout << setw( cte ) << i;
			for( int j = 0 ; j < 6 ; ++j ){
				string cad ;
				int len = S[ j ][ i ].size();
				if( len  == 0 ) cad = "---";
				else if( len == 1 ){
					cad = S[ j ][ i ].back();
					vec.push_back(cad);
				}
				cout << setw( cte ) << cad;
			}
			cout << '\n';
		}
		cout << "creditaje = " << cred << endl;
		cout << "cantidad de cursos = " << cnt << endl;
		sort(vec.begin(),vec.end());
		vec.resize(unique(vec.begin(),vec.end()) - vec.begin());
		cout << setw(6) << "Cur-Sec" << " " << setw(35) << "Nombre del curso" << setw(50) << "Docente(s)" << endl;
		for( auto x : vec ){
			string s = x;
			s.pop_back();
			int id = mapaCourseId[ s ];
			//cout << s << " " << id << endl;
			cout << setw(6) << x << " " << setw(35) << coursesName[ id ];
			for(auto y : teachers[x]) cout << " (" << y << ")";
			cout << endl;
		}
		return;
	}
	
	if( !O[ pos ] )back( pos + 1 , cnt , cred );
	
	auto it1 = P[ pos ];
	for( auto x : T[ it1 ] ){
		string sec = x.first;
		vector< pair< int , int > > V = x.second;
		if( !SET.count(courseName[ P[ pos ] ] + sec) ) continue;
		for( int i = 0 ; i < (int)V.size() ; ++i){
			int a = V[ i ].first;
			int b = V[ i ].second;
			S[ a ][ b ].push_back( courseName[ P[ pos ] ] + sec );
		}
		back( pos + 1 , cnt + 1 , cred + coursesCred[ mapaCourseId[ courseName[ P[ pos ] ] ] ] );
		for( int i = 0 ; i < (int)V.size() ; ++i){
			int a = V[ i ].first;
			int b = V[ i ].second;
			S[ a ][ b ].pop_back();
		}
	}
}

string data = "CB-101	U	T	MI	8	10 CB-101	U	P	VI	10	12 CB-101	V	T	MI	10	12 CB-101	V	P	VI	10	12 CB-101	W	T	MI	10	12 CB-101	W	P	VI	10	12 CB-101	X	T	LU	8	10 CB-101	X	PC	VI	10	12 CB-101	X	PD	MI	10	12 CB-111	U	T	MA	10	12 CB-111	U	P	JU	10	12 CB-111	V	T	MI	10	12 CB-111	V	PC	JU	10	12 CB-111	W	T	MA	12	14 CB-111	W	PC	JU	10	12 CB-112	U	T	JU	10	12 CB-112	U	P	MA	8	10 CB-112	V	T	MI	8	10 CB-112	V	P	MA	8	10 CB-112	W	T	MA	18	20 CB-112	W	P	MI	20	22 CB-121	U	T	JU	10	12 CB-121	U	T	MA	8	10 CB-121	U	PC	MI	12	14 CB-121	U	PD	VI	8	10 CB-121	V	T	LU	14	16 CB-121	V	T	VI	8	10 CB-121	V	P	MI	12	14 CB-121	W	T	MI	8	10 CB-121	W	T	VI	8	10 CB-121	W	PD	MA	10	12 CB-121	W	PC	MI	12	14 CB-121	X	T	VI	8	10 CB-121	X	T	LU	8	10 CB-121	X	P	MI	12	14 CB-122	U	T	MI	10	12 CB-122	U	P	JU	8	10 CB-122	V	P	JU	8	10 CB-122	V	T	SA	8	10 CB-131	U	T	MI	10	12 CB-131	U	T	MA	10	12 CB-131	U	P	VI	14	16 CB-131	V	T	JU	14	16 CB-131	V	T	MA	14	16 CB-131	V	P	VI	14	16 CB-131	W	T	JU	14	16 CB-131	W	T	MA	14	16 CB-131	W	P	VI	14	16 CB-132	U	T	LU	10	12 CB-132	U	T	MI	8	10 CB-132	U	P	VI	12	14 CB-132	V	T	JU	8	10 CB-132	V	T	MA	10	12 CB-132	V	P	VI	12	14 CB-132	W	T	MA	16	18 CB-132	W	T	MI	14	16 CB-132	W	P	VI	12	14 CB-142	U	T	MA	8	10 CB-142	U	T	MI	8	10 CB-142	U	P	VI	16	18 CB-142	V	T	MA	14	16 CB-142	V	T	MI	14	16 CB-142	V	P	VI	16	18 CB-142	W	T	LU	8	10 CB-142	W	T	MA	10	12 CB-142	W	P	VI	16	18 CB-143	U	T	MA	10	12 CB-143	U	PC	JU	8	10 CB-143	V	T	LU	20	22 CB-143	V	P	MA	20	22 CB-201	U	T	LU	10	13 CB-201	U	P	JU	14	17 CB-201	V	T	JU	10	13 CB-201	V	P	MI	15	18 CB-201	V	P	MI	15	18 CB-201	W	T	VI	14	17 CB-201	W	P	MA	14	17 CB-211	U	T	MA	8	11 CB-211	U	P	MA	13	16 CB-211	V	T	JU	10	13 CB-211	V	P	MA	10	13 CB-221	U	T	MA	10	12 CB-221	U	P	LU	10	13 CB-221	U	P	LU	10	13 CB-221	V	T	LU	10	12 CB-221	V	P	LU	14	17 CB-221	V	P	LU	14	17 CB-222	U	T	LU	8	10 CB-222	U	P	JU	17	20 CB-222	V	T	VI	8	10 CB-222	V	P	LU	10	13 CB-222	W	T	MI	10	12 CB-222	W	P	JU	12	15 CB-302	U	T	LU	14	16 CB-302	U	T	MA	14	16 CB-302	U	LAB	MI	16	19 CB-302	U	LAB	MI	16	19 CB-302	V	T	LU	14	16 CB-302	V	T	MA	14	16 CB-302	V	LAB	MI	12	15 CB-302	V	LAB	MI	12	15 CB-302	W	T	JU	14	16 CB-302	W	T	LU	14	16 CB-302	W	LAB	LU	8	11 CB-312	U	T	LU	16	18 CB-312	U	T	MA	16	18 CB-312	U	LAB	JU	12	15 CB-312	U	LAB	JU	12	15 CB-312	V	T	MA	16	18 CB-312	V	T	MI	16	18 CB-312	V	LAB	JU	16	19 CB-312	V	LAB	JU	16	19 CB-312	W	T	LU	10	12 CB-312	W	T	MI	10	12 CB-312	W	LAB	LU	12	15 CB-312	W	LAB	LU	12	15 CB-313	U	T	LU	16	18 CB-313	U	LAB	VI	16	19 CB-313	V	T	LU	16	18 CB-313	V	LAB	JU	16	19 CB-402	U	T	VI	16	18 CB-402	U	PC	SA	10	12 CB-402	V	T	MA	10	12 CB-402	V	PC	JU	8	10 CB-402	W	T	VI	18	20 CB-402	W	PC	SA	12	14 CB-402	X	T	VI	10	12 CB-402	X	PC	JU	10	12 CB-402	Y	T	VI	10	12 CB-402	Y	PC	JU	10	12 CB-412	U	T	JU	18	20 CB-412	U	PC	SA	8	10 CB-412	V	T	VI	8	10 CB-412	V	PC	MA	8	10 GP-101	U	T	JU	14	16 GP-101	U	P	VI	16	18 GP-101	V	T	MA	16	18 GP-101	V	P	MI	16	18 GP-102	U	T	MI	16	18 GP-102	U	P	JU	16	18 GP-102	V	T	LU	18	20 GP-102	V	P	MI	18	20 GP-112	U	T	MI	11	14 GP-112	U	P	JU	10	12 GP-112	V	T	LU	10	13 GP-112	V	P	JU	10	12 GP-113	U	T	MI	16	19 GP-113	U	P	JU	16	18 GP-113	V	T	MA	10	13 GP-113	V	P	JU	10	12 GP-114	U	T	MA	14	16 GP-114	U	P	JU	14	16 GP-122	U	P	MI	16	18 GP-122	V	P	MA	18	20 GP-122	W	P	SA	12	14 GP-123	U	T	LU	14	16 GP-123	U	P	MI	14	16 GP-123	V	T	LU	16	18 GP-123	V	P	MI	16	18 GP-133	U	T	MI	12	14 GP-133	U	P	MI	14	16 GP-133	V	T	LU	14	16 GP-133	V	P	MA	14	16 GP-134	U	T	MA	18	20 GP-134	U	P	JU	18	20 GP-134	V	T	MA	18	20 GP-134	V	P	JU	18	20 GP-154	U	T	LU	20	22 GP-154	U	P	VI	20	22 GP-154	V	T	MA	20	22 GP-154	V	P	JU	20	22 GP-205	U	T	LU	20	22 GP-205	U	P	MI	20	22 GP-223	U	T	MA	16	18 GP-223	U	P	JU	16	18 GP-223	V	T	MA	16	18 GP-223	V	P	JU	16	18 GP-223	W	T	MI	18	20 GP-223	W	P	MI	20	22 GP-233	U	T	MA	14	16 GP-233	U	P	JU	14	16 GP-233	V	T	LU	16	18 GP-233	V	P	VI	16	18 GP-233	W	T	MA	18	20 GP-233	W	P	JU	18	20 GP-234	U	T	MA	14	16 GP-234	U	P	MI	14	16 GP-234	V	T	MI	12	14 GP-234	V	P	JU	12	14 GP-234	W	T	MA	18	20 GP-234	W	P	MA	20	22 GP-235	U	T	JU	16	18 GP-235	U	P	VI	16	18 GP-235	V	T	MA	20	22 GP-235	V	P	JU	20	22 GP-235	W	T	VI	18	20 GP-235	W	P	VI	20	22 GP-244	U	T	LU	18	20 GP-244	U	P	LU	20	21 GP-244	V	T	VI	19	20 GP-244	V	P	VI	20	22 GP-304	U	T	LU	14	16 GP-304	U	P	MI	14	16 GP-304	V	T	MA	16	18 GP-304	V	P	JU	16	18 GP-304	W	T	LU	18	20 GP-304	W	P	VI	18	20 GP-314	U	T	SA	8	10 GP-314	U	P	SA	10	12 GP-314	V	T	LU	16	18 GP-314	V	P	MI	16	18 GP-314	W	T	SA	8	10 GP-314	W	P	SA	10	12 GP-324	U	T	LU	16	18 GP-324	U	P	MI	16	18 GP-334	V	T	VI	16	17 GP-334	V	P	VI	17	19 GP-403	U	T	MI	12	14 GP-403	U	P	JU	12	14 GP-403	V	T	MA	16	18 GP-403	V	P	JU	16	18 GP-404	U	T	MA	18	20 GP-404	U	P	JU	18	20 GP-404	V	T	LU	16	18 GP-404	V	P	VI	16	18 GP-514	U	T	JU	14	16 GP-514	U	P	JU	16	18 GP-514	V	T	LU	16	18 GP-514	V	P	MA	16	18 GP-515	U	T	MA	16	18 GP-515	U	P	MA	18	20 GP-515	V	T	LU	16	18 GP-515	V	P	MI	16	18 GP-515	W	T	LU	18	20 GP-515	W	P	MI	18	20 GP-515	X	T	LU	18	20 GP-515	X	P	LU	20	22 GP-525	U	T	MA	17	20 GP-525	U	P	VI	18	20 GP-525	V	T	MA	17	20 GP-525	V	P	LU	18	20 GP-525	W	T	MA	17	20 GP-525	W	P	JU	18	20 GP-535	U	P	LU	16	18 GP-535	U	P	MI	16	18 GP-535	V	P	MI	18	20 GP-535	V	P	MI	20	22 GP-545	U	P	MI	16	18 GP-545	U	P	MI	18	20 GP-545	V	P	MI	18	20 GP-545	V	P	MI	20	22 GP-555	U	T	SA	8	10 GP-555	U	P	SA	10	12 GP-555	V	T	JU	18	20 GP-555	V	P	VI	18	20 GP-575	U	T	LU	16	18 GP-575	U	P	JU	18	20 GP-575	V	T	MA	20	22 GP-575	V	P	JU	20	22 GP-585	U	P	VI	18	20 GP-202	U	T	MA	8	10 GP-202	U	P	JU	8	10 GP-202	V	T	LU	10	12 GP-202	V	P	JU	10	12 GP-202	W	T	LU	14	16 GP-202	W	P	MI	14	16 GP-202	X	T	LU	16	18 GP-202	X	P	MI	16	18 GP-203	U	T	MA	14	16 GP-203	U	P	JU	14	16 GP-203	V	T	MA	16	18 GP-203	V	P	JU	16	18 GP-203	W	T	LU	10	12 GP-203	W	P	JU	10	12 HS-101	U	T	LU	8	9 HS-101	U	P	LU	9	11 HS-101	V	T	JU	8	9 HS-101	V	P	JU	9	11 HS-101	W	T	SA	8	9 HS-101	W	P	SA	9	11 HS-101	X	T	SA	11	12 HS-101	X	P	SA	12	14 HS-102	U	P	JU	20	22 HS-102	U	T	MI	18	21 HS-102	V	T	SA	10	13 HS-102	V	P	VI	8	10 HS-111	U	T	MA	8	10 HS-111	U	P	MI	10	12 HS-111	V	T	LU	10	12 HS-111	V	P	LU	16	18 HS-111	W	T	MA	8	10 HS-111	W	P	MA	14	16 HS-111	X	T	LU	14	16 HS-111	X	P	MA	10	12 HS-121	U	P	JU	14	16 HS-121	U	T	MA	14	16 HS-121	V	T	LU	8	10 HS-121	V	P	JU	8	10 HS-121	W	T	MI	12	14 HS-121	W	P	VI	16	18 HS-131	U	T	MA	10	12 HS-131	V	T	JU	10	12 HS-131	W	T	VI	10	12 HS-141	U	T	SA	10	12 HS-141	V	T	SA	8	10 HS-141	W	T	VI	8	10 HS-141	X	T	VI	10	12 HS-144	U	T	LU	16	17 HS-144	U	P	LU	17	19 HS-151	U	T	VI	19	20 HS-151	U	P	VI	20	22 HS-161	U	P	LU	18	20 HS-161	V	P	MI	18	20 HS-201	U	T	MI	14	16 HS-201	V	T	JU	16	18 HS-201	W	T	VI	10	12 HS-201	X	T	VI	12	14 HS-204	U	T	MI	16	18 HS-204	V	T	JU	18	20 HS-204	W	T	SA	8	10 HS-405	U	T	LU	18	20 HS-405	U	P	MA	18	20 ST-101	U	T	LU	16	18 ST-101	U	P	MI	16	18 ST-101	V	T	JU	8	10 ST-101	V	P	JU	10	12 ST-103	U	T	JU	18	20 ST-103	U	P	JU	20	22 ST-103	V	T	VI	18	20 ST-103	V	P	VI	20	22 ST-111	U	T	LU	18	20 ST-111	U	P	MI	18	20 ST-111	V	T	MI	14	16 ST-111	V	P	MI	16	18 ST-113	U	T	MI	10	12 ST-113	U	P	JU	12	14 ST-113	V	T	MI	10	12 ST-113	V	P	VI	10	12 ST-113	W	P	VI	12	14 ST-113	W	T	JU	10	12 ST-113	X	T	JU	10	12 ST-113	X	P	VI	12	14 ST-113	Y	T	MA	8	10 ST-113	Y	P	MI	10	12 ST-114	U	T	VI	14	16 ST-114	U	P	VI	16	18 ST-114	V	T	MI	14	16 ST-114	V	P	MI	16	18 ST-114	W	T	MA	14	16 ST-114	W	P	JU	14	16 ST-123	U	T	MA	16	18 ST-123	U	P	JU	16	18 ST-123	V	T	MA	10	12 ST-123	V	P	MI	10	12 ST-123	W	T	MA	16	18 ST-123	W	P	JU	16	18 ST-123	X	T	JU	18	20 ST-123	X	P	JU	20	22 ST-124	U	T	LU	18	20 ST-124	U	P	MI	18	20 ST-124	V	T	JU	18	20 ST-124	V	P	JU	20	22 ST-124	W	T	SA	14	16 ST-124	W	P	SA	16	18 ST-133	U	T	SA	13	15 ST-133	U	P	SA	15	17 ST-133	V	T	MI	18	20 ST-133	V	P	MI	20	22 ST-133	W	T	LU	10	12 ST-133	W	P	LU	12	14 ST-202	U	T	LU	10	11 ST-202	U	P	LU	11	12 ST-202	U	P	VI	14	17 ST-202	V	T	LU	17	18 ST-202	V	P	LU	18	22 ST-202	W	T	VI	16	17 ST-202	W	P	VI	17	18 ST-202	W	P	SA	14	17 ST-203	U	T	MA	18	20 ST-203	U	P	JU	20	22 ST-203	V	T	JU	18	20 ST-203	V	P	JU	20	22 ST-203	W	T	SA	8	10 ST-203	W	P	SA	10	12 ST-204	U	P	LU	18	20 ST-204	U	P	MI	18	20 ST-204	U	P	VI	18	20 ST-204	V	P	MA	19	22 ST-204	V	P	JU	19	22 ST-205	U	T	LU	18	20 ST-205	U	P	LU	20	22 ST-205	V	T	SA	8	10 ST-205	V	P	SA	10	12 ST-213	U	T	MA	18	21 ST-213	U	P	VI	18	22 ST-213	V	T	LU	18	21 ST-213	V	P	VI	18	22 ST-213	W	T	MI	12	15 ST-213	W	P	MI	15	16 ST-213	W	P	VI	13	16 ST-214	U	T	MA	18	20 ST-214	U	P	MA	20	22 ST-214	V	P	JU	18	20 ST-214	V	T	MA	20	22 ST-215	U	T	LU	20	22 ST-215	U	P	MI	20	22 ST-215	V	T	JU	18	20 ST-215	V	P	JU	20	22 ST-221	U	T	LU	16	18 ST-221	U	P	MA	8	10 ST-221	V	P	MA	8	10 ST-221	V	T	MI	10	12 ST-221	W	P	MA	8	10 ST-221	W	T	VI	8	10 ST-221	X	P	MA	8	10 ST-221	X	T	LU	8	10 ST-222	U	P	MI	14	16 ST-222	U	T	LU	12	14 ST-222	V	P	VI	8	10 ST-222	V	T	MI	8	10 ST-222	W	T	MA	14	16 ST-222	W	P	MA	16	18 ST-231	U	P	VI	20	22 ST-231	V	P	MA	18	20 ST-232	U	T	JU	10	11 ST-232	U	P	JU	11	13 ST-232	U	P	MA	10	12 ST-232	V	T	SA	8	9 ST-232	V	P	SA	9	13 ST-232	W	T	LU	9	10 ST-232	W	P	LU	10	14 ST-235	U	P	VI	18	22 ST-235	V	P	LU	18	22 ST-235	W	P	MA	18	22 ST-235	X	P	MA	14	18 ST-236	U	P	VI	18	22 ST-236	V	P	MA	18	22 ST-253	U	T	VI	14	16 ST-253	U	P	VI	16	18 ST-254	U	T	JU	18	20 ST-254	U	P	JU	20	22 ST-255	U	T	SA	9	11 ST-255	U	P	SA	11	13 ST-255	V	T	MA	18	20 ST-255	V	P	MA	20	22 ST-264	U	T	SA	8	10 ST-264	U	P	SA	10	12 ST-264	V	T	SA	9	11 ST-264	V	P	SA	11	13 ST-265	U	T	VI	18	20 ST-265	U	P	VI	20	22 ST-274	U	T	LU	20	22 ST-274	U	P	MI	20	22 ST-275	U	T	JU	18	20 ST-275	U	P	JU	20	22 ST-275	V	T	VI	18	20 ST-275	V	P	VI	20	22 ST-285	U	T	SA	15	16 ST-285	U	P	SA	16	20 ST-285	V	T	SA	8	9 ST-285	V	P	SA	9	13 ST-295	U	P	LU	18	20 ST-295	U	T	MI	18	20 ST-295	V	T	LU	18	20 ST-295	V	P	LU	20	22 ST-314	U	T	SA	10	12 ST-314	U	P	SA	12	14 ST-314	V	T	LU	14	16 ST-314	V	P	MI	12	14 ST-324	U	T	MI	18	20 ST-324	U	P	MI	20	22 ST-324	V	T	VI	14	16 ST-324	V	P	VI	16	18 ST-334	U	P	MI	16	18 ST-334	U	T	LU	16	18 ST-334	V	P	JU	14	16 ST-334	V	T	MA	14	16 ST-344	U	T	MI	19	20 ST-344	U	P	MI	20	22 ST-414	U	T	MA	16	18 ST-414	U	P	MA	18	20 ST-414	V	T	MI	18	20 ST-414	V	P	MI	20	22 ST-415	U	T	SA	14	16 ST-415	U	P	SA	16	18 TP-103	U	T	MA	18	20 TP-103	U	P	JU	18	20 TP-103	V	T	LU	14	16 TP-103	V	P	MI	14	16 TP-113	U	T	LU	18	20 TP-113	U	P	MI	18	20 TP-113	U	P	JU	20	22 TP-113	V	T	LU	13	16 TP-113	V	P	MI	13	16 TP-123	U	T	MA	12	14 TP-123	U	P	JU	12	14 TP-123	V	T	MI	18	20 TP-123	V	P	MI	20	22 TP-203	U	T	MA	14	16 TP-203	U	P	JU	14	16 TP-203	V	T	LU	16	18 TP-203	V	P	MI	16	18 TP-213	U	T	LU	8	11 TP-213	U	P	VI	8	11 TP-213	V	T	MA	8	11 TP-213	V	P	JU	8	11 TP-223	U	T	MA	8	10 TP-223	U	P	MI	8	11 TP-223	V	T	MI	8	10 TP-223	V	P	VI	8	11 TP-223	W	T	MI	10	12 TP-223	W	P	VI	8	11 TP-224	U	T	LU	20	22 TP-224	U	P	MI	18	20 TP-224	V	T	MA	16	18 TP-224	V	P	MI	16	18 TP-244	U	T	LU	16	18 TP-244	U	P	JU	16	18 TP-244	V	T	MA	16	18 TP-244	V	P	JU	16	18 TP-254	U	T	JU	18	20 TP-254	U	P	JU	20	22 TP-254	V	T	LU	16	18 TP-254	V	P	LU	18	20 TP-254	W	T	MA	16	18 TP-254	W	P	MA	18	20 TP-301	U	T	SA	8	10 TP-301	U	P	VI	15	18 TP-301	U	PC	MI	14	16 TP-301	V	T	MI	8	10 TP-301	V	P	VI	13	16 TP-301	V	PC	MI	14	16 TP-301	W	T	LU	12	14 TP-301	W	P	VI	13	16 TP-301	W	PC	MI	14	16 TP-301	X	T	JU	8	10 TP-301	X	P	LU	8	11 TP-301	X	PC	MI	14	16 TP-302	U	T	SA	8	10 TP-302	U	P	SA	10	12 TP-302	V	T	LU	18	20 TP-302	V	P	MI	16	18 TP-302	W	T	VI	18	20 TP-302	W	P	SA	10	12 TP-303	U	T	MI	14	16 TP-303	U	P	JU	16	18 TP-303	V	T	MI	14	16 TP-303	V	P	VI	14	16 TP-304	U	T	MI	16	18 TP-304	U	P	VI	16	18 TP-304	V	T	SA	12	14 TP-304	V	P	SA	14	16 TP-313	U	T	MA	17	18 TP-313	U	P	MA	18	22 TP-314	U	T	LU	18	21 TP-314	U	P	JU	18	21 TP-314	V	T	LU	19	22 TP-314	V	P	MI	19	22 TP-324	U	T	MA	16	18 TP-324	U	P	JU	16	18 TP-404	U	T	LU	16	18 TP-404	U	P	LU	18	20 TP-404	V	T	LU	20	22 TP-404	V	P	VI	20	22 TP-414	U	T	JU	18	20 TP-503	U	T	LU	14	16 TP-503	U	P	MA	14	16 TP-503	V	T	LU	16	18 TP-503	V	P	MI	16	18 TP-505	U	T	MA	16	18 TP-505	U	P	JU	16	18 TP-505	V	T	MI	18	20 TP-505	V	P	JU	18	20";
vector<string> dataTeachers = { "ACOSTA DE LA CRUZ, PEDRO RA�L","ACOSTA DE LA CRUZ, PEDRO RA�L","VASQUEZ  DOMINGUEZ, RIQUELMER","VASQUEZ  DOMINGUEZ, RIQUELMER","KALA BEJAR, LOURDES","KALA BEJAR, LOURDES","ACOSTA DE LA CRUZ, PEDRO RA�L","ALVARADO  RODRIGUEZ, LUIS","ACOSTA DE LA CRUZ, PEDRO RA�L","KALA BEJAR, LOURDES","KALA BEJAR, LOURDES","HUAMAN SANCHEZ,  ALEJANDRO","HUAMAN SANCHEZ,  ALEJANDRO","CERNADEZ  G�MEZ, JES�S","CERNADEZ  G�MEZ, JES�S","ANGULO PEREZ, JOSU�","ANGULO PEREZ, JOSUE","BENITES YARLEQU�, JOS� VALERIO","BENITES YARLEQU�, JOS� VALERIO","TOCTO INGA, PAUL MILLER","TOCTO INGA, PAUL MILLER","ALVARADO  RODRIGUEZ, LUIS","ALVARADO  RODRIGUEZ, LUIS","KALA BEJAR, LOURDES","ALVARADO  RODRIGUEZ, LUIS","VASQUEZ  DOMINGUEZ, RIQUELMER","VASQUEZ  DOMINGUEZ, RIQUELMER","VASQUEZ  DOMINGUEZ, RIQUELMER","HUAMAN SANCHEZ,  ALEJANDRO","HUAMAN SANCHEZ,  ALEJANDRO","HUAMAN SANCHEZ,  ALEJANDRO","HUAMAN SANCHEZ,  ALEJANDRO","BERMEO CARRASCO, OSMAR","BERMEO CARRASCO, OSMAR","BERMEO CARRASCO, OSMAR","HUALPA GUTIERREZ WALTER ANTONIO","HUALPA GUTIERREZ WALTER ANTONIO","SOTOMAYOR ARAMBURU,FERNANDO","SOTOMAYOR ARAMBURU,FERNANDO","ARAMBULO OSTOS, CARLOS","ARAMBULO OSTOS, CARLOS","ARAMBULO OSTOS, CARLOS","ECHEANDIA CESPEDES, JAVIER","ECHEANDIA CESPEDES, JAVIER","ECHEANDIA CESPEDES, JAVIER","IQUISE MAMANI,  LUIS","IQUISE MAMANI,  LUIS","IQUISE MAMANI,  LUIS","BERMEO CARRASCO, OSMAR","BERMEO CARRASCO, OSMAR","BERMEO CARRASCO, OSMAR","ALVARADO  RODRIGUEZ, LUIS","ALVARADO  RODRIGUEZ, LUIS","ALVARADO  RODRIGUEZ, LUIS","ECHEANDIA CESPEDES, JAVIER","ECHEANDIA CESPEDES, JAVIER","ECHEANDIA CESPEDES, JAVIER","ARAMBULO OSTOS, CARLOS","ARAMBULO OSTOS, CARLOS","MONCADA  CAJAVILCA, V�CTOR JOS�","CHUNG CHING, RICARDO  ALEJANDRO","CHUNG CHING, RICARDO  ALEJANDRO","CHUNG CHING, RICARDO  ALEJANDRO","CERNADEZ  G�MEZ, JES�S","CERNADEZ  G�MEZ, JES�S","ANGULO PEREZ, JOSUE","ANGULO PEREZ, JOSU�","ANGULO PEREZ, JOSU�","TOCTO INGA, PAUL MILLER","TOCTO INGA, PAUL MILLER","ALC�NTARA MALCA, DANIEL","HIDALGO  RODR�GUEZ, JOS�","ALC�NTARA MALCA, DANIEL","CHAFLOQUE EL�AS, CARLOS ALBERTO","OSORIO   MARUJO,  BILMA","REYES ACOSTA,  ROSARIO","HIDALGO  RODR�GUEZ, JOS�","ALC�NTARA MALCA, DANIEL","FUKUDA KAGAMI, NANCY","OSORIO   MARUJO,  BILMA","RONDINEL  PINEDA, PETRA ELINE","FUKUDA KAGAMI, NANCY","HIDALGO  RODR�GUEZ, JOS�","REYES ACOSTA,  ROSARIO","RONDINEL  PINEDA, PETRA ELINE","FUKUDA KAGAMI, NANCY","HIDALGO  RODR�GUEZ, JOS�","ALC�NTARA MALCA, DANIEL","LESCANO  �VILA, LUIS","CHAFLOQUE EL�AS, CARLOS ALBERTO","FUKUDA KAGAMI, NANCY","LESCANO  �VILA, LUIS","LESCANO  �VILA, LUIS","SALCEDO  TORRES,  JOAQUIN","SALCEDO  TORRES, JOAQUIN","PE�A YALICO, VICENTE","VALDIVIA MENDOZA,  H�CTOR","CA�OTE FAJARDO,  PERCY","CA�OTE FAJARDO,  PERCY","SAN BARTOLOME, JAIME","TAFUR ANZUALDO,GELACIO","VALDIVIA  MENDOZA,  H�CTOR","VALDIVIA  MENDOZA,  H�CTOR","MOSQUERA MOLINA, MIGUEL","SALCEDO  TORRES,  JOAQUIN","SALCEDO  TORRES,  JOAQUIN","SALCEDO  TORRES,  JOAQUIN","SAN BARTOLOME, JAIME","CA�OTE FAJARDO,  PERCY","CA�OTE FAJARDO,  PERCY","SAN BARTOLOME, JAIME","TAFUR ANZUALDO,GELACIO","TAFUR ANZUALDO,GELACIO","TAFUR ANZUALDO,GELACIO","PE�A YALICO, VICENTE","MOSQUERA MOLINA, MIGUEL","CA�OTE FAJARDO,  PERCY","CA�OTE FAJARDO,  PERCY","VALDIVIA  MENDOZA,  H�CTOR","VALDIVIA  MENDOZA,  H�CTOR","SEGURA GARC�A, YOLANDA","SEGURA GARC�A, YOLANDA","CERNA VALDEZ,YARKO","CERNA VALDEZ,YARKO","SEGURA GARC�A, YOLANDA","SEGURA GARC�A, YOLANDA","CERNA VALDEZ,YARKO","CERNA VALDEZ,YARKO","NAVARRO  HUAMANI,  LUIS","NAVARRO  HUAMANI,  LUIS","SEGURA GARC�A, YOLANDA","SEGURA GARC�A, YOLANDA","CERNA VALDEZ,YARKO","CERNA VALDEZ,YARKO","RODR�GUEZ FRANCO,  WALDO ALEJANDRO","RODR�GUEZ FRANCO,  WALDO ALEJANDRO","MORILLO  ROJAS, DANIEL","MORILLO  ROJAS, DANIEL","ROJAS MENDOZA,  DORIS FANNY","ROJAS MENDOZA,  DORIS FANNY","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","LAU CARRILLO,  CARMEN IVONNE","FERNANDEZ LOSTAUNAU, CESAR ANTONIO","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","RODR�GUEZ FRANCO,  WALDO ALEJANDRO","RODR�GUEZ FRANCO,  WALDO ALEJANDRO","ARCE SOLIS DE URBINA, IRENE","ARCE SOLIS DE URBINA, IRENE","ARCE SOLIS DE URBINA, IRENE","ARCE SOLIS DE URBINA, IRENE","HUAMAN� HUAMAN�,  GLORIA TERESITA","MORILLO ROJAS, DANIEL","CIEZA DE LE�N TUESTA,  EDUARDO  JOS�","LLANCCE  MONDRAG�N, LUISA","LLANCCE  MONDRAG�N, LUISA","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","SEDANO SANTIAGO,  INOCENTE  CIRILO","SEDANO SANTIAGO,  INOCENTE  CIRILO","VILLANUEVA HERRERA,  JOS� ALBERTO","VILLANUEVA HERRERA,  JOS� ALBERTO","PONCE S�NCHEZ,  CARLOS FIDEL","PONCE S�NCHEZ,  CARLOS FIDEL","AVILES GONZALES, GLADIS MARIBEL","AVILES GONZALES, GLADIS MARIBEL","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","CAICEDO  BUSTAMANTE, V�CTOR ANTONIO","MORILLO  ROJAS, DANIEL","MORILLO  ROJAS, DANIEL","VALDIVIA  CAMACHO,  GLORIA ESTHER","NN","LEYTON DIAZ, V�CTOR ADOLFO","LEYTON DIAZ, V�CTOR ADOLFO","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","VALLE SANTOS,  JOHN CLERK","VALLE SANTOS,  JOHN CLERK","LEYTON DIAZ, V�CTOR ADOLFO","LEYTON DIAZ, V�CTOR ADOLFO","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","ORIA CHAVARRIA, WILLIAM","ORIA CHAVARRIA, WILLIAM","VALDIVIA  CARDENAS, DANIEL","FERN�NDEZ LOSTAUNAU, C�SAR ANTONIO","EYZAGUIRRE TEJADA, ROBERTO  ERASMO","EYZAGUIRRE TEJADA, ROBERTO  ERASMO","LINARES VALENCIA,  JOS� ANTONIO","LINARES VALENCIA,  JOS� ANTONIO","FLORES CISNEROS,  ERNESTO  ROBINSON","FLORES CISNEROS,  ERNESTO  ROBINSON","ORIA CHAVARRIA, WILLIAM","ORIA CHAVARRIA, WILLIAM","LINARES VALENCIA,  JOS� ANTONIO","LINARES VALENCIA,  JOS� ANTONIO","LINARES VALENCIA,  JOS� ANTONIO","LINARES VALENCIA,  JOS� ANTONIO","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","FALCON�  V�SQUEZ,  RODOLFO  EL�AS","Z�RATE OT�ROLA,  LEONIDAS  BENITO","Z�RATE OT�ROLA,  LEONIDAS  BENITO","HUAMAN�  HUAMAN�,  GLORIA TERESITA","HUAMAN� HUAMAN�,  GLORIA TERESITA","VALENCIA  NAP�N, ADOLFO ELEAZAR","VALENCIA  NAP�N, ADOLFO ELEAZAR","SEDANO SANTIAGO,  INOCENTE  CIRILO","SEDANO SANTIAGO,  INOCENTE  CIRILO","FLORES BASHI, CARLOS ANTONIO","FLORES BASHI, CARLOS ANTONIO","VICTORIA  BAZAN, VLADIMIR","VICTORIA  BAZAN, VLADIMIR","Z�RATE OT�ROLA,  LEONIDAS  BENITO","Z�RATE OT�ROLA,  LEONIDAS  BENITO","L�PEZ ALIAGA CAZORLA,  RAFAEL","L�PEZ ALIAGA CAZORLA,  RAFAEL","HUAMAN�  HUAMAN�,  GLORIA TERESITA","HUAMAN�  HUAMAN�,  GLORIA TERESITA","PONCE S�NCHEZ,  CARLOS FIDEL","PONCE S�NCHEZ,  CARLOS FIDEL","ACU�A PINAUD, LEONCIO  LUIS","ACU�A PINAUD, LEONCIO  LUIS","VALENCIA  NAP�N, ADOLFO ELEAZAR","VALENCIA  NAP�N, ADOLFO ELEAZAR","ZALD�VAR  ALVAREZ,  OSCAR GUILLERMO","ZALD�VAR  ALVAREZ,  OSCAR GUILLERMO","VILLANUEVA HERRERA,  JOS� ALBERTO","VILLANUEVA HERRERA,  JOS� ALBERTO","Z�RATE OT�ROLA,  LEONIDAS  BENITO","Z�RATE OT�ROLA,  LEONIDAS  BENITO","LLANCCE  MONDRAG�N, LUISA","LLANCCE  MONDRAG�N, LUISA","FLORES BASHI, CARLOS ANTONIO","FLORES BASHI, CARLOS ANTONIO","SHEPUT MOORE, JUAN MANUEL","SHEPUT MOORE, JUAN MANUEL","FLORES CISNEROS,  ERNESTO  ROBINSON","FLORES CISNEROS,  ERNESTO  ROBINSON","VALDIVIA  CARDENAS, DANIEL","VALDIVIA  CARDENAS, DANIEL","FLORES BASHI, CARLOS ANTONIO","FLORES BASHI, CARLOS ANTONIO","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","VALDIVIA  CAMACHO,  GLORIA ESTHER","VALDIVIA  CAMACHO,  GLORIA ESTHER","LAU CARRILLO,  CARMEN IVONNE","LAU CARRILLO,  CARMEN IVONNE","ROJAS MENDOZA,  DORIS FANNY","ROJAS MENDOZA,  DORIS FANNY","ORIA CHAVARRIA, WILLIAM","ORIA CHAVARRIA, WILLIAM","VALDIVIA  CARDENAS, DANIEL","VALDIVIA  CARDENAS, DANIEL","FLORES CISNEROS,  ERNESTO  ROBINSON","FLORES CISNEROS,  ERNESTO  ROBINSON","PONCE S�NCHEZ,  CARLOS FIDEL","PONCE S�NCHEZ,  CARLOS FIDEL","RODR�GUEZ  FRANCO, WALDO ALEJANDRO","QUINTEROS CH�VEZ, SILVIO","QUINTEROS CH�VEZ, SILVIO","MIRANDA TORRES, C�SAR","MIRANDA TORRES, C�SAR","MONDRAGON HERN�NDEZ, MARGARITA","MONDRAGON HERN�NDEZ, MARGARITA","MONDRAGON HERN�NDEZ, MARGARITA","MONDRAGON HERN�NDEZ, MARGARITA","MIRANDA  TORRES,  C�SAR","MIRANDA  TORRES,  C�SAR","MIRANDA  TORRES,  C�SAR","MIRANDA  TORRES,  C�SAR","ORTEGA LOAYZA,  Daniel","ORTEGA LOAYZA,  Daniel","CHAVARRI  ARCE, RAQUEL MARTHA","CHAVARRI  ARCE, RAQUEL MARTHA","CHAVARRI  ARCE, RAQUEL MARTHA","CHAVARRI  ARCE, RAQUEL MARTHA","TAIPE ARIAS, JOHN EDISON","TAIPE ARIAS, JOHN EDISON","TAIPE ARIAS, JOHN EDISON","TAIPE ARIAS, JOHN EDISON","HUAMAN�  HUAMAN�,  �NTERO SALUTINIANO","HUAMAN�  HUAMAN�,  �NTERO SALUTINIANO","HUERTA ORTEGA,  JAVIER","HUERTA ORTEGA,  JAVIER","CHAVARRI  ARCE, RAQUEL MARTHA","CHAVARRI  ARCE, RAQUEL MARTHA","ACEVEDO  RAYMUNDO,Sa�l","ACEVEDO  RAYMUNDO,Sa�l","ACEVEDO  RAYMUNDO,Sa�l","ACEVEDO  RAYMUNDO,Sa�l","ACEVEDO  RAYMUNDO,Sa�l","ACEVEDO  RAYMUNDO,Sa�l","KRAJNIK STULIN, FRANCO","KRAJNIK STULIN, FRANCO","ORTEGA LOAYZA,  Daniel","ORTEGA LOAYZA,  Daniel","LESCANO  �VILA, LUIS","LESCANO  �VILA, LUIS","CHAVARRI  ARCE, RAQUEL MARTHA","SANCHEZ  HUARINGA, CARLOS","SANCHEZ  HUARINGA, CARLOS","CAMPANA  A�ASCO,  RILDO","CAMPANA  A�ASCO,  RILDO","AYALA FALC�N,  ELOY ELADIO","AYALA FALC�N,  ELOY ELADIO","VALDIVIA  CAMACHO,  GLORIA ESTHER","VALDIVIA  CAMACHO,  GLORIA ESTHER","CAMPANA  A�ASCO,  RILDO","CAMPANA  A�ASCO,  RILDO","MONDRAGON HERN�NDEZ, MARGARITA","MONDRAGON HERN�NDEZ, MARGARITA","HUAMAN�  HUAMAN�,  �NTERO SALUTINIANO","HUAMAN� HUAMAN�,  �NTERO SALUTINIANO","HUERTA ORTEGA,  JAVIER","HUERTA ORTEGA,  JAVIER","HUAMAN� HUAMAN�,  �NTERO SALUTINIANO","HUAMAN� HUAMAN�,  �NTERO SALUTINIANO","HUERTA ORTEGA,  JAVIER","VILLANUEVA HERRERA,  JOS� ALBERTO","VILLANUEVA HERRERA,  JOS� ALBERTO","MORALES  CUELLAR,  MERY NOEMI","MORALES  CUELLAR,  MERY NOEMI","GUZM�N YANGATO,  JORGE FERNANDO","GUZM�N YANGATO,  JORGE FERNANDO","CANCHANO CARO, JAVIER TOLENTINO","CANCHANO CARO, JAVIER TOLENTINO","LLANOS PANDURO,  JORGE DANIEL","LLANOS PANDURO,  JORGE DANIEL","TOCTO INGA, PAUL MILLER","TOCTO INGA, PAUL MILLER","FISFALEN  HUERTA,  MARIO","FISFALEN  HUERTA,  MARIO","ALVAREZ  ALVAREZ,  JORGE","ALVAREZ  ALVAREZ,  JORGE","CANELO SOTELO,  C�SAR ALDO","FERN�NDEZ LOSTAUNAU, C�SAR ANTONIO","ALVAREZ  ALVAREZ,  JORGE","ALVAREZ  ALVAREZ,  JORGE","MEDINA AQUINO,  LUIS FELIPE","FERN�NDEZ LOSTAUNAU, C�SAR ANTONIO","EYZAGUIRRE TEJADA, ROBERTO  ERASMO","FERN�NDEZ LOSTAUNAU, C�SAR ANTONIO","PUCCIO QUEVEDO,  BRUNO JUAN","PUCCIO QUEVEDO,  BRUNO JUAN","MEDINA AQUINO,  LUIS FELIPE","MEDINA AQUINO,  LUIS FELIPE","CANELO SOTELO,  C�SAR ALDO","CANELO SOTELO,  C�SAR ALDO","MEDINA AQUINO,  LUIS FELIPE","MEDINA AQUINO,  LUIS FELIPE","EYZAGUIRRE TEJADA, ROBERTO  ERASMO","EYZAGUIRRE TEJADA, ROBERTO  ERASMO","CANELO SOTELO,  C�SAR ALDO","CANELO SOTELO,  C�SAR ALDO","ULFE VEGA, LUIS ALBERTO","ULFE VEGA, LUIS ALBERTO","SOTELO VILLENA,  JUAN CARLOS","SOTELO VILLENA,  JUAN CARLOS","ZULOAGA  ROTTA, LUIS ALBERTO","ZULOAGA  ROTTA, LUIS ALBERTO","PACHECO  VERA CESAR ABRAHAM","PACHECO  VERA CESAR ABRAHAM","M�NDEZ VALDIVIA,  CELEDONIO","M�NDEZ VALDIVIA,  CELEDONIO","LLANOS PANDURO,  JORGE DANIEL","LLANOS PANDURO,  JORGE DANIEL","PORTILLO  CAMPBELL, JOS� HUGO","PORTILLO  CAMPBELL,  JOS� HUGO","C�RDOVA  NERI, TEODORO  LUCIANO","C�RDOVA  NERI, TEODORO  LUCIANO","C�RDOVA  NERI, TEODORO  LUCIANO","CABALLERO ORTIZ, JOS� ALBERTO","CABALLERO ORTIZ, JOS� ALBERTO","PALACIOS  REZZA, ROY DAVID","PALACIOS  REZZA, ROY DAVID","PALACIOS  REZZA, ROY DAVID","REYNA MONTEVERDE, TINO EDUARDO","REYNA MONTEVERDE, TINO EDUARDO","MONROY  MIRANDA,  ARIEL LUDWING","MONROY  MIRANDA,  ARIEL LUDWING","MEZA YANGALI,  C�SAR","MEZA YANGALI,  C�SAR","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","CARRANZA  BARRENA  WILFREDO","CARRANZA  BARRENA  WILFREDO","RODR�GUEZ ULLOA, RICARDO,  AURELIO","RODR�GUEZ ULLOA, RICARDO,  AURELIO","TEJADA MALASPINA, MIGUEL �NGEL","TEJADA MALASPINA, MIGUEL �NGEL","ZULOAGA  ROTTA, LUIS ALBERTO","ZULOAGA  ROTTA, LUIS ALBERTO","ANTAURCO TRUJILLO,  JES�S WALTER","ANTAURCO TRUJILLO,  JES�S WALTER","PERFECTO  MANRIQUE, WILMER","PERFECTO  MANRIQUE, WILMER","PERFECTO  MANRIQUE, WILMER","VELARDE  CARPIO, MANUEL HELARF","VELARDE  CARPIO, MANUEL HELARF","REYNA MONTEVERDE, TINO EDUARDO","REYNA MONTEVERDE, TINO EDUARDO","BRINGAS  MASGO, ISAAC ERNESTO","BRINGAS  MASGO, ISAAC ERNESTO","TRIGO P�REZ, CARLOS ALFREDO","TRIGO P�REZ, CARLOS ALFREDO","SOTELO VILLENA,  JUAN CARLOS","SOTELO VILLENA,  JUAN CARLOS","RAMOS BALL�N,  GRIMANESA","RAMOS BALL�N,  GRIMANESA","ACOSTA DE LA CRUZ, PEDRO RA�L","ACOSTA DE LA CRUZ, PEDRO RA�L","C�RDOVA  NERI, TEODORO  LUCIANO","C�RDOVA  NERI, TEODORO  LUCIANO","RAMOS BALL�N,  GRIMANESA","RAMOS BALL�N,  GRIMANESA","ARADIEL CASTA�EDA, HILARIO","ARADIEL CASTA�EDA, HILARIO","LUJ�N CAMPOS,  LUIS ALBERTO","LUJ�N CAMPOS,  LUIS ALBERTO","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","ROJAS SOLIS, YSABEL","PERFECTO  MANRIQUE,  WILMER","PERFECTO  MANRIQUE,  WILMER","C�RDOVA  NERI, TEODORO  LUCIANO","HANCCO CARPIO, RONY JORDAN","HANCCO CARPIO, RONY JORDAN","GARCIA LA RIVA JOSE CARLOS","GARCIA LA RIVA JOSE CARLOS","SOTELO VILLENA,  JUAN CARLOS","OPORTO DIAZ, SAMUEL ALONSO","RODRIGUEZ RAFAEL, GLEN DARIO","UN JAN LIAU HING, EMILIO ALBERTO","MORALES  CUELLAR,  MERY NOEMI","UN JAN LIAU HING, EMILIO ALBERTO","M�NDEZ VALDIVIA,  CELEDONIO","M�NDEZ VALDIVIA,  CELEDONIO","CALIZAYA  NEIRA, PERCY","CALIZAYA  NEIRA, PERCY","CANCHANO CARO, JAVIER TOLENTINO","CANCHANO CARO, JAVIER TOLENTINO","GUZM�N YANGATO,  JORGE FERNANDO","GUZM�N YANGATO,  JORGE FERNANDO","HIROMOTO  HIROMOTO, FELIPE TSUTOMU","HIROMOTO  HIROMOTO, FELIPE TSUTOMU","REYNA MONTEVERDE, TINO EDUARDO","REYNA MONTEVERDE, TINO EDUARDO","VILCAPOMA ESCURRA,  EDGAR SOCR�TES","VILCAPOMA ESCURRA,  EDGAR SOCR�TES","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","S�NCHEZ  ESPINOZA,  JAVIER CONCEPCI�N","HUARCAYA JUNES, ALEJANDRINA NELLY","HUARCAYA JUNES, ALEJANDRINA NELLY","ARTEAGA  CORTEZ,  HUMBERTO URBANO","ARTEAGA  CORTEZ,  HUMBERTO URBANO","SIMICH L�PEZ, V�CTOR ARTURO","SIMICH L�PEZ, V�CTOR ARTURO","RAMOS MORENO,  JAIME IGNACIO","RAMOS MORENO,  JAIME IGNACIO","MORALES  CUELLAR,  MERY NOEMI","MORALES  CUELLAR,  MERY NOEMI","LLANOS PANDURO,  JORGE DANIEL","LLANOS PANDURO,  JORGE DANIEL","ZAMORA RAM�REZ,  JOS� ALBERTO","ZAMORA RAM�REZ,  JOS� ALBERTO","GALVEZ LEGUA MAURICIO","GALVEZ LEGUA MAURICIO","RAMOS MONTES CARLOS","RAMOS MONTES CARLOS","GALVEZ LEGUA MAURICIO","GALVEZ LEGUA MAURICIO","CARRANZA  MILLA, EMERSON","CARRANZA  MILLA, EMERSON","BORJA ROSALES,  RUB�N ARTURO","BORJA ROSALES,  RUB�N ARTURO","GUZM�N YANGATO,  JORGE FERNANDO","GUZM�N YANGATO,  JORGE FERNANDO","PORTILLO  CAMPBELL,  JOS� HUGO","PORTILLO  CAMPBELL,  JOS� HUGO","OPORTO DIAZ, SAMUEL ALONSO","OPORTO DIAZ, SAMUEL ALONSO","ZELA MORAYA,  WESTER EDISON","ZELA MORAYA,  WESTER EDISON","TARAZONA  PONTE, SANTIAGO","TARAZONA  PONTE, SANTIAGO","BENITES YARLEQU�, JOS� VALERIO","BENITES YARLEQU�, JOS� VALERIO","TARAZONA  PONTE, SANTIAGO","TARAZONA  PONTE, SANTIAGO","TARAZONA  PONTE, SANTIAGO","BORJA ROSALES,  RUB�N ARTURO","BORJA ROSALES,  RUB�N ARTURO","CARRANZA  MILLA, EMERSON","CARRANZA  MILLA, EMERSON","GALVEZ LEGUA,  MAURICIO","GALVEZ LEGUA, MAURICIO","CRUZ FIGUEROA,  GUILLERMO ROLD�N","CRUZ FIGUEROA,  GUILLERMO ROLD�N","MONCADA  CAJAVILCA, V�CTOR JOS�","MONCADA  CAJAVILCA, V�CTOR JOS�","PARRA OSORIO,  HERN�N JULIO","PARRA OSORIO,  HERN�N JULIO","CHAFLOQUE EL�AS, CARLOS ALBERTO","CHAFLOQUE EL�AS, CARLOS ALBERTO","PARRA OSORIO,  HERN�N JULIO","PARRA OSORIO,  HERN�N JULIO","RONDINEL  PINEDA, PETRA ELINE","RONDINEL  PINEDA, PETRA ELINE","OSORIO MARUJO,  BILMA","OSORIO MARUJO,  BILMA","MU�OZ INGA, CARLOS","MU�OZ INGA, CARLOS","CRUZ FIGUEROA,  GUILLERMO ROLD�N","CRUZ FIGUEROA,  GUILLERMO ROLD�N","HUAM�N URETA, PE�AFORT  LUIS","HUAM�N URETA, PE�AFORT  LUIS","AG�ERO MAURICIO,  ALFREDO  ROLANDO","AG�ERO MAURICIO,  ALFREDO  ROLANDO","MU�OZ INGA, CARLOS","MU�OZ INGA, CARLOS","Z��IGA MERCADO,  ANTONIO","Z��IGA MERCADO,  ANTONIO","Z��IGA MERCADO,  ANTONIO","Z��IGA MERCADO,  ANTONIO","CALLO MOSCOSO,  LUIS ALBERTO","CALLO MOSCOSO,  LUIS ALBERTO","CALLO MOSCOSO,  LUIS ALBERTO","MONZ�N  FERN�NDEZ, JORGE FELIPE","MONZ�N  FERN�NDEZ, JORGE FELIPE","MONZ�N  FERN�NDEZ, JORGE FELIPE","MONCADA  CAJAVILCA, V�CTOR JOS�","MONCADA  CAJAVILCA, V�CTOR JOS�","MONCADA  CAJAVILCA,  V�CTOR JOS�","MONZ�N FERN�NDEZ, JORGE FELIPE","MONZ�N FERN�NDEZ, JORGE FELIPE","MONZ�N FERN�NDEZ, JORGE FELIPE","CIEZA DE LE�N TUESTA, EDUARDO  JOS�","CIEZA DE LE�N TUESTA,  EDUARDO  JOS�","MU�OZ INGA, CARLOS","MU�OZ INGA, CARLOS","CALLO MOSCOSO,  LUIS ALBERTO","CALLO MOSCOSO,  LUIS ALBERTO","CRUZ FIGUEROA,  GUILLERMO ROLD�N","CRUZ FIGUEROA,  GUILLERMO ROLD�N","AG�ERO MAURICIO,  ALFREDO  ROLANDO","AG�ERO MAURICIO,  ALFREDO  ROLANDO","AG�ERO MAURICIO,  ALFREDO  ROLANDO","AG�ERO MAURICIO,  ALFREDO  ROLANDO","CALLO MOSCOSO,  LUIS ALBERTO","CALLO MOSCOSO,  LUIS ALBERTO","NN","NN","HUAM�N URETA, PE�AFORT  LUIS","HUAM�N URETA, PE�AFORT  LUIS","CIEZA DE LE�N TUESTA,  EDUARDO  JOS�","CIEZA DE LE�N TUESTA,  EDUARDO  JOS�","KRAJNIK STULIN, FRANCO","KRAJNIK STULIN, FRANCO","TERRASSE  ARROYO,  ROLANDO","TERRASSE  ARROYO,  ROLANDO","VALENCIA  NAP�N, ADOLFO ELEAZAR","VALENCIA  NAP�N, ADOLFO ELEAZAR","TERRASSE  ARROYO,  ROLANDO","LAU CARRILLO,  CARMEN IVONNE","LAU CARRILLO,  CARMEN IVONNE","ACU�A PINAUD, LEONCIO  LUIS","ACU�A PINAUD, LEONCIO  LUIS","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","EG�ZQUIZA FIGUEROA,  MAR�A ENERINA","KRAJNIK STULIN, FRANCO","KRAJNIK STULIN, FRANCO"};
int main(){
	//cout << data.size() << " " << dataTeachers.size() << endl;
	for(int i = 0 ; i < (int)coursesCode.size() ; ++i )
		mapaCourseId[coursesCode[i]] = i;
	
	map< string , int > mapaDay;
	for( int i = 0 ; i < (int)days.size() ; ++i )
		mapaDay[ days[ i ] ] = i;
	istringstream in( data );
	string course , section , type , day;
	int hBegin , hEnd;
	int pos = 0;
	while( in >> course >> section >> type >> day >> hBegin >> hEnd ){
		//cout << course << " " << section << " " << type << " " << day << " " << hBegin << " " << hEnd << endl;
		int itCourse;
		if( !mapaCourse.count( course ) ){
			itCourse = mapaCourse.size();
			mapaCourse[ course ] = itCourse;
			//add one more
			courseName.push_back( course );
			T.push_back( map< string , vector< pair< int , int > > >() );
		}else{
			itCourse = mapaCourse[ course ];
		}
		int d = mapaDay[ day ];

		if( !T[ itCourse ].count( section ) ){
			T[ itCourse ][ section ];
			
		}
		//pos ++;
		teachers[ course + section ].insert( dataTeachers[ pos++ ] );
		//cout << course + section << endl;
		for( int h = hBegin ; h < hEnd ; ++h ){
				T[ itCourse ][ section ].push_back( make_pair( d , h ) );
			}
	}
	/*
	cout << pos << endl;
	return 0;
	*/
	cin >> minCourses >> maxCourses >> maxCred;
	string cad , conj;
	int oblig;
	while( cin >> cad >> conj >> oblig ){
		P.push_back( mapaCourse[ cad ] );
		SEC.push_back( conj );
		for(auto sec : conj) SET.insert(cad + string(1,sec));
		O.push_back( oblig );
	}
	
	back( 0 , 0 , 0 );
}



