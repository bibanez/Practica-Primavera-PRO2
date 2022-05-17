#include "Ranking.hh"

// Auxiliares

void Ranking::update_ranking(int i, int j) {
	while (i < j) {
		ranking[i]->second.set_ranking(i+1);
		++i;
	}
}

void Ranking::sort_ranking() {
	sort(ranking.begin(), ranking.end(), cmp);
	int n = ranking.size();
	for (int i = 0; i < n; ++i) ranking[i]->second.set_ranking(i+1);
}

bool Ranking::cmp(const Player_it& a, const Player_it& b) {
	if (a->second.get_points() == b->second.get_points()) 
		return a->second.get_ranking() < b->second.get_ranking();
	return a->second.get_points() > b->second.get_points();
}


// Creadoras

Ranking::Ranking() {
	stats = map<string,Player>();
	ranking = vector<Player_it>();
}


// Modificadoras

bool Ranking::add_player(const string& name) {
	Player p(ranking.size()+1);
	pair<Player_it,bool> marker = stats.insert(pair<string,Player>(name, p));
	if (marker.second) {
		ranking.push_back(marker.first);
		return true;
	}
	return false;
}

bool Ranking::remove_player(const string& name) {
	Player_it it = stats.find(name);
	if (it != stats.end()) {
		int i = it->second.get_ranking() - 1;
		ranking.erase(ranking.begin()+i);
		stats.erase(it);
		update_ranking(i, ranking.size());
		return true;
	}
	return false;
}

bool Ranking::remove_player(int n) {
	if (1 <= n and n <= ranking.size()) {
		--n; // El ranking 1 pasa a ser el indice 0
		stats.erase(ranking[n]);
		ranking.erase(ranking.begin()+n);
		update_ranking(n, ranking.size());
		return true;
	}
	return false;
}

void Ranking::add_tournament_results(const map<string, int>& old, const map<string, Statistics>& results) {
	if (old.size() > 0) {
		map<string,int>::const_iterator it1 = old.begin();
		while (it1 != old.end()) {
			Player_it it = stats.find(it1->first);
			if (it != stats.end()) 
				it->second.set_points(it->second.get_points() - it1->second);
			++it1;
		}
	}

	if (results.size() > 0) {
		map<string,Statistics>::const_iterator it2 = results.begin();
		while (it2 != results.end()) {
			Player_it it = stats.find(it2->first);
			if (it != stats.end()) it->second.add_stats(it2->second);
			++it2;
		}
	}

	sort_ranking();
}


// Consultoras

string Ranking::get_name(int n) const {
	return ranking[n-1]->first;
}

int Ranking::get_ranking(const string& name) const {
	map<string,Player>::const_iterator it = stats.find(name);
	if (it != stats.end()) return it->second.get_ranking();
	return -1;
}

vector<string> Ranking::get_names_from_rankings(const vector<int>& rks) const {
	int n = rks.size();
	vector<string> names(n);
	for (int i = 0; i < n; ++i) names[i] = ranking[rks[i]-1]->first;
	return names;
}

int Ranking::count_players() const {
	return ranking.size();
}


// Lectoras

void Ranking::read_players(int P) {
	while (P--) {
		string s;
		cin >> s;
		add_player(s);
	}
}


// Escritoras

void Ranking::list_ranking() {
	int n = ranking.size();
	for (int i = 0; i < n; ++i) {
		cout << i+1 << ' ' << ranking[i]->first << ' ' << ranking[i]->second.get_points() << endl;
	}
}

void Ranking::list_players() {
	map<string, Player>::const_iterator it = stats.begin();
	while (it != stats.end()) {
		cout << it->first << " Rk:" << it->second.get_ranking() << ' ';
		it->second.print_statistics();
		++it;
	}
}

bool Ranking::consult_player(const string& name) {
	map<string,Player>::iterator it = stats.find(name);
	if (it != stats.end()) {
		cout << name << " Rk:" << it->second.get_ranking() << ' ';
		it->second.print_statistics();
		return true;
	}
	else return false;
}
