#include <stdio.h>
#include <windows.h>

int main() {
    SYSTEM_INFO sysInfo;
    DWORD pageSize;
    LPVOID memoria = NULL;
    // Număr fix de pagini - modifică aici pentru a aloca mai multe sau mai puține
    int numarPagini = 10;

    // Aflăm dimensiunea unei pagini
    GetSystemInfo(&sysInfo);
    pageSize = sysInfo.dwPageSize;

    printf("Dimensiunea unei pagini: %lu bytes\n", pageSize);
    printf("Se aloca %d pagini...\n", numarPagini);

    // Alocăm memoria
    SIZE_T dimensiuneTotala = (SIZE_T)pageSize * numarPagini;

    memoria = VirtualAlloc(NULL, dimensiuneTotala, MEM_COMMIT, PAGE_READWRITE);

    if (memoria == NULL) {
        printf("Eroare la alocare! Cod: %lu\n", GetLastError());
        return 1;
    }

    printf("Memorie alocata la adresa: 0x%p\n", memoria);
    printf("Total memorie alocata: %llu bytes\n", (unsigned long long)dimensiuneTotala);

    // Scriem ceva în memorie pentru test
    for (int i = 0; i < numarPagini; i++) {
        char* adrPagina = (char*)memoria + (i * pageSize);
        *adrPagina = (char)i;
    }

    // Eliberăm memoria
    VirtualFree(memoria, 0, MEM_RELEASE);
    printf("Memoria a fost eliberata\n");

    printf("\nApasa Enter pentru a inchide...");
    getchar();

    return 0;
}