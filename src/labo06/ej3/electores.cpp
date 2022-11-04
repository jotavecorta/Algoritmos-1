#include "electores.h"

int validarVotante(int a, int m, int d) {
    // Inicializo la edad del votante al día de la eleccion
    int edadVotante = edadVotanteAlDiaVotacion(a, m, d);

    // Asigno etiquetas según el caso
    if (edadVotante < 16){
        return NO_VOTA;
    }else if (edadVotante < 18){
        return OPCIONAL_MENOR;
    }else if (edadVotante < 70){
        return OBLIGATORIO;
    }else{
        return OPCIONAL_MAYOR;
    }
}

int edadVotanteAlDiaVotacion(int a, int m, int d){
    // Defino la fecha de eleccion
    int anio_eleccion = 2022;
    int mes_eleccion = 10;
    int dia_eleccion = 22;

    // Valido la fecha ingresada
    if (validarFecha(a, m, d)){
        // Calculo la edad del votante
        int edad = anio_eleccion - a;
        bool guarda = m > mes_eleccion || (m == mes_eleccion && d > dia_eleccion);

        if (guarda){
            edad -= 1;
        }

        return edad;

    }else{
        return -1;
    }
}

bool validarFecha(int a, int m, int d){
    bool validez_anio = a >= 1900 && a < 2022;
    bool validez_mes = m > 0 && m <= 12;
    bool validez_dia = d > 0 && d <= 31;
    bool validez_fecha = validez_anio && validez_mes && validez_dia;

    if (validez_fecha){
        return true;
    }else{
        return false;
    }
}


