#ifndef SIEVEERATOSTHENES_H
#define SIEVEERATOSTHENES_H


class SieveEratosthenes
{
public:
    SieveEratosthenes() = default;

    // Метод для нахождения всех простых чисел до 200
    static void findPrimes(int primes[], int& count)
    {
        const int limit = 200;
        bool isPrime[limit + 1]; // Массив для отметки простых чисел

        // Инициализация массива
        for (int i = 0; i <= limit; ++i) {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;

        // Решето Эратосфена
        for (int p = 2; p * p <= limit; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= limit; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        // Заполнение массива простых чисел
        count = 0;
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                primes[count++] = i;
            }
        }
    }
};


#endif // SIEVEERATOSTHENES_H
