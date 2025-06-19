#include <stdio.h>

// Fibonacci dizisini yazdirir (recursive)
int fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// EBOB hesaplama (recursive)
int ebob(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ebob(b, a % b);
}

// EKOK hesaplama
int ekok(int a, int b)
{
    return (a * b) / ebob(a, b);
}

// Faktöriyel hesaplama (recursive)
int faktoriyel(int sayi)
{
    if (sayi == 0 || sayi == 1)
    {
        return 1;
    }
    return sayi * faktoriyel(sayi - 1);
}

// Basamak toplama (recursive)
int basamakToplami(int sayi)
{
    if (sayi == 0)
    {
        return 0;
    }
    return (sayi % 10) + basamakToplami(sayi / 10);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n-- MENU --\n");
        printf("1. Fibonacci sequence\n");
        printf("2. EBOB & EKOK\n");
        printf("3. Factorial\n");
        printf("4. Digit sum\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        int n, a, b;
        switch (choice)
        {
        case 1:
            printf("How many Fibonacci numbers? ");
            scanf("%d", &n);
            printf("Fibonacci sequence: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
        case 2:
            printf("Enter 1st number: ");
            scanf("%d", &a);
            printf("Enter 2nd number: ");
            scanf("%d", &b);
            printf("EBOB: %d\n", ebob(a, b));
            printf("EKOK: %d\n", ekok(a, b));
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            if (n < 0)
                printf("Factorial not defined for negative numbers.\n");
            else
                printf("%d! = %d\n", n, faktoriyel(n));
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%d", &n);
            if (n < 0) n = -n; // negatifse pozitife cevir
            printf("Digit sum: %d\n", basamakToplami(n));
            break;
        case 0:
            printf("Exit!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
