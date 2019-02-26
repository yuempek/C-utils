# C-utils

## malloc-free-controller.c
solve multiple free problem.

void *ptr = malloc(3);
  free(ptr);
  free(ptr); //potential error cause
  
  
  
