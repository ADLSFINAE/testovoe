#include "sieveeratosthenes.h"

QVector<int> SieveEratosthenes::algorithm(int n)
{
    if (n < 2) return {}; // Нет простых чисел меньше 2

    // Создаем массив для отметки простых чисел
    QVector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    // Алгоритм Решета Эратосфена
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            // Вычеркиваем все кратные p, начиная с p²
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Собираем все простые числа в результат
    QVector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
