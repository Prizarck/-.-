
#include <iostream>
#include <stdio.h>
#include <locale.h>

// Специальная функция, которая превращает число в строку из 0 и 1

void print_binary(unsigned int num) {
    printf("Двоичный вид: ");
    // Проходимся по всем 32 битам числа (от старшего к младшему)
    for (int i = 31; i >= 0; i--) {
        // Достаем i-й бит и проверяем, 1 там или 0
        int bit = (num >> i) & 1;
        printf("%d", bit);

        // Для красоты разделяем байты пробелами
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

int main(){

    setlocale(LC_ALL, "Russian");
    unsigned int num;
    int choice;

    printf("=== Лабораторная работа: Побитовые операции ===\n");
    printf("Введите начальное число (целое положительное): ");
    scanf_s("%u", &num);

    // Бесконечный цикл для меню, пока пользователь не нажмет 9
    while (1) {
        printf("\nТекущее число: %u (HEX: %X)\n", num, num);
        print_binary(num); // Всегда показываем, что происходит с битами

        printf("\n--- МЕНЮ ---\n");
        printf("1 - Перевести в HEX\n");
        printf("2 - Побитовое НЕ (~)\n");
        printf("3 - Сдвиг вправо (>>)\n");
        printf("4 - Сдвиг влево (<<)\n");
        printf("5 - Побитовое И (&)\n");
        printf("6 - Побитовое ИЛИ (|)\n");
        printf("7 - Сбросить бит в 0 (bit in 0)\n");
        printf("8 - Установить бит в 1 (bit in 1)\n");
        printf("9 - Выход (exit)\n");
        printf("Выберите пункт: ");
        scanf_s("%d", &choice);

        if (choice == 9) {
            printf("Выход из программы.\n");
            break; 
        }

        switch (choice) {
        case 1:
            printf("\n Результат в HEX: %X\n", num);
            break;

        case 2:
            num = ~num;
            printf("\n Выполнено: Побитовое НЕ\n");
            break;

        case 3: {
            int shift;
            printf("На сколько бит сдвинуть вправо? ");
            scanf_s("%d", &shift);
            num = num >> shift;
            break;
        }

        case 4: {
            int shift;
            printf("На сколько бит сдвинуть влево? ");
            scanf_s("%d", &shift);
            num = num << shift;
            break;
        }

        case 5: {
            unsigned int second_num;
            printf("Введите второе число для операции И (&): ");
            scanf_s("%u", &second_num);
            num = num & second_num;
            break;
        }

        case 6: {
            unsigned int second_num;
            printf("Введите второе число для операции ИЛИ (|): ");
            scanf_s("%u", &second_num);
            num = num | second_num;
            break;
        }

        case 7: {
            int bit_index;
            printf("Индекс бита для сброса в 0 (0-31): ");
            scanf_s("%d", &bit_index);
            num &= ~(1 << bit_index);
            break;
        }

        case 8: {
            int bit_index;
            printf("Индекс бита для установки в 1 (0-31): ");
            scanf_s("%d", &bit_index);
            num |= (1 << bit_index);
            break;
        }

        default:
            printf("\n Неверный пункт меню! Попробуйте снова.\n");
        }
    }

    return 0;
}

