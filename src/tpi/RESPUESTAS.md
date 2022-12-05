### 2.4 Sobre la estructura de ``jugadas``:

En nuestra implementación actual, la complejidad de ``jugarPlus`` es $O(|t|\cdot|t|\cdot|j|)$,
al igual que la de ``sugerirAutomatico121``, donde $|j|$ y $|t|$
representan el largo del vector de jugadas ``j`` y el largo de uno de los lados del tablero ``t``,
respectivamente. En el caso de ``jugarPlus`` esto se debe a que posee una llamada recursiva, 
que le permite en el peor de los casos recorrer todo el tablero y además una búsqueda lineal 
en jugadas que es $O(|j|)$, y una comprobación en banderitas, por cada posición de la misma. 
En cambio ``sugerirAutomatico121`` recorre todo el tablero con dos loops, y para cada posición también 
hace una búsqueda lineal en el vector de jugadas ``j`` (recordemos que j no posee ningún orden particular)
y una comprobación en banderitas. Vale aclarar que la comprobación en banderitas resulta en un término
aditivo de orden $|t|^2$ cuando se calcula la complejidad, por lo que no modifica la misma:
$O(|t|^2 \cdot \left(|j| + |b|\right)) = O(|t|^2 \cdot 2 |t|^2) = O(|t|^4)$.

Pasar a una implementación donde ``j`` es una matriz cuyos puntos corresponden a una
posición del tablero (en una relación 1 a 1), y contienen el número de minas adyacentes
a dicha posición, simplificaría las búsquedas sobre ``j``. Para saber si una posición ``(p, q)`` 
se jugó, simplemente se accede a ``j[p][q]`` y se comprueba si es distinto de $-1$. 
Esta operación se realiza en tiempo constante, i.e. es de complejidad $O(1)$, por lo que ambos
``jugarPlus`` y ``sugerirAutomatico121`` tendrían una mejora en su performance. Sin embargo, 
no hay una mejora en la complejidad del algoritmo porque ambos siguen dependiendo de una búsqueda 
lineal sobre el vector de banderitas que, al igual que jugadas, en el peor de los casos $|b|$ es $|t|^2$:
$O(|t|^2 \cdot |b|) = O(|t|^2 \cdot |t|^2) = O(|t|^4)$.
Si hicieramos con banderitas lo mismo que con jugadas, ahí si podríamos hablar de una mejora 
en la complejidad:
$O(|t|^2 \cdot \left(|j| + |b|\right)) = O(|t|^2 \cdot 2 \cdot 1) = O(|t|^2)$.


