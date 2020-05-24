#pragma once

#ifndef LAB1_ARRAY_OBJECT_H
#define LAB1_ARRAY_OBJECT_H

typedef enum {INT_ARR, CHAR_ARR} array_type;

typedef struct dynamic_array {
    array_type type;
    size_t size;
    void* data;
} dynamic_array;

dynamic_array* create_array(int array_length,  array_type type_) {
    dynamic_array* new_arr = (dynamic_array*) malloc(sizeof(dynamic_array));
    new_arr->size = array_length;
    new_arr->type = type_;
    if (type_ == INT_ARR) {
        new_arr->data = create_array_i(array_length);
        return new_arr;
    }
    if (type_ == CHAR_ARR) {
        new_arr->data = create_array_s(array_length);
        return new_arr;
    }
}

dynamic_array* map(dynamic_array* arr, void* (*f)(void*)){
    dynamic_array* new_arr = create_array(arr->size, arr->type);
    if (arr->type == INT_ARR) {
        new_arr -> data = map_i((int (*)(int)) f, arr -> data, arr -> size);
        return new_arr;
    }
    if (arr->type == CHAR_ARR) {
        new_arr -> data = map_s((char *(*)(char *)) f, arr -> data, arr -> size);
        return new_arr;
    }
}

dynamic_array* where(dynamic_array* arr, bool (*f)(void*)){
    dynamic_array* new_arr = create_array(arr->size, arr->type);
    if (arr->type == INT_ARR) {
        new_arr -> data = where_i((bool (*)(int)) f, arr -> data, arr -> size);
        return new_arr;
    }
    if (arr->type == CHAR_ARR) {
        new_arr -> data = where_s((bool (*)(char *)) (bool *(*)(char *)) f, arr -> data, arr -> size);
        return new_arr;
    }
}

dynamic_array* concat(dynamic_array* a, dynamic_array* b) {
    if (a -> type == b -> type) {
        dynamic_array* new_array = create_array((int) (a->size+b->size), a->type);
        if (a->type == INT_ARR) {
            new_array->data = concat_i(a->data, a->size, b->data, b->size);
            return new_array;
        }
        if (a->type == INT_ARR) {
            new_array->data = concat_s(a->data, a->size, b->data, b->size);
            return new_array;
        }
    }
    else return create_array(0, INT_ARR);
}

void output_array(dynamic_array* arr) {
    if (arr -> type == INT_ARR) {
        output_array_i(arr->data, arr->size);
    }
    if (arr -> type == CHAR_ARR) {
        output_array_s(arr->data, arr->size);
    }
}

#endif //LAB1_ARRAY_OBJECT_H
