# Тема 21. Работа с массивами С++. Адресная арифметика.

В матрице `А(4,4)`, содержащей вещественные элементы, в каждом столбце поменять местами максимальный элемент с диагональным. Распечатать:

а) исходную и преобразованную матрицы;

б) адреса и значения тех элементов, которые оказались максимальными;


## Результат

```
The origin matrix:
32 12 65 23 
61 31 94 71 
45 37 82 67 
54 86 63 10 

Column 0. The biggest value is 61, found on 1 place.
It should be swapped with diagonal element on 3 place.

Column 1. The biggest value is 86, found on 3 place.
It should be swapped with diagonal element on 2 place.

Column 2. The biggest value is 94, found on 1 place.
It should be swapped with diagonal element on 1 place.

Column 3. The biggest value is 71, found on 1 place.
It should be swapped with diagonal element on 0 place.


The result matrix:
32 12 65 71 
54 31 94 23 
45 86 82 67 
61 37 63 10 
```

# Scheme

![](sources/scheme.png)
