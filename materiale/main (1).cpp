#include <bits/stdc++.h>

using namespace std;
const int NMAX = 31;

bool stop;
int N, M;
int v[NMAX * 3], cnt[NMAX];

bool checkArray(){
    for(int i = 0; i < 3 * N; i++){
        if(!v[i])
            continue;
        for(int j = 1; j <= M; j++){
            if(i + j < 3 * N && v[i + j] == v[i])
                return false;
            if(i - j >= 0 && v[i - j] == v[i])
                return false;
        }
    }
    return true;
}

void bkt(int n){
    if(stop)
        return;

    if(n >= 3 * N){
        stop = true;
        for(int i = 0; i < 3 * N; i++)
            printf("%d ", v[i]);
        printf("\n");

        return;
    }

    if(v[n]){
        bkt(n + 1);
        return;
    }

    for(int i = 1; i <= N && !stop; i++){
        if(cnt[i] == 3)
            continue;

        bool ok = true;
        for(int j = 1; j <= M; j++){
            if(n + j < 3 * N && v[n + j] == i){
                ok = false;
                break;
            }
            if(n - j >= 0 && v[n - j] == i){
                ok = false;
                break;
            }
        }
        if(!ok)
            continue;

        cnt[i]++;
        v[n] = i;
        bkt(n + 1);
        cnt[i]--;
        v[n] = 0;
    }
}

void solve(){
    if(!checkArray() || N <= M){
        printf("-1");
        return;
    }

    bkt(0);
}

void read(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i < 3 * N; i++){
        scanf("%d", &v[i]);
        if(v[i])
            cnt[v[i]]++;
    }
}

int main(){

    freopen("asc.in", "r", stdin);
    freopen("asc.out", "w", stdout);

    read();
    solve();

    return 0;
}
