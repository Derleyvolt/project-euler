#include <bits/stdc++.h>

using namespace std; 

#define vi vector<int>

// O código poderia ficar bem menor, mas preferi deixar tudo modularizado.

vector<vi> matrix;

int dim = 20;

vi read_column(int n) {
    vi ans;
    int idx = 0;
    while(idx < dim)
        ans.push_back(matrix[idx++][n]);
    return ans;
}

vi read_line(int n) {
    vi ans;
    int idx = 0;
    while(idx < dim)
        ans.push_back(matrix[n][idx++]);
    return ans;
}

vi right_diagonal(int r, int c) {
    vi ans;
    while(r < dim and c < dim)
        ans.push_back(matrix[r++][c++]);
    return ans;
}

vi left_diagonal(int r, int c) {
    vi ans;
    while(r < dim and c >= 0)
        ans.push_back(matrix[r++][c--]);
    return ans;
}

int sliding_window(vector<int> arr, int w = 4) {
    int length = arr.size();
    if(w > length)
        return 0;
    int ans  = 0;
    int temp = 1;
    for(int i = 0; i < w; i++)
        temp *= arr[i];
    ans = max(ans, temp);
    for(int i = 0; i < length - w; i++) {
        temp = temp * arr[i + w] / (arr[i] + (arr[i] == 0));
        ans  = max(ans, temp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    matrix.resize(dim);
    for(auto& a:matrix) a.resize(dim);

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int ans = 0;

    for(int i = 0; i < dim; i++) {
        // ler linhas e colunas
        ans = max(ans, sliding_window(read_line(i)));
        ans = max(ans, sliding_window(read_column(i)));
        for(int j = 0; j < dim; j++) {
            // ler as diagonais
            ans = max(ans, sliding_window(right_diagonal(i, j)));
            ans = max(ans, sliding_window(left_diagonal(i, j)));
        }
    }
    
    cout << ans << endl;
    return 0;
}
