#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 * 2. Program identyfikuje typy plików podane jako argumenty,
 * rozpoznaje zwykle pliki, katalogi oraz linki symboliczne.
 * Należy uzupełnić program w oznaczonych wierszach rozpoznając odpowiednie
 * rodzaje plików. (Trzy razy wywołać makro do sprawdzanie typu pliku z <podany
 * argument>.st_mode
 */

int main(int argc, char* argv[]) {
    int i;
    struct stat buf;
    char* tekst;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            printf("lstat error");
            continue;
        }

        /* CHANGES FROM HERE */

        /* TU UZUPELNIC warunek rozpoznajacy zwykly plik*/

        // st_mode - This field contains the file type and mod
        if(S_ISREG(buf.st_mode)) {
            tekst = "regular file";
        }

        /* TU UZUPELNIC warunek rozpoznajacy katalog*/

        else if(S_ISDIR(buf.st_mode)) {
            tekst = "directory";
        }
        

        /* TU UZUPELNIC warunek rozpoznajacy link symboliczny*/

        else if (S_ISLNK(buf.st_mode)) {
            tekst = "link";
        }


        /* TILL HERE */

        else {
            tekst = "**** cos innego !!! ****";
        }

        printf("%s\n", tekst);
    }

    exit(0);
}