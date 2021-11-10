#include <iostream>
#include <fstream>
#include <vector>


double poisson(double mu, int k) {
    return 0;
}

void counting() {
    std::vector<int> zaehler(11);
    std::ifstream fin("datensumme.txt");
    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i]+=1;

    }
    fin.close();
    for(int j=0;j<zaehler.size();j++){
      std::cout<<j<<":"<<zaehler[j]<<std::endl;
    }
}
int main(){
    counting();
}
