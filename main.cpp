#include <iostream>
#include <string>

#include "./itertools/range.hpp"
#include "./itertools/filter.hpp"
#include "./itertools/takewhile.hpp"
#include "./itertools/groupby.hpp"
#include "./itertools/sorted.hpp"

using namespace iter;

// https://github.com/ryanhaining/cppitertools

int main() {

    std::cout << "------------------------------ RANGE 1 -----------------------------" << std::endl;
    for (auto i : range(10)) {
        std::cout << i << std::endl;
    }

    std::cout << "------------------------------ RANGE 2 -----------------------------" << std::endl;
    for (auto i : range(10, 15)) {
        std::cout << i << std::endl;
    }

    std::cout << "------------------------------ RANGE 3 -----------------------------" << std::endl;
    for (auto i : range(2, -10, -3)) {
        std::cout << i << std::endl;
    }

    std::cout << "------------------------------ RANGE 4 -----------------------------" << std::endl;
    for (auto i : range(2.5, 12.2, 0.2)) {
        std::cout << i << std::endl;
    }


    std::cout << "------------------------ FILTER + TAKE WHILE -----------------------" << std::endl;
    // std::vector<int> v = {10, 20, 30, 40, 50};
    auto v = range(10, 100, 10);
    auto v1 = filter([](int i){return i > 20;}, v);
    auto final_result = takewhile([](int i) {return i < 40;}, v1);

    for (auto&& value : final_result ) {
        std::cout << value << std::endl;
    }

    std::cout << "---------------------------- PIPE STYLE ----------------------------" << std::endl;
    std::vector<std::string> names = { "Adrian", "Andy", "Jim","John", "Sarah","Sam", "James", "Alice" };
    auto test = [](auto&& name){return name.length() > 3;};
    auto comp = [](auto&& left_name, auto&& right_name) {return left_name > right_name;};
    auto res = names | filter(test) | sorted(comp);
    for (auto&& n : res) {
        std::cout << n << std::endl;
    }


    std::cout << "----------------------------- GROUP BY -----------------------------" << std::endl;
    auto sorted_names = sorted(names, [](auto&& left_name, auto&& right_name){return left_name < right_name;});
    auto grouped_by_name = groupby(sorted_names, [] (auto&& s) {return s[0]; });

    for (auto&& e : grouped_by_name) {
        std::cout << "FIRST LETTER: " << e.first << '\n';
        std::cout << "NAMES: ";
        for (auto&& n : e.second) {
            std::cout << n << "  ";
        }
        std::cout << '\n';
    }

    return 0;
}
