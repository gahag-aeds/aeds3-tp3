#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include <matrix/square.h>
#include <matrix/algorithm.h>


int main() {
  SqMatrixSize size, b_size;
  
  if (scanf("%" SCNuFAST16 "%" SCNuFAST16, &size, &b_size) != 2)
    return -1;
  
  
  SqMatrix* A = new_sqmatrix(size);{
    if (A == NULL)
      return -1;
  }
  
  for (SqMatrixSize i = 0; i < size; i++)
    for (SqMatrixSize j = 0; j < size; j++)
      if (scanf("%d", sqmatrix_query(A, i, j)) != 1)
        return free(A), -1;
  
  
  SqMatrix* B = new_sqmatrix(size);{
    if (B == NULL)
      return free(A), -1;
  }
  
  for (SqMatrixSize i = 0; i < size; i++)
    for (SqMatrixSize j = 0; j < size; j++)
      if (scanf("%d", sqmatrix_query(B, i, j)) != 1)
        return free(A), free(B), -1;
  
  
  SqMatrix* C = new_sqmatrix(size);{
    if (C == NULL)
      return free(A), free(B), -1;
  }
  
  #ifdef BLOCK
  sqmatrix_blockmult(A, B, C, b_size);
  #else
  sqmatrix_mult(A, B, C);
  #endif
  
  for (SqMatrixSize i = 0; i < size; i++) {
    for (SqMatrixSize j = 0; j < size; j++)
      if (printf("%d ", sqmatrix_get(C, i, j)) < 0)
        return free(A), free(B), free(C), -1;
    
    if (puts("") < 0)
      return free(A), free(B), free(C), -1;
  }
  
  
  return free(A), free(B), free(C), 0;
}
