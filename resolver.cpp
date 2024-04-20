#include <iostream>
#include <cmath>

/* Encuentra el valor de x de una ecuación por iteración, tiene margen de error en la imagen de la función */

float function(float x){
    return exp(-x) - atan(x);
}

float interseccion(float inicio, float n, float final, float error){
    float aumento = (final - inicio)/2;
    float x = inicio + aumento;
    float evaluar = function(x);



    if (fabs(evaluar - n) < error){ //Caso base
        return x;
    }

    //si es decresciente:
    if (evaluar > n){
        return interseccion(x, n, final, error);
    }else {
        return interseccion(inicio, n, x, error);
    }
}


int main(int argc, char const *argv[])
{
    
    float error;
    std::cout << "incluya margen de error en la imagen: ";
    std::cin >> error;

    std::cout << "Resultado: " << interseccion(0, 0, 1, error);



    return 0;
}
