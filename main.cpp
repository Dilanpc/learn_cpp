#include <iostream>
#include <chrono>
#include <thread>

int main() {
    std::string original = "Texto original muy largo";
    std::cout << original;
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Espera 2 segundos

    // Mueve el cursor hacia atrás y sobrescribe el texto con espacios
    std::cout << "\r" << std::string(original.length(), ' ') << "\r" << std::flush;

    std::cout << "Texto nuevo" << std::flush;

    std::this_thread::sleep_for(std::chrono::seconds(2));  // Espera 2 segundos
    return 0;
}