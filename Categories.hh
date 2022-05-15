 /** @file Categories.hh
  *  @brief Especificación de la clase Categories
  */

#ifndef _CATEGORIES_HH
#define _CATEGORIES_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

/** @class Categories
 *  @brief Contiene la información relativa a las categorías.
 */
class Categories
{
	private:
		vector<string> names;
		vector< vector<int> > ctg_scores;
		int C, K;
	
	public:

		// Creadoras

		/** @brief 
		 *	\pre  _cierto_
		 *	\post Crea la clase de categorías con categorías iniciales
		 */
		//Categories();


		// Modificadoras

		/** @brief Lee la información de las categorías
		 *	\pre `C >= 1`, `K >= 4`
		 *	En el canal de entrada hay primero C strings con los nombres
		 *	asociados a las categorías identificadas por los valores de 1 a C
		 *	en orden creciente.
		 *	Luego, en el canal de entrada hay CxK enteros >= 0 que serán los 
		 *	puntos por categoría y nivel ordenados crecientemente por 
		 *	categorías y dentro de cada categoría, ordenados crecientemente por
		 *	nivel. 
		 *	\post Se borra el contenido de 'this->ctg_scores' y reempleza con 
		 *	los puntos por categoría y nivel en el canal de entrada. Se borra
		 *	el contenido de 'this->names' y se reemplaza con los nombres en el
		 *	canal de entrada.
		 */
		void read_categories(int C, int K);


		// Consultoras

		/** @brief Obtiene las putunaciones por nivel de una categoría
		 *	\pre `1 <= c < C = names.size()`
		 *	\post Retorna el valor de `ctg_scores` para la categoría `c`
		 */
		vector<int> get_ctg_scores(int c) const;

		/** @brief Obtiene el número de categorías en la clase
		 *	\pre _cierto_
		 *	\post Retorna el número de categorías que hay actualmente en la
		 *	clase
		 */
		int count_categories() const;

		/** @brief Obtiene el número de rangos
		 *	\pre _cierto_
		 *	\post Retorna el número de rangos para los cuales la clase tiene
		 *	valores de puntuación
		 */
		int get_rank_depth() const;

		/** @brief Obtener el nombre de una categoría
		 *	\pre 1 <= c <= C
		 *	\post Retorna el nombre de la categoría con identificador c
		 */
		string get_name(int c) const;


		// Escritoras

		/** @brief Imprime las categorías
		 *	\pre _cierto_
		 *	\post Para cada categoría, imprime su nombre y en orden creciente
		 *	las puntuaciones por nivel
		 */
		void list_categories();

};
#endif
