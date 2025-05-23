#include <iostream>  // Para entrada/salida (cout, cin)
#include <cstdlib>   // Para funciones rand() y srand()
#include <ctime>     // Para función time()
#include <limits>    // Para std::numeric_limits
#include <algorithm> // Para std::min y std::max (opcional, para limpieza de entrada)

// --- Funciones del juego ---

/**
 * @brief Muestra un mensaje de bienvenida al usuario.
 */
void welcomeMessage()
{
    std::cout << "¡Bienvenido al juego de adivinar el número!" << std::endl;
    std::cout << "Estoy pensando en un número entre 1 y 100." << std::endl;
}

/**
 * @brief Genera un número aleatorio en un rango dado.
 * @param min El valor mínimo del rango (inclusive).
 * @param max El valor máximo del rango (inclusive).
 * @return Un número entero aleatorio.
 */
int generateRandomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

/**
 * @brief Permite al usuario seleccionar un nivel de dificultad y retorna el número de intentos.
 * @return El número de intentos permitidos para el nivel seleccionado.
 */
int selectDifficulty()
{
    int choice;
    int maxAttempts = 0;

    do
    {
        std::cout << "\nSelecciona un nivel de dificultad:" << std::endl;
        std::cout << "1. Fácil (15 intentos)" << std::endl;
        std::cout << "2. Normal (10 intentos)" << std::endl;
        std::cout << "3. Difícil (5 intentos)" << std::endl;
        std::cout << "Ingresa tu opción (1-3): ";
        std::cin >> choice;

        // Validar la entrada para asegurar que es un número y limpiar el buffer
        if (std::cin.fail())
        {
            std::cout << "Entrada inválida. Por favor, ingresa un número." << std::endl;
            std::cin.clear(); // Limpiar el flag de error
            // Ignorar el resto de la línea para evitar bucles infinitos
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // Para que el bucle continúe
            continue;
        }
        // Limpiar el buffer de entrada para el caso de que el usuario escriba, por ejemplo, "1asdf"
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
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
            std::cout << "Opción inválida. Por favor, elige 1, 2 o 3." << std::endl;
            break;
        }
    } while (maxAttempts == 0); // Repetir hasta que se elija una opción válida

    std::cout << "Has seleccionado el nivel con " << maxAttempts << " intentos." << std::endl;
    return maxAttempts;
}

/**
 * @brief Contiene la lógica principal del juego de adivinar el número.
 * @param maxAttempts El número máximo de intentos permitidos para el juego.
 */
void playGame(int maxAttempts)
{
    int secretNumber = generateRandomNumber(1, 100);
    int guess;
    int attempts = 0;
    bool guessedCorrectly = false;

    std::cout << "\n¡Intenta adivinarlo!" << std::endl;

    while (attempts < maxAttempts && !guessedCorrectly)
    {
        std::cout << "Intentos restantes: " << (maxAttempts - attempts) << std::endl;
        std::cout << "Ingresa tu intento: ";
        std::cin >> guess;

        // Validar la entrada del intento
        if (std::cin.fail())
        {
            std::cout << "Entrada inválida. Por favor, ingresa un número." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // Saltar el resto del bucle y pedir de nuevo
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

        attempts++;

        if (guess < secretNumber)
        {
            std::cout << "El número secreto es mayor." << std::endl;
        }
        else if (guess > secretNumber)
        {
            std::cout << "El número secreto es menor." << std::endl;
        }
        else
        {
            std::cout << "¡Felicidades! ¡Adivinaste el número en " << attempts << " intentos!" << std::endl;
            guessedCorrectly = true;
        }
    }

    if (!guessedCorrectly)
    {
        std::cout << "\n¡Se acabaron tus intentos! El número secreto era: " << secretNumber << std::endl;
    }
}

/**
 * @brief Pregunta al usuario si desea jugar de nuevo.
 * @return true si el usuario quiere jugar de nuevo, false en caso contrario.
 */
bool askToPlayAgain()
{
    char choice;
    std::cout << "¿Quieres jugar de nuevo? (s/n): ";
    std::cin >> choice;
    // Limpiar el buffer de entrada para evitar problemas en futuras lecturas
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return (choice == 's' || choice == 'S');
}

// --- Función principal ---

/**
 * @brief Función principal del programa.
 * Aquí comienza la ejecución del juego.
 */
int main()
{
    // Inicializa la semilla para el generador de números aleatorios una única vez.
    srand(static_cast<unsigned int>(time(0)));

    bool playAgain = true;
    int attemptsAllowed;

    while (playAgain)
    {
        welcomeMessage();                     // Muestra el mensaje de bienvenida
        attemptsAllowed = selectDifficulty(); // Permite al usuario elegir la dificultad
        playGame(attemptsAllowed);            // Ejecuta la lógica principal del juego con los intentos elegidos
        playAgain = askToPlayAgain();         // Pregunta si quiere jugar de nuevo
    }

    std::cout << "¡Gracias por jugar! ¡Hasta luego!" << std::endl;

    return 0; // Indica que el programa terminó correctamente
}
