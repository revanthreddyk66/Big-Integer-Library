#include "BigInt.h"

// --- Constructors ---
BigInt::BigInt() : number("0"), is_negative(false) {}

BigInt::BigInt(long long n) {
    if (n < 0) {
        is_negative = true;
        n = -n;
    } else {
        is_negative = false;
    }
    number = to_string(n);
}

BigInt::BigInt(const string& s) {
    if (s.empty() || (s.length() == 1 && s[0] == '0')) {
        number = "0";
        is_negative = false;
    } else if (s[0] == '-') {
        number = s.substr(1);
        is_negative = true;
    } else {
        number = s;
        is_negative = false;
    }
}

// --- Helper Functions ---
string BigInt::add(string num1, string num2) const {
    string result = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += to_string(sum % 10);
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string BigInt::subtract(string num1, string num2) const {
    string result = "";
    int n1 = num1.length(), n2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int carry = 0;

    for (int i = 0; i < n2; i++) {
        int sub = ((num1[i] - '0') - (num2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    for (int i = n2; i < n1; i++) {
        int sub = ((num1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(sub + '0');
    }

    reverse(result.begin(), result.end());
    // Remove leading zeros
    result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
    return result;
}

string BigInt::multiply(string num1, string num2) const {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> res(num1.length() + num2.length(), 0);
    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = num1.length() - 1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;

        for (int j = num2.length() - 1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + res[i_n1 + i_n2] + carry;
            carry = sum / 10;
            res[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0) {
            res[i_n1 + i_n2] += carry;
        }
        i_n1++;
    }

    int i = res.size() - 1;
    while (i >= 0 && res[i] == 0) i--;

    if (i == -1) return "0";

    string s = "";
    while (i >= 0) s += to_string(res[i--]);

    return s;
}

// --- Operator Overloading Implementations ---
BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result;
    if (is_negative == other.is_negative) {
        result.number = add(number, other.number);
        result.is_negative = is_negative;
    } else {
        // Different signs, perform subtraction
        if (number.length() > other.number.length() || (number.length() == other.number.length() && number > other.number)) {
            result.number = subtract(number, other.number);
            result.is_negative = is_negative;
        } else {
            result.number = subtract(other.number, number);
            result.is_negative = other.is_negative;
        }
    }
    return result;
}

BigInt BigInt::operator-(const BigInt& other) const {
    BigInt temp = other;
    temp.is_negative = !temp.is_negative;
    return *this + temp;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.number = multiply(number, other.number);
    result.is_negative = is_negative != other.is_negative;
    if(result.number == "0") result.is_negative = false; // Zero is not negative
    return result;
}

bool BigInt::operator==(const BigInt& other) const {
    return (number == other.number && is_negative == other.is_negative);
}

bool BigInt::operator!=(const BigInt& other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt& other) const {
    if (is_negative != other.is_negative) return is_negative;
    if (is_negative) { // Both are negative
        if (number.length() != other.number.length()) return number.length() > other.number.length();
        return number > other.number;
    } else { // Both are positive
        if (number.length() != other.number.length()) return number.length() < other.number.length();
        return number < other.number;
    }
}

bool BigInt::operator>(const BigInt& other) const {
    return other < *this;
}

bool BigInt::operator<=(const BigInt& other) const {
    return !(*this > other);
}

bool BigInt::operator>=(const BigInt& other) const {
    return !(*this < other);
}

ostream& operator<<(ostream& os, const BigInt& bi) {
    if (bi.is_negative) {
        os << "-";
    }
    os << bi.number;
    return os;
}
