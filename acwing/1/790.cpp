#include<bits/stdc++.h>
using namespace std;

double n;

double bs(double n) {
    double l = -1e4, r = 1e4;
    while(r-l>1e-8) {
        double mid = (l+r)/2;
        if(pow(mid, 3)<n) l = mid;
        else r = mid;
    }
    return l;
}
int main() {
    scanf("%lf", &n);
    printf("%.6lf", bs(n));
    return 0;
}