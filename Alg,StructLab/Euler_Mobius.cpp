#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Функція для обчислення функції Ейлера (Totient function)
int eulerTotientFunction(int n) {
    int result = n; // Ініціалізуємо результат значенням n

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i; // Віднімаємо внесок простого числа до результату
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

// Функція для обчислення функції Мьобіуса
int moebiusFunction(int n) {
    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            if (n == i * i) {
                count += 1;
            }
            else {
                count += 2;
            }
        }
    }

    return (count % 2 == 0) ? 1 : -1;
}

// Функція для знаходження НСК двох чисел
int findLCM(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Функція для знаходження НСК набору чисел
int findLCMOfArray(const vector<int>& numbers) {
    if (numbers.size() < 2) {
        cerr << "Error: At least two numbers are required to find LCM." << endl;
        return -1;
    }

    int lcm = numbers[0];

    for (size_t i = 1; i < numbers.size(); ++i) {
        lcm = findLCM(lcm, numbers[i]);
    }

    return lcm;
}

int main() {
    // Приклад використання для обчислення функцій Ейлера та Мьобіуса
    int n;
    cout << "Введіть число n для обчислення функцій Ейлера та Мьобіуса: ";
    cin >> n;

    int eulerResult = eulerTotientFunction(n);
    int moebiusResult = moebiusFunction(n);

    cout << "Функція Ейлера(" << n << ") = " << eulerResult << endl;
    cout << "Функція Мьобіуса(" << n << ") = " << moebiusResult << endl;

    // Приклад використання для знаходження НСК набору чисел
    int m;
    cout << "Введіть кількість чисел для знаходження НСК: ";
    cin >> m;

    vector<int> numbers(m);
    cout << "Введіть " << m << " чисел: ";
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }

    int lcmResult = findLCMOfArray(numbers);
    cout << "НСК чисел: " << lcmResult << endl;

    return 0;
}
