/**	@file Statistics.hh
 	@brief Especificación de la clase Statistics
*/

#ifndef _STATISTICS_HH
#define _STATISTICS_HH

#ifndef NO_DIAGRAM
#include <set>
#include <string>
#include <iostream>
#endif

/**	@class Statistics
 *  @brief Contiene las estadísticas de un jugador.
 *
 *  Se puede utilizar para transmitir la información de los resultados de un 
 *  jugador en un torneo. Es una clase puramente informativa.
 */
class Statistics
{
	private:
		int tournaments, points;
		int matches_won, matches_lost;
		int sets_won, sets_lost;
		int games_won, games_lost;
	
	public:
		
		// Creadoras

		/** @brief Creadora por defecto
		 *	\pre _cierto_
		 *	\post Crea unas estadísticas con todos los int inicializados en 0
		 *	y el set de 'tournaments' vacío.
		 */
		Statistics();

		/** @brief Creadora por copia
		 *	\pre _cierto_
		 *	\post Crea estadísticas con un número de torneo
		 */
		Statistics(int tournaments);


		// Modificadoras

		/** @brief Actualiza las estadísticas sumando de nuevas
		 *	\pre _cierto_
		 *	\post Se actualizan los valors privados con los de stats, añadiendo
		 *	el torneo en 'stats.first_tournament()' si 
		 */
		void add_stats(const Statistics& stats);

		/** @brief Obtener puntos
		 *	\pre n >= 0
		 *	\post Actualiza los puntos contenidos en 'this->points'
		 */
		void set_points(int n);

		/** @brief Actualizar partidos ganados
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->matches_won'
		 */
		void set_matches_won(int n);

		/** @brief Actualizar partidos perdidos
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->matches_lost'
		 */
		void set_matches_lost(int n);

		/** @brief Actualizar sets ganados
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->sets_won'
		 */
		void set_sets_won(int n);

		/** @brief Actualizar sets perdidos
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->sets_lost'
		 */
		void set_sets_lost(int n);

		/** @brief Actualizar juegos ganados
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->games_won'
		 */
		void set_games_won(int n);

		/** @brief Actualizar juegos perdidos
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->games_lost'
		 */
		void set_games_lost(int n);

		/** @brief Actualizar torneos jugados
		 *	\pre n >= 0
		 *	\post Actualiza el contenido de 'this->tournaments'
		 */
		void set_tournaments(int n);
		
		// Consultoras

		/** @brief Obtener puntos
		 *	\pre _cierto_
		 *	\post Retorna los puntos contenidos en 'this->points'
		 */
		int get_points() const;

		/** @brief Obtener torneos jugados
		 *	\pre _cierto_
		 *	\post Retorna la cantidad de torneos jugados
		 */
		int get_tournaments() const;

		/** @brief Obtener partidos ganados
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->matches_won'
		 */
		int get_matches_won() const;

		/** @brief Obtener partidos perdidos
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->matches_lost'
		 */
		int get_matches_lost() const;

		/** @brief Obtener sets ganados
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->sets_won'
		 */
		int get_sets_won() const;

		/** @brief Obtener sets perdidos
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->sets_lost'
		 */
		int get_sets_lost() const;

		/** @brief Obtener juegos ganados
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->games_won'
		 */
		int get_games_won() const;

		/** @brief Obtener juegos perdidos
		 *	\pre _cierto_
		 *	\post Retorna el contenido de 'this->games_lost'
		 */
		int get_games_lost() const;


		// Escritoras

		/** @brief Imprime las estadísticas
		 *	\pre _cierto_
		 *	\post En el canal de salida hay todas las estadísticas en el
		 *	format adecuado.
		 */
		void print_statistics() const;
};

#endif
