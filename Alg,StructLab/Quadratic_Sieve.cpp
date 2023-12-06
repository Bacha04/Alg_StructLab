#include <iostream>
#include <vector>
#include <cmath>

namespace QuadraticSieve {

  
    class QuadraticSieve {
    private:
      
       
        bool isPerfectSquare(int n) {
            int sqrtN = sqrt(n);
            return (sqrtN * sqrtN == n);
        }

      
        int gcd(int a, int b) {
            if (b == 0)
                return a;

            return gcd(b, a % b);
        }

        int computeFx(int x, int n) {
            return (x * x - n);
        }

        
        bool isBSmooth(int num, int B) {
            for (int i = 2; i <= B; i++) {
                while (num % i == 0) {
                    num /= i;
                }
            }

            return (num == 1);
        }

    public:
        
        void factorize(int n, int B) {
            if (isPerfectSquare(n)) {
                std::cout << "The number is a perfect square.\n";
                return;
            }

            int x = ceil(sqrt(n));
            int fx = computeFx(x, n);

            std::vector<int> exponents;
            std::vector<int> smoothValues;

            while (!isBSmooth(fx, B)) {
                x++;
                fx = computeFx(x, n);
            }

            for (int i = 2; i <= B; i++) {
                while (fx % i == 0) {
                    exponents.push_back(i);
                    fx /= i;
                }
            }

            if (fx > B) {
                std::cout << "The smoothness bound is too small to factorize the number.\n";
                return;
            }

            smoothValues.push_back(fx);

            std::cout << "x: " << x << "\n";
            std::cout << "f(x): " << smoothValues[0] << "\n";
            std::cout << "Exponents: ";
            for (int i = 0; i < exponents.size(); i++) {
                std::cout << exponents[i] << " ";
            }
            std::cout << "\n";
        }
    };
}

int main() {
    int numberToFactorize = 123456789;
    int smoothnessBound = 10;

    QuadraticSieve::QuadraticSieve sieve;
    sieve.factorize(numberToFactorize, smoothnessBound);

    return 0;
}