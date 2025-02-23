# Lab 1

For using program - Launch **main.py** with this console commands:
|           |                               |                                                               |
|-----------|-------------------------------|---------------------------------------------------------------|
|-h         |                               |  /..    -- if you want to see help once more                  |
|--help     |                               | /..    -- if you want to see help once more, but in long way  |
|-v         | template-name   -(p/d/f)      | /..    -- if you want to verify your file(s)                  |
|--verify   | template-name   -(p/d/f)      | /..    -- if you want to verify your file(s), but in long way |
|-f         | template-name   -(p/d/f)      | /..    -- if you want to fromat your file(s), but in long way |
|--format   | template-name   -(p/d/f)      |  /..    -- if you want to fromat your file(s), but in long way|

|Usages|Meaning|
|-|-|
|-p | project |
|-d | directory |
|-f | file |
|/.. | path to project, directory or file |

**Remember!** template-name has to be in **template.json**<br>

## Task

Використовуючи мову програмування C++/Java/Kotlin/C#/Python (на вибiр), розробити
консольну iнтерактивну утилiту позицiйного форматування програмного коду для певної
мови програмування/розмiтки. Система повинна вмiти:
1. Виконувати аналiз структури дерева проєкту та виявляти файли, що мiстять програмнi коди певною мовою програмування (в залежностi вiд обраного варiанту) шляхом аналiзу розширень файлiв.
2. Виконувати аналiз структури програмних кодiв в рамках окремих файлiв та виявляти невiдповiдностi та помилки позицiювання структурних елементiв програмного коду. У випадку виявлення таких помилок, система повинна записувати повiдомлення про знайденi помилки у вiдповiдний файл errors.log вказуючи повний шлях до файлу, номер рядка та тип помилки чи невiдповiдностi у форматi<br>
    _Id. File Path: Line Number - Error Code: Error Message_
3. Виконувати форматування розмiщення структурних елементiв вхiдних програмних кодiв, використовуючи визначений шаблон форматування. Шаблон для форматування потрiбно задавати у виглядi конфiгурацiйного файлу. В якостi базового шаблону для форматування програмних кодiв потрiбно використовувати шаблон вiдповiдно до обраного варiанту. Доступ до вiдповiдних шаблонiв в IDEs
JetBrains вiдбувається через:
    * Linux/Windows: _File->Settings->Editor->Code Style->LANGUAGE_,
    * _IDE->Preferences->Editor->Code Style->LANGUAGE_,<br>
        де ->LANGUAGE визначається в кожному окремому варiантi, а IDE – це назва обраного IDE.
4. Використовувати рiзнi шаблони для форматування програмних кодiв. Система
повинна аналiзувати каталог iз наявними шаблонами та використовувати обраний
користувачем шаблон форматування.
