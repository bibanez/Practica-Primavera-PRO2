#include "Player.hh"


/*Player::Player() {
	name = "";
	points = 0;
}*/

Player::Player(int n) {
	name = "";
	points = tmp = n;
	ranking = 0;
}

Player::Player(const string& _name) {
	name = _name;
	points = tmp = ranking = 0;
}

Player::Player(const string& _name, int _points) {
	name = _name;
	points = tmp = _points;
	ranking = 0;
}

Player::Player(const Player& p) {
	name = p.get_name();
	points = p.get_points();
	tmp = p.get_tmp_points();
	ranking = p.get_ranking();
}

void Player::set_name(const string& _name) {
	name = _name;
}

void Player::set_points(int n) {
	points = n;
}

void Player::set_tmp_points(int n) {
	tmp = n;
}

void Player::set_ranking(int n) {
	ranking = n;
}

void Player::update_player() {
	points = tmp;
}

string Player::get_name() const {
	return name;
}

int Player::get_points() const {
	return points;
}

int Player::get_tmp_points() const {
	return tmp;
}

int Player::get_ranking() const {
	return ranking;
}
