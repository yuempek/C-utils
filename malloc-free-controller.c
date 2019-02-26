#define MAX_DYN_MEM_PTR_COUNT 1000
void *ymp_ptr_arr[MAX_DYN_MEM_PTR_COUNT] = {0};
int   ymp_ptr_arr_idx = 0;

int ymp_ptr_arr_add(void *ptr){
    if (ptr == NULL) return 0;
    
    for(int i = 0; i < MAX_DYN_MEM_PTR_COUNT; i++){
        if(ymp_ptr_arr[i] == 0){
            ymp_ptr_arr[i] = ptr;
            if(i == ymp_ptr_arr_idx) ymp_ptr_arr_idx++;
            return 1;
        }
    }
    
    return 0;
}


int ymp_ptr_arr_remove(void *ptr){
    if (ptr == NULL) return 0;
    
    for(int i = 0; i < MAX_DYN_MEM_PTR_COUNT && i < ymp_ptr_arr_idx; i++){
        if(ymp_ptr_arr[i] == ptr){
            ymp_ptr_arr[i] = 0;
            if(i == ymp_ptr_arr_idx) ymp_ptr_arr_idx--;
            return 1;
        }
    }
    
    return 0;
}



void* ymp_malloc(size_t size){
    void *ptr = malloc(size);
    
    if(!ymp_ptr_arr_add(ptr)){
        if(ptr > NULL) free(ptr);
        return NULL;
    }
    
    return ptr;
}


void free(void *ptr){
    if(ymp_ptr_arr_remove(ptr)){
        free(ptr);
    }
}

