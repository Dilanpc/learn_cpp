#include <iostream>
#include <array>
#include "myStrings.h"

char matrix[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

char turno = 'o';

void show (char matrix[3][3] ) {
    for (int i=0 ; i<3; i++){
        for (int j=0 ; j<3; j++){
            if(j==0){std::cout << "|"; }
            std::cout << " " << matrix[i][j] << " ";
            if (j==2){std::cout << "|"; }

        }
        std::cout << std::endl;
    }
}

void update(char matrix[3][3], int fila, int colum, char turno){
    matrix[fila][colum] = turno;
}

void cambio(char& turno){
    //cambio de turno
    if (turno == 'x'){turno = 'o';}
    else {turno = 'x';}
}


void move(char matrix[3][3], char& turno){
    
        int fila;
        int colum;
        std::cout << "Fila: "; std::cin >> fila;
        std::cout << "Colummna: "; std::cin >> colum;
        fila--; colum--; //iniciar desde 1
        if (matrix[fila][colum] == ' '){
            update(matrix, fila, colum, turno);
        }else{
            std::cout << "Casilla inválida" << std::endl;
            move(matrix, turno);
        }
}


bool row_colum(char matrix[3][3], char turno){
    bool alguno = false;
    for ( int i = 0; i<3; i++){
        bool colum = true;
        bool fila = true;
        for (int j = 0; j<3; j++){
            colum = (matrix[j][i] == turno) && colum; // comprobar columa
            fila = (matrix[i][j] == turno) && fila; // comprobar fila
        }
        alguno = colum || fila || alguno;
    }
    return alguno;
}

bool diagonal(char matrix[3][3], char turno){
    bool abajo = true;
    bool arriba = true;
    for (int i = 0; i<3; i++){
        abajo = (matrix[i][i]==turno) && abajo;
        arriba = (matrix[i][2-i]==turno) && arriba;
    }
    return abajo || arriba;
}

bool is_win(char matrix[3][3], char turno){
    return row_colum(matrix, turno) || diagonal(matrix, turno);
}


bool validMove(int fila, int colum, char matrix[3][3]){
    if (fila < 0 || fila > 2 || colum < 0 || colum > 2){
        return false;
    }
    return matrix[fila][colum] == ' ';
}


std::array<int, 2> get_move(char matrix[3][3], char& turno){
    std::array<int, 2> pos;
    std::string txt;

    std::cout << "Ingrese fila, columa: "; std::getline(std::cin, txt);
    std::vector<std::string> datos = split(txt, ',', false);

    pos[0] = std::stoi(datos[0]) -1;
    pos[1] = std::stoi(datos[1]) -1;

    if (validMove(pos[0], pos[1], matrix)){
        update(matrix, pos[0], pos[1], turno);
    }else {
        std::cout << "Movimiento inválido" << std::endl;
        return get_move(matrix, turno);
    }

    return pos;
}



int main(int argc, char const *argv[])
{
    int count = 0;
    while (count < 9 && !is_win(matrix, turno)){
        count++;
        cambio(turno);
        show(matrix);

        get_move(matrix, turno);

    };

    show(matrix);
    if (is_win(matrix, turno)){
        std::cout << "Ha ganado " << turno << std::endl;
    }else{
        std::cout << "Empate" << std::endl;
    }

    return 0;
}
