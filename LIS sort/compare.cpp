#include "bits/stdc++.h"
#include "testlib.h"
#include "lis_sort.h"
using namespace std;

const int val = 1000000;
const int num = 20;

long long test_naive(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    naive(vec);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_opt1(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    optimization_1(vec);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_opt2(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    optimization_2(vec);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_opt3(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    optimization_3(vec);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_sort(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    sort(vec.begin(), vec.end());
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_stable(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    stable_sort(vec.begin(), vec.end());
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_heap(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    make_heap(vec.begin(), vec.end());
    sort_heap(vec.begin(), vec.end());
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

long long test_merge(int n, int a){
    vector<int> vec(n);

    if(a == 0) for(int &i : vec) i = rnd.next(1, val);
    else if(a == 1) iota(vec.begin(), vec.end(), rnd.next(1, val - n));
    else if(a == 2) iota(vec.begin(), vec.end(), rnd.next(1, val - n)), reverse(vec.begin(), vec.end());
    else vec.assign(n, rnd.next(1, val));

    auto start = chrono::steady_clock::now().time_since_epoch().count();
    mergeSort(vec, 0, n - 1);
    auto finish = chrono::steady_clock::now().time_since_epoch().count();

    return finish - start;
}

int main(){
    double avg;

    for(int i = 0; i < num; ++i){
        long long val = test_stable(2000000, 0);
        avg += val;
        cout << val << '\n';
    }

    avg /= 1000000000.0 * num;
    cout << fixed << setprecision(6) << avg << endl;
}
