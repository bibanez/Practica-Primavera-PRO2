/** @file Ranking.hh
 *	@brief Especificación de la clase Ranking
 */

#ifndef _RANKING_HH
#define _RANKING_HH

#include "Player.hh"
#include "Statistics.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#endif

using namespace std;

/** @class Ranking
 * 	@brief Contiene el ranking y las estadísticas de los jugadores en un 
 *	circuito. Implementa también las funciones necesarias para actualizar este
 *	ranking con los resultados de torneos.
 */
class Ranking 
{
	/** @brief Facilita la lectura de los iteradores del mapa de jugadores
	 */
	typedef map<string,Player>::iterator Player_it;

	private:
		/** @brief Contiene las estadísticas de los jugadores y sus rankings.
		 */
		map<string,Player> stats; 			

		/** @brief Contiene los punteros a los elementos del mapa de jugadores.
		 */
		vector<Player_it> ranking;

		// Auxiliares 

		/** @brief Corrige el ranking dentro de los Players en un intervalo
		 *	\pre `0 <= i < j <= ranking.size()`
		 *	\post Se actualizan los rankings de los jugadores en el intervalo
		 *	`[i,j)`
		 */
		void update_ranking(int i, int j);

		/** @brief Ordena los jugadores en el ranking
		 *	\pre _cierto_
		 *	\post El vector `ranking` está ordenado en orden decreciente de
		 *	puntuación y en caso de empate, por anterioridad de rango.
		 */
		void sort_ranking();

		/** @brief Comparar puntuación de jugadores
          *  \pre _cierto_
          *  \post Retorna cierto si el jugador a tiene más puntuación que b.
          */
		static bool cmp(const Player_it& a, const Player_it& b);

	public:
		
		// Creadoras
		
		/** @brief Creadora
		 * 	\pre _cierto_
		 * 	\post Crea un ranking con 0 jugadores
		 */
		Ranking();


		// Modificadoras

		/** @brief Añade un jugador
		 *	\pre _cierto_
		 *	\post Añade un jugador con nombre `name` y el último ranking. Se 
		 *	añade en el diccionario de estadísticas con todas a 0. Retorna 
		 *	`false` si el ranking ya contiene un jugador con el mismo nombre 
		 *	`name`.
		 */
		bool add_player(const string& name);

		/** @brief Elimina un jugador
		 *	\pre _cierto_
		 *	\post Elimina al jugador con nombre `name` del ranking y el 
		 *	diccionario de estadísticas. Retorna `false` si el ranking no 
		 *	contiene ningún jugador con nombre `name`.
		 */
		bool remove_player(const string& name);

		/** @brief Elimina un jugador por su ranking
		 *	\pre _cierto_
		 *	\post Retorna falso si el jugador con rango n no está en el ranking
		 */
		bool remove_player(int n);

		/** @brief Añade los resultados de un torneo
		 *	\pre Todos los valores `key` de `old` y `results` se encuentran en 
		 *	`this->ranking`. El mapa `old` contiene las puntuaciones que se van
		 *	a restar (de la anterior edición del torneo) y el mapa `results` las
		 *	nuevas estadísticas que se van a sumar.
		 *	\post Se actualizan las estadísticas y el ranking con los resultados del torneo.
		 */
		void add_tournament_results(const map<string, int>& old, const map<string, Statistics>& results);

		
		// Consultoras	

		/** @brief Obtiene el nombre asociado al jugador con ranking `n`
		 *	\pre `n <= P = ranking.size()`
		 *	\post Retorna el nombre del jugador con ranking `n`
		 */
		string get_name(int n) const;

		/** @brief Obtener el ranking asociado al jugador con id `name`
		 *	\pre _cierto_
		 *	\post Si el jugador con id `name` no existe, retorna -1. Si no,
		 *	retorna la posición en el ranking de modo que el jugador que esté
		 *	en primera posición retorna 1.
		 */
		int get_ranking(const string& name) const;
		
		/** @brief Obtiene un vector con los nombres asociados a rankings
		 *	\pre rankings.size() <= P = ranking.size(). No hay ningún ranking
		 *	repetido en el vector `rankings`. El vector rankings está ordenado
		 *	por orden creciente. El último valor de rankings es menor o igual al
		 *	tamaño del ranking.
		 *	\post Retorna un vector de nombres con cada índice `i` asociado al 
		 *	jugador con ranking `rankings[i]`
		 */
		vector<string> get_names_from_rankings(const vector<int>& rankings) const;

		/** @brief Obtener el número de jugadores
		 *	\pre _cierto_
		 *	\post Retorna el número de jugadores en el ranking.
		 */
		int count_players() const;


		// Lectoras

		/** @brief Lee jugadores del canal de entrada
		 *	\pre `P >= 0`; En el canal de entrada hay P strings que corresponden
		 *	a los P identificadores de los jugadores
		 *	\post Se añaden P jugadores al ranking con 0 puntos
		 */
		void read_players(int P);


		// Escritoras

		/** @brief Imprime el ranking
		 *	\pre _cierto_
		 *	\post Imprime el ranking por orden creciente, con la posición, el
		 *	nombre y los puntos de cada jugador.
		 */
		void list_ranking();

		/** @brief Imprime los jugadores 
		 *	\pre _cierto_
		 *	\post Imprime los jugadores por orden creciente de identificador
		 *	(nombre), con el nombre, la posición en el ranking, los puntos y
		 *	el resto de estadísticas.
		 */
		void list_players();

		/** @brief Imprime un jugador
		 *	\pre _cierto_
		 *	\post Imprime el nombre, la posición en el ranking, los puntos y
		 *	el resto de estadísticas del jugador con nombre `name`. Si no hay
		 *	ningún jugador con el nombre `name`, retorna falso.
		 */
		bool consult_player(const string& name);
		
};	

#endif
