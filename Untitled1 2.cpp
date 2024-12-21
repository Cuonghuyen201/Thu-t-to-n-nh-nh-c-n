#include <iostream>

using namespace std;

const int maxn = 21;
int n, S, cnt, cnt_best, sum, a[maxn], mark[maxn], mark_best[maxn], maxmoney[maxn];
int t[maxn];

void nhap_du_lieu() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
}

void tao_du_lieu() {
    
    cnt_best = n + 1; 

 
    maxmoney[n] = t[n];
    for (int i = n - 1; i >= 0; --i)
        maxmoney[i] = max(maxmoney[i + 1], t[i]);
}

void cap_nhat_giai_phap_toi_uu() {
    if (sum == S && cnt < cnt_best) {
        cnt_best = cnt;
        for (int i = 1; i <= n; ++i)
            mark_best[i] = mark[i];
    }
}

void in_ket_qua() {
    if (cnt_best == n + 1)
        cout << -1;
    else {
        cout << cnt_best << endl;
        for (int i = 1; i <= n; ++i)
            if (mark_best[i])
                cout << t[i] << ' ';
    }
}

void thuat_toan_nhanh_can(int i) {
   
    if (i > n || (maxmoney[i + 1] > 0 && cnt + (S - sum) / maxmoney[i + 1] >= cnt_best) || (maxmoney[i + 1] == 0 && sum < S))
        return;

 
    for (int j = 0; j <= 1; ++j) {
        sum += t[i] * j;
        cnt += j;
        mark[i] = j; 

        if (i == n) 
            cap_nhat_giai_phap_toi_uu();
        else if (sum <= S)
            thuat_toan_nhanh_canh(i + 1);

        sum -= t[i] * j;
        cnt -= j;
        mark[i] = 0; 
    }
}

int main() {
    nhap_du_lieu();
    tao_du_lieu();
    thuat_toan_nhanh_canh(1);
    in_ket_qua();
    return 0;
}
