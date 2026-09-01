#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <climits>
int cubic(int* l, int n){
    int best = INT_MIN;
    for (int i=0;i<n;++i){
        for (int j=i;j<n;++j){
            int add = 0;
            for (int k=i;k<=j;++k){
                add += l[k];
            }
            if (add>best) best = add;
        }
    }
    return best;
}
int quadratic(int* l, int n){
    int best = INT_MIN;
    for (int i=0;i<n;++i){
        int add = 0;
        for (int j=i;j<n;++j){
            add += l[j];
            if (add > best) best = add;
        }
    }
    return best;
}
int kadane(int* l, int n){
    int here = l[0];
    int global = l[0];
    for (int i=1;i<n;++i){
        here = std::max(l[i], here + l[i]);
        global = std::max(global, here);
    }
    return global;
}
int* randomArray(int n, int lo, int hi){
    int* l = new int[n];
    for (int i=0;i<n;++i){
        l[i] = lo+rand() % (hi-lo+1);
    }
    return l;
}
void verify(){
    srand(42);
    int fails = 0;
    for (int t=1;t<=100;++t){
        int n = 1+rand() % 50;
        int* a = randomArray(n, -100, 100);
        int r1 = cubic(a, n);
        int r2 = quadratic(a, n);
        int r3 = kadane(a, n);
        if (r1!=r2 || r2!=r3){
            fails++;
            std::cout << "mismatch prueba " << t << ": " << r1 << " " << r2 << " " << r3 << "\n";
        }
        delete[] a;
    }
    std::cout << (100 - fails) << "/100 pruebas coinciden\n";
}
std::string cell(bool active, double ms){
    if (!active) return "N/A";
    std::ostringstream out;
    out << std::fixed << std::setprecision(3) << ms;
    return out.str();
}
void measure(){
    srand(123);
    const double LIMIT_MS = 5000.0;
    const int N_MAX = 100000000;
    bool cubic_active = true;
    bool quadratic_active = true;
    bool kadane_active = true;
    std::cout << "\n";
    std::cout << std::left << std::setw(12) << "      n" << "| " << std::setw(14) << " cubica(ms)" << "| " << std::setw(14) << "cuadratica(ms)" << "| " << std::setw(14) << " kadane(ms)" << "\n";
    std::cout << std::string(58, '-') << "\n";
    int n = 1000;
    bool last_step = false;
    while (true){
        if (!cubic_active && !quadratic_active && !kadane_active) break;
        int* a = randomArray(n, -1000, 1000);
        volatile int sink;
        double ms_cubic = 0, ms_quadratic = 0, ms_kadane = 0;
        bool measured_cubic = false, measured_quadratic = false, measured_kadane = false;
        if (cubic_active){
            auto t0 = std::chrono::high_resolution_clock::now();
            sink = cubic(a, n);
            auto t1 = std::chrono::high_resolution_clock::now();
            ms_cubic = std::chrono::duration<double, std::milli>(t1 - t0).count();
            measured_cubic = true;
            if (ms_cubic > LIMIT_MS) cubic_active = false;
        }
        if (quadratic_active){
            auto t0 = std::chrono::high_resolution_clock::now();
            sink = quadratic(a, n);
            auto t1 = std::chrono::high_resolution_clock::now();
            ms_quadratic = std::chrono::duration<double, std::milli>(t1 - t0).count();
            measured_quadratic = true;
            if (ms_quadratic > LIMIT_MS) quadratic_active = false;
        }
        if (kadane_active){
            auto t0 = std::chrono::high_resolution_clock::now();
            sink = kadane(a, n);
            auto t1 = std::chrono::high_resolution_clock::now();
            ms_kadane = std::chrono::duration<double, std::milli>(t1 - t0).count();
            measured_kadane = true;
            if (ms_kadane > LIMIT_MS) kadane_active = false;
        }
        std::cout << std::left << std::setw(12) << n << "| " << std::setw(14) << cell(measured_cubic, ms_cubic) << "| " << std::setw(14) << cell(measured_quadratic, ms_quadratic) << "| " << std::setw(14) << cell(measured_kadane, ms_kadane) << "\n";
        delete[] a;
        if (last_step) break;
        if (n >= N_MAX) break;
        n *= 2;
        if (n>N_MAX){
            n = N_MAX;
            last_step = true;
        }
    }
}
int main(){
    verify();
    measure();
    return 0;
}
