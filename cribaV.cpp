#include <iostream>
#include <vector>


std::vector<int> criba(int n){
    
    std::vector valores(n+1, true);
    valores[0] = false;
    valores[1] = false;

    std::vector<int> primos = {};

    for (long long i=0 ; i < n+1; i++){
        if (valores[i]){
            for (long long j=i*i ; j < n+1; j=j+i){
                valores[j] = false;
            }
            primos.push_back(i);
        }
    }

    return primos;
}


int main(int argc, char const *argv[])
{

    int n;
    std::cout << "Calcular primos hasta: ";
    std::cin >> n;

    std::vector<int> crib = criba(n);

    for (int valor : crib){
        std::cout << valor << ", ";
    }

    std::cout << std::endl << "Longtud: " << crib.size() << std::endl;
    return 0;
}
