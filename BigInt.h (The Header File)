#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {
private:
    string number;
    bool is_negative;

public:
    // Constructors
    BigInt();
    BigInt(long long n);
    BigInt(const string& s);

    // Operator Overloading
    // Arithmetic Operators
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;

    // Comparison Operators
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    // Friend function for output stream
    friend ostream& operator<<(ostream& os, const BigInt& bi);

private:
    // Helper functions for arithmetic
    string add(string num1, string num2) const;
    string subtract(string num1, string num2) const;
    string multiply(string num1, string num2) const;
};

#endif // BIGINT_H
