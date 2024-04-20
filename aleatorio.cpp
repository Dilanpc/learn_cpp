#include <iostream>
#include <random> // Incluimos la biblioteca <random>

int main() {
    const int MIN = 1;
    const int MAX = 100;
    const int RAND_NUMS_TO_GENERATE = 10;

    std::random_device rd; // Generamos una semilla aleatoria
    std::default_random_engine eng(rd()); // Creamos un motor aleatorio
    std::uniform_int_distribution<int> distr(MIN, MAX); // Definimos la distribución

    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        std::cout << distr(eng) << std::endl; // Generamos y mostramos los números aleatorios
    }

    std::cout << std::endl;
    return 0;
}
