/*
** EPITECH PROJECT, 2020
** liblinked
** File description:
** Header file
*/

#ifndef LINKED_H_
#define LINKED_H_

typedef struct linked_list {
    void *data;
    void *next;
} linked_list_t;

typedef struct dictionary {
    void *data;
    void *next;
    char *index;
} dictionary_t;

// Linked Lists

linked_list_t *ll_add(linked_list_t *list, void *value, int index);
linked_list_t *ll_append(linked_list_t *list, void *value);
linked_list_t *ll_prepend(linked_list_t *list, void *value);
void *ll_get(linked_list_t *list, int index);
int ll_len(linked_list_t *list);
linked_list_t *ll_shift(linked_list_t *list);
linked_list_t *ll_pop(linked_list_t *list);
linked_list_t *ll_remove(linked_list_t *list, int index);
void ll_destroy_content(linked_list_t *list);
void ll_destroy(linked_list_t *list);
void ll_set(linked_list_t *list, int index, void *value);
linked_list_t *ll_swap(linked_list_t *list, int i1, int i2);
void ll_free(linked_list_t *list, void (free_content)(void *));
void ll_v_destroy(void *list);
void ll_v_destroy_c(void *list);
linked_list_t *ll_concat(linked_list_t *a, linked_list_t *b);

// Dictionaries

dictionary_t *dict_add(dictionary_t *dict, char *index, void *value);
dictionary_t *dict_add_before(dictionary_t *dict, char *key, void *value,
    char *before);
dictionary_t *dict_add_after(dictionary_t *dict, char *key, void *value,
    char *after);
void dict_destroy(dictionary_t *dict);
dictionary_t *dict_remove(dictionary_t *dict, char *index);
void *dict_get(dictionary_t *dict, char *index);
void dict_destroy_content(dictionary_t *dict);
void dict_set(dictionary_t *dict, char *index, void *value);
dictionary_t *dict_swap(dictionary_t *list, int i1, int i2);
void no_free(void *a);
void dict_free(dictionary_t *dict, int free_index,
    void (free_content)(void *));
int dict_len(dictionary_t *dict);

#endif /* !LINKED_H_ */