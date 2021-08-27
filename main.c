#include <stdio.h>

double coefficient_a = 0; /*!< коэффициент квадратного уравнения a */
double coefficient_b = 0; /*!< коэффициент квадратного уравнения b */
double coefficient_c = 0; /*!< коэффициент квадратного уравнения c */
double first_root = 0; /*!< первый корень квадратного уравнения */
double second_root = 0; /*!< второй корень квадратного уравнения */
int total_roots = 0; /*!< количество корней квадратного уравнения */
double discriminant = 0; /*!< дискриминант квадратного уравнения */

/*! \brief Функция нахождения квадратного корня.
 *         Нахождение квадратного корня бинарным поиском.
 *
 *  Вводные данные: number (тип double).
 *
 *  Выходные данные: r (тип double).
 *
 *  Number - дискриминант, number > 0.
 *
 *  l, r - левая и правая граница бинарного поиска соответственно.
 *
 *  mid - вспомогательная переменная алгоритма.
 *
 *  Описание алгоритма: https://ru.wikipedia.org/wiki/Двоичный_поиск.
 */

double sqrt(double number) {
    double l = 0, r = 100000, mid;
    while (r * r - number >= 0.0001) {
        mid = (l + r) / 2;
        if (mid * mid < number) {
            l = mid;
        } else if (mid * mid > number) {
            r = mid;
        } else {
            return mid;
        }
    }
    return r;
}

/*! \brief Вывод результата работы программы.
 *
 *  Вводные данные: -
 *
 *  Выходные данные: -
 *
 *  Функция использует глобальные переменные first_root, second_root, discriminant.
 *
 *  Примечание:
 *  Строки формата функции printf(), выводящие first_root и/или second_root предусматривают округление чисел с
 *      плавающей точкой до 3 знаков после запятой.
 */

void PrintResult() {
    switch (total_roots) {
        case -1:
            printf("Ваше уравнение имеет 1 корень. \n");
            printf("Единственный корень - %1.3lf. \n", first_root);
            return;

        case 0:
            printf("Ваше уравнение не имеет действительных корней. \n");
            return;

        case 1:
            printf("Ваше уравнение имеет %d действительный корень. \n", total_roots);
            printf("Единственный действительный корень - %1.3lf. \n", first_root);
            return;

        default:
            printf("Ваше уравнение имеет %d действительных корня. \n", total_roots);
            printf("Первый действительный корень - %1.3lf. \n", first_root);
            printf("Второй действительный корень - %1.3lf. \n", second_root);
            return;
    }
}

/*! \brief Функция для нахождения корней квадратного уравнения.
 *
 *  Вводные данные: code (тип int).
 *
 *  Выходные данные: -
 *
 *  code - переменная, обозначающая количество корней квадратного уравнения.
 *      инструкция switch определяет количество вычисляемых корней.
 *
 *  Функция использует и изменяет глобальные переменные first_root, second_root, discriminant.
 */

void SolveEquation(int code) {
    switch (code) {
        case -1:
            first_root = -coefficient_c / coefficient_b;
            PrintResult();
            return;

        case 0:
            PrintResult();
            return;

        case 1:
            first_root = -coefficient_b / (2 * coefficient_a);
            PrintResult();
            return;

        default:
            first_root = (-coefficient_b - sqrt(discriminant)) / (2 * coefficient_a);
            second_root = (-coefficient_b + sqrt(discriminant)) / (2 * coefficient_a);
            PrintResult();
            return;
    }
}

/*! \brief Функция для ввода коэффициентов квадратного уравнения a, b, c из потока stdin.
 *
 *  Входные данные: -
 *
 *  Выходные данные: -
 *
 *  Функция обновляет значения глобальных переменных coefficient_a, coefficient_b, coefficient_c.
 *
 *  Функция scanf() НЕ возвращает ошибки конверсии в случае получения неверных входных данных.
 *      Для проверки корректности вводных данных используйте strtod().
 *
 */

void GetCoefficients() {
    scanf("%lf %lf %lf", &coefficient_a, &coefficient_b, &coefficient_c);
}

/*! \brief Функция для нахождения количество корней квадратного уравнения.
 *
 *  Входные данные: -
 *
 *  Выходные данные: -
 *
 *  Возвращает предупреждение (a = 0) и завершает программу.
 *
 *  Использует и изменяет глобальные переменные discriminant, coefficient_a (_b, _c).
 */

void FindNumberOfRoots() {
    if (coefficient_a == 0) {
        printf("Ваше уравнение не является квадратным. Причина: a = 0. \n");
        printf("Решаю линейное уравнение. \n");
        total_roots = -1;
        return;
    }
    discriminant = coefficient_b * coefficient_b - 4 * coefficient_a * coefficient_c;
    if (discriminant < 0) {
        total_roots = 0;
    } else if (discriminant == 0) {
        total_roots = 1;
    } else {
        total_roots = 2;
    }
}

/*! \brief Функция вывода приветственного сообщения.
 *         Выводит сообщение о назначении программы и порядке действий пользователя.
 *
 */

void PrintStartingMessage() {
    printf("Эта программа создана для решения уравнений вида ax² + bx + c = 0. \n");
    printf("Введите в следующей строке через пробел коэффициенты a, b, c соответственно. \n");
    printf("Помните, что в квадратном уравнении коэффициент a не должен быть равен 0. \n");
}


int main() {
    PrintStartingMessage();
    GetCoefficients();
    FindNumberOfRoots();
    SolveEquation(total_roots);
    return 0;
}
