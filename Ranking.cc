#include "Ranking.hh"
using namespace std;


Ranking::Ranking() {
	stats = map<string, Statistics>();
	ranking = vector<Player>();
}


bool Ranking::add_player(const string& name) {
	map<string,Statistics>::iterator it = stats.find(name);
	if (it == stats.end()) {
		ranking.push_back(Player(name));
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
		return true;
	}
	return false;
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
bool cmp(const pair<Player,int>& a, const pair<Player,int>& b) {
	if (a.first.get_points() == b.first.get_points()) {
		return a.second < b.second;
	}
	return a.first.get_points() > b.first.get_points();
}
*/

bool cmp(const Player& a, const Player& b) {
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

/*
void Ranking::update_player(const string& name, const Statistics& result) {
	int i = get_ranking(name) - 1;
	if (i >= 0) {
		ranking[i].set_points(ranking[i].get_points() + result.get_points());
		stats[name].add_stats(result);
	}
}
*/

void Ranking::add_tournament_results(const map<string, int>& old, const map<string, Statistics>& results) {
	/*
	map<string,Statistics>::const_iterator it1 = results.begin();
	while (it1 != results.end()) {
		update_player(it1->first, it1->second);
		++it1;
	}
	old.size();
	map<string,int>::const_iterator it2 = old.begin();
	while (it2 != old.end()) {
		Statistics st;
		st.set_points(-it2->second);
		update_player(it2->first, st);
		++it2;
	}
	sort_ranking();
	*/
	//results.size();
	/*
	map<string,Statistics>::const_iterator it1 = results.begin();
	while (it1 != results.end()) {
		it1->second.print_statistics();
		++it1;
	}
	*/
	/*
	map<string,int>::const_iterator it1 = old.begin();
	while (it1 != old.end()) {
		int i = get_ranking(it1->first);
		ranking[i].set_points(it1->second);
		++it1;
	}
	*/
	old.size();
	map<string,Statistics>::const_iterator it2 = results.begin();
	while (it2 != results.end()) {
		map<string,Statistics>::iterator it = stats.find(it2->first);
		if (it != stats.end()) it->second.add_stats(it2->second);
		++it2;
	}
	//sort_ranking();
}

void Ranking::sort_ranking() {
	sort(ranking.begin(), ranking.end(), cmp);
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
