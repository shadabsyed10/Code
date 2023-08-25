#include <stdio.h>

unsigned long long countRoutes(int size) {
    unsigned long long grid[size + 1][size + 1];

    for (int i = 0; i <= size; ++i) {
        grid[i][size] = 1;
        grid[size][i] = 1;
    }

    for (int i = size - 1; i >= 0; --i) {
        for (int j = size - 1; j >= 0; --j) {
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
        }
    }

    return grid[0][0];
}

int main() {
    int gridSize = 20; // Change this to the desired grid size
    unsigned long long routes = countRoutes(gridSize);

    printf("Number of routes through a %dx%d grid: %llu\n", gridSize, gridSize, routes);

    return 0;
}
/*

The formula for the number of routes through an n x n grid, which is given by 
(2n)!/(n!)^2
 , can be proven using combinatorics and the properties of binomial coefficients.

Imagine a grid where you need to move from the top left corner to the bottom right corner by only moving right and down. You need to make exactly 
2n moves: 
n moves to the right and 
n moves downwards. The order in which you make these moves determines your path.

For each path, you can consider the 
n rightward moves as "R" and the 
n downward moves as "D". For example, in a 2x2 grid, you might have a path like "RRDD" or "RDRD". The total number of ways you can arrange these moves (or the total number of paths) is the number of permutations of the string "RR...RDD...D", which is 
(2n)!/n!⋅n!
However, this count includes duplicate paths because the "R"s and "D"s are indistinguishable. For instance, "RRDD" and "RDRD" represent the same path. To account for this, you divide by 
n!
⋅
n!
n!⋅n! to eliminate the duplicates, resulting in the formula 
(2n)!(n!)2(n!)2(2n)!.

In essence, the formula counts the number of ways to arrange the 
�
n rightward and 
�
n downward moves, which is equivalent to the number of paths from the top left to the bottom right corner in an 
�
×
�
n×n grid.

This formula is based on combinatorial reasoning and is a powerful tool in solving various counting problems involving paths, arrangements, and combinations.

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

unsigned long long calculateRoutes(int gridSize) {
    return factorial(2 * gridSize) / (factorial(gridSize) * factorial(gridSize));
}

int main() {
    int gridSize = 6;
    unsigned long long routes = calculateRoutes(gridSize);

    printf("Number of routes through a %dx%d grid: %llu\n", gridSize, gridSize, routes);

    return 0;
}
*/