#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*
int main() {
    FILE* fp;
    char buffer[256];

    printf("Dispozitive USB conectate:\n\n");

    // Executăm comanda 'pnputil /enum-devices /class USB' și capturăm output-ul
    fp = _popen("pnputil /enum-devices /class USB", "r");
    if (fp == NULL) {
        printf("Eroare la executarea comenzii.\n");
        return 1;
    }

    // Citim și afișăm linie cu linie rezultatul
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    _pclose(fp);

    printf("\nApasati Enter pentru a inchide...");
    getchar();
    return 0;
}*/