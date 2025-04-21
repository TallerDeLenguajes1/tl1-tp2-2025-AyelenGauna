#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_COMPUS 5

typedef struct{ 
    int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
}compu; 

compu PCs[CANT_COMPUS];

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

int generarVelocidad (){
    return 1 + rand() % 3;
}

int generarYear (){
    return 2015 + rand() % (2024-2015+1);
}

int generarCantidadNucleos (){
    return 1 + rand() % 8;
}

void listarPcs(compu pcs[], int cantidad){
    printf("\n----- CARACTERISTICAS DE PCs -----\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("PC %d\nVelocidad: %d\tAnio de fabricacion: %d\tCantidad de nucleos: %d\tTipo de procesador: %s\n", i+1, pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(compu pcs[], int cantidad){
    printf("\n----- PC MAS VIEJA -----\n");
    int anio = 2025;
    compu vieja;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < anio)
        {
            vieja = pcs[i];
            anio = pcs[i].anio;
        }        
    }

    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio == vieja.anio)
        {
            printf("PC %d\nVelocidad: %d\tAnio de fabricacion: %d\tCantidad de nucleos: %d\tTipo de procesador: %s\n", i+1, pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
            break;
        }
        
    }
    
}

int main (){
    srand(time(NULL));
    for (int i = 0; i < CANT_COMPUS; i++)
    {
        compu PC= {
            generarVelocidad(),
            generarYear(),
            generarCantidadNucleos(),
            tipos[rand()%6]
        };

        PCs[i] = PC;
    }
    
    listarPcs(PCs,CANT_COMPUS);
    mostrarMasVieja(PCs,CANT_COMPUS);
    
    return 0;
}