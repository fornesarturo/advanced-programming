#include <stdlib.h>
#include <stdio.h>
#include "island_perimeter.h"

int island_perimeter(int ** grid, int row_size, int col_size) {
	int perimeter = 0, i, j, temp_perimeter;
	for (i = 0; i < row_size; i++) {
		for (j = 0; j < col_size; j++) {
			temp_perimeter = 4;
			printf("At [%d][%d] = %d\n", i, j, grid[i][j]);
			if (grid[i][j] == 0) {
				temp_perimeter = 0;
			}
			else {
				if (i != 0) {
					temp_perimeter -= grid[i - 1][j];
					printf("\tTop %d\n", temp_perimeter);
				}
				if (i != row_size - 1) {
					temp_perimeter -= grid[i + 1][j];
					printf("\tBottom %d\n", temp_perimeter);
				}
				if (j != 0) {
					temp_perimeter -= grid[i][j - 1];
					printf("\tLeft %d\n", temp_perimeter);
				}
				if (j != col_size - 1) {
					temp_perimeter -= grid[i][j + 1];
					printf("\tRight %d\n", temp_perimeter);
				}
			}
			perimeter += temp_perimeter;
		}
	}

	return perimeter;
}
