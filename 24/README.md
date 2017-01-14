# Тема 24. Текстовая обработка

Дана последовательность строк. Каждая строка состоит из групп букв, цифр и знаков `+`,`-`,`*`. Группой букв называется группа, которой не предшествует и за которой не следует буква. Группой цифр называется группа, которой не предшествует и за которой не следует цифра. Группой знаков называется группа, которой не предшествует и за которой не следует знак. Написать программу, определяющую верно ли, что в каждой строке количество групп букв больше, чем групп знаков и, если это так, то осуществляющую замену каждой группы знаков на группу цифр «123». Вывести на печать исходную и скорректированную последовательности строк.


## Результат

```
# Origin sentencies:
  0. Do not worry about your +-+----+++--+ difficulties3123in mathematics *-+, I assure you that mine are greater.
    Letters: 15 groups
    Numbers: 1 groups
    Signs: 2 groups

  1. Mathematics is1222the tool+specially suited 32886 for dealing with abstract concepts of any kind
    Letters: 14 groups
    Numbers: 2 groups
    Signs: 1 groups

  2. *-+If*-++-you*-+ask*-+mathematicians*-+333what*-+they*-+do*-+
    Letters: 7 groups
    Numbers: 1 groups
    Signs: 8 groups


Letter group amount is greater than sign group amount. Iterating over all sentencies and replacing all sign groups to 123 in accondance with task.


# Resultee sentencies:
  0. Do not worry about your 123 difficulties3123in mathematics 123, I assure you that mine are greater.
  1. Mathematics is1222the tool123specially suited 32886 for dealing with abstract concepts of any kind
  2. 123If123you123ask123mathematicians123333what123they123do123
```
