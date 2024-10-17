#include <iostream>
using namespace std;

const int MAX_INTENTOS = 6; //Número máximo de intentos

//Función para mostrar el estado actual del juego
void mostrarEstado(const char* palabraSecreta, const bool* letrasAdivinadas, int longitud) { //Apuntador hacia el valor de palabra secreta, un apuntador booleano para ir letra por letra de la palabra secreta y el int es para la longitud de la palabra
    for (int i = 0; i < longitud; ++i) { //Se recorre letra por letra
        if (letrasAdivinadas[i]) { //Si se encuentra la misma letra que el usuario ingreso entonces
            cout << palabraSecreta[i] << " "; //Se muestra la letra adivinada
        } else { //Si la letra que el usuario ingreso no está en la palabra 
            cout << "_ "; //Se muestra un guion bajo
        }
    }
    cout << endl;
}

int main() {
    const char palabraSecreta[] = "programacion"; //Palabra a adivinar
    const int longitudPalabra = sizeof(palabraSecreta) - 1; //Longitud de la palabra
    bool letrasAdivinadas[longitudPalabra] = {false}; //Inicializar letras adivinadas
    int intentosRestantes = MAX_INTENTOS; //Intentos permitidos

    cout << "¡Bienvenido al juego de Ahorcados!" << endl; //Bienvenida al usuario

    //Bucle principal del juego
    while (intentosRestantes > 0) { //Mientras que los intentos restantes sean mayores a 0 se seguirá ejecutando
        cout << "\nPalabra: "; 
        mostrarEstado(palabraSecreta, letrasAdivinadas, longitudPalabra); //Llamamos a la funcion
        cout << "Intentos restantes: " << intentosRestantes << endl;

        char letra; //Aquí declaramos la variable letra
        cout << "Adivina una letra: "; 
        cin >> letra; //Aquí guardamos el valor ingresado por el usuario (letra)

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
            cout << "¡Incorrecto! La letra no esta en la palabra." << endl;
        } else {
            cout << "¡Correcto! La letra esta en la palabra." << endl;
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
