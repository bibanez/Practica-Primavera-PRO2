#include "Statistics.hh"

// Creadoras

Statistics::Statistics() {
	tournaments = points = matches_won = matches_lost = sets_won = 
		sets_lost = games_won = games_lost = 0;
}

Statistics::Statistics(int t) {
	points = matches_won = matches_lost = sets_won = 
		sets_lost = games_won = games_lost = 0;
	tournaments = t;
}


// Modificadoras

void Statistics::add_stats(const Statistics& stats) {
	tournaments += stats.tournaments;
	points += stats.points;
	matches_won += stats.matches_won;
	matches_lost += stats.matches_lost;
	sets_won += stats.sets_won;
	sets_lost += stats.sets_lost;
	games_won += stats.games_won;
	games_lost += stats.games_lost;
}

void Statistics::set_points(int n) {
	points = n;
}

void Statistics::set_tournaments(int n) {
	tournaments = n;
}

void Statistics::set_matches_won(int n) {
	matches_won = n;
}

void Statistics::set_matches_lost(int n) {
	matches_lost = n;
}

void Statistics::set_games_won(int n) {
	games_won = n;
}

void Statistics::set_games_lost(int n) {
	games_lost = n;
}

void Statistics::set_sets_won(int n) {
	sets_won = n;
}

void Statistics::set_sets_lost(int n) {
	sets_lost = n;
}

void Statistics::clear() {
	tournaments = points = matches_won = matches_lost = sets_won = 
		sets_lost = games_won = games_lost = 0;
}


// Consultoras

int Statistics::get_points() const {
	return points;
}

int Statistics::get_tournaments() const {
	return tournaments;
}

int Statistics::get_matches_won() const {
	return matches_won;
}

int Statistics::get_matches_lost() const {
	return matches_lost;
}

int Statistics::get_sets_won() const {
	return sets_won;
}

int Statistics::get_sets_lost() const {
	return sets_lost;
}

int Statistics::get_games_won() const {
	return games_won;
}

int Statistics::get_games_lost() const {
	return games_lost;
}


// Escritoras

void Statistics::print_statistics() const {
	cout << "Ps:" << points;
	cout << " Ts:" << tournaments;
	cout << " WM:" << matches_won;
	cout << " LM:" << matches_lost;
	cout << " WS:" << sets_won;
	cout << " LS:" << sets_lost;
	cout << " WG:" << games_won;
	cout << " LG:" << games_lost;
	cout << endl;
}
