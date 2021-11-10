#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>


double poisson(double mu, int k) {
    double P= pow(mu,k)*exp(-mu)/tgamma(k+1);
    return P;
}

std::vector<int> counting() {
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
    return zaehler;
}

void creating_histo(std::vector<int> counts){
    double mu=3.11538;
    int sum =std::accumulate(counts.begin(),counts.end(),0);
    std::ofstream fout("hist.txt");
    std::ofstream fout2("histpoi.txt");
    for(int i=0;i<counts.size();i++){
        fout<<i<<"  "<<counts[i]<<std::endl;
        fout2<<i<<"  "<<counts[i]<<"  "<<poisson(mu,i)*sum<<std::endl;
    }
}
int main(){
    std::vector<int> counts=counting();
    creating_histo(counts);
}
