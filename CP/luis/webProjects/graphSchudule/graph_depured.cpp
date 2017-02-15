digraph G{
	node[shape=box];
	rankdir = LR;
	TOPICOS,TESIS1,DYEP,PLANEAMIENTO,AUDITORIA[style=filled,color=".7 .3 1.0"];

	//9no ciclo
	TOPICOS -> ANE;
	TESIS1 -> TESIS2;
	DYEP -> GPI;
	PLANEAMIENTO -> IE;
	//

	//9no ciclo
	{ rank = same; TOPICOS TESIS1 DYEP PLANEAMIENTO }
	//1mo ciclo
	{ rank = same; ANE TESIS2 AUDITORIA GPI IE }
	
}
