#pragma once

#include "../other/template.hpp"
#include "ModInt.hpp"

template<class T>
struct Combinatorics {
    inline static vector<T> fac{1}, ifac{1};

    static void init(int n) {
        int m = fac.size();
        if (n < m) return;

        fac.resize(n + 1);
        rep2(i, m, n + 1) fac[i] = fac[i - 1] * i;

        ifac.resize(n + 1);
        ifac[n] = fac[n].inv();
        for (int i = n; i >= m; --i) ifac[i - 1] = ifac[i] * i;
    }

    static T fact(int n) {
        if (n < 0) return 0;
        init(n);
        return fac[n];
    }

    static T finv(int n) {
        if (n < 0) return 0;
        init(n);
        return ifac[n];
    }

    static T inv(int n) {
        if (n <= 0) return 0;
        init(n);
        return fac[n - 1] * ifac[n];
    }

    static T perm(int n, int r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return fac[n] * ifac[n - r];
    }

    static T comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return fac[n] * ifac[r] * ifac[n - r];
    }

    static T homo(int n, int r) {
        if (n == 0) return r == 0;
        return comb(n + r - 1, r);
    }
};
