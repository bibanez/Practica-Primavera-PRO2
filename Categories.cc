#include "Categories.hh"

// Lectoras

void Categories::read_categories(int C, int K) {
	names = vector<string>(C);
	ctg_scores = vector< vector<int> >(C, vector<int>(K));
	this->C = C;
	this->K = K;

	for (int i = 0; i < C; ++i) cin >> names[i];
	
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < K; ++j) cin >> ctg_scores[i][j];
	}
}


// Consultoras

vector<int> Categories::get_ctg_scores(int c) const {
	return ctg_scores[c-1];
}

int Categories::count_categories() const {
	return C;
}

int Categories::get_rank_depth() const {
	return K;
}

string Categories::get_name(int c) const {
	return names[c-1];
}


// Escritoras

void Categories::list_categories() {
	cout << C << ' ' << K << endl;
	for (int i = 0; i < C; ++i) {
		cout << names[i];
		for (int j = 0; j < K; ++j) cout << ' ' << ctg_scores[i][j];
		cout << endl;
	}
}
