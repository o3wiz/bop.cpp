#pragma once

#include <functional>

namespace bop
{

template <typename Op> struct BinFunctor
{
	template <typename T, class Proj = std::identity> //
	constexpr auto operator()(const T &rhs, Proj proj) const
	{
		return [&rhs, proj](const auto &lhs) { return Op{}(std::invoke(proj, lhs), rhs); };
	}

	template <class Proj = std::identity> //
	constexpr auto operator()(Proj proj) const
	{
		return
			[proj](const auto &lhs, const auto &rhs) { return Op{}(std::invoke(proj, lhs), std::invoke(proj, rhs)); };
	}
};

// Comparisons
inline constexpr BinFunctor<std::less<>> lt{};
inline constexpr BinFunctor<std::less_equal<>> le{};
inline constexpr BinFunctor<std::greater<>> gt{};
inline constexpr BinFunctor<std::greater_equal<>> ge{};
inline constexpr BinFunctor<std::equal_to<>> eq{};
inline constexpr BinFunctor<std::not_equal_to<>> ne{};

// Arithmetic operations
inline constexpr BinFunctor<std::plus<>> add{};
inline constexpr BinFunctor<std::minus<>> sub{};
inline constexpr BinFunctor<std::multiplies<>> mul{};
inline constexpr BinFunctor<std::divides<>> div{};
inline constexpr BinFunctor<std::modulus<>> mod{};

// Logical operations
inline constexpr BinFunctor<std::logical_and<>> land{};
inline constexpr BinFunctor<std::logical_or<>> lor{};

// Bitwise operations
inline constexpr BinFunctor<std::bit_and<>> band{};
inline constexpr BinFunctor<std::bit_or<>> bor{};
inline constexpr BinFunctor<std::bit_xor<>> bxor{};

} // namespace bop
