// BigInt.h (single-file presentation)
#include <bits/stdc++.h>
using namespace std;

class BigInt {
public:
    string number;      // decimal digits, no leading zeros except "0"
    bool is_negative;

    // --- constructors
    BigInt();
    BigInt(long long n);
    BigInt(const string& s);

    // --- arithmetic operators
    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;

    // --- comparisons
    bool operator==(const BigInt& other) const;
    bool operator!=(const BigInt& other) const;
    bool operator<(const BigInt& other) const;
    bool operator>(const BigInt& other) const;
    bool operator<=(const BigInt& other) const;
    bool operator>=(const BigInt& other) const;

    // --- helpers
private:
    string add(const string& a, const string& b) const;
    string subtract(const string& a, const string& b) const; // assumes a >= b
    string multiply(const string& a, const string& b) const;
    static string strip_leading_zeros(const string& s);
    // friend IO
    friend ostream& operator<<(ostream& os, const BigInt& bi);
};

// --- implementations (concise)
BigInt::BigInt() : number("0"), is_negative(false) {}
BigInt::BigInt(long long n) {
    if (n < 0) { is_negative = true; n = -n; } else is_negative = false;
    number = to_string(n);
}
BigInt::BigInt(const string& s) {
    if (s.empty()) { number = "0"; is_negative = false; return; }
    if (s[0] == '-') { is_negative = true; number = s.substr(1); }
    else { is_negative = false; number = s; }
    number = strip_leading_zeros(number);
    if (number == "0") is_negative = false;
}

string BigInt::strip_leading_zeros(const string& s) {
    size_t p = s.find_first_not_of('0');
    if (p == string::npos) return "0";
    return s.substr(p);
}

string BigInt::add(const string& num1, const string& num2) const {
    string a = num1; string b = num2;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    string res; int carry = 0;
    int n = max(a.size(), b.size());
    for (int i = 0; i < n; ++i) {
        int da = (i < (int)a.size()) ? a[i]-'0' : 0;
        int db = (i < (int)b.size()) ? b[i]-'0' : 0;
        int s = da + db + carry;
        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }
    if (carry) res.push_back(char('0' + carry));
    reverse(res.begin(), res.end());
    return strip_leading_zeros(res);
}

string BigInt::subtract(const string& num1, const string& num2) const {
    // assumes num1 >= num2 (both positive strings)
    string a = num1; string b = num2;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    string res; int carry = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        int da = a[i]-'0';
        int db = (i < (int)b.size()) ? b[i]-'0' : 0;
        int s = da - db - carry;
        if (s < 0) { s += 10; carry = 1; } else carry = 0;
        res.push_back(char('0' + s));
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return strip_leading_zeros(res);
}

string BigInt::multiply(const string& num1, const string& num2) const {
    if (num1 == "0" || num2 == "0") return "0";
    int n1 = num1.size(), n2 = num2.size();
    vector<int> res(n1 + n2, 0);
    for (int i = n1-1; i >= 0; --i) {
        for (int j = n2-1; j >= 0; --j) {
            int d1 = num1[i]-'0';
            int d2 = num2[j]-'0';
            int sum = res[i+j+1] + d1 * d2;
            res[i+j+1] = sum % 10;
            res[i+j] += sum / 10;
        }
    }
    string s;
    for (int x : res) if (!(s.empty() && x == 0)) s.push_back('0' + x);
    return s.empty() ? "0" : s;
}

// operators
BigInt BigInt::operator+(const BigInt& other) const {
    BigInt out;
    if (is_negative == other.is_negative) {
        out.number = add(number, other.number);
        out.is_negative = is_negative;
    } else {
        // different signs -> subtraction
        if (number.size() > other.number.size() || (number.size() == other.number.size() && number >= other.number)) {
            out.number = subtract(number, other.number);
            out.is_negative = is_negative;
        } else {
            out.number = subtract(other.number, number);
            out.is_negative = other.is_negative;
        }
    }
    if (out.number == "0") out.is_negative = false;
    return out;
}

BigInt BigInt::operator-(const BigInt& other) const {
    BigInt t = other; t.is_negative = !t.is_negative;
    return *this + t;
}

BigInt BigInt::operator*(const BigInt& other) const {
    BigInt out;
    out.number = multiply(number, other.number);
    out.is_negative = (out.number == "0") ? false : (is_negative != other.is_negative);
    return out;
}

// comparisons
bool BigInt::operator==(const BigInt& o) const { return number == o.number && is_negative == o.is_negative; }
bool BigInt::operator!=(const BigInt& o) const { return !(*this == o); }
bool BigInt::operator<(const BigInt& o) const {
    if (is_negative != o.is_negative) return is_negative;
    if (!is_negative) {
        if (number.size() != o.number.size()) return number.size() < o.number.size();
        return number < o.number;
    } else {
        if (number.size() != o.number.size()) return number.size() > o.number.size();
        return number > o.number;
    }
}
bool BigInt::operator>(const BigInt& o) const { return o < *this; }
bool BigInt::operator<=(const BigInt& o) const { return !(*this > o); }
bool BigInt::operator>=(const BigInt& o) const { return !(*this < o); }

ostream& operator<<(ostream& os, const BigInt& bi) {
    if (bi.is_negative && bi.number != "0") os << "-";
    os << bi.number;
    return os;
}
