#pragma once

#include <functional>

namespace bop
{

template <typename Op> struct BinFunctor
{
	template <typename T, class Proj = std::identity> //
	constexpr auto operator()(const T &rhs, Proj proj) const
	{
		return [&rhs, proj = std::move(proj)]<typename U>(const U &lhs)
			requires std::invocable<Proj, const U &> && //
					 std::invocable<Op, std::invoke_result_t<Proj, const U &>, const T &>
		{ return Op{}(std::invoke(proj, lhs), rhs); };
	}

	template <class Proj = std::identity> //
	constexpr auto operator()(Proj proj) const
	{
		return [proj = std::move(proj)]<typename T>(const T &lhs, const T &rhs)
			requires std::invocable<Proj, const T &> && //
					 std::invocable<Op, std::invoke_result_t<Proj, const T &>, std::invoke_result_t<Proj, const T &>>
		{ return Op{}(std::invoke(proj, lhs), std::invoke(proj, rhs)); };
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
