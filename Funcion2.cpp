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


