/* baldosasDelPiso: toma tres enteros, M y N -largo y ancho- del
 * piso y B -lado de las baldosas- y retorna la cantidad de baldosas
 * necesarias para cubrir el piso. Se cuentan los trozos de baldosas
 * necesarias como una baldosa entera.*/
int baldosasDelPiso(int M, int N, int B) {

    int baldosas_largo = M / B;
    int baldosas_ancho = N / B;

    if (M % B != 0){
        baldosas_largo += 1;
    }
    if (N % B != 0){
        baldosas_ancho += 1;
    }

    return baldosas_ancho * baldosas_largo;
}
