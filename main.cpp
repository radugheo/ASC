#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin  ("asc.in");
ofstream cout ("asc.out");

int n, m, ok;
int x[110], v[110], f[110];

void print (){
    int i;
    for (i=1; i<=3*n; i++){
        cout << x[i] << " ";
    }
    cout << "\n";
}

bool verif (int k){
    int i, j;
    for (i=1; i<=k; i++){
        if (v[i] != 0 && v[i] != x[i]){
            return false;
        }
    }
    for (i=1; i<=k; i++){
        for (j=i+1; j<=k && j<=i+m; j++){
            if (x[i] == x[j])
                return false;
        }
    }
    return true;
}

void bkt (int k){
    int i;
    for (i=1; i<=n; i++){
        if (f[i] == 3){
            continue;
        }
        x[k] = i;

        if (verif(k)){
            f[i]++;
            if (k == 3*n){
                print();
                ok = 1;
                return;
            }
            else{
                bkt(k+1);
            }
            f[i]--;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=3*n; i++)
        cin >> v[i];
    bkt(1);
    if (ok == 0){
        cout << -1;
    }
    return 0;
}
