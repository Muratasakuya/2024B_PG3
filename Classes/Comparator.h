#pragma once

///=================================================================================
/// Comparator class
///=================================================================================
template <typename T1, typename T2>
class Comparator {
public:

	static auto Min(T1 a, T2 b) -> decltype(a);

};

template<typename T1, typename T2>
inline auto Comparator<T1, T2>::Min(T1 a, T2 b) -> decltype(a) {

	if (a < b) {

		return a;
	} else {

		return b;
	}
}