#include <iostream>
#include <vector>

int potencia(int n, int k, int m) {
    if (k == 0) return 1;
    else {
        //return 2;
        int res = potencia(n,k/2,m);
        if (k%2 == 0) return (res*res);
        else return (((res*res)%m)*n);
    }
}

int main() {
    int n, k, m;
    while (std::cin >> n >> k >> m) {
        std::cout << potencia(n,k,m) << std::endl;
    }
}