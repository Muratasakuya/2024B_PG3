#pragma once

///=================================================================================
/// include
///=================================================================================
// c++
#include <iostream>
#include <array>

///=================================================================================
//** enum

enum class Phase
	: size_t {

	Approach = 0, // 接近
	Shoot,        // 射撃
	Retreat,      // 離脱
	Count         // フェーズの最大数
};

///=================================================================================
/// Enemy class
///=================================================================================
class Enemy {
public:

	///=================================================================================
	/// public Methods
	///=================================================================================

	Enemy() : phase_(Phase::Approach) {}
	~Enemy() = default;

	void Update();

	///=================================================================================
	//** getter

	Phase GetCurrentPhase() const { return phase_; }

private:

	///=================================================================================
	/// private Methods
	///=================================================================================

	///=================================================================================
	//** variables

	Phase phase_;

	using EnemyFunction = void (Enemy::*)();
	static const std::array<EnemyFunction, static_cast<size_t>(Phase::Count)> phaseFunc_;

	///=================================================================================
	//** functions

	void Approach(); //* 接近

	void Shoot();    //* 射撃

	void Retreat();  //* 離脱

};