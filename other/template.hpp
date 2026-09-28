#pragma once

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep2(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)

#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

template<class T, class U> bool chmin(T& a, const U& b) { return a > b ? a = b, true : false; }
template<class T, class U> bool chmax(T& a, const U& b) { return a < b ? a = b, true : false; }

using ll = long long;
using ld = long double;
using ull = unsigned long long;

constexpr ll inf = 1e18;
