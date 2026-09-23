#include <stdio.h>

#define NUM_EQUIPOS 4
#define TIPOS_EVENTOS 4  /* (0) Acceso correcto, (1) Contraseña incorrecta, (2) Usuario inexistente, (3) Acceso bloqueado*/


int main() {
    int i;
    int ctr_incorrecto;
    int usr_inexistente;
    int suma_intentos;
    
    int matriz_equipos[NUM_EQUIPOS][TIPOS_EVENTOS]={
            {8,1,0,0},
            {1,6,2,1},
            {5,0,1,0},
            {0,2,5,1}

    };
       
    for(i=0;i<NUM_EQUIPOS;i++){
        int *apt_fila=*(matriz_equipos+i);
        ctr_incorrecto=*(apt_fila+1);
        usr_inexistente=*(apt_fila+2);

        suma_intentos=ctr_incorrecto+usr_inexistente;
        printf("%d\n",suma_intentos);
    } 

    return 0;
    }