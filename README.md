# Algorithmen UB4
Bei diesem Beispiel soll die Performance(CPU-Zeit) des Travelling Salesman Problems unter Anwendung von Enumeration und Nearest Neighbour verglichen werden.
**Enumeration** wurde mittels Permutation umgesetzt, ohne auf gleiche Wege Rücksicht zu nehmen, weswegen hierbei ein **Aufwand** von **O( (n-1)! )** entsteht.
Nearest Neighbour wählt jeden Durchgang einen zufälligen Startknoten und geht von diesem aus immer den kürzesten verfügbaren Weg zu einem noch nicht besuchten Knoten. Hierdurch entsteht ein **Aufwand** von **O( n^2 )**

## Zeit-/Performance-vergleich Enum vs. NN
in Millisekunden (außer anders angeschrieben)
|  |Enum|Neirest Neighbour|
|--|--|--|
|5|0.150714|0.112573|  
|10|98.1146|0.178761|
|11|768.732|0.124864|
|12|8452.54|0.135192|
|13|106185|0.130578|
|127|1.21 * 10 ^ 198 Jahre|1.80083|

## Abweichung des NN-Weges vom Optimum
|  |Enum|Neirest Neighbour|
|--|--|--|
|11|31.5952|32.0336|
|12|31.2884|31.875|

Eine geringe Abweichung vom Optimalweg ist ersichtlich. Dieser ist jedoch angesichts der deutlich höheren CPU Zeiten zu vernachlässigen. Diese minimale Abweichung ensteht durch die selbst erstellten Testfiles und könnte mit anders gewählten Wegen durchaus noch grösser ausfallen.
