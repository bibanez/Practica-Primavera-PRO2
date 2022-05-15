/** @file Player.hh
 *  @brief Especificación de la clase Player
 */

#ifndef _PLAYER_HH
#define _PLAYER_HH

#ifndef NO_DIAGRAM
#include <string>
#endif

using namespace std;

/** @class Player
 *  @brief Contiene el nombre y puntuación de un jugador 
 */
class Player {
	private:
		string name;
		int points, tmp, ranking;

	public:

		// Creadoras

		/** @brief Creadora por defecto
		 *	\pre _cierto_
		 *	\post Crea un jugador con nombre vacío y puntuación 0
		 */
		//Player();

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con nombre `name` y puntuación 0
		 */
		Player(const string& name);

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con nombre vacío y puntuación `n`
		 */
		Player(int n);

		/** @brief Creadora
		 *	\pre points >= 0
		 *	\post Crea un jugador con nombre `name` y puntuación `points`
		 */
		Player(const string& name, int points);

		/** @brief Creadora
		 *	\pre _cierto_
		 *	\post Crea un jugador con los mismos parámetros que `p`
		 */
		Player(const Player& p);


		// Modificadoras

		/** @brief Canviar nombre
		 *	\pre _cierto_
		 *	\post Canvia `this->name` por `name`
		 */
		void set_name(const string& name);

		/** @brief Canviar puntuación
		 *	\pre `n >= 0`
		 *	\post Canvia el valor de `this->points` con el valor de `n`
		 */
		void set_points(int n);

		/** @brief Canviar puntuación temporal
		 *	\pre _cierto_
		 *	\post Canvia el valor en `this->tmp`
		 */
		void set_tmp_points(int n);

		/** @brief Canviar el ranking
		 *	\pre `1 <= n`
		 *	\post Canvia el valor de `this->ranking`
		 */
		void set_ranking(int n);
		/** @brief Mueve el valor de `tmp` a `points`
		 *	\pre _cierto_
		 *	\post `points` contiene el previo valor de `tmp`
		 */
		void update_player();


		// Consultoras

		/** @brief Obtener nombre
		 *	\pre _cierto_
		 *	\post Retorna el nombre del jugador en `this->name`
		 */
		string get_name() const;

		/** @brief Obtener puntos
		 *	\pre _cierto_
		 *	\post Retorna los puntos del jugador en `this->points`
		 */
		int get_points() const;

		/** @brief Obtener puntos temporales
		 *	\pre _cierto_
		 *	\post Retorna los puntos temporales del jugador
		 */
		int get_tmp_points() const;

		/** @brief Obtener el ranking del jugador
		 *	\pre _cierto_
		 *	\post Retorna el ranking (puede que sea temporal) del jugador
		 */
		int get_ranking() const;

};

#endif
