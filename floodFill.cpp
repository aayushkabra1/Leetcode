#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void fill(vector<vector<int>> &image, int sr, int sc, int newColor, int prev) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
        
        if (image[sr][sc] == prev) {
            if (prev == newColor) return;
            image[sr][sc] = newColor;
            fill(image, sr + 1, sc, newColor, prev);
            fill(image, sr, sc + 1, newColor, prev);
            fill(image, sr - 1, sc, newColor, prev);
            fill(image, sr, sc - 1, newColor, prev);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prev = image[sr][sc];
        fill(image, sr, sc, newColor, prev);
        return image;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    image = sol.floodFill(image, 1, 1, 1);
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[0].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
