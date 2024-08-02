#include <iostream>
#include <vector>
#include <algorithm>
#define IO ios::sync_with_stdio(0);cin.tie(0);

using namespace std;
using ll = long long;

struct Q{
    int start, end, index;
};

int main(){ IO;
    int n, t, sq_n, start, end, left, right;
    ll p = 0;
    vector<ll> a, subarray_power, count(1000001);
    vector<Q> quary;
    cin >> n >> t;
    a.resize(n);
    for(ll &ai: a){
        cin >> ai;
    }
    subarray_power.resize(t);
    quary.resize(t);
    for(int i = 0; i < t; i++){
        cin >> quary[i].start >> quary[i].end;
        quary[i].start--;
        quary[i].end--;
        quary[i].index = i;
    }
    for(sq_n = 1; (sq_n + 1) * (sq_n + 1) <= n; sq_n++);
    sort(quary.begin(), quary.end(), 
        [sq_n](Q q1, Q q2) -> bool {
            return q1.start / sq_n == q2.start / sq_n ? q1.end < q2.end : q1.start < q2.start;
        }
    );
    left = quary[0].start;
    right = left - 1;
    for(int i = 0; i < t; i++){
        start = quary[i].start;
        end = quary[i].end;
        for(;start < left;){
            p -= count[a[--left]] * count[a[left]] * a[left];
            p += ++count[a[left]] * count[a[left]] * a[left];
        }
        for(;end > right;){
            p -= count[a[++right]] * count[a[right]] * a[right];
            p += ++count[a[right]] * count[a[right]] * a[right];
        }
        for(;start > left;){
            p -= count[a[left]] * count[a[left]] * a[left];
            p += --count[a[left]] * count[a[left]] * a[left++];
        }
        for(;end < right;){
            p -= count[a[right]] * count[a[right]] * a[right];
            p += --count[a[right]] * count[a[right]] * a[right--];
        }
        subarray_power[quary[i].index] = p;
    }
    for(ll sp: subarray_power){
        cout << sp << '\n';
    }
    return 0;
}