#include <stdlib.h>
#include <stdio.h>
#include "dict.h"

/** init_dict
  * Receives the maximum number of elements in the Dictionary and a pointer
  * to an integer to save an error code.
  * @param:
  *     size: maximum number of elements.
  *     error_code: address in which to save the error code.
  * @return:
  *     Dictionary *: a pointer to the newly initialized dictionary or NULL.
  *
*/
Dictionary * init_dict (unsigned int size, int * error_code) {
    * error_code = 0;
    Dictionary * new_dictionary = (Dictionary *) calloc(1, sizeof(Dictionary));
    if (new_dictionary == NULL) {
        * error_code = 100;
        return NULL;
    }
    new_dictionary->elements = (DictionaryElement *) calloc(size, sizeof(DictionaryElement));
    if (new_dictionary->elements == NULL) {
        * error_code = 200;
        return NULL;
    }
    new_dictionary->size = size;
    new_dictionary->used = 0;
    return new_dictionary;
}

// Form and return the hash value for string s.
static unsigned int hash (char *s, unsigned int size) {
    unsigned int hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % size;
}

void upsert_dict (Dictionary * dict, char * key, void * value, int * error_code) {
    if (dict == NULL || key == NULL || value == NULL || dict->elements == NULL) {
        *error_code = 100;
        return;
    }
    if (dict->used == dict->size) {
        *error_code = 500;
        return;
    }
    unsigned int index = hash(key, dict->size);
    if (dict->elements[index].key == NULL) {
        dict->elements[index].key = key;
        dict->elements[index].value = value;
        dict->used += 1;
    } else {
        while(dict->elements[++index].key == NULL) {
            dict->elements[index].key = key;
            dict->elements[index].value = value;
            dict->used += 1;
        }
    }

    *error_code = 0;

}
