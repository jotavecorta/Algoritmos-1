### 2.4 Sobre la estructura de ``jugadas``:

En nuestra implementación actual, la complejidad de ``jugarPlus`` es $O(|t|\cdot|t|\cdot|j|)$,
mientras que la de ``sugerirAutomatico121`` es $O(|t|\cdot|t|\cdot|j|)$, donde $|t|$ y $|j|$
representan el largo del vector de jugadas ``j`` y uno de los lados del tablero ``t``,
respectivamente. En el caso de ``jugarPlus`` esto se debe a que posee una llamada recursiva, 
que le permite en el peor de los casos recorrer todo el tablero y además una búsqueda lineal 
en jugadas que es O(|j|) por cada posición de la misma. En cambio ``sugerirAutomatico121`` 
recorre todo el tablero con dos loops, y para cada posición también hace una búsqueda lineal
en el vector de jugadas ``j`` (recordemos que j no posee ningún orden particular). 

Pasar a una implementación donde ``j`` es una matriz cuyos puntos corresponden a una
posición del tablero (en una relación 1 a 1), y contienen el número de minas adyacentes
a dicha posición, simplificaría las búsquedas sobre ``j``. Para saber si una posición ``(p, q)`` 
se jugó, simplemente se accede a ``j[p][q]`` y se comprueba si es distinto de -1. 
Esta operación se realiza en tiempo constante, i.e. es de complejidad O(1), por lo que ambos
``jugarPlus`` y ``sugerirAutomatico121`` tendrían una mejora en la performance. No hay una mejora
en la complejidad del algoritmo porque ambos siguen dependiendo de una búsqueda lineal sobre
el vector de banderitas que, al igual que jugadas, en el peor de los casos $|b|$ es $|t|²$.
Si hicieramos lo mismo con banderitas que con jugadas ahí si podríamos hablar de una mejora 
en la complejidad de $O(|t|\cdot|t|\cdot|j|)$ a $O(|t|\cdot|t|\cdot 1) = O(|t|\cdot|t|)$.


