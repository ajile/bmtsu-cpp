# Тема 23. Динамические структуры данных. Списки

С клавиатуры вводится символьная строка, содержащая последовательность вещественных чисел x<sub>1</sub>, x<sub>2</sub>, x<sub>3</sub>... x<sub>n</sub> (n>2) в символьном представлении. Написать программу, формирующую из этих чисел двунаправленный список, предварительно преобразовав числа в вещественную форму представления. Вычислить x<sub>1</sub> * x<sub>n</sub> ; x<sub>2</sub> * x<sub>n-1</sub> ; x<sub>3</sub> * x<sub>n-2</sub> ... x<sub>n</sub> * x<sub>1</sub> и составить из произведений новый список. Вывести на печать список чисел, а также соответствующие произведения, используя сформированный список произведений.

Указание. Использовать двусвязный список.


## Результат

```
# Input numbers (at least 2)
  9 8 7 6 5 4 3
# Iterating over the list
  Pointer I: 9	|	Pointer II: 3
  Pointer I: 8	|	Pointer II: 4
  Pointer I: 7	|	Pointer II: 5
  Pointer I: 6	|	Pointer II: 6
  Pointer I: 5	|	Pointer II: 7
  Pointer I: 4	|	Pointer II: 8
  Pointer I: 3	|	Pointer II: 9
# The result of the multiplications:
  27
  32
  35
  36
  35
  32
  27
```

# Schema

![](sources/schema.png)
