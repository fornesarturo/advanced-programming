#include <stdlib.h>
#include <stdio.h>
#include "island_perimeter.h"

/** island_perimeter 
  * Receives a bidimensional array of 0's and 1's that represent
  * an islands area, where there's a 1, there's land, and where
  * there's a  0, there's water. The array is always rectangular.
  * Returns the perimeter of the island.
  * @param:
  *   island: the bidimensional array that represents the island.
  *   row_size: the amount of rows in island.
  *   col_size: the amount of columns in island.
  * @return:
  *   int: perimeter of the island.
 */
int island_perimeter(int ** island, int row_size, int col_size) {
	int perimeter = 0, i, j, temp_perimeter;
	for (i = 0; i < row_size; i++) {
		for (j = 0; j < col_size; j++) {
			temp_perimeter = 4;
			if (island[i][j] == 0) {
				temp_perimeter = 0;
			}
			else {
				if (i != 0) {
					temp_perimeter -= island[i - 1][j];
				}
				if (i != row_size - 1) {
					temp_perimeter -= island[i + 1][j];
				}
				if (j != 0) {
					temp_perimeter -= island[i][j - 1];
				}
				if (j != col_size - 1) {
					temp_perimeter -= island[i][j + 1];
				}
			}
			perimeter += temp_perimeter;
		}
	}

	return perimeter;
}
