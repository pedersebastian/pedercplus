#include <Rcpp.h>
#include <algorithm>
using namespace Rcpp;

//' Summer alle elementer i en numerisk vektor
//'
//' @param x En numerisk vektor
//' @return Summen av alle elementer
//' @export
// [[Rcpp::export]]
double sum_cpp(NumericVector x) {
    double total = 0;
    for (int i = 0; i < x.size(); i++) {
        total += x[i];
    }
    return total;
}

//' Versjon 1: std::transform med ::tolower
//' @param x En tekststreng
//' @return Strengen med små bokstaver
//' @export
// [[Rcpp::export]]
String to_lower_v1(String x) {
    std::string s = x;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

//' Versjon 2: manuell loop med ASCII-aritmetikk
//' Store bokstaver A-Z har ASCII 65-90, små a-z har 97-122 (avstand 32)
//' @param x En tekststreng
//' @return Strengen med små bokstaver
//' @export
// [[Rcpp::export]]
String to_lower_v2(String x) {
    std::string s = x;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

//' Versjon 3: range-based for-loop med referanse
//' @param x En tekststreng
//' @return Strengen med små bokstaver
//' @export
// [[Rcpp::export]]
String to_lower_v3(String x) {
    std::string s = x;
    for (char& c : s) {
        c = std::tolower(c);
    }
    return s;
}

//' Simuler en AR(1)-prosess
//'
//' Hvert steg: x(t) = phi * x(t-1) + støy.
//' Fordi hvert steg avhenger av forrige kan ikke R vektorisere dette.
//'
//' @param n   Antall tidssteg
//' @param phi Autokorrelasjon (-1 til 1). 0.9 = treg mean-reversion
//' @param sigma Standardavvik på støyen
//' @return Numerisk vektor av lengde n
//' @export
// [[Rcpp::export]]
NumericVector ar1_cpp(int n, double phi, double sigma) {
    NumericVector x(n);
    x[0] = 0.0;
    for (int i = 1; i < n; i++) {
        x[i] = phi * x[i - 1] + R::rnorm(0, sigma);
    }
    return x;
}
