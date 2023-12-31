---
marp: true
theme: gaia
footer: 'Программирование на языке C++. Гагаринов Даниил. ВШПИ МФТИ 2023'
paginate: true

---
<style>
{
    font-size: 30px
}
</style>

# Лекция 2

---

<!-- header: 1.2.6 Выражения и операторы-->

Еще есть операторы присваивания: =, +=, -=, \*=, /=, %=, &=, |=, ^=, <<=, >>=

При этом следующий код выведет 5, потому что оператор = присваивает и возвращает объект:

```c++
int main() {
  int x = 10;
  std::cout << x = 5;
}
```

**Note** Начиная с C++17 гарантируется что правая часть от оператора = вычисляется первой (++x = x++).

---

Операторы += и аналогичные: берут то что слева и изменяют его в соответствии с оператором. То есть x += 10 увеличивает x на 10.

**Note** Выражения x += 5 и x = x + 5 не эквивалентны. Во втором случае создается еще одна переменная.

---

### lvalue и rvalue

***Note*** Сейчас мы введем очень неформальное (и даже неправильное) определение

***Def*** lvalue это то, что может стоять слева от оператора присваивания, а rvalue то что не может:

x + 5 - rvalue (x + 5 = 10 это CE)
5 - rvalue (5 = 10 это CE)
x - lvalue (x = 10 это ок)
++x - lvalue (++x = 10 это ок)
x++ - rvalue (x++ = 10 это CE)

***Note*** "=" не всегда является оператором. Например в строчке int x = 5

---

### Тернарный оператор

Единственный оператор в языке, который принимает три аргумента. Синтаксис:

```c++
a ? b : c;
```

Пример:

```c++
x = (x < 2 ? 1 : 2);
```

---

### Остальные операторы

- Оператор запятая. Вычисляет левый аргумент, вычисляет правый аргумент, возвращает правый аргумент.

- Вызов функции (то есть оператор круглые скобки)

- sizeof - возвращает количество байт, которое занимает объект. При этом sizeof не вычисляет переданный ему expression.

---

### Приоритет вызова операторов

https://en.cppreference.com/w/cpp/language/operator_precedence

----

<!-- header: 1.2 Введение в язык-->

## 1.2.7 Управляющие конструкции

- if: ```if (bool-expr) statement;```

Но так не пишем, пишем так:

```c++
if (bool-expr) {
  statement;
} else { // Можно без else
  statement;
}
```

Начиная с C++17:

```c++
if (init-statement; bool-expr) {
  statement;
}
```

---

<!-- header: 1.2.7 Управляющие конструкции-->

- while

```c++
while (bool-expr) {
  statement;
}
```

- do while

```c++
do {
  statement;
} while (bool expr);
```

---

- for

```c++
for (init-statement; bool-expr; expr) {
  statement;
}

for (int i = 0; i < 10; ++i) {
  ...
}
```

Различные части можно пропускать:

```c++
int a = 10;
for (;a < 20;) {
  ...
}
```

---

- switch

```c++
switch (expr) {
  case value:
    ...
    break;
  case value2:
    ...
    break;
  default:
    ...
}
```

В качестве expr могут быть: "integral or enumerated type, or be of a class type in which the class has a single conversion function to an integral or enumerated type."

---

- break - прервать цикл
- continue - пропустить итерацию цикла
- return ...
- go to (забыть как страшный сон)

---

<!-- header: 1.2 Введение в язык-->

## 1.2.8 Ошибки (RE, CE, UB)

### CE (Compilation Error)

- лексические ошибки ```123bad456;```

- синтаксические ошибки ```int + 5;```

- семантические ошибки
    - undefined operation: 5.0 % 0.5;
    - ambiguous call
    - access error

---

<!-- header: 1.2.8 Ошибки (RE, CE, UB)-->

### RE (Runtime Error)

Некоторые примеры:

- Segmentation fault - обращение к "плохой" памяти
- Целочисленное деление на 0
- Исключение, которое не поймали

---

### UB (Undefined Behaviour)

Иногда в стандарте написано, что комплиятор ничего не гарантирует в данном случае. Примеры:

- Вечный цикл
- Обращение к элементу за границами массива
- Переполнение знакового типа

---

Веселый пример UB:

