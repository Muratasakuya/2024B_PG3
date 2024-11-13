#include "Enemy.h"

///=================================================================================
/// Enemy classMethods
///=================================================================================

const std::array<Enemy::EnemyFunction, static_cast<size_t>(Phase::Count)> Enemy::phaseFunc_ = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::Retreat
};

void Enemy::Approach() {
	std::cout << "接近" << std::endl;
}

void Enemy::Shoot() {
	std::cout << "射撃" << std::endl;
}

void Enemy::Retreat() {
	std::cout << "離脱" << std::endl;
}

void Enemy::Update() {

	(this->*phaseFunc_[static_cast<size_t>(phase_)])();

	// 遷移状態
	phase_ = static_cast<Phase>((static_cast<size_t>(phase_) + 1) % static_cast<size_t>(Phase::Count));
}