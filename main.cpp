#include "./vector/vector.hpp"
#include <iostream>
#include <vector>
int main_t()
{
    ft::vector<int> a;
    ft::vector<int>::iterator ptr;

    // ft::vector<int> c(5, 4);

    // a.assign(5, 10);
    // c.assign(a.begin() + 2, a.end());
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    a.erase(a.begin() + 2, a.begin() + 5);
    // std::cout << a.size() << "--";
    // ft::vector<int>::iterator it;
    // std::cout << a.size() << std::endl;
    for (std::size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << " ";
    }
    // a.push_back(8);
    // a.push_back(9);
    // std::cout<< a.capacity() << std::endl;
    // a.reserve(20);
    // std::cout << a.capacity() << std::endl;
    // a.assign(5, 10);
    // a.reserve(3);
    // a.push_back(20);
    // a.push_back(10);
    // a.push_back(30);
    // std::cout << a.size() << std::endl;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     std::cout << a[i] << " ";
    // }
    // std::cout << "\n"
    //           << std::endl;

    // std::cout << a.front() << std::endl;
    // std::cout << a.back() << std::endl;

    return 0;
}

int main()
{

    main_t();
    // system("leaks a.out");

    return 0;
}