```c++
int main() {
  for (int i = 0; i < 300; ++i) {
    std::cout << i << ' ' << i * 12345678 << std::endl;
  }
}
```

При компиляции с -O2 получается вечный цикл.

Почему так?

---

```c++
int main() {
  for (int i = 0; i < 300; ++i) {
    std::cout << i << ' ' << i * 12345678 << std::endl;
  }
}
```

Ответ: компилятор уверен что i * 12345678 не превосходит max_int (иначе UB и компилятор все равно может делать что хочет). Тогда i не превосходит 173, а значит условие всегда true и его можно не проверять.

---

Бонус: unspecified behaviour:

```c++
int f() {
  std::cout << 1;
  return 1;
}

int g() {
  std::cout << 2;
  return 2;
}

int h() {
  std::cout << 4;
  return 3;
}

int main() {
  std::cout << f() * g() + h();
}
```

---

<!-- header: ""-->

# 2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов.

0. Функции. Базовый синтаксис
1. Указатели и виды памяти
2. Особые указатели
3. Операторы new/delete
4. Массивы и операции над ними
5. Функции и указатели на них
6. Ссылки и константы. Приведение типов.

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.0 Функции. Базовый синтаксис

Функция это блок кода, который выполняет какую-то операцию. Функция характеризуется следующими параметрами:

- тип возвращаемого значения
- название функции
- тип принимаемых аргументов и их названия
- тело функции

---

<!-- header: 2.0 Функции. Базовый синтаксис-->

Объявление функции выглядит так:

```c++
return_type function_name(ArgType1 arg1, ArgType2 arg2);
```


Например:

```c++
int foo(int a, double b);
```
---

Определение функции состоит из объявления и тела функции:

```c++
return_type function_name(ArgType1 arg1, ArgType2 arg2) {
  your_code;
}
```

---

При этом если у функции возвращаемое значение не void (специальный тип, который означает буквально "ничего"), то внутри функции должен быть return.

Внутри функции, которая возвращает void так же может быть return, но без аргументов. Это может быть использовано для досрочного выхода из функции:

```c++
void DevideAndPrint(int a, int b) {
  if (b == 0) {
    std::cout << "Devision by zero!";
    return;
  }

  std::cout << a / b;
}
```

---

К сожалению текущих знаний нам не хватит, чтобы реализовать функцию swap (меняет два объекта местами), потому что мы не умеем менять аргументы функции, то есть следующий код

```c++
void swap(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a = 0;
  int b = 1;
  swap(a, b);
  std::cout << a << b;
}
```

выведет 0 и 1, а хотелось бы 1 и 0.

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.1 Указатели и виды памяти

Основная концепция: мы хотим взаимодействовать с адресами наших переменных в памяти.

***Note*** На самом деле мы не взаимодействуем с реальными адресами в оперативной памяти, так как операционная система выделяет нам некую виртуальную память. Но в рамках данного курса этот факт не нужен :)

---

<!-- header: 2.1 Указатели и виды памяти -->

Переменные, очевидно, адресуются каким-то набором байт. Давайте выведем адрес переменной типа int:

```c++
int a = 10;
std::cout << &a;
```

***Def*** Оператор '&' это унарный оператор, который возвращает адрес объекта. Этот адрес имеет специальный тип (для типа T это T*). Этот тип называется "указатель*

***Note*** Оператор '&' можно применить только к невременным переменным. То есть взять адрес например литерала невозможно.

---

Указатель можно сохранить в отдельную переменную:

```c++
int a = 10;
int* ptr = &a;
```

Так как ptr это тоже переменная, то и она хранится где-то в памяти. Таким образом мы можем взять и ее адрес:

```c++
int a = 10;
int* ptr = &a;
int** ptr_to_ptr = &ptr;
```

---

По адресу переменной мы можем брать ее значение:

```c++
int a = 10;
int* ptr = &a;
int value = *ptr; // разыменование
std::cout << value;
```

***Def*** Оператор * это унарный оператор, который по адресу объекта возвращает его значение. Эта операция называется "разыменование"

---

Теперь можно апгрейднуть наш swap!

---

Теперь можно апгрейднуть наш swap!

```c++
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
```

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.2 Операции над указателями

К указателям применимы следующие операции:

