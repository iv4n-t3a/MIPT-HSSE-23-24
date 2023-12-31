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

# Лекция 1.

## Введение

---

# 1. Введение

1. Организационные вопросы
2. Введение в язык

---
<!-- header: 1. Введение -->

# 1.1 Организационные вопросы

1. Контакты
2. Содержание курса
3. Отчетность
4. Домашние задания
5. Скат
6. Полезные ссылки и литература
7. Codestyle

---

<!-- header: 1. Организационные вопросы -->

# 1.1.1 Контакты

Лектор - Даниил Гагаринов, t.me/yaishenka

---

# 1.1.2 Содержание курса

Курс на два семестра.

- [Программа прошлого года](https://gitlab.com/yaishenka/cpp_course/-/blob/2022_2023/program/program_in_dev.md?ref_type=heads)
- На лекциях все про C++
- На семинарах первого семестра - хард скиллы
- На семинарах второго семестра - C++

---

# 1.1.3 Отчетность

В конце первого семестра - зачет по темам семинаров + ДЗ.

В конце второго семестра - годовой экзамен по материалам лекций + ДЗ.

---

# 1.1.4 Домашние задания

В течение семестра будет несколько задач. Большинство из этих задач будет с ревью (проверка кода семинаристом/ассистентом).

Про систему сдачи домашних заданий будет отдельное объявление.

Количество решенных задач будет влиять на итоговую оценку

---

# 1.1.5 Скат

0. Катать плохо
1. 1 скатанная задача = - ее стоимость к общему количеству баллов (обоим попавшимся).
2. 2 скатанные задачи = пересдача

---

# 1.1.6 Полезные ссылки и литература

- [cppreference](https://en.cppreference.com/w/)
- [stackoverflow](https://stackoverflow.com)
- [google](https://google.com)
- [google c++ codestyle](https://google.github.io/styleguide/cppguide.html)
- Книга Язык программирования C++, Бьёрн Страуструп
- Книга Effective C++, Скотт Мэйерс

---

# 1.1.7 Codestyle

В рамках курса мы будем соблюдать Google C++ Style Guide, который можно найти по [следующей ссылке](https://google.github.io/styleguide/cppguide.html).

Подробней про пункты кодстайла будет рассказано на семинарах.

---

<!-- header: ""-->

# 1.2 Введение в язык

1. Общая информация про язык
2. Hello World
3. Основные типы и операции над ними
4. Объявления VS определения
5. Области видимости
6. Выражения и операторы
7. Управляющие конструкции
8. Ошибки (RE, CE, UB)

---

<!-- header: 1.2 Введение в язык-->

# 1.2.1 Общая информация про язык

https://ru.wikipedia.org/wiki/C%2B%2B

---

<!-- header: 1.2.1 Общая информация про язык -->

Основное:
- Создан Бьерном Страуструпом на основе C
- Компилируемый
- Быстрый
- Широко применяемый
- Описан стандартом
- Легко выстрелить себе в ногу

---

На плюсах написаны:

- Существенная часть Yandex: поиск, почта, такси, беспилотники...
- Существенная часть Google
- Telegram
- Dota, Wow

---

Сферы применения:

0. Легаси
1. Высоконагруженные части приложений (веб и не только)
2. Trading (HFT)
3. ML (внутрянка)

---

<!-- header: 1.2 Введение в язык-->

# 1.2.2 Hello world

1. Функция main как точка входа в программу
2. Подключение заголовочных файлов
3. Работа с потоком вывода
4. Компиляция и запуск программы
5. Переменные
6. Работа с потоком ввода

---

<!-- header: 1.2.2 Hello world-->

```c++
#include <iostream>

int main() {
    std::cout << "Hello World!";
}
```
---

## 1. Функция main как точка входа в программу

С первой строчки функции main начинается выполнение кода.

main возвращает int - число, которое показывает с каким статусом завершилась программа.

По умолчанию возвращается 0 (но можно явно написать return 0).

---

## 2. Подключение заголовочных файлов

Чтобы подключить дополнительный функционал нужно написать директиву #include

***Def*** Директивы в исходном файле сообщают препроцессору о выполнении определенных действий

В данном случае мы подключаем библиотеку iostream. В ней содержится функционал для работы с потоками ввода/вывода.

---

## 3. Работа с потокам вывода

Для того чтобы что-то вывести в консоль нужно написать следующий код:

```c++
std::cout << "again and" << " again";
```

cout - объект созданный заранее. Он предоставляет интерфейс для записи чего-то в поток вывода вашей программы. Далее идет оператор << и после него то, что мы хотим вывести.

---

## 4. Компиляция и запуск программы

Компилятор - g++/clang/etc
    g++ main.cpp -o main

Запуск
    ./main

Чтобы указать стандарт
    g++ -std=c++20 main.cpp -o main

---

## 5. Переменные

Чтобы ***объявить*** переменную нужно сначала написать ее тип а затем имя:

```c++
int a;
```

Переменную можно сразу ***определить***:

```c++
int a = 0;
```

Можно определить с помощью предыдущей переменной:

```c++
int c = a;
```

***Note*** Изначально при объявлении базового типа туда кладется "мусор"

---

Над переменными можно совершать разные арифметические (и не только) действия:

```c++
int a = 10;
int b = 20;
int c = a + b + (b / 2);
```

Переменные можно выводить в поток

```c++
std::cout << a + b;
```

---

## 6. Работа с потоком ввода

За поток ввода отвечает cin. Используется так:

```c++
#include <iostream>

int main() {
    int age = 0;
    std::cout << "Type your age: \n";
    std::cin >> age;
    std::cout << "Your age is " << age;
}
```

---
<!-- header: 1.2 Введение в язык-->

# 1.2.3 Основные типы и операции над ними

1. Понятия статической и динамической типизации
2. Основные типы
3. Операции над этими типами
4. Литералы VS идентификаторы
5. Vector

---

<!-- header: 1.2.3 Основные типы и операции над ними-->

## 1. Понятия статической и динамической типизации

***Def*** Статическая типизация: переменная, параметр подпрограммы, возвращаемое значение функции связывается с типом в момент объявления и тип не может быть изменён позже (переменная или параметр будут принимать, а функция — возвращать значения только этого типа).

***Def*** Динамическая типизация: переменная связывается с типом в момент присваивания значения, а не в момент объявления переменной. Таким образом, в различных участках программы одна и та же переменная может принимать значения разных типов.

---

Сильная и слабая типизация: https://ru.wikipedia.org/wiki/Сильная_и_слабая_типизация

Кратко: при слабой типизации тип можно например привести один к другому. При сильной нет.

---

## 2. Основные типы

Опираться будем на [эту статью](https://en.cppreference.com/w/cpp/language/types)

- целочисленные типы (int, long, long long, short) и беззнаковые версии
- size_t
- типы с фиксированным размером (int32_t, int64_t и тд) и их беззнаковые версии
- bool и char
- float, double и long double

---

Числа с плавающей точкой устроены следующем образом:

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/IEEE_754_Double_Floating_Point_Format.svg/1236px-IEEE_754_Double_Floating_Point_Format.svg.png)

Подробней почитать можно [на вики](https://en.wikipedia.org/wiki/Double-precision_floating-point_format)

---

## 3. Операции над этими типами

- арифметические операции (+, -, \*, /, %)
- побитовые операции (&, |, ^, <<, >>)
- логические операции (&&, ||)

***Note*** C++ поддерживает запись чисел в 8ми и 16ти ричных системах счисления (префиксы 0 и 0x)

```c++
int a = 012; // 1*2 + 8 * 1 = 10
int b = 0x12; // 1 * 2 + 16 * 1 = 18
```

---

Стоит упомянуть про переполнение. Это ситуация, когда мы пытаемся присвоить типу больше, чем он может в себя вместить. В таком случае действует следующее правило:

1. Беззнаковые вычисления выполняются по модулю 2^n
2. Знаковое переполнение ведет к UB (об этом попозже)

---

Некоторые типы C++ умеет приводить друг к другу. Перечислим некоторые ситуации:

- Integer promotion - "повышение" целого типа. То есть int -> long long например. Просто увеличиваем число байт. Но есть проблема при переходе signed -> unsigned. В этом случае биты знакового типа начинают интерпретироваться как биты беззнакового (подумайте почему это боль)
- От большего инта к меньшему тоже можно. Тогда лишние байты просто отрезаются
- Floating promotion (аналогично интам)
- Различные неявные конверсии

Более подробно про все приведения базовых типов можно почитать [тут](https://docs.microsoft.com/en-us/cpp/cpp/standard-conversions?view=msvc-170)

---

## 4. Литералы VS идентификаторы

Примеры литералов:

- 5 (int)
- 5.0 (double)
- 5.0f (float)
- 'a' (char)
- "aaa" (const char*)
- true (bool) (при это является ключевым словом)

---

Идентификаторы:
- x
- CoOlFuNcTiOnNaMe
- 😀 (эмоджи поддерживаются далеко не всеми компиляторами, кланг не поддерживает)

---

## 5. Vector

```c++
#include <vector>

int main() {
  std::vector<int> v; // создание вектора, который хранит int'ы
  v.push_back(1); // запихиваем в конец вектора 1
  std::cout << v[0]; // смотрим что лежит на первой позиции в векторе
  std::cout << v.size(); // смотрим на размер вектора
  v.pop_back(); // выкидываем из вектора элемент крайний слева
}
```

Коротко: последовательный контейнер который поддерживает вставку в конец и обращение по индексу (массив).

---

<!-- header: 1.2 Введение в язык-->

## 1.2.4 Объявления VS определения

Код на C++ состоит из строчек, разделенных ; (на самом деле не совсем)

Эти строчки это инструкции (statements).

Statements можно разделить условно на три типа:

1. Declarations (объявления)
2. Expressions (выражения)
3. Control statements (управляющие конструкции)

---

<!-- header: 1.2.4 Объявления VS определения-->

***Def*** Объявление = введение какой-то новой сущности.

Объявление переменной:

```c++
int a;
```

А можно объявить и присвоить значение:

```c++
int a = 10;
```

При этом переменная объявленная вне функций (и классов) называется глобальной (в противном случае локальной).

---
Про определения:

***Note*** Для переменных объявление почти всегда является и определением.

Разницу определения и объявления можно понять на примере функции (про них мы будем говорить позже)

```c++
double f(int a);

int main() {
  f(1);
}
```

Такой код не скомпилируется, потому что мы объявили функцию f но не определили ее.

**Note** Каждое определение является объявлением

---

Существует правило одного определения (One definition rule). То есть каждая сущность должна быть один раз определена. Объявлять при этом можно любое количество раз.

---
<!-- header: 1.2 Введение в язык-->

## 1.2.5 Области видимости

```c++
int x = 10;

int main() {
  int x = 5;
}
```

Код работает, так как x внутри main в другой области видимости

---
<!-- header: 1.2.5 Области видимости-->

Можно создать новую область видимости:

```c++
int x = 10;

int main() {
  int x = 5;
  {
    int x = 3;
  }
}
```

---

Можно обратиться к глобальной области видимости:

```c++
int x = 10;

int main() {
  int x = 5;
  {
    int x = 3;

    std::cout << ::x; // вот тут
  }
}
```

Код выведет 10

---

```c++
int main() {
  int x = 5;
  {
    int x = 3;

    std::cout << ::x; // вот тут
  }
}
```

Не скомпилируется!

----

В C++ существует механизм разграничения областей видимости: namespaces

```c++
namespace N {
  int x = 10;
}

int main() {
  std::cout << N::x;
}
```

***Note*** std это тоже namespace

namespace'ы можно открывать только вне функций и классов/структур. Внутри одного namespace можно открыть другой namespace.

---

namespace можно открывать сколько угодно раз и добавлять туда новые сущности:


```c++
namespace N {
  int x = 10;
}

namespace N {
  int y = 10;
}

int main() {
  std::cout << N::y;
}
```

---

Можно определять функции из namespace'ов:

```c++
namespace N {
  int f(int x);
}

int N::f(int x) {
  return x + 10;
}
```

При этом N::f в данном случае это qualified-id (потому что указан namespace).

---

Using - механизм для более удобного обращения к неймспейсам:


```c++
#include <vector>

int main() {
  using my_vector_int = std::vector<int>;
  my_vector_int v;
  v.push_back(1)
}
```

Более простой пример:

```c++
int main() {
  using Sec = size_t;
  Sec secs_since_epoch = 1662492043;
}
```

---

Using так же позволяет вносить сущности из одной области видимости в другую:

```c++
namespace N {
  int a = 10;
}

int main() {
  using N::a;
  std::cout << a;
}
```

Еще:

```c++
int main() {
  using std::cout;
  cout << 10;
}
```

---

using позволяет внести вообще все сущности из namespace к себе в namespace. Знаменитое using namespace std; именно это и делает.

```c++
using namespace std;

int main() {
    vector<int> v;
}
```

---

Под конец набросик:

```c++
namespace N {
  int x = 10;
}

int main() {
  using N::x;
  int x = 20;
}
```

не компилируется!

---

```c++
namespace N {
  int x = 10;
}

int main() {
  using namespace N; // Тут поменяли
  int x = 20;
}
```

компилируется!

----

<!-- header: 1.2 Введение в язык-->

## 1.2.6 Выражения и операторы

***Note*** Приводить полное определение выражения автор отказывается :)

Примеры выражений:

- a + 5;
- (--a * b << 3) + 1;

Грубо говоря это различные идентификаторы и литералы связанные операторами.

---
<!-- header: 1.2.6 Выражения и операторы-->

Операторы:

- Арифметические операторы: +, -, \*, /, %, унарный +, унарный -
- Побитовые операторы: &, |, ^ (XOR), \~ (побитовое НЕ), <<, >>
- Сравнения: ==, !=, <, >, <=, >=, <=> (since C++20, spaceship operator)
- Логические операторы: &&, ||, !.

**Note** Операторы могут по разному работать в зависимости от типов. Например оператор << для чисел работает как побитовый сдвиг влево, а для std::cout как указание куда выводить данные.

---

### Ленивые вычисления:

Логические операторы && и || не вычисляют лишнего.
В выражении вида (expr1 && expr2) если expr1 при вычислении дает false, то expr2 даже не вычисляется. Аналогично с ||.

Это нужно например для следущих конструкций: if (vector.size() > 0 && vector[0] == 10) (если бы правило не выполнялось, то мы бы попали в UB).

---

### Инкремент и декремент: ++, --

```c++
int main() {
  {
    int x = 10;
    std::cout << ++x; // выведет 11
    std::cout << x; // выведет 11
  }
  {
    int x = 10;
    std::cout << x++; // выведет 10
    std::cout << x; // выведет 11
  }
}
```

---

Что выведет код?

```c++
int main() {
  int x = 0;
  x++ && ++x;
  std::cout << x;
}
```

---

Что выведет код?

```c++
int main() {
  int x = 0;
  x++ && ++x;
  std::cout << x;
}
```

Ответ: 1

---

Спасибо за внимание!

![img](https://cataas.com/cat/gif)
