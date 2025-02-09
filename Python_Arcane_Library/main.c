#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estructura de mago
struct Mago {
    char nombre[50];
    int nivelMagico;
    char hechizoFavorito[30];
};

// imprimir mago
void imprimirMago(struct Mago mago) {
    printf("Nombre: %s\n", mago.nombre);
    printf("Nivel magico: %d\n", mago.nivelMagico);
    printf("Hechizo favorito: %s\n\n", mago.hechizoFavorito);
}

// crear nuevo mago
struct Mago crearMago(char nombre[], int nivelMagico, char hechizoFavorito[]) {
    struct Mago nuevoMago;
    strncpy(nuevoMago.nombre, nombre, sizeof(nuevoMago.nombre) - 1);
    nuevoMago.nombre[sizeof(nuevoMago.nombre) - 1] = '\0';  // Asegurarse de que la cadena está terminada
    nuevoMago.nivelMagico = nivelMagico;
    strncpy(nuevoMago.hechizoFavorito, hechizoFavorito, sizeof(nuevoMago.hechizoFavorito) - 1);
    nuevoMago.hechizoFavorito[sizeof(nuevoMago.hechizoFavorito) - 1] = '\0';
    return nuevoMago;
}

// funcion para ordenar mags por poder
void ordenarMagos(struct Mago magos[], int n) {
    struct Mago temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (magos[i].nivelMagico < magos[j].nivelMagico) {
                temp = magos[i];
                magos[i] = magos[j];
                magos[j] = temp;
            }
        }
    }
}

// modificar nivel magico
void modificarNivelMagico(struct Mago *mago, int nuevoNivel) {
    if (nuevoNivel < 1 || nuevoNivel > 100) {
        printf("Error: El nivel magico debe estar entre 1 y 100.\n");
        return;
    }
    if (nuevoNivel < mago->nivelMagico) {
        printf("Advertencia: El nivel magico ha disminuido!\n");
    }
    mago->nivelMagico = nuevoNivel;
}

// crear lista de magos
typedef struct Mago* ListaMagos;

ListaMagos crearListaMagos(int numeroMagos) {
    ListaMagos lista = (ListaMagos)malloc(numeroMagos * sizeof(struct Mago));
    if (lista == NULL) {
        printf("Error: No se pudo crear lista de magos.\n");
        exit(1);
    }

    for (int i = 0; i < numeroMagos; i++) {
        printf("Ingrese el nombre del mago %d: ", i + 1);
        scanf("%49s", lista[i].nombre);
        printf("Ingrese el nivel magico del mago %d (1-100): ", i + 1);
        scanf("%d", &lista[i].nivelMagico);
        printf("Ingrese el hechizo favorito del mago %d: ", i + 1);
        scanf("%29s", lista[i].hechizoFavorito);
    }
    return lista;
}

// el main
int main() {
    int numeroMagos;
    printf("Ingrese el numero de magos a registrar: ");
    scanf("%d", &numeroMagos);

    ListaMagos magos = crearListaMagos(numeroMagos);
    int *modificados = (int *)calloc(numeroMagos, sizeof(int));

    if (modificados == NULL) {
        printf("Error: No se pudo, no hay memoria suficiente.\n");
        free(magos);
        return 1;
    }

    int modificadosCount = 0;
    while (modificadosCount < numeroMagos) {
        printf("\nMenu de modificacion de magos:\n");
        for (int i = 0; i < numeroMagos; i++) {
            if (!modificados[i]) {
                printf("%d. %s\n", i + 1, magos[i].nombre);
            }
        }

        int opcion;
        printf("Selecciona el numero del mago a modificar: ");
        if (scanf("%d", &opcion) != 1) {
            while(getchar() != '\n');
            printf("Entrada invalida, intentalo de nuevo.\n");
            continue;
        }

        if (opcion < 1 || opcion > numeroMagos || modificados[opcion - 1]) {
            printf("Opcion invalida o mago ya modificado.\n");
            continue;
        }

        int nuevoNivel;
        printf("Ingresa el nuevo nivel magico para %s: ", magos[opcion - 1].nombre);
        if (scanf("%d", &nuevoNivel) != 1) {
            while(getchar() != '\n');
            printf("Entrada invalida. Intente de nuevo.\n");
            continue;
        }

        modificarNivelMagico(&magos[opcion - 1], nuevoNivel);
        modificados[opcion - 1] = 1;
        modificadosCount++;
    }

    printf("\nTodos los magos han sido modificados:\n");
    for (int i = 0; i < numeroMagos; i++) {
        imprimirMago(magos[i]);
    }

    ordenarMagos(magos, numeroMagos);
    printf("Magos mas poderosos (de mayor a menor):\n");
    for (int i = 0; i < numeroMagos; i++) {
        imprimirMago(magos[i]);
    }

    free(magos);
    free(modificados);

    return 0;
}
