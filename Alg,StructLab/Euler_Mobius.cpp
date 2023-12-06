#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// ������� ��� ���������� ������� ������ (Totient function)
int eulerTotientFunction(int n) {
    int result = n; // ���������� ��������� ��������� n

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i; // ³������ ������ �������� ����� �� ����������
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

// ������� ��� ���������� ������� �������
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

// ������� ��� ����������� ��� ���� �����
int findLCM(int a, int b) {
    return (a * b) / gcd(a, b);
}

// ������� ��� ����������� ��� ������ �����
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
    // ������� ������������ ��� ���������� ������� ������ �� �������
    int n;
    cout << "������ ����� n ��� ���������� ������� ������ �� �������: ";
    cin >> n;

    int eulerResult = eulerTotientFunction(n);
    int moebiusResult = moebiusFunction(n);

    cout << "������� ������(" << n << ") = " << eulerResult << endl;
    cout << "������� �������(" << n << ") = " << moebiusResult << endl;

    // ������� ������������ ��� ����������� ��� ������ �����
    int m;
    cout << "������ ������� ����� ��� ����������� ���: ";
    cin >> m;

    vector<int> numbers(m);
    cout << "������ " << m << " �����: ";
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }

    int lcmResult = findLCMOfArray(numbers);
    cout << "��� �����: " << lcmResult << endl;

    return 0;
}
