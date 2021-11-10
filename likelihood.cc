#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>


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
std::vector<double> likelihood_scan(std::vector<int> daten){
    std::ofstream fout("likelihood.txt");
    std::ofstream fout2("nll.txt");
    std::ofstream fout3("deltanll.txt");
    std::vector<double> likelihoods(61);
    std::vector<double> likelihoods_delta(61);
    for(int i=0;i<=60;i++){
        double mu=i*0.1;
        likelihoods[i]=prob(daten,mu);
        likelihoods_delta[i]=-2*log(likelihoods[i])+2*log(prob(daten,3.11538));
        fout<<mu<<"  "<<likelihoods[i]<<std::endl;
        fout2<<mu<<"  "<<-2*log(likelihoods[i])<<std::endl;
        fout3<<mu<<"  "<<likelihoods_delta[i]<<std::endl;
    }
    fout.close();
    fout2.close();
    fout3.close();
    return likelihoods_delta;
}
 double minimum(std::vector<double> likelihood_vec){
    int index=std::min_element(likelihood_vec.begin(),likelihood_vec.end())-likelihood_vec.begin();
    double min_mean=index*0.1;

    return min_mean;


}
double z(std::vector<int> daten,double mu){
    double L_0=prob(daten,mu);
    double L = 1;
    for(int i : daten){
        L=L*pow(i,i)*exp(-i)/tgamma(i+1);
    }
    std::cout<<-2*log(L_0/L)<<std::endl;
    return (-2*log(L_0/L)-233)/(sqrt(2*233));
}

int main() {
    double mu=3.11538;
    std::vector<int> data =creating_vector();
    double L=prob(data,mu);
    std::cout<<L<<std::endl;
    std::vector<double> likelihood_vec=likelihood_scan(data);
    double min_mu=minimum(likelihood_vec);
    double z_value=z(data,min_mu);
    std::cout<<z_value<<std::endl;
}