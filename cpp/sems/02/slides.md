---
theme: gaia
header: 'Программирование на языке C++'
footer: 'Полторак Семён. ВШПИ МФТИ 2023'
marp: true
---
# Семинар 2

---

## План семинара

0. Организационное
1. Codestyle
2. Коротко про хороше практики написания кода
3. Разбор задач
4. Вопросы

---

### Организационное

* Регистрация на курс
* Окружение должно быть настроено

---

### Codestyle

* [Google codestyle](https://google.github.io/styleguide/cppguide.html)
* [cpplint](https://github.com/cpplint/cpplint)
* Почему это важно?

---

### Про красивый код

* Две реальные проблемы в программировании
* Что такое хороший код и как учиться его писать?
* Отступы
* Паттерны проектирования
* Точка входа

---

#### Именование переменных

* snake_cas
* разумная длина
* имя отражает суть

---

```c++
bool	vlNoExitIfZeroBytesReceived = false;
```

---

```c++
Cells[i].S = Cells[i].n;
Cells[i].L = Cells[i].I = Cells[i].R = Cells[i].cumTC = Cells[i].D = 0;
Cells[i].infected = Cells[i].latent = Cells[i].susceptible + Cells[i].S;
```

---

```c++
void setPassword(const std::string& password) {
  if (password.length() > 7) {
      // any action...
  }
}
```

---

```c++
int x = 86400;
void foo(int t) {
  if (t >= 86400) {
    // anything...
  }
}
```

---

#### Copy-paste
* В своем коде
* Откуда угодно вообще

---

#### Moore examples
[Examples](https://shitcode.net/latest/language/cpp)
[More examples](https://pvs-studio.com/en/blog/posts/cpp/1053/)

---

### Разбор задач

[Contest](https://contest.yandex.ru/contest/40236/problems)
- E...N

---

#### B. Гипотенуза

$\sqrt{a^2 + b^2}$

---

#### C. Следующее и предыдущее

```c++
#include <iostream>

void TypicalPrint(const std::string pos, const int main_number, const int new_number) {
  std::cout << "The " << pos << " number for the number ";
  std::cout << main_number << " is " << new_number << "." << std::endl;
}

void RunTypicalPrint(const int cur_number) {
  TypicalPrint("next", cur_number, cur_number + 1);
  TypicalPrint("previous", cur_number, cur_number - 1);
}

int main() {
  int cur_number;
  std::cin >> cur_number;
  RunTypicalPrint(cur_number);
  return 0;
}

```

---

* [std::format](https://en.cppreference.com/w/cpp/utility/format/format)
```c++
#include <iostream>
#include <format>
...

std::cout << std::format("Hello {}!\n", "world");
```

---

#### D. МКАД


---

#### E. Сумма цифр


---

#### F. Следующее четное

---

```c++
int GetNextEventNumber(const int current_number) {
  return current_number + (current_number % 2 == 0 ? 2 : 1);
}
```

---

#### G. Электронные часы

* Разобраться в наименованиях
* Постараться избежать магических констант

---

#### H. Разность времен

* Обратить внимание на именование переменных
* Магические константы
* Посмотреть на разные типы данных

---

#### I. Улитка

---

* Решение без if
* Алгоритм?

---

#### J. Проверьте делимость

* Решение без if

---

#### K. Максимум из двух чисел

* Нельзя использовать if, тернарный оператор, библиотечные функции
* Идеи?

---

* попробовать расположить числа `a` и `b` на прямой
* что нужно прибавить правому числу на прямой?
* как найти середину?

---

### Решение через битовые операции

```c++
    int x, y, r;
    std::cin >> x >> y;
    r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
```

[Bonus](http://graphics.stanford.edu/~seander/bithacks.html#CopyIntegerSign)

---

### Размер объектов

* Зависит от системы
* sizeof(...)

---

#### Побитовый сдвиг

```
10(00001010) << 1 = 20(00010100)
00001010
00010100
```

```
10(00001010) >> 1 = 5(00000101)
00001010
00000101
```

---

#### XOR
7 ^ 2 = 5

```
00000111
^
00000010
--------
00000101
```

---

### Вопросы?
