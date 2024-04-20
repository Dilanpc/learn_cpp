#include <iostream>
#include <cmath>


float compuesto(float inicial, float interes, int years, float aumento){
    float base = inicial *  pow((interes+1), years);
    float increment = 0;
    for (int i = 0; i < years; i++){
        increment += aumento * pow((interes+1), i);
        
    }
    std::cout << "increment: " << increment << std::endl;
    return base + increment;

}


int main(int argc, char const *argv[])
{

    std::cout << compuesto(500, 0.1, 1, 10) << std::endl;
    


    return 0;
}
