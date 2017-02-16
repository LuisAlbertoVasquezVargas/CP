digraph G{
	DIGITALES,COSTOS,ABD,LOGISTICA,MERCA[style=filled,color=".7 .3 1.0"];
	
	//6to ciclo
	DIGITALES -> ARQUI;
	DIGITALES -> OPERATIVOS;
	//7mo ciclo
	ABD -> IA;
	ARQUI -> SCD;
	OPERATIVOS -> SCD;
	COSTOS -> GESTION;
	COSTOS -> LEGISLACION;
	//8vo ciclo
	SCD -> SEGURIDAD;
	GESTION -> TESIS1;
	GESTION -> DYEP;
	LEGISLACION -> DYEP;
	MERCA -> PLANEAMIENTO;

	
	
	//6to ciclo
	{ rank = same; DIGITALES }
	//7mo ciclo
	{ rank = same;  ABD  ARQUI OPERATIVOS COSTOS }
	//8vo ciclo
	{ rank = same; IA LOGISTICA SCD GESTION LEGISLACION MERCA }
	//9no ciclo
	{ rank = same; TOPICOS TESIS1 SEGURIDAD DYEP PLANEAMIENTO }

}
