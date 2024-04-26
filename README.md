# treap-data-structure

## Introudcción:

<p>Para comenzar tengamos en cuenta la estructura de un arbol binario (BST):</p>

<div style="text-align: center; color: orange">
  <pre>
  <img src="images-readme/BST.png" alt="BST" />
  <br/>
  En donde: BST(Vacio) = True
  BST(T) => x &isin; L : x < elemento
            x &isin; R : x > elemento
  En donde el BST se ve entre la union  de L ^ R.
  </pre>
</div>

<p>Sin embargo si deseamos implementar un <b>treap</b> Debemos entender la estructura de un heap:</p>

<div style="text-align: center; color: orange">
  <pre>
  <img src="images-readme/heap.png" alt="Heap" />
  <br/>
  En donde: heap(Vacio) = True
  heap(T) => p < s ^ p < t
  En donde el heap se ve entre la union  de L ^ R.
  </pre>
</div>

<p>Teniendo eso en cuenta imaginemos el siguiente heap:</p>
<div style="text-align: center;">
  <img src="images-readme/H.png" alt="BST" />
</div>

<p>Sin embargo debemos a su vez mirar si éste heap es un <b> heap min </b> o es éste un <b> heap max </b> dependiendo de si su padre es mayor(heap min) o menor(heap max) que sus hijos:</p>

<div style="text-align: center;">
  <img src="images-readme/Padre-HIjo.png" alt="BST" />
</div>
<div style="text-align: center;">
  <img src="images-readme/Insercion.png" alt="BST" />
</div>

## máxima cantidad de elementos y altura máxima de un heap

<div style="font-size: 18px;">

**Altura** = log₂(N + 1)

**Máxima cantidad de elementos** = 2ⁿ - 1

</div>

## Balanceo de los heap

<div style="text-align: center;">
  <img src="images-readme/H1.png" alt="BST" />
</div>


## Reglas para un treap: X

1. inserto x  siguiendo la propiedad del bst

2. Genero un numero aleatorio en una distribucion probabilistica
      uniforme.

3. Revisamos que la propiedad del HEAP se cumpla y de lo contrario realizamos las rotaciones necesarias.

<pre style="color: orange">
Si la probalidad es uniforme entonces las rotaciones seran balanceadas y por consecuente el treap sera balanceado
</pre>

## Búsqueda

<div style="font-size: 18px;">

 **Complejidad de búsqueda** = O(ln(X))

 </div>