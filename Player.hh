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
 *  @brief Esta clase extiende la funcionalidad de Statistics para comprender 
 *  los rankings en el circuito.
 */
class Player : public Statistics {
	private:
		/** @brief Ranking del jugador */
		int ranking;

	public:

		// Creadoras

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con ranking `rk` y estadísticas vacías
		 */
		Player(int rk);

		/** @brief Canviar el ranking
		 *	\pre `1 <= n`
		 *	\post Canvia el valor de `this->ranking`
		 */
		void set_ranking(int n);


		// Consultoras

		/** @brief Obtener el ranking del jugador
		 *	\pre _cierto_
		 *	\post Retorna el ranking (puede que sea temporal) del jugador
		 */
		int get_ranking() const;

};

#endif
