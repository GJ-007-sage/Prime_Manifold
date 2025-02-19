#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()
using namespace std;

// Function to compute (base^exp) % mod using modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  // If exp is odd
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate the Jacobi symbol (a/n)
int jacobi(long long a, long long n) {
    if (a == 0) return 0; // (0/n) = 0
    if (a == 1) return 1; // (1/n) = 1

    int result = 1;
    if (a < 0) {
        a = -a;  // (−a/n) = (a/n) * (−1/n)
        if (n % 4 == 3)
            result = -result;
    }

    while (a != 0) {
        while (a % 2 == 0) { // Reduce even numbers
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5)
                result = -result;
        }
        swap(a, n); // Reciprocity law: (a/n) = (n/a)
        if (a % 4 == 3 && n % 4 == 3)
            result = -result;
        a %= n; // Reduce a
    }

    return (n == 1) ? result : 0;
}


// Solovay-Strassen Primality Test
bool is_prime(long long n, int k) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    srand(time(0)); // Seed for randomness

    for (int i = 0; i < k; i++) {
        long long a = rand() % (n - 2) + 2; // Choose random a in range [2, n-2]
        int j_symbol = jacobi(a, n) % n;
        if (j_symbol < 0) j_symbol += n; // Ensure positive value

        long long mod_exp_result = mod_exp(a, (n - 1) / 2, n);
        if (j_symbol != mod_exp_result)
            return false; // Composite
    }
    return true; // Probably prime
}


// Main function to test the primality check
int main() {
    long long n;
    int k = 5; // Number of iterations

    cout << "Enter a number to check for primality: ";
    cin >> n;

    if (is_prime(n, k))
        cout << n << " is probably prime.\n";
    else
        cout << n << " is composite.\n";

    return 0;
}