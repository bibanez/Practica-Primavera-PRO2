#include "Tournament.hh"

// Auxiliares

bool Tournament::first_wins(const match& m) const {
	int a = 0;
	int b = 0;
	int n = m.result.size();
	for (int i = 0; i < n; ++i) {
		if (m.result[i].first > m.result[i].second) ++a;
		else ++b;
	}
	return a > b;
}

void Tournament::pairings(BinTree<match>& t, int a, int s, int max) {
	int b = s + 1 - a;
	if (b <= max) {
		BinTree<match> left, right;
		pairings(left, a, s*2, max);
		pairings(right, b, s*2, max);
		match m = {a, b, vector< pair<int,int> >()};
		t = BinTree<match>(m, left, right);
	}
}

void Tournament::calculate_rankings(const BinTree<match>& t, const vector<int>& rank_scores, vector<int>& p, int k) {
	int i = t.value().a-1;
	int j = t.value().b-1;
	int n = t.value().result.size();
	// Solo añadimos los juegos y sets ganados y perdidos cuando se han
	// disputado un mínimo de 2 sets, es decir, que el partido se ha disputado
	if (n > 1) {
		for (int s = 0; s < n; ++s) {
			stats[i].set_games_won(stats[i].get_games_won() + t.value().result[s].first);
			stats[i].set_games_lost(stats[i].get_games_lost() + t.value().result[s].second);
			stats[j].set_games_won(stats[j].get_games_won() + t.value().result[s].second);
			stats[j].set_games_lost(stats[j].get_games_lost() + t.value().result[s].first);
			if (t.value().result[s].first > t.value().result[s].second) {
				stats[i].set_sets_won(stats[i].get_sets_won() + 1);
				stats[j].set_sets_lost(stats[j].get_sets_lost() + 1);
			}
			else {
				stats[j].set_sets_won(stats[j].get_sets_won() + 1);
				stats[i].set_sets_lost(stats[i].get_sets_lost() + 1);
			}
		}
	}
	if (first_wins(t.value())) {
		stats[i].set_matches_won(stats[i].get_matches_won() + 1);
		stats[j].set_matches_lost(stats[j].get_matches_lost() + 1);
		if (k < p[i] or p[i] == 0) {
		 	p[i] = k;
			stats[i].set_points(rank_scores[k-1]);
		}
		if (k+1 < p[j] or p[j] == 0) {
			p[j] = k+1;
			stats[j].set_points(rank_scores[k]);
		}
	}
	else {
		stats[j].set_matches_won(stats[j].get_matches_won() + 1);
		stats[i].set_matches_lost(stats[i].get_matches_lost() + 1);
		if (k+1 < p[i] or p[i] == 0) {
			p[i] = k+1;
			stats[i].set_points(rank_scores[k]);
		}
		if (k < p[j] or p[j] == 0) {
			p[j] = k;
			stats[j].set_points(rank_scores[k-1]);
		}
	}
	if (not t.left().empty()) calculate_rankings(t.left(), rank_scores, p, k+1);
	if (not t.right().empty()) calculate_rankings(t.right(), rank_scores, p, k+1);
}

void Tournament::read_match(match& m) {
	string r;
	cin >> r;
	int n = r.size();
	if (n == 11) {
		int i = 0;
		while (i < 9) {
			m.result.push_back(pair<int,int>(r[i] - '0', r[i+2] - '0'));
			i += 4;
		}
	}
	else if (n == 7) {
		int i = 0;
		while (i < 5) {
			m.result.push_back(pair<int,int>(r[i] - '0', r[i+2] - '0'));
			i += 4;
		}
	}
	else if (n == 3) {
		m.result.push_back(pair<int,int>(r[0] - '0', r[2] - '0'));
	}
}

void Tournament::read_matches(BinTree<match>& t) {
	match m = t.value();
	read_match(m);
	BinTree<match> left = t.left();
	BinTree<match> right = t.right();
	if (not left.empty()) {
		read_matches(left);
		if (first_wins(left.value())) m.a = left.value().a;
		else m.a = left.value().b;
	}
	else {
		int c;
		cin >> c;
	}
	if (not right.empty()) {
		read_matches(right);
		if (first_wins(right.value())) m.b = right.value().a;
		else m.b = right.value().b;
	}
	else {
		int c;
		cin >> c;
	}
	t = BinTree<match>(m, left, right);
}

void Tournament::print_pairings(const BinTree<match>& t) {
	if (t.left().empty()) {
		cout << '(' << t.value().a << '.' << names[t.value().a - 1];
		if (t.right().empty()) 
			cout << ' ' << t.value().b << '.' << names[t.value().b - 1] << ')';
		else {
			cout << ' ';
			print_pairings(t.right());
			cout << ')';
		}
	}
	else {
		cout << '(';
		print_pairings(t.left());
		cout << ' ';
		print_pairings(t.right());
		cout << ')';
	}
}

void Tournament::print_table(const BinTree<match>& t) {
	cout << '(' << t.value().a << '.' << names[t.value().a-1] << " vs " 
		<< t.value().b << '.' << names[t.value().b-1] << ' ';
	int n = t.value().result.size();
	cout << t.value().result[0].first << '-' << t.value().result[0].second;
	for (int i = 1; i < n; ++i) {
		cout << ',' << t.value().result[i].first << '-' << t.value().result[i].second;
	}
	if (not t.left().empty()) print_table(t.left());
	if (not t.right().empty()) print_table(t.right());
	cout << ')';
}


// Creadoras

Tournament::Tournament() {
	c = 0;
}

Tournament::Tournament(int c) {
	this->c = c;
}


// Modificadoras

void Tournament::start_tournament(const vector<string>& players) {
	started = true;
	old_results.clear();
	int n = stats.size();
	for (int i = 0; i < n; ++i) 
		old_results.insert(pair<string,int>(names[i],stats[i].get_points()));
	names = players;
	Statistics st;
	st.set_tournaments(1);
	stats = vector<Statistics>(players.size(), st);
}

void Tournament::end_tournament(map<string, int>& old, map<string, Statistics>& res, const vector<int>& rank_scores) {
	started = false;
	old = old_results;
	read_matches(results);
	print_results_table();
	vector<int> p(names.size());
	calculate_rankings(results, rank_scores, p, 1);
	res.clear();
	int n = stats.size();
	for (int i = 0; i < n; ++i) {
		if (stats[i].get_points() != 0) cout << i+1 << '.' << names[i] << ' ' << stats[i].get_points() << endl;
		res[names[i]] = stats[i];
	}
}

bool Tournament::remove_player_from_results(const string& name) {
	map<string,int>::iterator it = old_results.find(name);
	if (it != old_results.end()) {
		old_results.erase(it);
		return true;
	}
	else {
		int n = stats.size();
		for (int i = 0; i < n; ++i) {
			if (names[i] == name) {
				stats[i].clear();
				return true;
			}
		}
		return false;
	}
}


// Consultoras

int Tournament::get_category() const {
	return c;
}

bool Tournament::has_started() const {
	return started;
}

map<string,int> Tournament::get_old_results() const {
	map<string,int> res;
	int n = stats.size();
	for (int i = 0; i < n; ++i) res[names[i]] = stats[i].get_points();
	return res;
}


// Escritoras

void Tournament::print_starting_pairs() {
	pairings(results, 1, 2, names.size());
	print_pairings(results);
	cout << endl;
}

void Tournament::print_results_table() {
	print_table(results);
	cout << endl;
}
