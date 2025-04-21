#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{ 
    int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
}compu; 

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

int generarVelocidad (){
    return 1 + rand() % 3;
}

int generarYear (){
    return 2015 + rand() % 2024;
}

int generarCantidadNucleos (){
    return 1 + rand() % 8;
}

int main (){
    srand(time(NULL));
    compu PC = {
        generarVelocidad(),
        generarYear(),
        generarCantidadNucleos(),
        tipos[rand()%6]
    }; 
    
    return 0;
}