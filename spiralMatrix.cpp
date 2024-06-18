#include <iostream>
#include <vector>
#include <cmath>

using std::cout, std::endl, std::vector, std::string;

vector<string> split(string text, char separator)
{
    vector<string> result = {};
    string word = "";
    for (char c : text)
    {
        if (c == separator)
        {
            result.push_back(word);
            word = "";
        }
        else if (c != ' ') word += c;
    }
    if (text[text.size()-1] != separator ) result.push_back(word);

    return result;

}

vector<float> toFloat(vector<string> words)
{
    vector<float> numbers = {};
    for (string word : words)
    {
        int size = word.size();
        //find point
        int digits = 0;
        for (char c : word)
        {
            if (c=='.') break;
            digits++;
        }


        // Get number
        float num = 0;
        for (int i=0; i<digits; i++)
        {
            num += (word[i] - '0') * pow(10, digits-i-1);
        }
        for (int i=digits+1; i<size; i++)
        {
            num += (word[i] - '0') * pow(10, -i+digits);
        }
        numbers.push_back(num);
    }
    return numbers;
}


// Directions
class direction
{
private:
    const int directions[4][2] = {
        {0,1},  // Right
        {1,0},  // Down
        {0,-1}, // Left
        {-1,0}  // Up
    };

    int cycle = 0;
    const int* currentDir = directions[0];
    
protected:
    const int* operator[](int n)
    {
        return directions[n];
    }

public:

    const int* next()
    {
        cycle++;
        if (cycle > 4) cycle = 0;
        currentDir = directions[cycle];
        return currentDir;
    }

    void changeLimit(int& top, int& buttom, int& left, int& right)
    {
        if (currentDir == directions[0]) // going to right
        {
            top++;
        }
        else if (currentDir == directions[1]) // going to down
        {
            right--;
        }
        else if (currentDir == directions[2]) // going to left
        {
            buttom--;
        }
        else if (currentDir == directions[3]) // going to up
        {
            left++;
        }
    }

    int* operator+(int other[])
    {
        other[0] = other[0]+currentDir[0];
        other[1] = other[1]+currentDir[1];
        return other;
    }

    int* operator-(int other[])
    {
        other[0] = other[0]-currentDir[0];
        other[1] = other[1]-currentDir[1];
        return other;
    }
};

direction dir;

int main(int argc, const char* argv[])
{
    string text = "";
    cout << "Enter numbers, separed by ',': "; std::getline(std::cin, text);

    vector<float> numbers = toFloat(split(text, ','));

    // Limits
    int size = numbers.size();
    int top = 0;
    int buttom = pow(size, 0.5); 
    int left = 0;
    int right = buttom;

    int index = 0;
    int pos[2] = {0,0};

    float matrix[buttom][right]{0};

    while (index < size)
    {
        while ((pos[0] < buttom && pos[0] >= top) && (pos[1] < right && pos[1] >= left))
        {
            matrix[pos[0]][pos[1]] = numbers[index];
            index++;
            dir + pos;
            cout << pos[0] << " " << pos[1] << endl;
        }
        dir - pos; // Undo last move
        dir.changeLimit(top, buttom, left, right);
        dir.next();
        dir + pos;
    }

    // print matrix
    cout << "Matrix: \n";
    for (int i=0; i<pow(size, 0.5); i++)
    {
        for (int j=0; j<pow(size, 0.5); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}