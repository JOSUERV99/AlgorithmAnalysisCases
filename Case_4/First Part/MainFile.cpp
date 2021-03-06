
/*  [ author: Josue Andrey Rojas Vega ]  */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "PowerRelationsGraph.cpp"
#include "Utils.cpp"

#define COMPLETE_TEXT_FILENAME 	"El_libro_de_Urantia.txt" 		
#define STOP_WORDS_FILENAME 		"Stop_words_set.txt"

using namespace Utils;

int main() {

	/*  Idea de trabajo:
			[1] Extraer las palabras descartando caracteres innecesarios 						  
			[2] Agregar las palabras que cumpla con el criterio   
			[3] Generar el grafo, registrando sus apariciones y las relaciones como un arco 
			donde el peso representa las veces que se han relacionado esas dos palabras. La 
			relacion entre las dos se hara tomando en cuenta alguna de estas alternativas:
					- Palabra anterior y consecutiva
					- Palabras dentro de la misma oracion
			[4] Una vez dada la precarga del grafo de palabras y ordenacion de palabras 
			para consulta por poder de palabra respecto al texto y uso de relaciones 
	*/

	PowerRelationsGraph graph(COMPLETE_TEXT_FILENAME, STOP_WORDS_FILENAME); 
	graph.getReady();

	// Querying for groups
	std::string queryedWord = "hombre";
	int requestedGroups = 4;
	auto groups = graph.getPowerGroups( queryedWord, requestedGroups );
	show( groups, queryedWord, requestedGroups );

	// Querying for power words
	int requestedPowerWords = 5;
	auto powerWords = graph.getPowerWords( requestedPowerWords );
	show( powerWords );

	// Querying for dominated words
	std::string poweredWord = "hombre";
	auto dominatedWords = graph.getDominatedWords( poweredWord );
	show (dominatedWords, poweredWord);

	return EXIT_SUCCESS;
}