#include <iostream>
#include <cstdlib>


void print(std::string text){
    std::cout << text << std::endl;
}
void print(int number){
    std::cout << number << std::endl;
}


int main(int argc, char const *argv[])
{

    if (system(nullptr)){
        std::cout << "system is available" << std::endl;
    }else{
        std::cout << "system is not available" << std::endl;
        exit(1);
    }
    system("triqui");



    return 0;
}
