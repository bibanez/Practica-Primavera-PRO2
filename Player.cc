#include "Player.hh"

// Creadoras

Player::Player(int rk) {
	ranking = rk;
}

/*
Player::Player(const Player& p) {
	st = Statistics();
	st.add_stats(p.get_stats);
	ranking = p.get_ranking();
}
*/


// Modificadoras

/*
void Player::set_points(int n) {
	points = n;
}
*/

void Player::set_ranking(int n) {
	ranking = n;
}

/*
void Player::add_stats(const Statistics& stats) {
	st.add_stats(stats);
}

int Player::get_points() const {
	return points;
}
*/

int Player::get_ranking() const {
	return ranking;
}
