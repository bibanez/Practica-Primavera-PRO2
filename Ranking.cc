#include "Ranking.hh"
using namespace std;


Ranking::Ranking() {
	stats = map<string, Statistics>();
	ranking = vector<Player>();
}


bool Ranking::add_player(const string& name) {
	map<string,Statistics>::iterator it = stats.find(name);
	if (it == stats.end()) {
		Player p(name);
		p.set_ranking(ranking.size()+1);
		ranking.push_back(p);
		stats[name];
		return true;
	}
	return false;
}

bool Ranking::remove_player(const string& name) {
	map<string, Statistics>::iterator it = stats.find(name);
	if (it != stats.end()) {
		int i = get_ranking(name)-1;
		ranking.erase(ranking.begin()+i);
		stats.erase(it);
		update_ranking(i, ranking.size());
		return true;
	}
	return false;
}

void Ranking::update_ranking(int i, int j) {
	while (i < j) {
		ranking[i].set_ranking(i+1);
		++i;
	}
}

bool Ranking::remove_player(int n) {
	if (1 <= n and n <= ranking.size()) {
		--n;
		stats.erase(ranking[n].get_name());
		ranking.erase(ranking.begin()+n);
		return true;
	}
	return false;
}

/*
bool cmp(const Player& a, const Player& b) {
	if (a.get_points() == b.get_points()) return a.get_ranking() < b.get_ranking();
	else return a.get_points() > b.get_points();
}
*/

bool cmp(const Player& a, const Player& b) {
	if (a.get_points() == b.get_points()) return a.get_ranking() < b.get_ranking();
	return a.get_points() > b.get_points();
}

int Ranking::count_players() const {
	return ranking.size();
}

int Ranking::get_ranking(const string& name) const {
	map<string, Statistics>::const_iterator it1 = stats.find(name);
	if (it1 != stats.end()) {
		int p = it1->second.get_points();
		vector<Player>::const_iterator it2;
		it2 = lower_bound(ranking.begin(), ranking.end(), Player(p), cmp);
		while (it2->get_name() != name and it2->get_points() == p) ++it2;
		return (it2 - ranking.begin()) + 1;
	}
	return -1;
}

void Ranking::add_tournament_results(const map<string, int>& old, const map<string, Statistics>& results) {
	set<int> visited;
	if (old.size() > 0) {
		map<string,int>::const_iterator it1 = old.begin();
		while (it1 != old.end()) {
			int i = get_ranking(it1->first) - 1;
			ranking[i].set_tmp_points(ranking[i].get_tmp_points() - it1->second);
			visited.insert(visited.end(), i);
			++it1;
		}
	}

	map<string,Statistics>::const_iterator it2 = results.begin();
	while (it2 != results.end()) {
		int i = get_ranking(it2->first) - 1;
		ranking[i].set_tmp_points(ranking[i].get_tmp_points() + it2->second.get_points());
		visited.insert(i);
		++it2;
	}

	set<int>::iterator it = visited.begin();
	while (it != visited.end()) {
		ranking[*it].update_player();
		++it;
	}
	
	sort_ranking();

	if (old.size() > 0) {
		map<string,int>::const_iterator it1 = old.begin();
		while (it1 != old.end()) {
			map<string,Statistics>::iterator it = stats.find(it1->first);
			it->second.set_points(it->second.get_points() - it1->second);
			++it1;
		}
	}

	it2 = results.begin();
	while (it2 != results.end()) {
		map<string,Statistics>::iterator it = stats.find(it2->first);
		it->second.add_stats(it2->second);
		++it2;
	}
}

void Ranking::sort_ranking() {
	sort(ranking.begin(), ranking.end(), cmp);
	int n = ranking.size();
	for (int i = 0; i < n; ++i) ranking[i].set_ranking(i+1);
}

string Ranking::get_name(int n) const {
	return ranking[n-1].get_name();
}

vector<string> Ranking::get_names_from_rankings(const vector<int>& rankings) const {
	int n = rankings.size();
	vector<string> names(n);
	for (int i = 0; i < n; ++i) {
		names[i] = get_name(rankings[i]);
	}
	return names;
}

void Ranking::read_players(int P) {
	while (P--) {
		string s;
		cin >> s;
		add_player(s);
	}
}

void Ranking::list_ranking() {
	int n = ranking.size();
	for (int i = 0; i < n; ++i) {
		cout << i+1 << ' ' << ranking[i].get_name() << ' ' << ranking[i].get_points() << endl;
	}
}

void Ranking::list_players() {
	cout << stats.size() << endl;
	map<string, Statistics>::const_iterator it = stats.begin();
	while (it != stats.end()) {
		consult_player(it->first);
		++it;
	}
}

bool Ranking::consult_player(const string& name) {
	map<string,Statistics>::iterator it = stats.find(name);
	if (it != stats.end()) {
		cout << name << " Rk:" << get_ranking(name) << ' ';
		it->second.print_statistics();
		return true;
	}
	else return false;
}
