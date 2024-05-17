#include <iostream>
#include <array>
#include <vector>
#include <unordered_set>

class Sudoku : public std::array<std::array<int, 9>, 9>{
public:

    Sudoku(std::string str){
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                (*this)[i][j] = str[i*9+j] - '0';
            }
        }
        std::cout << "Sudoku creado" << std::endl;
    }
    Sudoku(std::array<std::array<int, 9>, 9> arr){
        (*this) = arr;
        std::cout << "Sudoku creado" << std::endl;
    }

    bool veryRow(int rowNum){
        std::array<int, 9> row = (*this)[rowNum];
        std::unordered_set<int> set = {1,2,3,4,5,6,7,8,9};

        for (int i = 0; i<9; i++){
            if (row[i] == 0 || set.erase(row[i]) == 0){
                return false;
            }
        }
        return true;
    }

    bool veryCol(int colNum){
        std::array<int, 9> col;
        for (int i = 0; i<9; i++){
            col[i] = (*this)[i][colNum];
        }
        std::unordered_set<int> set = {1,2,3,4,5,6,7,8,9};

        for (int i = 0; i<9; i++){
            if (col[i] == 0 || set.erase(col[i]) == 0){
                return false;
            }
        }
        return true;
    }

    bool verySquare(int rowNum, int colNum){ // dato de la esquina superior izquierda
        std::unordered_set<int> set = {1,2,3,4,5,6,7,8,9};

        for (int i = rowNum; i<rowNum+3; i++){
            for (int j = colNum; j<colNum+3; j++){
                if ((*this)[i][j] == 0 || set.erase((*this)[i][j]) == 0){
                    return false;
                }
            }
        }
        return true;
    }

    bool isCorrect(){
        for (int i = 0; i<9; i++){
            if (!veryRow(i) || !veryCol(i)){
                return false;
            }
        }

        for (int i = 0; i<9; i+=3){
            for (int j = 0; j<9; j+=3){
                if (!verySquare(i, j)){
                    return false;
                }
            }
        }
        return true;
    }

    int cantEspacios(){
        int count = 0;
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if ((*this)[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }

    std::vector<int> aumento(std::vector<int> vector){
        int lastElement = vector.back();

        if (lastElement == 9){
            vector.pop_back();
            vector = aumento(vector);
            vector.push_back(1);
        }else{
            vector.pop_back();
            vector.push_back(lastElement+1);
        }

        return vector;

    }

    std::vector<std::array<int, 2>> posiciones(){
        std::vector<std::array<int,2>> pos;
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if ((*this)[i][j] == 0){
                    pos.push_back({i, j});
                }
            }
        }
        return pos;
    }


    void fuerzaBruta(){
        int n = cantEspacios();
        std::vector<int> sol(n);

        std::vector<std::array<int, 2>> freePos = posiciones();
        
        int iter = 0;
        while (!isCorrect() && iter<10000000){    
            for (int i = 0; i<n; i++){
                (*this)[freePos[i][0]][freePos[i][1]] = sol[i];
            }
            sol = aumento(sol);
            iter++;
            std::cout << "\r" << iter << std::flush;
        }
        std::cout << std::endl;
        if (isCorrect()){
            std::cout << "Solución encontrada" << std::endl;
        }else{
            std::cout << "No se encontró solución" << std::endl;
        }
    }

    std::vector<std::array<int, 2>> search(int n){
        std::vector<std::array<int, 2>> pos;
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if ((*this)[i][j] == n){
                    pos.push_back({i, j});
                }
            }
        }
        return pos;
    }

    bool inSquare(int n, int rowNum, int colNum){
        for (int i = rowNum; i<rowNum+3; i++){
            for (int j = colNum; j<colNum+3; j++){
                if ((*this)[i][j] == n){
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<std::array<int,2>> getFreeSquares(int n){
        std::vector<std::array<int,2>> squares = {};
        for (int i = 0; i<9; i+=3){
            for (int j = 0; j<9; j+=3){
                if (!inSquare(n, i, j)){
                    squares.push_back({i, j});
                }
            }
        }
        return squares;
    }

    std::array<std::array<int,2>, 9> iterSquare(int row, int col){
        std::array<std::array<int,2>, 9> square = {};
        int k = 0;
        for (int i = row; i<row+3; i++){
            for (int j = col; j<col+3; j++){
                square[k] = {i,j};
                k++;
            }
        }
        return square;
    }

    bool inRows(int row, std::vector<std::array<int, 2>> taken){
        for (int i = 0; i<taken.size(); i++){
            if (taken[i][0] == row){
                return true;
            }
        }
        return false;
    }

    bool inCols(int col, std::vector<std::array<int, 2>> taken){
        for (int i = 0; i<taken.size(); i++){
            if (taken[i][1] == col){
                return true;
            }
        }
        return false;
    }

    int solveSquare(int n, int row, int col, std::vector<std::array<int, 2>> taken){
        std::array<std::array<int,2>, 9> square = iterSquare(row, col);
        std::vector<int*>  posibilities = {};
        for (auto& [i,j] : square){
            //encontrar espacios libres
            if ((*this)[i][j] == 0){
                // verificar si es posible poner el número en esa posición
                if (!inRows(i, taken) && !inCols(j, taken)){
                    posibilities.push_back( &(*this)[i][j] );
                };
                
            }
        }
        if (posibilities.size() == 1){
            *posibilities[0] = n;
        }
        return posibilities.size();
    }

    void solve(){
        int iter = 0;
        int added = 0;
        int n = 1;
        while (!isCorrect() && iter<10000000){
            std::vector<std::array<int,2>> squares = getFreeSquares(n);
            std::vector<std::array<int, 2>>  taken = search(n);
            // Recorrer cada cuadro libre y verificar si hay solución
            for (int i = 0; i<squares.size(); i++){
                if (solveSquare(n, squares[i][0], squares[i][1], taken) == 1){
                    added++;
                }
                
            }
            n++;
            if (n == 10){
                n = 1;
            }
            iter ++;
            std::cout << "\r" << "iter: " << iter << " added: "<< added << std::flush;

        }
        std::cout << std::endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

    }

};


int main(int argc, char const *argv[]){
    std::string sudo;
    if (argc != 2){
        sudo = "587210094014695083000007052170064000003000500000130040021000970000006010350900400";
        if (sudo.size() != 81){
            std::cout << "El sudoku debe tener 81 caracteres" << std::endl;
            return 1;
        }
    }else{
        sudo = argv[1];
    }

    Sudoku sudoku(sudo);
    
    // sudoku.fuerzaBruta(); // 891374602726158943305629178479586231162437890538912467913865724687203019250791386
    sudoku.solve();

    for (int i = 0; i<9; i++){ // Imprimir el sudoku (opcional
        for (int j = 0; j<9; j++){
            std::cout << sudoku[i][j] << " ";
            if (j == 2 || j == 5){
                std::cout << "| ";
            }
        }
        if (i == 2 || i == 5){
            std::cout << std::endl;
            std::cout << "---------------------";
        }
        std::cout << std::endl;
    }




    return 0;
}