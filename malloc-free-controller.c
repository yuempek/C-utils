#include <stdio.h>
#include <stdlib.h>


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
            while( ymp_ptr_arr_idx > 0 && ymp_ptr_arr[ymp_ptr_arr_idx-1] == NULL)
              ymp_ptr_arr_idx--;
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


void ymp_free(void *ptr){
    if(ymp_ptr_arr_remove(ptr)){
        free(ptr);
    }
}

void print_ymp_ptr_arr(){
  for(int i = 0; i < ymp_ptr_arr_idx; i++)
    printf("%d-", (unsigned) ymp_ptr_arr[i]);
   printf("\n");
}

int main(){
  void *ptr1 = ymp_malloc(3);
  print_ymp_ptr_arr();
  
  void *ptr2 = ymp_malloc(2);
  print_ymp_ptr_arr();
  
  void *ptr3 = ymp_malloc(5);
  print_ymp_ptr_arr();
  
  void *ptr4 = ymp_malloc(7);
  print_ymp_ptr_arr();
  
  ymp_free(ptr3);
  print_ymp_ptr_arr();
  
  void *ptr5 = ymp_malloc(100);
  print_ymp_ptr_arr();
   
  ymp_free(ptr2);
  print_ymp_ptr_arr();
  
  ymp_free(ptr1);
  print_ymp_ptr_arr();
  
  ymp_free(ptr4);
  print_ymp_ptr_arr();
  
  ymp_free(ptr5);
  print_ymp_ptr_arr();
  
  


}
