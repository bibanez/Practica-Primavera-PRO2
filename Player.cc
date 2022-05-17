#include "Player.hh"

// Creadoras

Player::Player(int rk) {
	ranking = rk;
}


// Modificadoras

void Player::set_ranking(int n) {
	ranking = n;
}

int Player::get_ranking() const {
	return ranking;
}
