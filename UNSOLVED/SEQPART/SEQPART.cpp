#include <iostream>
#define FILE "SEQPART" 
const int MAXL = 8008;
const int MAXG = 808;
const long long INF = (long long)1e18;

using namespace std;

long long F[MAXG][MAXL], sum[MAXL], C[MAXL];
int P[MAXG][MAXL];

long long cost(int i, int j) {
    if (i > j) return 0;
    return (sum[j] - sum[i - 1]) * (j - i + 1);
}

void solve(int g, int L, int R, int optL, int optR) {
    if (L > R) return;
    int mid = (L + R) / 2;
    F[g][mid] = INF;
    for (int i = optL; i <= optR; ++i) {
        long long new_cost = F[g - 1][i] + cost(i + 1, mid);
        if (F[g][mid] > new_cost) {
            F[g][mid] = new_cost;
            P[g][mid] = i;
        }
    }
    solve(g, L, mid - 1, optL, P[g][mid]);
    solve(g, mid + 1, R, P[g][mid], optR);
}

int main() {
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    int G, L;
    cin >> L >> G;
    for (int i = 1; i <= L; ++i) {
        cin >> C[i];
        sum[i] = sum[i - 1] + C[i];
    }
    for (int i = 1; i <= L; ++i) F[1][i] = cost(1, i);
    for (int g = 2; g <= G; ++g) solve(g, 1, L, 1, L);
    cout << F[G][L] << endl;
    return 0;
}
