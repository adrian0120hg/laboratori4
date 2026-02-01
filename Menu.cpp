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