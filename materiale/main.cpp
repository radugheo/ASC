/// Se va genera cea mai mica permutare in sens lexicografic a multimii {1, ..., n}
/// fiecare element apare de exact 3 ori
/// avand o distanta de minimum m elemente intre oricare doua elemente egale

#include <iostream>

using namespace std;

int n, m, v[91];
int pozitii[91], aparitii[91];
int nr_elemente;


/// ca numarul sa fie bun:
/// - MINIMUL din {1, 2, ..., n} care sa respecte regulile
/// - sa fie la distanta >= m fata de "vecinii" sai egali
/// - sa apara de maxim 3 ori

void afisare()
{
    for(int j = 0; j< 3*n; j++)
        cout<<v[j]<<" ";
    cout<<endl;
}

bool check(int pozitie){
    int pozitie_anterioara = 0;
    int aparitii = 0;
    for(int i = 0; i < 3*n; i++){
        if(v[pozitie] == v[i]){
            aparitii++;
        }
    }
    if(aparitii>3){
        return false;
    }
    for(int i = pozitie-1; i>= pozitie-m;i--){
        if(v[pozitie]==v[i]){
            return false;
        }
    }
    for(int i = pozitie+1; i<= pozitie+m;i++){
        if(v[pozitie]==v[i]){
            return false;
        }
    }
    return true;

}

void backtracking(int pozitie){
        if(v[pozitie]>0)
            backtracking(pozitie+1);

        else
            for(int valoare = 1; valoare <= n; valoare++){

                    v[pozitie] = valoare;

                    if(check(pozitie)){

                        if(pozitie == nr_elemente){
                            afisare();
                            return;
                        }
                        else{
                            backtracking(pozitie + 1);
                        }
                    }else v[pozitie]=0;
            }
}

int main()
{
    cin >> n >> m;
    nr_elemente = n * 3;
    for(int i = 0; i < nr_elemente; i++)
        cin >> v[i];
    backtracking(0);
    return 0;
}
