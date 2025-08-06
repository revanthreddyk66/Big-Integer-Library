#include "BigInt.h"

int main() {
    cout << "--- BigInt Library Demonstration ---" << endl;

    // Create BigInt objects
    BigInt a("123456789012345678901234567890");
    BigInt b("987654321098765432109876543210");
    BigInt c("-55555555555555555555");
    BigInt d(1000);

    cout << "\na = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    // Addition
    cout << "\n--- Addition ---" << endl;
    BigInt sum = a + b;
    cout << "a + b = " << sum << endl;
    BigInt sum2 = a + c;
    cout << "a + c = " << sum2 << endl;


    // Subtraction
    cout << "\n--- Subtraction ---" << endl;
    BigInt diff = a - b;
    cout << "a - b = " << diff << endl;

    // Multiplication
    cout << "\n--- Multiplication ---" << endl;
    BigInt product = a * d;
    cout << "a * d = " << product << endl;

    // Comparison
    cout << "\n--- Comparison ---" << endl;
    cout << "Is a > b? " << (a > b ? "Yes" : "No") << endl;
    cout << "Is a < b? " << (a < b ? "Yes" : "No") << endl;
    cout << "Is c == -555...? " << (c == BigInt("-55555555555555555555") ? "Yes" : "No") << endl;

    return 0;
}
