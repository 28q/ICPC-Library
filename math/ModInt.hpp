#pragma once

#include "../other/template.hpp"

template<unsigned int mod>
struct ModInt {
    unsigned int val;

    ModInt(ll v = 0) {
        v %= mod;
        if (v < 0) v += mod;
        val = v;
    }

    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= mod) val -= mod;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if (val < x.val) val += mod;
        val -= x.val;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = (ull)val * x.val % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) {
        return *this *= x.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

    ModInt pow(ll n) const {
        ModInt x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const { return pow(mod - 2); }

    friend istream& operator>>(istream& is, ModInt& x) {
        ll v;
        return is >> v, x = v, is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.val;
    }
};

using mint = ModInt<998244353>;