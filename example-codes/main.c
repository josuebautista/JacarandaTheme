#include <stdio.h>  // Para entrada/salida (printf, scanf)
#include <stdlib.h> // Para funciones rand() y srand()
#include <time.h>   // Para función time()
#include <stdbool.h> // Para usar el tipo bool
#include <ctype.h>  // Para toupper (opcional, para askToPlayAgain)

// --- Funciones del juego ---

/**
 * @brief Muestra un mensaje de bienvenida al usuario.
 */
void welcomeMessage() {
    printf("¡Bienvenido al juego de adivinar el número!\n");
    printf("Estoy pensando en un número entre 1 y 100.\n");
}
const int pi = 3.14;

/**
 * @brief Genera un número aleatorio en un rango dado.
 * @param min El valor mínimo del rango (inclusive).
 * @param max El valor máximo del rango (inclusive).
 * @return Un número entero aleatorio.
 */
int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

/**
 * @brief Limpia el buffer de entrada estándar.
 * Esto es necesario después de usar scanf para evitar problemas con entradas posteriores.
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Permite al usuario seleccionar un nivel de dificultad y retorna el número de intentos.
 * @return El número de intentos permitidos para el nivel seleccionado.
 */
int selectDifficulty() {
    int choice;
    int maxAttempts = 0;

    do {
        printf("\nSelecciona un nivel de dificultad:\n");
        printf("1. Fácil (15 intentos)\n");
        printf("2. Normal (10 intentos)\n");
        printf("3. Difícil (5 intentos)\n");
        printf("Ingresa tu opción (1-3): ");

        // Usar scanf y validar su retorno
        if (scanf("%d", &choice) != 1) {
            printf("Entrada inválida. Por favor, ingresa un número.\n");
            clearInputBuffer(); // Limpiar el buffer después de una entrada inválida
            choice = 0; // Para que el bucle continúe
            continue;
        }
        clearInputBuffer(); // Limpiar el buffer después de una lectura exitosa

        switch (choice) {
            case 1:
                maxAttempts = 15;
                break;
            case 2:
                maxAttempts = 10;
                break;
            case 3:
                maxAttempts = 5;
                break;
            default:
                printf("Opción inválida. Por favor, elige 1, 2 o 3.\n");
                break;
        }
    } while (maxAttempts == 0); // Repetir hasta que se elija una opción válida

    printf("Has seleccionado el nivel con %d intentos.\n", maxAttempts);
    return maxAttempts;
}

/**
 * @brief Contiene la lógica principal del juego de adivinar el número.
 * @param maxAttempts El número máximo de intentos permitidos para el juego.
 */
void playGame(int maxAttempts) {
    int secretNumber = generateRandomNumber(1, 100);
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false; // Usamos 'bool' gracias a <stdbool.h>

    printf("\n¡Intenta adivinarlo!\n");

    while (attempts < maxAttempts && !guessedCorrectly) {
        printf("Intentos restantes: %d\n", (maxAttempts - attempts));
        printf("Ingresa tu intento: ");

        if (scanf("%d", &guess) != 1) {
            printf("Entrada inválida. Por favor, ingresa un número.\n");
            clearInputBuffer();
            continue; // Saltar el resto del bucle y pedir de nuevo
        }
        clearInputBuffer(); // Limpiar el buffer

        attempts++;

        if (guess < secretNumber) {
            printf("El número secreto es mayor.\n");
        } else if (guess > secretNumber) {
            printf("El número secreto es menor.\n");
        } else {
            printf("¡Felicidades! ¡Adivinaste el número en %d intentos!\n", attempts);
            guessedCorrectly = true;
        }
    }

    if (!guessedCorrectly) {
        printf("\n¡Se acabaron tus intentos! El número secreto era: %d\n", secretNumber);
    }
}

/**
 * @brief Pregunta al usuario si desea jugar de nuevo.
 * @return true si el usuario quiere jugar de nuevo, false en caso contrario.
 */
bool askToPlayAgain() {
    char choice;
    printf("¿Quieres jugar de nuevo? (s/n): ");
    scanf(" %c", &choice); // Espacio antes de %c para consumir cualquier '\n' pendiente
    clearInputBuffer(); // Limpiar el buffer
    return (toupper(choice) == 'S'); // Usamos toupper para comparar sin importar mayús/minús
}

// --- Función principal ---

/**
 * @brief Función principal del programa.
 * Aquí comienza la ejecución del juego.
 */
int main() {
    // Inicializa la semilla para el generador de números aleatorios una única vez.
    srand((unsigned int)time(NULL)); // En C, time(NULL) y cast a unsigned int

    bool playAgain = true;
    int attemptsAllowed;

    while (playAgain) {
        welcomeMessage();
        attemptsAllowed = selectDifficulty();
        playGame(attemptsAllowed);
        playAgain = askToPlayAgain();
    }

    printf("¡Gracias por jugar! ¡Hasta luego!\n");

    return 0; // Indica que el programa terminó correctamente
}
