/** @file Tournaments.hh
 *  @brief Especificación de la clase Tournaments
 */

#ifndef _TOURNAMENTS_HH
#define _TOURNAMENTS_HH

#include "Tournament.hh"
#include "Ranking.hh"
#include "Categories.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif

/** @class Tournaments
 *  @brief Contiene todos los torneos del circuito y permite hacer operaciones
 *  con ellos.
 */
class Tournaments
{
	private:
		map<string, Tournament> tournaments;

	public:
		
		// Creadoras
		
		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un conjunto de torneos vacío
		 */
		//Tournaments();


		// Modificadoras

		/** @brief 
		 *	\pre T >= 0;
		 *	En el canal de entrada hay 'T' pares de string t y entero c, donde
		 *	t será el nombre que identifica al torneo (sin repeticiones) y c la
		 *	categoría válida (entre 1 y `C`, de la clase main) a la que 
		 *	pertenece el torneo.
		 *	\post Se borran los torneos que se encuentran en 'this->tournaments'
		 *	y se reemplazan con los que se encuentran en el canal de entrada.
		 */
		void read_starting_tournaments(int T);

		/** @brief Añade un torneo
		 *	\pre 1 <= c <= C
		 *	\post Añade un torneo con identificador 't' y categoría 'c' a 
		 *	'this->tournaments'. Retorna falso si ya existe un torneo con el 
		 *	identificador 't'.
		 */
		bool add_tournament(const string& t, int c);

		/** @brief Elimina un torneo
		 *	\pre _cierto_
		 *	\post Elimina el torneo con identificador 't'. Si no existe, 
		 *	retorna false.
		 */
		bool remove_tournament(const string& t); // Ranking& r

		/** @brief Empieza un torneo
		 *	\pre Los jugadores en 'players' estan ordenados por orden creciente
		 *	de ranking. El torneo con identificador 't' existe.
		 *	\post Se inicia el torneo 't' con los jugadores de 'players'. 
		 *	En el canal de salida hay la tabla de emparejamientos de jugadores
		 *	inscritos.
		 *
		 *  Nota: Cabe llamar a la función 'this->end_tournament()' para leer 
		 *  los resultados del torneo
		 */
		void start_tournament(const string& t, const vector<string>& players);

		/** @brief Termina un torneo
		 *	\pre El torneo con identificador 't' existe y está empezado. En el 
		 *	canal de entrada se encuentran los resultados de los partidos en el
		 *	formato correcto. Todos los jugadores del torneo se encuentran en
		 *	el ranking `r` y la categoría del torneo se encuentra en `ctg`.
		 *	\post Se termina el torneo 't' y se actualizan sus resultados.
		 *  El ranking 'r' se actualiza con los resultados del torneo. En el
		 *  canal de salida hay la tabla de resultados del torneo.
		 */
		void end_tournament(string t, Ranking& r, const Categories& ctg);

		/** @brief Eliminar jugador de todos los torneos que haya jugado
		 *	\pre El jugador con id 'name' existe
		 *	\post Se elimina el jugador de los resultados antiguos de los
		 *	campeonatos.
		 */
		void remove_player(const string& name);


		// Consultoras

		/** @brief Cuenta el número de torneos
		 *	\pre _cierto_
		 *	\post Retorna el número de torneos contenidos en 'this->tournaments'
		 */
		int count_tournaments() const;

		
		// Escritoras
		
		/** @brief Imprimir los torneos
		 *	\pre _cierto_
		 *	\post Se listan, por orden creciente de identificador, el nombre y 
		 *	la categoría de cada torneo en 'this->tournaments'
		 */
		void list_tournaments(const Categories& c) const;

		/** @brief 
		 *	\pre Existe un torneo con identificador 't'
		 *	\post Se imprime en el canal de salida la lista de jugadores y 
		 *	puntos ganados por cada uno en el orden del ranking al empezar el
		 *	torneo por última vez.
		 */
		//void print_tournament_results(string t);

};

#endif
