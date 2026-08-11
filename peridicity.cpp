

#include <iostream>
#include "numerical.h"
#include "geometry.h"
int main()
{
    using namespace periodicity;
    Complex<double> a(1.0, 2.0);
    const auto [real, imagine] = a;
    std::cout << a.dot(a) << std::endl;
    std::cout << periodicity::ofDegree<double>(90.0).sine() << std::endl;
    std::cout << "Hello World!\n";
}
