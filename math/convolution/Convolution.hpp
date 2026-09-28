#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"

// NTT prime / primitive root
// 998244353  = 119 * 2^23 + 1, g = 3
// 469762049  =   7 * 2^26 + 1, g = 3
// 167772161  =   5 * 2^25 + 1, g = 3

void ntt(vector<mint>& a, bool inv) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        while (j & bit) j ^= bit, bit >>= 1;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        mint z = mint(3).pow((998244353 - 1) / len);
        if (inv) z = z.inv();

        for (int i = 0; i < n; i += len) {
            mint w = 1;
            rep(j, len / 2) {
                mint x = a[i + j];
                mint y = a[i + j + len / 2] * w;
                a[i + j] = x + y;
                a[i + j + len / 2] = x - y;
                w *= z;
            }
        }
    }

    if (inv) {
        mint in = mint(n).inv();
        for (auto& x : a) x *= in;
    }
}

vector<mint> convolution(vector<mint> a, vector<mint> b) {
    if (a.empty() || b.empty()) return {};

    int sz = a.size() + b.size() - 1;
    int n = 1;
    while (n < sz) n <<= 1;

    a.resize(n);
    b.resize(n);

    ntt(a, false);
    ntt(b, false);
    rep(i, n) a[i] *= b[i];
    ntt(a, true);

    a.resize(sz);
    return a;
}