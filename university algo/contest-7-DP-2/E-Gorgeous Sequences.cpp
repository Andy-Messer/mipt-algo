#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec_1;
typedef std::vector<vec_1> vec_2;

const ll MOD = 1000000007;
const ll max_sz = 17;

ll count(ll s) {
    ll counter = 0;
    while (s != 0) (s & 1) && (counter++), s /= 2;
    return counter;
}

class Matrix {
public:
    vec_1 et;
    ll wd = 0, hg = 0;

    Matrix() = default;

    Matrix(vec_1 &B, ll n) {
        this->et = B;
        this->hg = n;
        this->wd = n;
    }

    Matrix(ll new_wd, ll new_hg) : et(vec_1(new_wd * new_hg)), hg(new_hg),
                                   wd(new_wd) {};


    void Make() {
        for (ll i = 0; i < this->wd; ++i)
            for (ll j = 0; j < this->hg; ++j)
                this->et[i * this->hg + j] = (abs(i - j) <= 1);
    }

    void Make_E() {
        for (ll i = 0; i < this->wd; ++i)
            for (ll j = 0; j < this->hg; ++j)
                this->et[i * this->hg + j] = (i == j);

    }

    static Matrix Power(Matrix M, ll p, ll mod) {
        Matrix ans = Matrix(M.wd, M.hg);
        ans.Make_E();
        if (p == 0) return ans;
        Matrix tmp = M;
        while (p) {
            if (p & 1) ans = ans * tmp;
            tmp = tmp * tmp;
            p >>= 1;
        }
        return ans;
    }

    Matrix operator*(Matrix &right) {
        Matrix ans(this->wd, this->hg);
        Matrix left = *this;
        for (long long i = 0; i < left.wd; ++i)
            for (long long j = 0; j < left.hg; ++j) {
                unsigned long long sum = 0;
                for (long long p = 0; p < left.wd; ++p)
                    sum = (sum + (left.et[i * this->hg + p] *
                                  right.et[p * this->hg + j]) %
                                 MOD) % MOD;

                ans.et[i * this->hg + j] = sum % MOD;
            }
        return ans;
    }

    Matrix &operator=(const Matrix &value) {
        this->et = value.et;
        this->wd = value.wd;
        this->hg = value.hg;
        return *this;
    }

    friend Matrix
    operator%(const Matrix &left, const unsigned long long &right);
};

Matrix operator%(const Matrix &left, const unsigned long long &right) {
    Matrix copy(left.wd, left.wd);
    for (ll i = 0; i < left.wd; ++i) {
        for (ll j = 0; j < left.wd; ++j) {
            copy.et[i * copy.wd + j] = left.et[i * left.wd + j] % 1000000007;
        }
    }
    return copy;
}

int main() {
    ll n, k;
    std::cin >> n >> k;
    vec_1 A(n);
    
    for (ll i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    
    vec_1 M(n * n, 0);
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            if (count(A[i] ^ A[j]) % 3 == 0)
                M[i * n + j] = 1;
    Matrix B(M, n);
    
    B = B.Power(B, k - 1, MOD);

    ll sum = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j)
            sum = (sum + B.et[i * n + j]) % MOD;
    std::cout << sum;
}