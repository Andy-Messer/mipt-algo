#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vec_1;
typedef std::vector<vec_1> vec_2;

const ll MOD = 1000000007;
const ll max_sz = 17;

class Matrix {
public:
    vec_1 et;
    ll wd = 0, hg = 0;

    Matrix() = default;

    Matrix(ll new_wd, ll new_hg) : et(vec_1(new_wd * new_hg)), hg(new_hg),
                                   wd(new_wd) {};


    void Make() {
        for (int i = 0; i < this->wd; ++i)
            for (int j = 0; j < this->hg; ++j)
                this->et[i * this->hg + j] = (abs(i - j) <= 1);
    }

    void Make_E() {
        for (int i = 0; i < this->wd; ++i)
            for (int j = 0; j < this->hg; ++j)
                this->et[i * this->hg + j] = (i == j);

    }

    static Matrix Power(Matrix M, ll p, ll mod) {
        Matrix ans = Matrix(M.wd, M.hg);
        ans.Make_E();
        if (!p) return ans;
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

};


int main() {
    ll n, k;
    std::cin >> n >> k;
    vec_1 a(n), b(n), c(n);
    vec_1 cur_pos(max_sz + 1), new_cur_pos(max_sz + 1);
    cur_pos[0] = 1;
    for (ll i = 0; i < n; i++)
        std::cin >> a[i] >> b[i] >> c[i];
    std::vector<Matrix> M_arr(max_sz + 1);
    ll i = 0;
    while (i <= max_sz) {
        Matrix tmp(i, i);
        M_arr[i] = tmp;
        M_arr[i].Make();
        i++;
    }
    ll diff;
    ll m_sz;
    for (ll i = 0; i < n; i++) {

        diff = b[i] - a[i];
        m_sz = c[i] + 1;
        (b[i] > k) && (diff = k - a[i]);

        Matrix T = Matrix::Power(M_arr[m_sz], diff, MOD);

        new_cur_pos.assign(max_sz, 0);
        for (int j = 0; j < m_sz; j++) {
            for (int k = 0; k < m_sz; k++) {
                new_cur_pos[j] += cur_pos[k] * T.et[j * (m_sz) + k];
                //std::cout << cur_pos[k] << " * " << T.et[j * (m_sz) + k]
                  //        << "\n";
                new_cur_pos[j] %= MOD;
            }
//            for (auto &x:new_cur_pos) {
//                std::cout << x << " ";
//            }
        }

        std::swap(new_cur_pos, cur_pos);
        for (int j = 0; j <= max_sz; j++)
            if (j > c[i]) cur_pos[j] = 0;

        if (b[i] >= k) break;
    }
    std::cout << cur_pos[0];
}