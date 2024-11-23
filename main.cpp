#include <iostream>

const int maxn = 10;

bool is_equivalence(int n, bool rel[maxn][maxn]) {
    for (int i = 0; i < n; i += 1) { //reflexive
        if (rel[i][i] != 1) {
            return false;
        }
        for (int j = 0; j < n; j += 1) { //symmetrical
            if (rel[i][j] != rel[j][i]) {
                return false;
            }
            for (int k = 0; k < n; k += 1) { //transitive
                if (rel[i][j] == 1 && rel[j][k] == 1 && rel[i][k] != 1) {
                    return false;
                }
            }
        }
    }
    return true;
}

void print(int n, bool rel[maxn][maxn]) {
	for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            std::cout << rel[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void generator(int n, bool rel[maxn][maxn], int i, int j, int &count) {
    if (i == n) {
        if (is_equivalence(n, rel)) {
            count += 1;
            print(n, rel);
        }
        return;
    }
    if (j == n) {
        generator(n, rel, i + 1, 0, count);
        return;
    }
    rel[i][j] = 0;
    generator(n, rel, i, j + 1, count);
    rel[i][j] = 1;
    generator(n, rel, i, j + 1, count);
}

int main() {
    int n;
    std::cin >> n;
    if (n > maxn) {
        std::cerr << "вводи меньше";
        return 1;
    }
    bool rel[maxn][maxn];
    int count = 0;
    generator(n, rel, 0, 0, count);
    std::cout << count;
    return 0;
}  