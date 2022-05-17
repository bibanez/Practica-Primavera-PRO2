/** @file Tournament.hh
 * 	@brief Especificación de la clase Tournament
 */

#ifndef _TOURNAMENT_HH
#define _TOURNAMENT_HH

#include "Statistics.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#endif

using namespace std;

/** @class Tournament
 *  @brief Contiene la información de un torneo y permite hacer operaciones
 *  con él.
 */
class Tournament
{
	/** @brief Contiene la información sobre un match, es decir, los jugadores
	 *  que se han enfrentado y el resultado final.
	 */
	struct match {
		int a, b;
		vector< pair<int,int> > result;
	};

	private:

		/** @brief Sirve para guardar el árbol de emparejamientos y resultados
		 *  del torneo.
		 */
		BinTree<match> results;

		/** @brief Guarda la información de los resultados de la edición 
		 *  anterior del torneo, para poderlos restar cuando se finalize la
		 *  nueva.
		 */
		map<string, int> old_results;

		/** @brief Contiene las estadísticas de los jugadores, ordenados por
		 *  ranking de entrada.
		 */
		vector<Statistics> stats;

		/** @brief Contiene los nombres de los jugadores, de acuerdo con los
		 *  índices del vector `stats`.
		 */
		vector<string> names;

		/** @brief Categoría del torneo */
		int c;

		/** @brief Vale `true` si el torneo ha empezado y `false` si ha 
		 *  terminado 
		 */
		bool started;

		/** @brief Calcula el ganador de un match
		 *	\pre El match `m` se ha disputado y tiene al menos un set
		 *	\post Retorna `true` si el jugador `m.a` ha ganado el match y falso
		 *	si lo ha ganado el jugador `m.b` (id numérica).
		 */
		bool first_wins(const match& m) const;

		/** @brief Funcion auxiliar de los emparejamientos
		 *	\pre `a <= max` es el valor del ganador, `s` es $2^{nivel}$ y max
		 *	es el índice máximo.
		 *	\post En `t` hay un cuadro de emparejamientos pero solo con los
		 *	identificadores de los jugadores dentro del ranking del torneo
		 *	Nota: Para iniciar el árbol, se debe pasar como argumentos un `t`
		 *	vacío, `a=1`, `s=2` y `max` dependiendo del número de jugadores.
		 */
		void pairings(BinTree<match>& t, int a, int s, int max);

		/** @brief Calcula los rankings y estadísticas de los jugadores
		 *	\pre `started = false` y se han leído los matches. Rank scores 
		 *	contiene suficientes niveles com los niveles del árbol. 
		 *	`p.size()` es igual a la cantidad de jugadores.
		 *	\post `this->stats` contiene las estadísticas de los jugadores y
		 *	sus puntuaciones
		 */
		void calculate_rankings(const BinTree<match>& t, const vector<int>& rank_scores, vector<int>& p, int k);

		/** @brief Lee un match en el canal de entrada
		 *	\pre En el canal de entrada hay los juegos de un match en el
		 *	formato: `a1-b1,a2-b2,a3-b3`, `a1-b1,a2-b2` o `a-b`
		 *	\post `m.result` contiene los resultados de cada juego
		 */
		void read_match(match& m);

		/** @brief Lee los matches en el canal de entrada
		 *	\pre En el canal de entrada hay los matches en preorden. `t` tiene
		 *	la misma estructura que los datos de entrada. Cada entrada cumple 
		 *	el `pre` de `read_match(match& m)`. Cuando no hay más entradas para
		 *	una rama, se termina leyendo un `0`
		 *	\post `t` contiene la información de los juegos disputados
		 */
		void read_matches(BinTree<match>& t);

		/** @brief Imprimir emparejamientos
		 *	\pre `t` contiene un árbol de enteros válido
		 *	\post Imprime los emparejamientos iniciales
		 */
		void print_pairings(const BinTree<match> &t);

		/** @brief Imprime la tabla de resultados
		 *	\pre _cierto_
		 *	\post En el canal de salida hay la tabla de resultados en el
		 *	formato de la sample
		 */
		void print_table(const BinTree<match>& t);


	public:

		// Creadoras

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un torneo nuevo con categoría `c`
		 */
		Tournament(int c);

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un torneo nuevo con categoría 0
		 */
		Tournament();

		// Modificadoras

		/** @brief Empieza el torneo
		 *	\pre El torneo no se ha empezado aún (es la primera vez que se 
		 *	inicia o bien se ha terminado anterior a empezarlo). 
		 *	`players` contiene los identificadores (nombres) de los jugadores 
		 *	ordenados por ranking previo al torneo.
		 *	`8 <= players.size() <= 2^(K-1)`, donde `K = rank_scores.size()`
		 *	es el número de rangos.
		 *	\post Se inicia el torneo con los jugadores `players` y se guardan
		 *	los resultados antiguos en `this->old_results` para luego restarse
		 *	del ranking cuando se llame end_tournament()
		 */
		void start_tournament(const vector<string>& players);

		/** @brief Finaliza el torneo
		 *	\pre El torneo está empezado y no ha sido terminado ya.
		 *	En el canal de entrada se encuentran los resultados de los partidos 
		 *	en el formato correcto. El vector `rank_scores` está asociado a la 
		 *	categoría `c` y tiene `K` elementos en orden creciente de rango 
		 *	que indican las puntuaciones por rango.
		 *	\post `old` contiene las puntuaciones que deben restarse a los
		 *	jugadores que jugaron la edición pasada del torneo. El mapa `results`
		 *	contiene las estadísticas de cada jugador en el torneo, que serviran 
		 *	para actualizar el ranking. En el canal de salida hay la tabla de 
		 *	resultados y las puntuaciones que ha obtenido cada jugador,
		 *	ordenado por el ranking original. 
		 *
		 *	Nota: Si un jugador no ha recibido puntos, no aparecerá en el canal
		 *	de salida.
		 */
		void end_tournament(map<string, int>& old, map<string, Statistics>& res, const vector<int>& rank_scores);

		/** @brief Elimina un jugador de los resultados antiguos 
		 *	\pre _cierto_
		 *	\post Se elimina del mapa de `old_results` al jugador con id `name`
		 *	Retorna cierto si el jugador existía en el torneo.
		 */
		bool remove_player_from_results(const string& name);


		// Consultoras
		
		/** @brief Obtiene la categoría del torneo
		 *	\pre _cierto_
		 *	\post Retorna el valor de `this->c`
		 */
		int get_category() const;

		/** @brief Obtiene el estado del torneo
		 *	\pre _cierto_
		 *	\post Retorna el valor de `this->started`
		 */
		bool has_started() const;

		/** @brief Obtiene los resultados del torneo en un diccionario
		 *	\pre _cierto_
		 *	\post Retorna un mapa con llaves los nombres de los jugadores y
		 *	valores sus puntuaciones en la última edición del torneo.
		 */
		map<string,int> get_old_results() const;


		// Escritoras
		
		/** @brief Imprime el cuadro de resultados
		 *	\pre Se ha finalizado el torneo al menos una vez
		 *	\post En el canal de salida hay el cuadro de resultados escrito con
		 *	el mismo formato que el juego de pruebas público 
		 */
		void print_results_table();

		/** @brief Imprime la tabla de emparejamientos
		 *	\pre Se ha empezado el torneo al menos una vez
		 *	\post En el canal de salida hay el cuadro de emparejamientos de
		 *	jugadores inscritos.
		 */
		void print_starting_pairs();
};

#endif
