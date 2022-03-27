////////////////////////////////////////////////////////////////////////////////////////////////////
//░▐█▀█▒▐█▀▀█▌▒▐██▄▒▄██▌░▐█▀▀/////▒█▀█▀█▒▐█▀▀█▌/////▒█▀█▀█░▐█░▐█░▐█▀▀///////////////////////////////
//░▐█──▒▐█▄▒█▌░▒█░▒█░▒█░░▐█▀▀/////░░▒█░░▒▐█▄▒█▌/////░░▒█░░░▐████░▐█▀▀///////////////////////////////
//░▐█▄█▒▐██▄█▌▒▐█░░░░▒█▌░▐█▄▄/////░▒▄█▄░▒▐██▄█▌/////░▒▄█▄░░▐█░▐█░▐█▄▄///////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//░▐█▀█▄─░▄█▀▄─▒▐█▀▀▄▒▐█▒▐▀/////▒▄█▀▀█░▐██░▐█▀█▄░▐█▀▀///////////////////////////////////////////////
//░▐█▌▐█░▐█▄▄▐█▒▐█▒▐█▒▐██▌░/////▒▀▀█▄▄─░█▌░▐█▌▐█░▐█▀▀///////////////////////////////////////////////
//░▐█▄█▀░▐█─░▐█▒▐█▀▄▄▒▐█▒▐▄/////▒█▄▄█▀░▐██░▐█▄█▀░▐█▄▄///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////+o+/+/-----...--:::///////////////////////////////////////
////////////////////////////////////::++ohss+///+ooooo:`     `...-://///////////////////////////////
/////////////////////////////////:+sdd/` :o.                 `-ohhs+/:://///////////////////////////
////////////////////////////////smdh+` `o:                `.://+yy/oshy+:://////////////////////////
/////////////////////////////:sms-.`  .s.            `:oydmmmmmmmd   `-oyy/::///////////////////////
///////////////////////////:/do` .   :y`           .sdmmmmmmmmmmmd      `:sho:://///////////////////
/////////////////////////:./s.  .   :y`           -dmmmmmmmmmmmmm:         .oho:////////////////////
////////////////////////:`-/       -h`          `ommmmmmmmmmmmmms            -yh////////////////////
///////////////////////:` .   `.  .y`          /dmmmmmmmmmmmmmmm-             `sd///////////////////
//////////////////////:    `/`h/ `s.          ommmmmmmmmmmmmmmmh               `yh://///////////////
/////////////////////:`   .hhyMs -.           /sdmmmmmmh:.....-/                /d+/////////////////
////////////////////:::` `dNhMM/                -dmmmmmd+`                      :ds:////////////////
//////////////////:.:-`   .yNMN``       ``     :dmmmmmmmmdo-                    :dy:////////////////
////////////////:-```     .NMMs--::.`   ``` `-/ymmmmmmmmo::/.                   :dy:////////////////
///////////////:.     `  `.//-``.`...--:--.`   `./ymmmmd`                       /dy:////////////////
///////////////.     .    .-``` .-.....-://:--``   -odms                        +ds:////////////////
/////////////+:      /`  :ys:--o+` ./osyyyyys+-:-`   -hs                        +d+/////////////////
/////////////+       y` .yy:-.:/- `yhhhhhyyyy/ ``-.   .s-                       od//////////////////
///////////:o`       o` :ho`..-`` :hhhhhhhhy:     ..   `+`                      yd-/////////////////
///////////+-        -/ :/.-` ..  ohhhhhyhy-     `:.`   `/                    `+dh-/////////////////
//////////:o          +`  .`   --`-/oyyyys-      /o--    .-                   -dds://///////////////
///////////+        .+so+.      `.:-.-::..  `:////` ``    -.                  `ddo://///////////////
//////////o-    `.--yssshs:`+oo: -/:--.``````````          /`                  ody://///////////////
//////////y    :hhdyydmmmo.`/os: :hhyyso/:.                 +`                 .dd//////////////////
/////////o/    -ddhy-.-++y` ``.` /hhhyhhhs`                 .+                  ody:////////////////
////////:y.    `dhy:     :s`   ..-syhyyhs`             ```   ::                 `hd+////////////////
/////////s      sy:  `  .`/o    ..:oyyhs.         `````       o`                 /dy:///////////////
////////o:      o/  `.`.`++++  `:/-:+oy-  ````````            .+                  yd+///////////////
///////:y`     +/  `.`y/.h`+h/ `/++`:++.-:::-.                 +.                 -dh://////////////
///////++  `..+o...y.+s`y:-h.y- `.---+//:.`                     o                  sd+//////////////
///////o-`yyy+yyhyyhodssd+ys/dh:-.////-``...`````````````````   -:                 .dh://///////////
///////:.`//::://++oosssyyyyydmmm-..........``````               :-                 /do:////////////
/////////:-`    `.`.:.-::--::--..                                 .```               yd/////////////
////////////:-`   .-....:+/://:` `                                                   -ds:///////////
///////////////:-.` `---.-//-// ```                                                   od////////////
///////////////////:-.../-.`::` ````                          `````                   `hy://////////
////////////////////////:os-.`` ````     ```             .-:::::://-    `              :d+//////////
///////////////////////////-   ```        `          .--..                          ``` :y//////////
///////////////////////////:.                     .:-.                               ``  .//////////
////////////////////////////-                   :/-                                        /////////
////////////////////////////.                 .:.                                        `-/////////
///////////////////////////o                                              .........----:////////////
//////////////::--.....``-:                                               ./////////////////////////
/////////:-.`           .     .--`                                        /+////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
#include <limits.h>
#include <math.h>

