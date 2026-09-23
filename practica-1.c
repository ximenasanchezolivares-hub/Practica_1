#include <stdio.h>

#define NUM_EQUIPOS 4
#define TIPOS_EVENTOS 4  /* (0) Acceso correcto, (1) Contraseña incorrecta, (2) Usuario inexistente, (3) Acceso bloqueado*/
#define TOTAL_EVENTOS 20
#define UMBRAL_X 3

int validarTipoEvento(int tipo) {
    if (tipo >= 0 && tipo <= 3) {
        return 1; // Válido
    }
    return 0; // Inválido
}

int main() {
    int i;
    int ctr_incorrecto;
    int usr_inexistente;
    int suma_intentos;
    int x=UMBRAL_X;
    
    int eventos_equipos[TOTAL_EVENTOS] = {0, 1, 2, 0, 1, 2, 1, 2, 2, 2, 1, 0, 2, 1, 2, 0, 1, 2, 1, 0};
    int eventos_tipos[TOTAL_EVENTOS]   = {0, 1, 1, 0, 1, 2, 1, 1, 2, 1, 0, 2, 1, 1, 2, 0, 1, 2, 1, 0};
    int matriz_equipos[NUM_EQUIPOS][TIPOS_EVENTOS] = {0};  

for (i = 0; i < TOTAL_EVENTOS; i++) {
        int eq = eventos_equipos[i];   
        int tipo = eventos_tipos[i]; 

        if (validarTipoEvento(tipo) == 1) {
            matriz_equipos[eq][tipo]++;
        }
    }

    for(i=0;i<NUM_EQUIPOS;i++){
        int *apt_fila=*(matriz_equipos+i);

        ctr_incorrecto=*(apt_fila+1);
        usr_inexistente=*(apt_fila+2);

         suma_intentos=ctr_incorrecto+usr_inexistente;
        
       // printf("%d\n",suma_intentos);

        if(suma_intentos>x){
            printf("  %d %d %d sospechose \n ",ctr_incorrecto,usr_inexistente,suma_intentos);
        }else{
            printf(" %d %d %d normal \n ",ctr_incorrecto,usr_inexistente,suma_intentos);
        }

    } 

    return 0;
    }