* ++ и -- (инкремент и декремент). Сдвигает указатель на число байт равное размеру типа. То есть если был указатель T* ptr. то ++ptr сдвинет указатель на sizeof(T)
* +n и -n, где n это какое-то число (инкремент/декремент n раз)
* a - b, где a и b это указатели. Это количество "шагов" между указателями (где каждый шаг это sizeof(T))

---

## 2.3 Особые указатели

- void* - указатель "на что угодно". Нужен когда работает с "сырой" памятью и не знаем какого типа она на самом деле
- nullptr - нулевой указатель. В C был NULL (просто int равный 0), но в c++ мы будем пользоваться именно nullptr, так как он имеет нужный тип (указатель)

---
## 2.4 Виды памяти

![w:1000 h:500](/assets/images/memory_model.png)

---
<!-- header: "2.4 Виды памяти"-->

### Кратко:

* data (статическая память). В этой секции лежат статические и глобальные переменные, а так же некоторые константы
* text. В этом секции лежит машинный код
* stack (автоматическая память). Тут лежат локальные переменные и адреса возвратов

---

### Про стек:

1. Когда мы создаем какую-либо локальную переменную она кладется на стек. При выходе из области видимости эта переменная удалится со стека (снимется)

2. На стек кладется адрес возврата, когда мы заходим в какую-либо функцию (иначе непонятно куда возвращаться после return в функции)

3. Stack overflow (переполнение стека) - ситуация, когда пытаемся на стеке занять больше памяти чем есть (достаточно глубокая рекурсия)

---

### Статические переменные:

Такую переменную можно завести (не только) внутри функции:

```c++
int foo() {
  static int x = 0;
}
```

Тогда эта переменная будет храниться в секции data и будет одинаковой для всех вызовов функции

---

### Пример работы со статической переменной

```c++
void foo() {
  static int x = 0;
  x += 1;
  std::cout << x;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    foo();
  }
}
```

Что выведет?

---

### Пример работы со статической переменной

```c++
void foo() {
  static int x = 0;
  x += 1;
  std::cout << x;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    foo();
  }
}
```

Что выведет?

Ответ: числа от 1 до 10

---

Размер стэка обычно ограничен 4мя или 8ю мегабайтами памяти

***А как выделить побольше памяти? На куче!***

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.3 Операторы new/delete

***Def*** динамическая память - оперативная память из которой мы можем запрашивать кусочки. Эта память так же называется "куча".

Для работы с этой памятью нужны операторы new и delete.

---
<!-- header: "2.3 Операторы new/delete"-->

### Оператор new

Для выделения динамической памяти в плюсах служит оператор new. Его синтаксис: ```T* p = new T(...);```

Выделим памяти на один int:

```c++
int* a = new int;
```

Теперь у нас есть 4 байта на куче. Можно было сразу проинициализировать:

```c++
int* a = new int(10);
```

---

### Оператор delete

Память, выделнную с помощью оператора new нужно "очищать". Для этого нужен оператор delete:

```c++
int* a = new int(10);
delete a;
```

***Note*** после завершения программы вся память и так очистится, но вы много раз будете сталкиваться с ситуацией, когда память нужно очищать прямо во время работы программы

---

### Memory leak

***Note*** Если память не очистить, то произойдет так называемая "утечка памяти" (memory leak)

Пример явной утечки памяти:

```c++
int* a = new int(10);
a = new int(11);
delete a;
```

---

#### Double free

Дважды очищать память нельзя, то есть такой код приведет к ошибке:

```c++
int* a = new int(10);
delete a;
delete a;
```

***Note*** после первого вызова delete эта память уже "не наша", а очищать память которой мы не владеем нельзя

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.4 Массивы и операции над ними

Для выделения массива служит другая версия оператора new: new int[]. Выделим массив на 10 int:

```c++
int* ptr = new int[10];
```

***Note*** При этом sizeof(ptr) равен 8ми (или 4м) байтам

Указатель ptr указывает на первый int в нашем массиве из 10ти интов и мы можем удобно работать с этой памятью:

```c++
int* ptr = new int[10];
for (int i = 0; i < 10; ++i) {
  ptr[i] = i + 1;
}
```

---

<!-- header: "2.4 Массивы и операции над ними"-->

## Очистка массивов

Для очистки массивов существует специальная версия delete:

```c++
int* ptr = new int[10];
delete[] ptr;
```

