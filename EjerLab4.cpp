#include <iostream>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};

Nodo* head = nullptr;
Nodo* tail = nullptr;

bool existeId(int id);
void insertarInicio(int id, string nombre, float peso);
void insertarFinal(int id, string nombre, float peso);
void mostrarAdelante();
void mostrarAtras();
Nodo* buscarPorId(int id);
bool eliminarPorId(int id);
int contarPaquetes();
void liberarLista();

bool existeId(int id) {
    Nodo* aux = head;
    while (aux != nullptr) {
        if (aux->id == id)
            return true;
        aux = aux->sig;
    }
    return false;
}

void insertarInicio(int id, string nombre, float peso) {
    if (existeId(id)) {
        cout << "El ID ya existe.\n";
        return;
    }

    Nodo* nuevo = new Nodo;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->ant = nullptr;
    nuevo->sig = head;

    if (head == nullptr) {
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }

    cout << "Paquete insertado al inicio.\n";
}

void insertarFinal(int id, string nombre, float peso) {
    if (existeId(id)) {
        cout << "El ID ya existe.\n";
        return;
    }

    Nodo* nuevo = new Nodo;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = nullptr;
    nuevo->ant = tail;

    if (tail == nullptr) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }

    cout << "Paquete insertado al final.\n";
}