using std::cin;
using std::cout;
using std::vector;
using std::set;
using std::unordered_set;
using std::multiset;
using std::queue;
typedef long long ll;
typedef size_t st;
typedef vector<bool> vb;
typedef queue<ll> qll;
typedef set<ll> sll;
typedef unordered_set<ll> usll;
typedef multiset<ll> msll;
typedef vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::pair<pll, ll> plll;
typedef vector<vll> vvll;
typedef vector<sll> vsll;
typedef vector<msll> vmsll;
typedef set<sll> ssll;
using namespace std;
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pause_cout "std::cout << "|| ------------------------------------------- ||""
#define mp make_pair
#define pb push_back
#define in insert
#define ff first
#define ss second
#define iter iterator
typedef long long ll;
typedef int ii;
typedef long double ld;
const ll INF = 1e18;
const ll INF_bit = 1e9 - 1;
const ld EPS = 0.000000001;
typedef unsigned long long ull;
typedef std::string str;
#define fill(x) std::generate(x.begin(), x.end(), []() {static ll ind = 0; return ind++;})
#define rfor(i, n) for(int i=n-1;i>=1;--i)
#define all(x) (x).begin(),(x).end()
#define for_0(n) for(int i=0;i<n;++i)
#define for_1(n) for(int i=1;i<=n;++i)
#define for_2(sta, n) for(int i=sta;i<n;++i)
#define for_3(sta, n, p) for(int i=sta;i<=n;i+=p)
#define debug(x) std::cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) std::cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) std::cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {std::cerr<<#v<<" : ";for (auto x:v) std::cerr<<x<<' ';std::cerr<<endl;}
#define kill(x) return std::cout<<x<<'\n', 0;
#define sum(a)     ( std::accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*std::min_element((a).begin(), (a).end()))
#define maxe(a)    (*std::max_element((a).begin(), (a).end()))
#define mini(a)    ( std::min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( std::max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( std::lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( std::upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

class Solve {
    vll generateSieve(const ll &n = 1e6) {
        vll primes;
        vll mind(n);

        std::generate(mind.begin(), mind.end(), []() {
            static long long ind = 0;
            return ind++;
        });

        for (long long k = 2; k <= n; ++k) {
            if (mind[k] == k) { primes.push_back(k); }
            for (auto p:primes) {
                if (k * p <= n)
                    if (p <= mind[k])
                        mind[p * k] = p;
                    else
                        break;
                else
                    break;
            }
        }
        return primes;
    }

    std::vector<long long> primes = generateSieve();
    vvll phi_c;

    ull count_30(ull x) {
        return x - x / 2 - x / 3 + x / 6 - x / 5 + x / 10 + x / 15 - x / 30;
    }

    ll phi(ull x, ull a, int s = +1) {
        switch (a) {
            case 0:
                return s * x;
            case 1:
                return s * (x - x/2);
            case 2:
                return s * (x - x/2 - x/3 + x/6);
        }
        if (x < phi_c.size() && a < phi_c[x].size())
            return s * phi_c[x][a];
        ull res = 0;
        while (a > 3) {
            if (a < primes.size() && x < primes[a]) return res + s;
            --a;
            res += phi(x / primes[a], a, -s);
        }
        return res + s * count_30(x);
    }

    ull pi(ull x) {
        if (x < primes.back())
            return uppb(primes, x);
        auto a = pi(pow(x, (double) 1/4));
        auto b = pi(pow(x, (double) 1/2));
        auto c = pi(pow(x, (double) 1/3));
        auto res = phi(x, a) + (b + a - 2) * ( b - a + 1) / 2;
        for_2(a, b) {
            res -= pi(x / primes[i]);
            if (i < c)
                for (auto j = i; j < pi(std::pow(x / primes[i], (double) 1 / 2)); j++)
                    res -= pi((x / primes[i]) / primes[j]) - j;
        }
        return res;
    }
public:
    ll ans;

    Solve(const ll &n) {
        ans = pi(n);
    }
};

int main() {
    ll n;
    std::cin >> n;
    Solve solve(n);
    std::cout << solve.ans;
}