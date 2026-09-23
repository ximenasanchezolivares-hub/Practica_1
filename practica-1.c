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
void calcularSumaReferencia(int *resultado, int incorrecto, int inexistente) {
    *resultado = incorrecto + inexistente;
}

int main() {
    int i;
    int ctr_incorrecto;
    int usr_inexistente;
    int acs_correcto;
    int acs_bloqueado;
    int suma_intentos;
    int x=UMBRAL_X;
    
    int equipos[TOTAL_EVENTOS] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
    int eventos_tipos[TOTAL_EVENTOS]   = {0, 1, 1, 0, 1, 2, 1, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 2, 1, 0};
    const char *nombres_equipos[NUM_EQUIPOS] = {"PC-01", "PC-02", "PC-03", "PC-04"};
    int matriz_equipos[NUM_EQUIPOS][TIPOS_EVENTOS] = {0};  
    

for (i = 0; i < TOTAL_EVENTOS; i++) {
        int eq = equipos[i];   
        int tipo = eventos_tipos[i]; 

        if (validarTipoEvento(tipo) == 1) {
            matriz_equipos[eq][tipo]++;
        }

    }
    printf("--- LOG DE EVENTOS REGISTRADOS ---\n");
    for (i = 0; i < TOTAL_EVENTOS; i++) {
        printf("Evento %d -> Equipo: %s, Tipo de Evento: %d\n", i + 1, nombres_equipos[equipos[i]], eventos_tipos[i]);
    }
    printf("\n");

    printf("--- REPORTE FINAL Y ANALISIS ---\n");
    for(i=0;i<NUM_EQUIPOS;i++){
        int *apt_fila=*(matriz_equipos+i);

        acs_correcto=*(apt_fila+0);
        ctr_incorrecto=*(apt_fila+1);
        usr_inexistente=*(apt_fila+2);
        acs_bloqueado=*(apt_fila+3);
        calcularSumaReferencia(&suma_intentos, ctr_incorrecto, usr_inexistente);

        printf("Equipo: %s |(0) -- %d |(1) -- %d |(2) -- %d |(3) -- %d |Intentos fallidos -- %d ", nombres_equipos[i], acs_correcto, ctr_incorrecto, usr_inexistente, acs_bloqueado, suma_intentos);
        if(suma_intentos>x){
            printf("SOSPECHOSO \n ");
        }else{
            printf("NORMAL \n ");
        }

    } 

    return 0;
    }