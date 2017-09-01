#include <stdlib.h>
#include <stdio.h>
#include "can_place_flowers.h"

/** can_place_flower
  *
  * Given a flowerbed (represented as an array containing 0 and 1, where 0
  * means empty and 1 means not empty), and a number n, return if n new flowers
  * can be planted in it without violating the no-adjacent-flowers rule.
  * Notes:
  *     The input array won't violate no-adjacent-flowers rule.
  *     The input array size is in the range of [1, 20000].
  *     n is a non-negative integer which won't exceed the input array size.
  * @params:
  *     flowerbed: an array containing 0 and 1 representing the flowerbed.
  *     flowerbed_size: the size of the array flowerbed.
  *     n: the number of flowers to be placed.
  * @return:
  *     int: 1 | 0
*/
int can_place_flowers(int * flowerbed, int flowerbed_size, int n) {
    int index = 0;
    int current_ground;
    while(index < flowerbed_size && n > 0) {
        current_ground = flowerbed[index];
        // Current ground is non-empty, move over two spaces because of the
        // no-adjacent-flowers rule.
        if (current_ground) {
            index += 2;
            continue;
        }
        // Current ground is empty, so check for the no-adjacent-flowers rule.
        // If we're at the edge, just "place" a flower.
        else if (index == flowerbed_size - 1 || !flowerbed[index + 1]) {
            n--;
            index += 2;
            continue;
        }
        // Current ground is empty, but there's a flower up-next, move 3 spaces.
        index += 3;
    }

    if (n > 0) {
        return 0;
    }
    return 1;
}
