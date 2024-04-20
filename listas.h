#include <list>



class Lista : public std::list<float>{
public:
    int length;
    Lista(std::initializer_list<float> init) : std::list<float>(init){
        this->length = this->size();
    }

    float& get_element(int pos){
        static float error_value = -1.0f;
        if (pos >= this->length){
            return error_value;
        }
        if (pos < 0){
            return get_element(this->length + pos);
        }

        auto it = this->begin();
        std::advance(it, pos);
        return *it;
    }

    float& operator[](int pos){
        return this->get_element(pos);
    }

    void push_back(float value){
        std::list<float>::push_back(value);
        this->length = this->size();
    }
    void push_front(float value){
        std::list<float>::push_front(value);
        this->length = this->size();
    }

};


// Invertir lista
Lista invert(Lista lista){
    Lista invertida = {};
    for (auto valor : lista){
        invertida.push_front(valor);
    }

    return invertida;
}


//Máximo de una lista
float max(Lista lista){
    float n = lista[0];
    for (auto valor : lista){
        if (valor > n ){
            n = valor;
        }
    }
    return n;
}

float min(Lista lista){
    float n = lista[0];
    for (auto valor : lista){
        if (valor < n){
            n = valor;
        }
    }
    return n;
}

// Criba

Lista criba(int n){
    Lista lista = {};
    Lista primos = {};

    for (int i=0; i<n+1; i++){
        lista.push_back( 1 );
    }
    lista[0] = 0;
    lista[1] = 0;

    for (int i = 2; i<n+1; i++){
        if (lista[i] != 0){
            //Eliminar múltiplos
            for (int j=i*i; j<n+1; j = j+i){
                lista[j] = 0;
            }
            primos.push_back(i);
        }
    }
    return primos;
}



