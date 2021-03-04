#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <set>
#include <numeric>
#include <functional>

int main()
{
	//1
	std::vector <int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	//2
	std::cout << "2: insert numbers" << std::endl;
	std::copy(std::istream_iterator <int>(std::cin), std::istream_iterator <int>(), std::back_inserter(v1));

	//3 - рандомное перемешивание ??
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(v1), std::end(v1), g);
	std::cout << "3: ";
	std::for_each(std::begin(v1), std::end(v1), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//4
	std::sort(std::begin(v1), std::end(v1));
	v1.erase(std::unique(std::begin(v1), std::end(v1)), std::end(v1));
	std::cout << "4: ";
	std::for_each(std::begin(v1), std::end(v1), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//5 - кол-во нечетных
	int k = 0;
	std::for_each(std::begin(v1), std::end(v1), [&k](auto x) {return k += x % 2; });
	std::cout << "5: number nechet = " << k << std::endl;;

	//6 - minmax
	auto res = std::minmax_element(std::begin(v1), std::end(v1));
	std::cout << "6: min = " << *res.first << " max = " << *res.second << std::endl;

	//7 

	//8 - squares
	std::transform(std::begin(v1), std::end(v1), std::begin(v1), [](auto x) {return x * x; });
	std::cout << "8: ";
	std::for_each(std::begin(v1), std::end(v1), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//9
	std::default_random_engine dre(static_cast <unsigned int> (std::chrono::system_clock::now().time_since_epoch().count()));
	std::uniform_int_distribution<> uid(1, 100);
	std::vector <int> v2;
	std::copy(std::begin(v1), std::end(v1), back_inserter(v2));
	std::generate_n(std::begin(v2), std::distance(std::begin(v2), std::end(v2)), [&dre, &uid]() {return uid(dre); });
	std::cout << "9: ";
	std::for_each(std::begin(v2), std::end(v2), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//10
	std::cout << "10: " << std::accumulate(std::begin(v2), std::end(v2), 0) << std::endl;

	//11
	std::fill_n(std::begin(v2), 5, 1);
	std::cout << "11: ";
	std::for_each(std::begin(v2), std::end(v2), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//12
	std::vector <int> v3;
	std::copy(std::begin(v1), std::end(v1), back_inserter(v3));
	std::transform(std::begin(v1), std::end(v1), std::begin(v2), std::begin(v3), [](auto a, auto b) {return a - b; });
	std::cout << "12: ";
	std::for_each(std::begin(v3), std::end(v3), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//13
	std::replace_if(std::begin(v3), std::end(v3), [](auto x) {return x < 0; }, 0);
	std::cout << "13: ";
	std::for_each(std::begin(v3), std::end(v3), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//14
	v3.erase(std::remove_if(std::begin(v3), std::end(v3), [](auto x) {return x == 0; }), std::end(v3));
	std::cout << "14: ";
	std::for_each(std::begin(v3), std::end(v3), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//15
	std::reverse(std::begin(v3), std::end(v3));
	std::cout << "15: ";
	std::for_each(std::begin(v3), std::end(v3), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//16


	//17
	std::sort(std::begin(v1), std::end(v1));
	std::sort(std::begin(v2), std::end(v2)); 

	//18
	std::vector <int> v4;
	std::merge(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2), std::back_inserter(v4));
	std::cout << "18: ";
	std::for_each(std::begin(v4), std::end(v4), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;

	//19
	std::cout << "19: ";
	std::cout << *std::lower_bound(std::begin(v4), std::end(v4), 1) << ' ' << *std::upper_bound(std::begin(v4), std::end(v4), 1) << std::endl;

	//20
	std::cout << "20: v1: ";
	std::for_each(std::begin(v1), std::end(v1), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;
	std::cout << "20: v2: ";
	std::for_each(std::begin(v2), std::end(v2), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;
	std::cout << "20: v3: ";
	std::for_each(std::begin(v3), std::end(v3), [](auto x) {std::cout << x << ' '; });
	std::cout << std::endl;
	std::cout << "20: v4: ";
	std::for_each(std::begin(v4), std::end(v4), [](auto x) {std::cout << x << ' '; });

	return EXIT_SUCCESS;
}