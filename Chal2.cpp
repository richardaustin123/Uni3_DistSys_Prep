#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
    int n = a.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> a = {{1, 2}, {3, 4}};
    vector<vector<int>> b = {{5, 6}, {7, 8}};
    vector<vector<int>> result = multiply(a, b);
    for(auto& row : result) {
        for(int& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
