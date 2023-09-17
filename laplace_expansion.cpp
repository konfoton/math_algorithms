#include <iostream>
#include <vector>
using namespace std;
/*
This program will calculate roots for linear system with any number variables.
Sorry for not creating GUI but it is exteremly boring. 
modify coeficient in this way:
A1x + B1y + C1z + ... = A
A2x + B2y + C2z + ... = B
A3x + B3y + C3z + ... = C
:
:
In values input {A, B, C, ...}
In coefficient write {A1, B1, A2, ...}
*/
vector<vector<float>> coefficients = {
    {0.5, 1, 1},
    {1, 2, 1},
    {6, 1, 8}
};
vector<int> values = {
    1, 1, 1
};
float determinant(vector<vector<float>> matrix) {
    if (matrix.size() == 2)  {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    float sum, sign;
    sign = 1;
    sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        vector<vector<float>> copied_matrix = matrix;
        copied_matrix.erase(copied_matrix.begin() + 0);
        for (int j = 0; j < matrix.size() - 1; j++) { 
            copied_matrix[j].erase(copied_matrix[j].begin() + i);
        }
        sum += sign * matrix[0][i] * determinant(copied_matrix);
        sign *= -1;
        
    }
    return sum;
}
int main() {
    float W = determinant(coefficients);
    for (int i = 0; i < values.size(); i++) {
        vector<vector<float>> changed = coefficients;
        for (int j = 0; j < values.size(); j++) {
            changed[j][i] = values[i];
        }
        cout << i + 1 << " solution is equal to " << determinant(changed) / W << endl;
    } 
return 0;
}
