#include "square.h"

#include <assert.h>
#include <stdlib.h>


struct SqMatrix {
  SqMatrixSize size;
  int data[];
};


SqMatrix* new_sqmatrix(SqMatrixSize size) {
  assert(size > 0);
  SqMatrix* m = calloc(1, sizeof(SqMatrix) + sizeof(int[size][size]));
  
  if (m == NULL)
    return NULL;
  
  m->size = size;
  
  return m;
}

void delete_sqmatrix(SqMatrix** m) {
  assert(m != NULL);
  
  free(*m);
  
  *m = NULL;
}


SqMatrixSize sqmatrix_size(const SqMatrix* m) {
  assert(m != NULL);
  return m->size;
}

int* sqmatrix_query(SqMatrix* m, SqMatrixSize i, SqMatrixSize j) {
  assert(m != NULL);
  assert(i < sqmatrix_size(m) && j < sqmatrix_size(m));
  
  int (*data)[sqmatrix_size(m)][sqmatrix_size(m)] = (void*) m->data;
  
  return &(*data)[i][j];
}
int sqmatrix_get(const SqMatrix* m, SqMatrixSize i, SqMatrixSize j) {
  assert(m != NULL);
  assert(i < sqmatrix_size(m) && j < sqmatrix_size(m));
  
  return *sqmatrix_query((void*) m, i, j);
}
