typedef struct dict_element {
    char * key;
    void * value;
} DictionaryElement;

typedef struct dict {
    DictionaryElement * elements;
    unsigned int size;
    unsigned int used;
} Dictionary;

Dictionary * init_dict(unsigned int,int *);
void upsert_dict(Dictionary *, char *,void *,int,int *);
void * get_dict(Dictionary *,char *, int, int *);
