#define DIRECTIONTYPES 3
#define DIAGONALTYPES 4

class LinesGenerator {
public:
	std::vector<Line> giveMeLines(int linesAmount) {

		/*
			Genera un set de lineas usando *getRandomLine() por tamanio definido por *linesAmount

			Complejidad: O(c) siendo c igual a linesAmount 
		*/

		std::vector<Line> generatedLines;	
		
		for (int _ = 0; _ < linesAmount; _++)
			generatedLines.push_back( getRandomLine() );

		return generatedLines;
	}

	Line getRandomLine() {

		/*
			Se encarga de generar una linea en una direccion aleatoria, tomando
			dos puntos aleatorios* para formar una recta comprendida entre
			WIDTH y HEIGHT

			Complejidad: O(c) 
		*/

		Line line;

		int direction = rand() % DIRECTIONTYPES ; // choose direction

		int randomX = rand() % WIDTH;
		int randomY = rand() % HEIGHT;
  
	   switch(direction) {
	  
	    case VERTICAL: 
	    	line.setFirstPoint( {randomX, 0} );
	      line.setSecondPoint( {randomX, HEIGHT} );
	      line.type = VERTICAL;
	    break;

	    case HORIZONTAL: 
	      line.setFirstPoint( {0, randomY} );
	      line.setSecondPoint( {WIDTH, randomY} );
	      line.type = HORIZONTAL;
	    break;

	    case DIAGONAL: 

	    	int diagonalType = rand() % DIAGONALTYPES + 2;
	    	line.type = diagonalType ;
			
			if (diagonalType ==  BOTTOM_TO_LEFT) {
    			line.setFirstPoint( {randomX, HEIGHT} );
      		line.setSecondPoint( {0, randomY} ); 
	     	} 
	     	else if (diagonalType == BOTTOM_TO_RIGHT) {
      		line.setFirstPoint( {randomX, HEIGHT} );
      		line.setSecondPoint( {WIDTH, randomY} );
	      } 
	      else if (diagonalType == TOP_TO_LEFT) {
	      	line.setFirstPoint( {randomX, 0} );
	      	line.setSecondPoint( {0, randomY} );
	      } 
	      else if (diagonalType == TOP_TO_RIGHT) {
	      	line.setFirstPoint( {randomX, 0} );
	      	line.setSecondPoint( {WIDTH, randomY} );
	      }

	    break;
	  }

		return line;
	}

};