#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define fordt(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define forde(i, a, b) for (int i = (a), _b = (b); i > _b; --i)
#define trav(a, x) for (auto& a : x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define t (double)log(V)

//#include "radix.h"

using namespace std;
using namespace __gnu_pbds;

template<class A, class B> bool maxi(A &a, const B &b) {return (a < b) ? (a = b, true):false;};
template<class A, class B> bool mini(A &a, const B &b) {return (a > b) ? (a = b, true):false;};

typedef int64_t i64;
typedef pair<int,int> _ii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
constexpr int maxn=1e8+7;
constexpr i64 oo=1e9+7;
constexpr double eps=1e-9;
int V, a[maxn], base, output[maxn], cnt[maxn], i, n;

double f(double x) {
    return (n + x) * int(log(V)/log(x) + 1);
}

int b(){
    int ans = 2, val = f(2);

    for(int i = 1; (int)pow(V, 1.0 / i) > 2; ++i){
        int cur = pow(V, 1.0 / i);
        
        if(f(cur - 1) < f(ans)) ans = cur - 1;
        if(f(cur) < f(ans)) ans = cur;
        if(f(cur + 1) < f(ans)) ans = cur + 1;
    }

    return ans;
}

///The core sorting algorithm
template<typename _iterator>
void _radix(_iterator _begin, _iterator _end, const int base){
	long long _max = LLONG_MIN;
	for(auto i = _begin; i < _end; ++i) _max = max(_max, llabs(*i));

	int loops = (log(_max) / log(base)) + 1;

	int bucket[base];
    unsigned long long div = 1;
	vector<long long> helper(_end - _begin);

	for(int pos = 0; pos < loops; ++pos){
		memset(bucket, 0, base * sizeof(int));

		for(auto it = _begin; it < _end; ++it){
			int digit = (llabs((unsigned long long)*it) / div) % base;
			++bucket[digit];
		}

		for(int i = 1; i < base; ++i) bucket[i] += bucket[i - 1];

		_iterator parser = (_end - 1);
		while(parser >= _begin){
			int digit = (llabs((unsigned long long)*parser) / div) % base;
			int i = bucket[digit] - 1;

			helper[i] = *parser;
			--bucket[digit];
			--parser;
		}

		for(int i = 0; i < (_end - _begin); ++i) *(_begin + i) = helper[i];
        div *= base;
	}

    //cout << base << ' ' << loops << endl;
}

#define NAME "test."
int main() {
    random_device rd;
    mt19937 g(rd());
    cout << fixed << setprecision(8);
    system("clear");

    n = 10000000; //1e7

    fore(i, 0, n) {
        a[i] = g();
        maxi(a[i], -a[i]);
    }

    V = *max_element(a, a + n);
    cout << "V: " << V << endl;

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    sort(a, a + n);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();
    cout << "std::sort: " << float(finish - start) / 1000000000.0 << endl;

    shuffle(a, a + n, g);

    start = chrono::steady_clock::now().time_since_epoch().count();
    _radix(a, a + n, b());
    finish = chrono::steady_clock::now().time_since_epoch().count();
    cout << "Unknown sort: " << float(finish - start) / 1000000000.0 << endl;
}