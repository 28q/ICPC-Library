#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/Convolution.hpp"
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<mint> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<mint> c = convolution(a, b);
    rep(i, n + m - 1) cout << c[i] << " \n"[i == n + m - 2];
}
