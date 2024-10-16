#include <iostream>
using namespace std;

const int MAX_INTENTOS = 6; //Número máximo de intentos

//Función para mostrar el estado actual del juego
void mostrarEstado(const char* palabraSecreta, const bool* letrasAdivinadas, int longitud) {
    for (int i = 0; i < longitud; ++i) {
        if (letrasAdivinadas[i]) {
            cout << palabraSecreta[i] << " "; //Mostrar letra si ha sido adivinada
        } else {
            cout << "_ "; //Mostrar guion bajo si no se ha adivinado
        }
    }
    cout << endl;
}

int main() {
    const char palabraSecreta[] = "programacion"; //Palabra a adivinar
    const int longitudPalabra = sizeof(palabraSecreta) - 1; //Longitud de la palabra
    bool letrasAdivinadas[longitudPalabra] = {false}; //Inicializar letras adivinadas
    int intentosRestantes = MAX_INTENTOS; //Intentos permitidos

    cout << "¡Bienvenido al juego de Ahorcados!" << endl;

    //Bucle principal del juego
    while (intentosRestantes > 0) {
        cout << "\nPalabra: ";
        mostrarEstado(palabraSecreta, letrasAdivinadas, longitudPalabra); 
        cout << "Intentos restantes: " << intentosRestantes << endl;

        char letra;
        cout << "Adivina una letra: ";
        cin >> letra;

        bool letraEncontrada = false;

        //Verificar si la letra está en la palabra secreta
        for (int i = 0; i < longitudPalabra; ++i) {
            if (palabraSecreta[i] == letra) {
                letrasAdivinadas[i] = true; //Marcar letra como adivinada
                letraEncontrada = true;
            }
        }

        //Verificar si la letra fue encontrada
        if (!letraEncontrada) {
            intentosRestantes--; //Restar un intento si la letra no está
            cout << "¡Incorrecto! La letra no está en la palabra." << endl;
        } else {
            cout << "¡Correcto! La letra está en la palabra." << endl;
        }

        //Verificar si el jugador ha adivinado la palabra
        bool adivinada = true;
        for (int i = 0; i < longitudPalabra; ++i) {
            if (!letrasAdivinadas[i]) {
                adivinada = false; //Si hay una letra que no ha sido adivinada
                break;
            }
        }

        if (adivinada) {
            cout << "¡Felicidades! Has adivinado la palabra: " << palabraSecreta << endl;
            break;
        }
    }

    if (intentosRestantes == 0) {
        cout << "¡Game over! La palabra era: " << palabraSecreta << endl;
    }

    return 0;
}
