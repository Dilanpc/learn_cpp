#include <iostream>
#include <iomanip>
#include <cmath>


std::pair<int, int> fraction(float n, double precision = 0.0000001)
{
    int a = 1, b = 1;
    int iter = 0;

    while (std::abs(static_cast<float>(a) / b - n) > precision)
    {
        if (static_cast<float>(a) / b < n)
        {
            a++;
        }
        else
        {
            b++;
        }
        iter++;
    }
    std::cout << "Iteraciones: " << iter << std::endl;
    return {a, b};
}


int main(int argc, char const *argv[])
{
    if (argc != 3 && argc != 1){
        std::cout << "Usage: " << argv[0] << " [number] [precision]" << std::endl;
        return 1;
    }else if (argc == 3){
        std::pair<int,int> result = fraction(std::stod(argv[1]), std::stod(argv[2]));
        std::cout << result.first << " / " << result.second << std::endl;
        std::cout << std::setprecision(20) << static_cast<double>(result.first) / result.second << std::endl;
        return 0;
    }
    
    std::pair<int,int> result = fraction(3.14159265, 0.00000001);
    std::cout << result.first << " / " << result.second << std::endl;
    std::cout << std::setprecision(20) << static_cast<double>(result.first) / result.second << std::endl;

    return 0;
}
