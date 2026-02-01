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
int main() {
    int opcion, id;
    string nombre;
    float peso;

    do {
        cout << "\n===== EMPRESA DE TERRY =====\n";
        cout << "1. Insertar paquete al final\n";
        cout << "2. Insertar paquete al inicio\n";
        cout << "3. Mostrar lista adelante\n";
        cout << "4. Mostrar lista atrás\n";
        cout << "5. Buscar paquete por ID\n";
        cout << "6. Eliminar paquete por ID\n";
        cout << "7. Mostrar cantidad de paquetes\n";
        cout << "8. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Peso: "; cin >> peso;
                insertarFinal(id, nombre, peso);
                break;

            case 2:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Peso: "; cin >> peso;
                insertarInicio(id, nombre, peso);
                break;

            case 3:
                mostrarAdelante();
                break;

            case 4:
                mostrarAtras();
                break;

            case 5: {
                cout << "ID a buscar: ";
                cin >> id;
                Nodo* encontrado = buscarPorId(id);
                if (encontrado)
                    cout << "Encontrado: " << encontrado->nombre
                         << " | Peso: " << encontrado->peso << endl;
                else
                    cout << "No encontrado.\n";
                break;
            }

            case 6:
                cout << "ID a eliminar: ";
                cin >> id;
                eliminarPorId(id);
                break;

            case 7:
                cout << "Total de paquetes: "
                     << contarPaquetes() << endl;
                break;

            case 8:
                liberarLista();
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 8);

    return 0;
}


