digraph G{
	SCD,TOPICOS,TESIS1,DYEP,IE[style=filled,color=".7 .3 1.0"];

	//8vo ciclo
	SCD -> SEGURIDAD;
	//9no ciclo
	TOPICOS -> ANE;
	TESIS1 -> TESIS2;
	SEGURIDAD -> AUDITORIA;
	DYEP -> GPI;
	//
	
	//8vo ciclo
	{ rank = same; SCD }
	//9no ciclo
	{ rank = same; TOPICOS TESIS1 SEGURIDAD DYEP }
	//1mo ciclo
	{ rank = same; ANE TESIS2 AUDITORIA GPI IE }
	
}
