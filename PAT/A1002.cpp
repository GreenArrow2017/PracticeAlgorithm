#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, float> poly1;

int main() {
    for (int i = 0; i < 2; ++i) {
        int n1;
        scanf("%d", &n1);
        for (int i = 0; i < n1; ++i) {
            int exp;
            float cof;
            scanf("%d%f", &exp, &cof);
            poly1[exp] += cof;
        }
    }
    vector<pair<int, float> > res;
    for (map<int, float>::reverse_iterator it = poly1.rbegin(); it != poly1.rend(); it++) {
        if (it->second != 0) // 两个系数和为0的得过滤掉
            res.push_back(make_pair(it->first, it->second));
    }

    printf("%lu", res.size());
    for (int i = 0; i < res.size(); ++i) {
        printf(" %d %.1f", res[i].first, res[i].second);
    }
    return 0;
}