/** @file Player.hh
 *  @brief Especificación de la clase Player
 */

#ifndef _PLAYER_HH
#define _PLAYER_HH

#include "Statistics.hh"

#ifndef NO_DIAGRAM
#include <string>
#endif

using namespace std;

/** @class Player
 *  @brief Contiene el nombre y puntuación de un jugador 
 */
class Player : public Statistics {
	private:
		int ranking;

	public:

		// Creadoras

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con ranking `rk` y estadísticas vacías
		 */
		Player(int rk);

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con los mismos parámetros que `p`
		 */
		//Player(const Player& p);


		// Modificadoras

		/** @brief Canviar puntuación
		 *	\pre `n >= 0`
		 *	\post Canvia el valor de `this->points` con el valor de `n`
		 */
		//void set_points(int n);

		/** @brief Canviar el ranking
		 *	\pre `1 <= n`
		 *	\post Canvia el valor de `this->ranking`
		 */
		void set_ranking(int n);

		/** @brief Añade estadísticas al parámetro implícito
		 *	\pre `stats` tiene estadísticas válidas
		 *	\post Se añaden las `stats` al parámetro implícito `st`
		 */
		//void add_stats(const Statistics& stats);


		// Consultoras

		/** @brief Obtener puntos
		 *	\pre _cierto_
		 *	\post Retorna los puntos del jugador en `this->points`
		 */
		//int get_points() const;

		/** @brief Obtener el ranking del jugador
		 *	\pre _cierto_
		 *	\post Retorna el ranking (puede que sea temporal) del jugador
		 */
		int get_ranking() const;

};

#endif
