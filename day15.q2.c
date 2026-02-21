#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int row0 = 0, col0 = 0;

    // Check first column
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            col0 = 1;
            break;
        }
    }

    // Check first row
    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            row0 = 1;
            break;
        }
    }

    // Mark zero rows and columns
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes using markers
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero first column
    if(col0) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    // Zero first row
    if(row0) {
        for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Output matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
