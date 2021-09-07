#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solvefunctions.h"


/*! \brief Функция генерации рандомного числа с плавающей точкой.
 *
 * @returns произвольное число с плавающей точкой
 *
 *  Функция использует функцию rand() из библиотеки <math.h> для получения рандомного числа типа int,
 *  после чего получает число с плавающей точкой и 6 знаками после точки приведением к типу (double) и делению на
 *  константу.
 *
 */

double GetRandom () {
    return (double) rand() / (double) RAND_PRECISION;
}

void PrintResult (double x1, double x2, int roots_number) {
    switch (roots_number) {
        case INFIN_ROOTS:
            printf("Equation has infinite roots. \n");
            break;

        case 0:
            printf("Equation has no roots. \n");
            break;

        case 1:
            printf("Equation has one root - %1.3lf. \n", x1);
            break;

        default:
            printf("Equation has two roots - %1.3lf and %1.3lf. \n", x1, x2);
            break;
    }
}


/*! \brief Функция проверки корректности найденного корня квадратного (!) уравнения.
 *
 * @param [in] a коэффициент уравнения a.
 * @param [in] b коэффициент уравнения b.
 * @param [in] c коэффициент уравнения c.
 * @param [in] x1 первый корень решаемого уравнения.
 * @returns 0 если переданный корень (x1) не является корнем уравнения или неточен.
 * @returns 1 если переданный корень (x1) является корнем уравнения.
 *
 * Возвращает 1 или 0 в зависимости от правильности найденного корня. Является частью стресс теста.
 *
 */

int CompleteTest(double x1, double a, double b, double c) {
    double x1_result = a * x1 * x1 + b * x1 + c;
    if (!isApproxZero(x1_result)) {
        printf("test failed. a = %1.6lf, b = %1.6lf, c = %1.6lf \n", a, b, c);
        return 0;
    } else {
        return 1;
    }
}


/*! \brief Функция выполнения стресс теста для заданного количества тестов.
 *
 * @param [in] stress_test_count количество выполняемых функцией стресс тестов.
 * @returns success_count количество успешно выполненных стресс тестов.
 *
 * Генерирует коэффициенты уравнений, изменяя сид генерации при каждом запуске.
 * Тестирует найденные корни на правильность с помощью функции CompleteTest().
 *
 */

int StressTest (int stress_test_count) {
    int success_count = 0;
    srand(time(NULL));

    for (int i = 0; i < stress_test_count; ++i) {
        double x1 = 0, x2 = 0;

        double random_a = GetRandom();
        double random_b = GetRandom();
        double random_c = GetRandom();

        int roots_number = SolveEquation(random_a, random_b, random_c, &x1, &x2);
        switch (roots_number) {
            case 1:
                success_count += CompleteTest(x1, random_a, random_b, random_c);
                break;

            case 2:
                success_count += CompleteTest(x1, random_a, random_b, random_c) &&
                                 CompleteTest(x1, random_a, random_b, random_c);
                break;

            case INFIN_ROOTS:
            case 0:
                // there is nothing to test for
                success_count++;
                break;

            default:
                printf("Unexpected roots_number (Stress tests) - %d \n", roots_number);
                break;
        }
    }
    return success_count;
}


/*! \brief Функция выполнения юнит тестов для заданного (до запуска программы) количества тестов.
 *
 * @param [in] unit_test_count количество выполняемых функцией юнит тестов.
 * @returns success_count количество успешно выполненных юнит тестов.
 *
 * Решает уравнение для заданных коэффициентов. Проверяет соответствие найденных корней заданным вручную.
 *
 */

int UnitTest (int unit_test_count, struct Equation unit_tests[unit_test_count][6]) {
    int success_count = 0;

    for (int i = 0; i < unit_test_count; ++i) {
        double a = unit_tests[i]->coef_a, b = unit_tests[i]->coef_b, c = unit_tests[i]->coef_c;
        int roots_number = (int) unit_tests[i]->roots_count;
        double x1 = unit_tests[i]->x1, x2 = unit_tests[i]->x2;

        double x1_1 = 0, x1_2 = 0;
        int my_roots_number = SolveEquation(a, b, c, &x1_1, &x1_2);

        if (my_roots_number != roots_number || !isApproxZero(x1_1 - x1) || !isApproxZero(x1_2 - x2)) {
            printf("test failed. a = %1.6lf, b = %1.6lf, c = %1.6lf, "
                   "roots_number = %d, x1 = %lf, x2 = %lf \n", a, b, c, roots_number, x1, x2);
        } else {
            success_count++;
        }
    }
    return success_count;
}



/*! \brief Функция получения количества стресс тестов с клавиатуры.
 *
 * @param [out] stress_test_count количество стресс тестов, выполняемых программой.
 *
 */

void GetTestCount (int* stress_test_count) {
    int success_scan = scanf("%d", stress_test_count);
    if (success_scan != 1) {
        scanf("%*[^\n]s");
        printf("Please enter valid test count. \n");
        GetTestCount(stress_test_count);
    }
}


/*! \brief Функция запуска выполнения стресс теста и всех необходимых функций.
 *
 */

void RunStressTests () {
    printf("Please enter stress test count. \n");
    int stress_test_count = 0;

    GetTestCount(&stress_test_count);
    int success_stress_count = StressTest(stress_test_count);

    printf("Completing stress tests. \n");
    printf("Successful stress tests - %d out of %d. \n", success_stress_count, stress_test_count);
}


/*! \brief Функция запуска выполнения юнит теста и всех необходимых функций.
 *
 */

void RunUnitTests () {
    printf("Completing unit tests. \n");

    struct Equation unit_tests[7][6] = {{0, 0, 0, INFIN_ROOTS, NOT_ROOT, NOT_ROOT},
                               {1, 4, 4, 1, -2, NOT_ROOT},
                               {2, 4, 2, 1, -1, NOT_ROOT},
                               {2, 2, 17, 0, NOT_ROOT, NOT_ROOT},
                               {100.123, 1000.234234, 100000.324234, 0, NOT_ROOT, NOT_ROOT},
                               {1, -3, 2, 2, 1, 2},
                               {1, 7, 12, 2, -4, -3}};
    int success_unit_count = UnitTest(7, unit_tests);

    printf("Successful unit tests - %d out of %d. \n", success_unit_count, 7);
}




/*! \brief Главная функция, задающая порядок выполнения и ход функций в программе.
 *
 */

int main() {
    RunEquationSolving();
    RunStressTests();
    RunUnitTests();
    return 0;
}