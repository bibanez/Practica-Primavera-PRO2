#include "Tournaments.hh"

void Tournaments::remove_player(const string& name) {
	map<string, Tournament>::iterator it = tournaments.begin();
	while (it != tournaments.end()) {
		it->second.remove_player_from_results(name);
		++it;
	}
}

void Tournaments::read_starting_tournaments(int T) {
	while (T--) {
		string t;
		int c;
		cin >> t >> c;
		tournaments[t] = Tournament(c);
	}
}

bool Tournaments::add_tournament(const string& t, int c) {
	return tournaments.insert(pair<string, Tournament>(t, Tournament(c))).second;
}

bool Tournaments::remove_tournament(const string& t, Ranking& r) { // Ranking& r
	map<string, Tournament>::iterator it = tournaments.find(t);
	if (it != tournaments.end()) {
		r.count_players();
		map<string,int> old = it->second.get_old_results();
		/*
		map<string,int>::const_iterator res = old.begin();
		while (res != old.end()) {
			cout << res->first << ' ' << res->second << endl;
			++res;
		}
		*/
		r.remove_tournament_results(old);
		tournaments.erase(it);
		return true;
	}
	return false;
}

void Tournaments::start_tournament(const string& t, const vector<string>& players) {
	map<string, Tournament>::iterator it = tournaments.find(t);
	if (it != tournaments.end()) {
		it->second.start_tournament(players);
		it->second.print_starting_pairs();
	}
}

void Tournaments::end_tournament(string t, Ranking& r, const Categories& ctg) {
	map<string, int> old;
	map<string, Statistics> results;
	int c = tournaments[t].get_category();
	tournaments[t].end_tournament(old, results, ctg.get_ctg_scores(c));
	r.add_tournament_results(old, results);
}

int Tournaments::count_tournaments() const {
	return tournaments.size();
}

void Tournaments::list_tournaments(const Categories& c) const {
	cout << tournaments.size() << endl;
	map<string, Tournament>::const_iterator  it = tournaments.begin();
	while (it != tournaments.end()) {
		cout << it->first << ' ' << c.get_name(it->second.get_category()) << endl;
		++it;
	}
}
