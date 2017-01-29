# Тема 28. Программирование с использованием классов в С++. Наследование и композиция

Разработать и реализовать диаграмму классов для описанных объектов предметной области, используя механизмы наследования и композиции. Проверить ее на тестовом примере, с демонстрацией всех возможностей разработанных классов на конкретных данных.

**Даны:**

Объект запись, состоящий из полей: целое число и вещественное число. Объект умеет выводить на печать содержимое своих полей, возвращать содержимое своих полей по запросу.

Объект «массив записей» переменной длины, которая определяется на этапе инициализации объекта. Объект состоит из числового поля, содержащего размер массива, и собственно массива записей. Объект умеет выводить на печать содержимое своих полей, возвращать по запросу реальный размер массива, упорядочивать массив записей по значению числового поля записи, определять максимальное четное значение целого числового поля элемента-записи.


## Результат

```
# The object has 10 elements
# info from RecordArray
## Records: 
   Record 0. # info from Record: integer:8; real:0
   Record 1. # info from Record: integer:9; real:0.5
   Record 2. # info from Record: integer:1; real:1
   Record 3. # info from Record: integer:-7; real:1.5
   Record 4. # info from Record: integer:-9; real:2
   Record 5. # info from Record: integer:-2; real:2.5
   Record 6. # info from Record: integer:6; real:3
   Record 7. # info from Record: integer:9; real:3.5
   Record 8. # info from Record: integer:4; real:4
   Record 9. # info from Record: integer:-5; real:4.5
# A max odd integer element: 8

# Sorting elements in the array

# info from RecordArray
## Records: 
   Record 0. # info from Record: integer:9; real:0.5
   Record 1. # info from Record: integer:9; real:3.5
   Record 2. # info from Record: integer:8; real:0
   Record 3. # info from Record: integer:6; real:3
   Record 4. # info from Record: integer:4; real:4
   Record 5. # info from Record: integer:1; real:1
   Record 6. # info from Record: integer:-2; real:2.5
   Record 7. # info from Record: integer:-5; real:4.5
   Record 8. # info from Record: integer:-7; real:1.5
   Record 9. # info from Record: integer:-9; real:2
```

# Scheme

![](sources/scheme.png)
