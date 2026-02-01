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
void mostrarAdelante() {
    if (head == nullptr) {
        cout << "La lista está vacía.\n";
        return;
    }

    Nodo* aux = head;
    while (aux != nullptr) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << endl;
        aux = aux->sig;
    }
}

void mostrarAtras() {
    if (tail == nullptr) {
        cout << "La lista está vacía.\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != nullptr) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << endl;
        aux = aux->ant;
    }
}

Nodo* buscarPorId(int id) {
    Nodo* aux = head;
    while (aux != nullptr) {
        if (aux->id == id)
            return aux;
        aux = aux->sig;
    }
    return nullptr;
}

bool eliminarPorId(int id) {
    if (head == nullptr) {
        cout << "La lista está vacía.\n";
        return false;
    }

    Nodo* aux = buscarPorId(id);

    if (aux == nullptr) {
        cout << "ID no encontrado.\n";
        return false;
    }

    if (aux == head && aux == tail) {
        head = tail = nullptr;
    } else if (aux == head) {
        head = head->sig;
        head->ant = nullptr;
    } else if (aux == tail) {
        tail = tail->ant;
        tail->sig = nullptr;
    } else {
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
    }

    delete aux;
    cout << "Paquete eliminado correctamente.\n";
    return true;
}

int contarPaquetes() {
    int contador = 0;
    Nodo* aux = head;
    while (aux != nullptr) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

void liberarLista() {
    while (head != nullptr) {
        Nodo* aux = head;
        head = head->sig;
        delete aux;
    }
    tail = nullptr;
}


