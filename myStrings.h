#include <iostream>
#include <vector>


std::vector<std::string> split(std::string cadena, char separador, bool espacios = true){
    std::vector<std::string> palabras;
    std::string cad = "";

    for (int i = 0; i<cadena.length(); i++){
        if (!espacios && cadena[i] == ' '){
            continue;
        }else if (cadena[i] == separador && cad != ""){
            palabras.push_back(cad);
            cad = "";
        }else{
            cad += cadena[i];
        }
    }
    palabras.push_back(cad);

    return palabras;
}


