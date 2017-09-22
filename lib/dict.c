#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void upsert_dict (Dictionary *dictionary, char *key, void *value, int size, int *error_code) {
    if (dictionary == NULL || dictionary->elements == NULL || key == NULL || value == NULL || size <= 0) {
        *error_code = 100;
        return;
    }

    int index = hash(key, dictionary->size);
    dictionary->elements[index].key = key;
    dictionary->elements[index].value = malloc(size);
    if(dictionary->elements[index].value == NULL){
        *error_code = 100;
        return;
    }
    memcpy(dictionary->elements[index].value, value,size);
    *error_code = 0;
}

void * get_dict (Dictionary *dictionary,char *key,int size, int *error_code) {
    if (dictionary == NULL || dictionary->elements == NULL || key == NULL || size <= 0) {
        *error_code = 100;
        return NULL;
    }
    * error_code = 0;

    int index = hash(key, dictionary->size);
    if (dictionary->elements[index].key == 0) {
        return NULL;
    }
    void *result = malloc(size);
    if (result == NULL) {
        *error_code = 100;
        return NULL;
    }
    memcpy(result, dictionary->elements[index].value, size);
    if (result == NULL || dictionary->elements[index].value == NULL) {
        return NULL;
    }
    return result;
}
