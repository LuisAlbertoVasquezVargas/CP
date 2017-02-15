digraph G{
	rankdir = LR;
	//IA,TOPICOS,GESTION,SEGURIDAD,MERCA[style=filled,color=".7 .3 1.0"];

	//9no ciclo
	TOPICOS -> ANE;
	TESIS1 -> TESIS2;
	DYEP -> GPI;
	PLANEAMIENTO -> IE;
	//ELECTIVOS

	DISE�OGRAFICO -> TALLERHERRAMIENTASRV;
	COMPORTAMIENTO -> ADMRH;
	AUTOMATIZACION -> ROBOTICA;

	//9no ciclo
	{ rank = same; TOPICOS,TESIS1,DYEP,PLANEAMIENTO[color=cyan,style=filled] }
	//10mo ciclo
	{ rank = same; ANE TESIS2 AUDITORIA[color=cyan,style=filled] GPI IE }
	//electivos
	//shape=circle
	//{ PROTOCOLO,ANALISISECONOMICO[style=filled,shape=box,color=cyan]}
	{ IDEOLOGIAS,REALIDAD,LITERATURA,DISE�OGRAFICO,TALLERHERRAMIENTAS1,COMPORTAMIENTO,SISTECONOMICOS,TDA,TALLERHERRAMIENTASRV,ADMRH,TALLER2,TLENG,SISTCOSTOS,MODELOSGE,IAAVANZADA,INGSOFTAVANZ,AUTOMATIZACION,SERVCD,BOLSA,FINANCIAMIENTO,DIAGNOSTICO,GESTIONNEG1,TOPICOSNEG,COMERCIO,ROBOTICA[style=filled,shape=box] }
}

