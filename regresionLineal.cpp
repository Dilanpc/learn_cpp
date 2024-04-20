#include <iostream>

float funcion(float m, float x, float b){
    return m*x + b;
}

// float error(float x, float y){
//     return (x-funcion()) * (x-y);
// }

float valoresX[] = {0.21,0.56,0.01,0.33,0.67,7,8,9,10};
float valoresY[] = {1,2,3,4,5,6,7,8,9,10};

int main(int argc, char *argv[])
{
    std::cout << valoresX[3] << std::endl;
    return 0;
}
