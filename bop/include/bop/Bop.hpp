#pragma once

#include <functional>

namespace bop
{

template <typename Op> struct BindRHS
{
	template <typename T, typename Proj = std::identity> //
	constexpr auto operator()(const T &rhs, Proj proj = {}) const
	{
		return [rhs, proj](const auto &lhs) { return Op{}(std::invoke(proj, lhs), rhs); };
	}
};


// Comparisons
inline constexpr BindRHS<std::less<>> lt{};
inline constexpr BindRHS<std::less_equal<>> le{};
inline constexpr BindRHS<std::greater<>> gt{};
inline constexpr BindRHS<std::greater_equal<>> ge{};
inline constexpr BindRHS<std::equal_to<>> eq{};
inline constexpr BindRHS<std::not_equal_to<>> ne{};

// Arithmetic operations
inline constexpr BindRHS<std::plus<>> add{};
inline constexpr BindRHS<std::minus<>> sub{};
inline constexpr BindRHS<std::multiplies<>> mul{};
inline constexpr BindRHS<std::divides<>> div{};
inline constexpr BindRHS<std::modulus<>> mod{};

// Logical operations
inline constexpr BindRHS<std::logical_and<>> land{};
inline constexpr BindRHS<std::logical_or<>> lor{};

// Bitwise operations
inline constexpr BindRHS<std::bit_and<>> band{};
inline constexpr BindRHS<std::bit_or<>> bor{};
inline constexpr BindRHS<std::bit_xor<>> bxor{};

} // namespace bop
