[![MIT License][license-shield]][license-url]



<br />
<p align="center">
  <a href="https://github.com/mQwand/SolveEquation/">
    <img src="images/logo.gif" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">SolveEquation</h3>

  <p align="center">
    Простая и небольшая программа для решения квадратных уравнений.
    <br />
    <a href="https://github.com/mQwand/SolveEquation"><strong>Список файлов »</strong></a>
    <br />
    <br />
    <a href="https://github.com/mQwand/SolveEquation/blob/main/solvefunctions.c">Код функций решения уравнения </a>
  </p>
</p>



<details open="open">
  <summary>Контент </summary>
  <ol>
    <li>
      <a href="#о_проекте">О проекте</a>
      <ul>
        <li><a href="#сборка">Сборка</a></li>
      </ul>
    </li>
    <li>
      <a href="#с_чего_начать?">С чего начать?</a>
      <ul>
        <li><a href="#установка">Установка</a></li>
      </ul>
    </li>
    <li><a href="#использование">Использование</a></li>
    <li><a href="#лиценция">Лицензия</a></li>
    <li><a href="#контакты">Контакты</a></li>
  </ol>
</details>



## О проекте

[![Product Name Screen Shot][product-screenshot]](https://example.com)

Существует множество программ, решающих квадратные уравнения. Я хотел написать свою, способную быстро работать и выполнять множество стресс и юнит тестов; и улучшить свое понимание языка.

Что может SolveEquation?
* Решать квадратное уравнение, определять количество корней в зависимости от интерактивно заданных пользователем коэффициентов.
* Выполнять заданное пользователем количество стресс-тестов.
* Выполнять заданное разработчиком количество юнит-тестов (используйте при необходимости проверки своей функции решения квадратного уравнения).

### Сборка

Программа использует стандартную библиотеку языка C и библиотеку <math.h>. Компилятор: gcc. При разработке использовались:
* [CLion IDE](https://www.jetbrains.com/ru-ru/clion/)
* [CMake](https://cmake.org/)
* [repl.it](https://repl.it)



## С чего начать?

Здесь приведен пример для настройки проекта на своей локальной машине.
Чтобы настроить проект, выполните несколько приведенных ниже шагов.

### Установка

1. Скопируйте себе директорию.
   ```sh
   git clone https://github.com/mQwand/SolveEquation.git
   ```
2. Выполните билд любым удобным вам способом.



## Использование

Программу можно использовать для нахождения корней квадратного уравнения с любыми действительными коэффициентами a, b, c. 
Пример работы программы приведен на скриншоте выше.

Общий алгоритм работы программы:
1) Запуск функции ввода коэффициентов и решения квадратного уравнения, введенного пользователем.
2) Проверка корректности и работоспособности алгоритма. Пользователю предлагается ввести количество выполняемых программой стресс и юнит тестов, после чего программа выводит отчет о проделанной работе (количество верно выполненных тестов).
3) Завершение работы программы.

Для тестирования вашей собственной функции решения квадратного уравнения:
1) Для выполнения стресс-тестов на произвольно сгенерированных коэффициентах:
  ``` c
  int StressTest (int stress_test_count); // функция выполнения стресс-тестов.
  ```
  Вызов моей функции:
  ``` c
  int roots_number = SolveEquation(random_a, random_b, random_c, &x1, &x2);
  ```
  Аргументы функции SolveEquation:
  ``` c
  int SolveEquation (double coef_a, double coef_b, double coef_c, double* x1, double* x2);
  ```
  
Подробнее читайте в документации. Сгенерировать документацию вы можете используя [файл конфигурации](https://github.com/mQwand/SolveEquation/blob/main/Doxygen_config) [doxygen](doxygen.nl). Подробнее читайте на официальном сайте.

## Лицензия

Распространяется под лицензией MIT. Смотрите `LICENSE` для полной информации.


## Контакты

Бирюков Никита - n.biryukov.04@gmail.com
Ссылка на проект: [https://github.com/mQwand/SolveEquation](https://github.com/mQwand/SolveEquation)



[license-url]: https://github.com/othneildrew/https://github.com/mQwand/SolveEquation/blob/main/LICENSE.txt
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge

[product-screenshot]: images/2021-09-07.png
