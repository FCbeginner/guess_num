#include <iostream>
#include <cmath>

using namespace std;

double worst_Case_divide_two(int n);
double worst_Case_divide_three(int n);
double simulation_avg(int n, int divided_num);

int main(){
    int n;
    cout << "Guess number" << "\n";
    cout << "--------------------------------------------\n";
    cout << "welcome to Guess Number!" << "\n" << "This is a simulation program" << "\n" << "to compare worst case and average case" << "\n" << "of two different guessing strategies." << "\n";
    cout << "--------------------------------------------\n";
    while (1){
        cout<< "N = ";
        cin >> n;
        if (n <= 0){
            cout << "\n" << "Exit the program." << "\n";
            break;
        }
        double times_w_1 = worst_Case_divide_two(n);
        double times_w_2 = worst_Case_divide_three(n);
        double times_a_1 = simulation_avg(n, 2);
        double times_a_2 = simulation_avg(n, 3);
        cout << "小華's version" << "\t" << times_w_1 << "\t" << times_a_1 << "\n";
        cout << "小英's version" << "\t" << times_w_2 << "\t" << times_a_2 << "\n";
        cout << "--------------------------------------------\n";
    }
    return 0;
}

double worst_Case_divide_two(int n){
    return log2(n);
}

double worst_Case_divide_three(int n){
    return log10(n) / (log10(3) - log10(2));
}

double simulation_avg(int n, int divided_num){
    int sum_steps = 0;
    for (int i=1; i<=n; i++){
        int l=1, r=n, g;
        while (l<=r){
            g = (l+r) / divided_num;
            sum_steps++;
            if (i == g) break;
            else if (i > g) l = g + 1;
            else if (i < g) r = g - 1;
            else if (l > r) cout << "error" << "\n";
        }
    }
    return sum_steps / n;
}