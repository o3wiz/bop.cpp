#include <bop/Bop.hpp>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>
#include <array>

namespace rng = std::ranges;
namespace vws = std::views;

struct Person
{
	std::string name;
	unsigned int age = 0;
};

using People = std::vector<Person>;

int main()
{
	People people{{"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5}};

	for (const Person &person : people | vws::filter(::bop::le(3, &Person::age)))
	{
		std::cout << person.name << std::endl;
	}
	std::cout << std::endl << std::endl;

	rng::sort(people, ::bop::ge(&Person::age));
	for (const Person &person : people)
	{
		std::cout << person.name << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::array numbers{1, 2, 3, 4};
	for (const int number : numbers | vws::filter(::bop::eq(0, ::bop::mod(2, {}))))
	{
		std::cout << number << std::endl;
	}
	std::cout << std::endl << std::endl;

	rng::sort(numbers, ::bop::ge({}));
	for (const int number : numbers)
	{
		std::cout << number << std::endl;
	}
	std::cout << std::endl << std::endl;
}
