#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wywołanie %s ścieżka", argv[0]);
        return 1;
    }
    struct dirent *pozycja;

    DIR *pDir = opendir(argv[1]);
/*Otwórz katalog, w przypadku błędu otwarcia zwróć błąd funkcji otwierającej i zwrócć 1. 
Wyświetl zawartość katalogu katalog, pomijając "." i ".."
Jeśli podczas tej operacji wartość errno zostanie ustawiona, zwróć błąd funkcji czytającej oraz wartość 2. */
    if (pDir == NULL) {
        return 1;
    }
    pozycja = readdir(pDir);
    pozycja = readdir(pDir);

    while ((pozycja = readdir(pDir)) != NULL) {
        char filename[255];
        strcpy(filename, pozycja->d_name);
        printf("%s\n", filename);
    }
    closedir(pDir);
    return 0;










/*koniec*/
//    return (0);
}
