#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::transform;
using std::minus;
using std::plus;

void printVector(const vector<vector<int>> a) {
    int x = a.size();
    int y = a[0].size();

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

vector<vector<int>> strassen(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    if (n == 1) {
        vector<vector<int>> b;
        b.push_back({0});
        return b;
    }
    int k = n/2;
    vector<int> internalVector(k, 0);
    vector<vector<int>> A(k, internalVector);
    vector<vector<int>> B(k, internalVector);
    vector<vector<int>> C(k, internalVector);
    vector<vector<int>> D(k, internalVector);
    vector<vector<int>> E(k, internalVector);
    vector<vector<int>> F(k, internalVector);
    vector<vector<int>> G(k, internalVector);
    vector<vector<int>> H(k, internalVector);

    for (int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            A[i][j] = a[i][j];
            B[i][j] = a[i][k + j];
            C[i][j] = a[i + k][j];
            D[i][j] = a[i + k][j + k];
            E[i][j] = b[i][j];
            F[i][j] = b[i][j + k];
            G[i][j] = b[i + k][j];
            H[i][j] = b[i + k][j + k];
        }
    }

    vector<vector<int>> P1(k, internalVector);
    vector<vector<int>> P2(k, internalVector);
    vector<vector<int>> P3(k, internalVector);
    vector<vector<int>> P4(k, internalVector);
    vector<vector<int>> P5(k, internalVector);
    vector<vector<int>> P6(k, internalVector);
    vector<vector<int>> P7(k, internalVector);

    P1 = strassen(A, transform(F.begin(), F.end(), H.begin(), H.end(), minus<int>()));
    P2 = strassen(transform(A.begin(), A.end(), B.begin(), B.end(), plus<int>()), H);       
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> a, b;

    /*
        a = [1, 2]
            [3, 4]

        b = [5, 6]
            [7, 8]
    */

    a.push_back({1, 2});
    a.push_back({3, 4});

    b.push_back({5, 6});
    b.push_back({7, 8});

    std::cout << "X" << std::endl;
    printVector(a);

    std::cout << "Y" << std::endl;
    printVector(b);

    
    return 0;
}
