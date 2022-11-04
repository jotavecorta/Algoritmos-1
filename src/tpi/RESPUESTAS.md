% Contesten aquí la pregunta sobre complejidad
### 2.4 Sobre la estructura de ``jugadas``:

En el caso de nuestra implementación, que inicializa ``jugadas`` y ``banderitas``, 
y luego las modifica de manera estática, la complejidad de los procedimientos
``jugarPlus`` y ``sugerirAutomatico121`` no se verían afectadas por pasar de un 
vector de longitud $n**2$ a una matriz de $nxn$, i.e. las complejidades seguirían 
siendo O(n**2).

En el caso de una implementación que modifique dinámicamente a los vectores
de ``jugadas`` y ``banderitas``, se pasaría de complejidades más altas
-n**2*log n o n**3-, por tener dos ciclos más las búsquedas en j, a n**2.

