---
theme: gaia
header: 'Программирование на языке C++'
footer: 'Полторак Семён. ВШПИ МФТИ 2023'
marp: true
---
# Семинар 1

---

## План семинара

0. Правила игры
1. Рабочее окружение
2. Работа в терминале (shell)
3. Среда разработки
4. Bonus

---

## Правила игры

* Система отчетности: зачет в первом семестре, экзамен во втором (годовой)
* БРС = зачет + домашки в семестре
* Домашки с ревью и без ревью (система для сдачи будет позже)
* Ссылка на чат и канал
* Форма для регистрации на курс (ссылка в канале в тг)

---

## Рабочее окружение

* Linux or OSX
* Ubuntu
* VisualCode, vim, etc
* bash/zsh

---

### Как дела с Windows?

* Лектор и семинарист любят OSX и Linux
* UNIX-like окружение практически де-факто стандарт в индустрии
* Хочется поддерживать минимум платформ

#### А если очень хочется?

* [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/)

---

## Работа в терминале?

```bash
epsilond1-x mipt/cpp_course ‹main*› » echo $0
-zsh
```

* bash
* zsh

---

### Hotkeys

* Зависит от вашего терминала
* Переход в начало/конец строки; Стереть строку; Переключение между словами;

---

### Навигация

* **man man**
* **<cmd> -h, --help**
* **cd /**
* **cd home** VS **cd /home**
* **cd ~**
* **cd -**
* **cd ../../<target>**
* **pwd**
* use <TAB> for autocomplete

---

* **tree**
* **ls**
* **ls -lah**
* **ls /home/**
* **ls -R**

---

### Работа с объектами файловой системы

* **cp <from> <to>**
* **rm <target>**
* **mv <from> <to>**

---

* **mkdir <target>**
* **rmdir <target>**
* **rm -r**
* **touch <target>**

---

### ACL

| read (r) | write (w) | execute (x) |
| :--------- | ----------- | ------------- |
| 4        | 2         | 1           |

* **chmod**
  - **+/-{r, w, x}**
* **chown**

---

* user (u)
* group (g)
* other (o)
* **chmod g+w,o-r somefile**

---

### SUID, SGID, sticky bit

* SUID -- выполнить файл с разрешениями владельца (только файлы)
* SGID -- выполнить файл с разрешениями владельца группы; наследовать права группы в каталоге
* sticky bit -- запрещает удалять файлы других пользователей (только каталоги)

---

### Вывод содержимого файлов

* **cat** -- осторожно!
* **less**
* **more**
* **tail**, **tail -f**
* **head**

---

### Поиск в тексте

* **cat <somefile> | grep "simple_pattern"**
* **grep -i**
* **grep -w**
* **grep -r**
* **grep -v**
* **grep -l**
* **grep -x**
* **grep -A (--after) N -B (--before) M**

---

### PIPE

* **cmd1 | cmd2 | .... | cmdN**
* **echo 'Hello, world!' | awk -F ', ' '{print $2}'**
* **echo "I Love C++" | tr '[:space:]' '\n'**

---

### Поиск в файловой системе

* **find . -name 'somefile' -path '*/folder/*'**
* -exec

---

### Пакетные менеджеры

* OS X
  - brew install

* Ubuntu
  - sudo apt install <package-name>
  - sudo dpkg -i <debian_package.deb>

---

## Среда разработки

* Настроим окружение
* Соберем первый проект
* Разберемся, как запускать программы

---

### Репозиторий курса
1. Сгенерировать ssh-ключи и добавить публичный ключ в GitLab
2. `mkdir ~/cpp_course/ && cd ~/cpp_course`
3. `git clone <url>`

---

### Настройка окружения
* OS X
  - xcode https://developer.apple.com/xcode/
  - `brew install g++ git`
* Ubuntu
  - `sudo apt install g++ git`

---

### Запуск проекта в консоли

1. `cd sems/01/examples/hello_world`
2. `g++ main.cpp -o prog`

```
./prog
Hello, World!
```

---

### Использование stdin/stdout

1. `cd sems/01/examples/in_out`
2. Шаги с предыдущего слайда

---

### Hints

* ctrl+c or cmd+c -- остановка программы
* echo $? -- последний код выхода программы
* Не забывайте обновлять вашу ОС (sudo apt update)

---

### Visual Code
* https://code.visualstudio.com/
* https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
* Примеры работы с текстом

---

### NVim
* https://neovim.io/
* [Plugins](https://github.com/rockerBOO/awesome-neovim)
* My favorite plugins: fzf, vim-snippets, ncm2, chadtree, plenary, coc
* Exit! ESC + :q!
* Демонстрация возможностей

---

## Bonus
* which
* lsof
* df -h
* free -h
* jq
* sed
* xargs
* !!
