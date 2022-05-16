#include "Player.hh"


/*Player::Player() {
	name = "";
	points = 0;
}*/

Player::Player(int rk) {
	ranking = rk;
}

void Player::set_ranking(int n) {
	ranking = n;
}

int Player::get_ranking() const {
	return ranking;
}
