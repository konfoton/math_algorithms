#include <iostream>
class simple { 
    public:
    static int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n *  factorial(n-1);
    }
    static int exponentiation(int a, int n) {
        if (n == 0) {
            return 1;
        }
        return a * exponentiation(a, n - 1);
    
    }
    static int binomial_theorem(int n, int k) {
        return simple::factorial(n) / (simple::factorial(k) * simple::factorial(n- k));
    }
    static int bernullis_diagram(int p, int k, int n) {
        return simple::binomial_theorem(n, k) * simple::exponentiation(p, k) * simple::exponentiation(1 - p, n - k);
    }
    static float function(float x ) {
        return x * x - 2;
    }
    static float dfunction(float x ) {
        return 2 * x;
    }
    static float trapezoidal_rule(float a, float b, float accuracy = 10000) {
        float sum = simple::function(a) + simple::function(b);
        float step = (b - a) / accuracy;
        float current_step = a;
        for (int x = 1; x < accuracy; x++) {
            current_step += step;
            sum += 2 * simple::function(current_step);
        }
        return sum * step / 2;
    
    }
    /*
    Assumptions:
    1. between [a, b] there is only one solution
    2. f(a) * f(b) < 0 
    3. sign of df(x) / dx is constant
    4. sign of d ^ 2 f(x) / d x ^ 2 is constant 
    */
    static float newton_raphson(int iterations) {
        float root = -10;
        for (int x = 1; x <= iterations; x++) {
            root = root - simple::function(root) / simple::dfunction(root);
        }
    return root;
    }
};
int main() {
    std::cout << simple::newton_raphson(1000);
    return 0;
}