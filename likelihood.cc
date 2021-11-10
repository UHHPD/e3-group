#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    return 0;
}
std::vector<int> creating_vector(){
    std::ifstream fin("datensumme.txt");
    std::vector<int> daten(234);
    for(int i=0;i<234;i++){
        fin>>daten[i];
    }
    return daten;
}
double prob(std::vector<int> daten, double mu){
    double L=1;
    for(int i: daten){
       L=L*pow(mu,i)*exp(-mu)/tgamma(i+1);
    }
    return L;
}
void likelihood_scan(std::vector<int> daten){
    std::ofstream fout("likelihood.txt");
    std::ofstream fout2("nll.txt");
    std::ofstream fout3("deltanll.txt");
    for(int i=0;i<=60;i++){
        double mu=i*0.1;
        fout<<mu<<"  "<<prob(daten,mu)<<std::endl;
        fout2<<mu<<"  "<<-2*log(prob(daten,mu))<<std::endl;
        fout3<<mu<<"  "<<-2*log(prob(daten,mu))+2*log(prob(daten,3.11538))<<std::endl;
    }
    fout.close();
    fout2.close();
    fout3.close();
}
int main() {
    double mu=3.11538;
    std::vector<int> data =creating_vector();
    double L=prob(data,mu);
    std::cout<<L<<std::endl;
    likelihood_scan(data);

}