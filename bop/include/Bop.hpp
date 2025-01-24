#pragma once

#include <concepts>
#include <functional>

namespace bop
{

template <typename O, typename T>
concept BinaryOperator = std::invocable<O, const T &, const T &>;

template <typename T, BinaryOperator<T> Op> struct BindRHS
{
  public:
	BindRHS(T &&rhs) : _rhs(std::forward<T>(rhs))
	{
	}

	auto operator()(const T &lhs) const
	{
		return _op(lhs, _rhs);
	}

  private:
	Op _op{};
	T _rhs{};
};

// Comparisons
template <typename T> using lt = BindRHS<T, std::less<T>>;
template <typename T> using le = BindRHS<T, std::less_equal<T>>;
template <typename T> using gt = BindRHS<T, std::greater<T>>;
template <typename T> using ge = BindRHS<T, std::greater_equal<T>>;
template <typename T> using eq = BindRHS<T, std::equal_to<T>>;
template <typename T> using ne = BindRHS<T, std::not_equal_to<T>>;

// Arithmetic operations
template <typename T> using add = BindRHS<T, std::plus<T>>;
template <typename T> using sub = BindRHS<T, std::minus<T>>;
template <typename T> using mul = BindRHS<T, std::multiplies<T>>;
template <typename T> using div = BindRHS<T, std::divides<T>>;
template <typename T> using mod = BindRHS<T, std::modulus<T>>;

// Logical operations
template <typename T> using land = BindRHS<T, std::logical_and<T>>;
template <typename T> using lor = BindRHS<T, std::logical_or<T>>;

// Bitwise operations
template <typename T> using band = BindRHS<T, std::bit_and<T>>;
template <typename T> using bor = BindRHS<T, std::bit_or<T>>;
template <typename T> using bxor = BindRHS<T, std::bit_xor<T>>;

} // namespace bop
