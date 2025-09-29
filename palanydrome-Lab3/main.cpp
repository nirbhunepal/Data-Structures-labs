#include <iostream>
#include <palanydrome/ispalanydrome.hpp>
#include <vector>
#include <numeric>

int main()
{

    std::vector<int> birthday{{0, 2, 9, 1, 9, 8, 2}};
    std::vector<char> band{{'a', 'b', 'b', 'a'}};
    std::vector<float> one_float{{1.0}};
    std::vector<std::string> two_strings{{std::string{"a"}, std::string{"b"}}};
    std::vector<int> increasing(1000, 0);
    std::iota(increasing.begin(), increasing.end(), 0);

    if (isPalanydrome(birthday)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (isPalanydrome(band)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }


    if (isPalanydrome(increasing)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (isPalanydrome(one_float)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    if (isPalanydrome(two_strings)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }

    return 0;
}
