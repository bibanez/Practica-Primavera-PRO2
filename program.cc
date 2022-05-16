/** @mainpage Práctica de PRO2 primavera 2022: Gestión de una liga de tenis profesional.
 *  Éste programa permite controlar un circuito de tenis similar al de la ATP o 
 *  WTA _tour_.
 *	Los posibles comandos son:
 *	1. nuevo_jugador
 *	2. nuevo_torneo
 *	3. baja_jugador
 *	4. baja_torneo
 *	5. iniciar_torneo
 *	6. finalizar_torneo
 *	7. listar_ranking
 *	8. listar_jugadores
 *	9. consultar_jugador
 *	10. listar_torneos
 *	11. listar_categorías
 *	12. fin
 */

/** @file main.cc
 *  @brief Programa principal para la gestión del circuito de tenis.
 */

#include "Tournaments.hh"
#include "Ranking.hh"
#include "Categories.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @brief Programa principal para la Práctica
 */
int main() {
	// Inicializaciones
	
	// Lectura del conjunt de categories
	int C, K;
	cin >> C >> K;
	Categories ctg;
	ctg.read_categories(C, K);

	// Lectura del conjunt inicial de tornejos
	int T;
	cin >> T;
	Tournaments tournaments;
	tournaments.read_starting_tournaments(T);

	// Lectura del conjunt inicial de jugadors
	int P;
	cin >> P;
	Ranking ranking;
	ranking.read_players(P);

	// Bucle de lectura de comandos
	string op;
	cin >> op;
	while (op != "fin") {
		if (op == "nuevo_jugador" or op == "nj") {
			string p;
			cin >> p;
			cout << '#' << op << ' ' << p << endl;
			if (not ranking.add_player(p)) 
				cout << "error: ya existe un jugador con ese nombre" << endl;
			else cout << ranking.count_players() << endl;
		}
		else if (op == "nuevo_torneo" or op == "nt") {
			string t;
			int c;
			cin >> t >> c;
			cout << '#' << op << ' ' << t << ' ' << c << endl;
			if (c < 1 or c > ctg.count_categories())
				cout << "error: la categoria no existe" << endl;
			else if (not tournaments.add_tournament(t, c))
				cout << "error: ya existe un torneo con ese nombre" << endl;
			else cout << tournaments.count_tournaments() << endl;
		}
		else if (op == "baja_jugador" or op == "bj") {
			string p;
			cin >> p;
			cout << '#' << op << ' ' << p << endl;
			if (ranking.remove_player(p)) {
				tournaments.remove_player(p);
				cout << ranking.count_players() << endl;
			}
			else cout << "error: el jugador no existe" << endl;
		}
		else if (op == "baja_torneo" or op == "bt") {
			string t;
			cin >> t;
			cout << '#' << op << ' ' << t << endl;
			if (not tournaments.remove_tournament(t, ranking))
				cout << "error: el torneo no existe" << endl;
			else cout << tournaments.count_tournaments() << endl;
		}
		else if (op == "iniciar_torneo" or op == "it") {
			string t;
			cin >> t;
			cout << '#' << op << ' ' << t << endl;
			int n;
			cin >> n;
			vector<int> ranks(n);
			for (int i = 0; i < n; ++i) cin >> ranks[i];
			vector<string> players = ranking.get_names_from_rankings(ranks);	
			tournaments.start_tournament(t, players);
		}
		else if (op == "finalizar_torneo" or op == "ft") {
			string t;
			cin >> t;
			cout << '#' << op << ' ' << t << endl;
			tournaments.end_tournament(t, ranking, ctg);
		}
		else if (op == "listar_ranking" or op == "lr") {
			cout << '#' << op << endl;
			ranking.list_ranking();
		}
		else if (op == "listar_jugadores" or op == "lj") {
			cout << '#' << op << endl;
			cout << ranking.count_players() << endl;
			ranking.list_players();
		}
		else if (op == "consultar_jugador" or op == "cj") {
			string p;
			cin >> p;
			cout << '#' << op << ' ' << p << endl;
			if (not ranking.consult_player(p))
				cout << "error: el jugador no existe" << endl;
		}
		else if (op == "listar_torneos" or op == "lt") {
			cout << '#' << op << endl;
			tournaments.list_tournaments(ctg);
		}
		else if (op == "listar_categorias" or op == "lc") {
			cout << '#' << op << endl;
			ctg.list_categories();
		}
		cin >> op;
	}
}