***Note*** Очищать память с помощью delete[] которая была выделена не с помощью new[] нельзя. Очищать память с помощью delete которая была выделена с помощью new[] тоже нельзя.

---

## "Сишные" массивы

Это массивы выделенные на стеке: ```int arr[10];```

Такие массивы нельзя друг другу присваивать, то есть такой код приведет к CE:

```c++
int arr1[10];
int arr2[10];
arr1 = arr2; // тут CE
```

***Note*** sizeof такого массива будет равен реальному размеру, то есть такой код выведет 10:

```c++
int arr1[10];
std::cout << sizeof(arr1);
```

---

<!-- header: "2. Модификаторы типов. Указатели. Функции. Ссылки и константы. Приведение типов."-->

## 2.5 Функции и указатели на них

1. Аргументы по умолчанию
2. Перегрузка функций
3. Указатель на функцию
4. Функции с переменным числом аргументов
5. inline функции

---

<!-- header: "2.5 Функции и указатели на них"-->

## 2.5.1 Аргументы по умолчанию

```c++
int PlusWithLogging(int a, int b, bool logging = false) {
  if (logging) {
    std::cout << "Plus";
  }
  return a + b;
}

int main() {
  PlusWithLogging(1, 2);
  PlusWithLogging(1, 2, false);
  PlusWithLogging(1, 2, true);
}
```

***Note*** Cначала аргументы без значений по умолчанию, а потом все аргументы со значениями по умолчанию (перемешивать нельзя).

---

Аргументы по умолчанию можно указать один раз, потому что это считается их определением. То есть следующий код даст CE:

```c++
void foo(int b = 10);

void foo(int b = 10) {
  return;
}
```

---

## 2.5.2 Перегрузка функций

* Хотим написать функцию print, которая принимает аргумент и выводит его в поток
* Проблема: хочется чтобы эта функция всегда называлась print, вне зависимости от типов переданных аргументов

Для этого существует механизм перегрузки функций

---
```c++
void foo(double) { std::cout << 1; }
void foo(int) { std::cout << 2; }

int main() {
  foo(10); // выведет 2
  foo(5.0); // выведет 1
}
```

Перегружать функции можно только по принимаем аргументам, формально: наличие двух и более функций которые отличаются только возвращаемым значением не считается перегрузкой и приводит к CE.

При этом в перегрузках можно менять возвращаемое значение:

```c++
double plus(double, double);
double plus(int, int);
```

---

## Выбор перегрузки

Полный список правил [тут](https://en.cppreference.com/w/cpp/language/overload_resolution). Кратко:

* Точное совпадение всегда побеждает
* Если точного совпадения нет, то выигрывает promotion (integer и float)
* Если нет promotion то дальше идет Conversion

Если нельзя выбрать между несколькими (они равнозначны), то CE:

```c++
void foo(float) {}
void foo(int) {}
int main() { foo(5.0); // CE call to foo is ambiguous }
```
***Note*** double->float и double->int это стандартные преобразования равнозначные с точки зрения компилятора

---

## 2.5.3 Указатель на функцию

Иногда нам хочется передать функцию внутрь другой функции. Пример: сортировка с кастомным компаратором.

Синтаксис: ```return_type(*name)(arg1, arg2) = &f;``` (можно без &). Пример:

```c++
int foo(int a, bool c) {return 10;}
int foo2(int, bool) { return 20;}

int main() {
  int(*ptr)(int, bool) = &f; // завели
  ptr(10, true); // вызвали
  ptr = &foo2; // переприсвоили (потому что совпадают сигнатуры)
}
```

---

## 2.5.4 Функции с переменным числом аргументов

***Note*** Этот пункт здесь просто для ознакомления. В экзамен/зачет/задачи он не войдет.

```c++
#include <cstdarg>
int add_nums(int count...) {
    int result = 0;
    std::va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}
```

---

## 2.5.5 inline функции

```c++
inline void foo(int) {return; }
```

***Def*** inline это подсказка компилятору что можно встроить код функции в момент вызова. Компилятор может это проигнорировать

***Note*** В inline в данном контексте смысла почти нет, потому что современные компиляторы и так достаточно умны, чтобы заинлайнить вашу функцию без вашей подсказки :)

---

Спасибо за внимание!

![img](https://cataas.com/cat/gif)
