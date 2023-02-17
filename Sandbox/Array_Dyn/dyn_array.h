typedef struct dyn_array* D_Array;

int push_d_array (D_Array* a, void* elem);
void* get_d_index (D_Array a, int n);
void* get_d_comp (D_Array a, void* elem, int (*compare) (void*, void*));
D_Array filter_d_array (D_Array a, int (*filter) (void*));
void free_d_array (D_Array a);