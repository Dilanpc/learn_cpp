#include <iostream>
#include <thread>
#include <chrono>


// Función que será ejecutada por el hilo
void threadFunction(int id) {
    std::this_thread::sleep_for(std::chrono::seconds(id+1));
    std::cout << "Hola desde el hilo " << id << std::endl;
}

int main() {
    const int numThreads = 5;
    std::thread threads[numThreads]; // Arreglo de hilos

    // Crear varios hilos
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(threadFunction, i);
    }

    std::cout << "Hola desde el hilo principal" << std::endl;

    // Esperar a que todos los hilos terminen
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join(); // función join() detiene el hilo principal hasta que el hilo i termine
        std::cout << "Hilo " << i << " terminado" << std::endl;
    }

    return 0;
}
