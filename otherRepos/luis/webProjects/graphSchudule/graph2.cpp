digraph G{
	//IA,TOPICOS,GESTION,SEGURIDAD,MERCA[style=filled,color=".7 .3 1.0"];
	//1er Ciclo
	INTRO -> TGS;
	INTRO -> METODO;
	QUIMICA;
	ANALITICA -> LINEAL;
	DIFERENCIAL -> INTEGRAL;
	DIFERENCIAL -> ALGORITMO;
	TECNICAS -> METODO;
	DESARROLLO -> FILO;
	DESARROLLO -> CONSTI;
	//2do Ciclo
	TGS -> DINAMICA;
	TGS -> AYD;
	ALGORITMO -> LPE;
	LINEAL -> DISCRETA;
	LINEAL -> MULTI;
	INTEGRAL -> MULTI;
	INTEGRAL -> ESTADISTICA;
	INTEGRAL -> FISICA1;
	METODO -> FISICA1;
	METODO -> SOCIO;
	FILO -> SOCIO;
	CONSTI -> LEGISLACION;
	//3er ciclo
	LPE -> LPOO;
	DISCRETA -> DIGITALES;
	MULTI -> NUMERICO;
	MULTI -> ECUA;
	MULTI -> MICRO;
	ESTADISTICA -> IO1;
	ESTADISTICA -> APLICADA;
	FISICAI -> NUMERICO;
	FISICAI -> FISICA2;
	SOCIO -> MICRO;
	//4to ciclo
	LPOO -> MODELAMIENTO;
	NUMERICO -> MATEAPLICADA;
	ECUA -> DINAMICA;
	ECUA -> MATEAPLICADA;
	FISICA2 -> ELECTRICOS;
	FISICA2 -> MODERNA;
	MICRO -> CONTA;
	MICRO -> MACRO;
	MICRO -> OYM;
	//5to ciclo
	MODELAMIENTO -> AYD;
	IO1 -> PRODUCTIVOS;
	IO1 -> IO2;
	ELECTRICOS -> DIGITALES;
	MODERNA -> DIGITALES;
	OYM -> CREATIVIDAD;
	//6to ciclo
	DINAMICA -> SIMULACION;
	AYD -> ABD;
	AYD -> TALLER;
	PRODUCTIVOS -> LOGISTICA;
	DIGITALES -> ARQUI;
	DIGITALES -> OPERATIVOS;
	CONTA -> COSTOS;
	//7mo ciclo
	SIMULACION -> IA;
	ABD -> IA;
	TALLER -> TOPICOS;
	TALLER -> TESIS1;
	ARQUI -> SCD;
	OPERATIVOS -> SCD;
	COSTOS -> GESTION;
	COSTOS -> LEGISLACION;
	CREATIVIDAD -> MERCA;
	//8vo ciclo
	SCD -> SEGURIDAD;
	GESTION -> TESIS1;
	GESTION -> DYEP;
	LEGISLACION -> DYEP;
	MERCA -> PLANEAMIENTO;
	//9no ciclo
	TOPICOS -> ANE;
	TESIS1 -> TESIS2;
	SEGURIDAD -> AUDITORIA;
	DYEP -> GPI;
	PLANEAMIENTO -> IE;
	//ELECTIVOS
	METODO -> IDEOLOGIAS;
	IDEOLOGIAS -> REALIDAD;
	LPOO -> DISEŅOGRAFICO;
	OYM -> COMPORTAMIENTO;
	CONTA -> SISTECONOMICOS;
	MACRO -> SISTECONOMICOS;
	CONTA -> ANALISISECONOMICO;
	MACRO -> ANALISISECONOMICO;
	AYD -> TDA;
	DISEŅOGRAFICO -> TALLERHERRAMIENTASRV;
	DINAMICA -> SISTHUMANOS;
	COMPORTAMIENTO -> ADMRH;
	IO2 -> TD;
	TALLER -> TALLER2;
	ABD -> TALLER2;
	TALLER -> CALIDAD;
	TALLER -> KM;
	TALLER -> TLENG;
	COSTOS -> SISTCOSTOS;
	CREATIVIDAD -> MODELOSGE;
	IA -> IAAVANZADA;
	CALIDAD -> INGSOFTAVANZ;
	LOGISTICA -> AUTOMATIZACION;
	SCD -> SERVCD;
	GESTION -> BOLSA;
	GESTION -> FINANCIAMIENTO;
	GESTION -> DIAGNOSTICO;
	GESTION -> GESTIONNEG1;
	CREATIVIDAD -> GESTIONNEG1;
	LEGISLACION -> TOPICOSNEG;
	MERCA -> COMERCIO;
	AUTOMATIZACION -> ROBOTICA;
	//1er ciclo
	{ rank = same; INTRO QUIMICA DIBUJO ANALITICA DIFERENCIAL TECNICAS DESARROLLO }
	//2do ciclo
	{ rank = same; TGS ALGORITMO LINEAL INTEGRAL METODO FILO CONSTI }
	//3er ciclo
	{ rank = same; LPE DISCRETA MULTI ESTADISTICA FISICA1 SOCIO }
	//4to ciclo
	{ rank = same; LPOO NUMERICO ECUA MICRO APLICADA FISICA2 }
	//5to ciclo
	{ rank = same; MODELAMIENTO MATEAPLICADA IO1 ELECTRICOS MODERNA MACRO OYM }
	//6to ciclo
	{ rank = same; DINAMICA AYD PRODUCTIVOS IO2 DIGITALES CONTA }
	//7mo ciclo
	{ rank = same; SIMULACION ABD TALLER ARQUI OPERATIVOS COSTOS CREATIVIDAD }
	//8vo ciclo
	{ rank = same; IA LOGISTICA SCD GESTION LEGISLACION MERCA }
	//9no ciclo
	{ rank = same; TOPICOS TESIS1 SEGURIDAD DYEP PLANEAMIENTO }
	//10mo ciclo
	{ rank = same; ANE TESIS2 AUDITORIA GPI IE }
	//electivos
	{ IDEOLOGIAS,REALIDAD,LITERATURA,PROTOCOLO,DISEŅOGRAFICO,TALLERHERRAMIENTAS1,COMPORTAMIENTO,SISTECONOMICOS,ANALISISECONOMICO,TDA,TALLERHERRAMIENTASRV,SISTHUMANOS,ADMRH,TD,TALLER2,CALIDAD,KM,TLENG,SISTCOSTOS,MODELOSGE,IAAVANZADA,INGSOFTAVANZ,AUTOMATIZACION,SERVCD,BOLSA,FINANCIAMIENTO,DIAGNOSTICO,GESTIONNEG1,TOPICOSNEG,COMERCIO,ROBOTICA[style=filled,color=".7 .3 1.0"] }
}


