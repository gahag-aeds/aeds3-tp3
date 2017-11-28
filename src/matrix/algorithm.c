#include "algorithm.h"


void sqmatrix_mult(const SqMatrix* A, const SqMatrix* B, SqMatrix* C) {
  SqMatrixSize size = sqmatrix_size(C);
  
  for (unsigned short i = 0; i < size; i++)
    for (unsigned short j = 0; j < size; j++) {
      *sqmatrix_query(C, i, j) = 0;
      
      for (unsigned short k = 0; k < size; k++)
        *sqmatrix_query(C, i, j) = sqmatrix_get(C, i, j)
                                 + sqmatrix_get(A, i, k) * sqmatrix_get(B, k, j);
    }
}

void sqmatrix_blockmult(
  const SqMatrix* A,
  const SqMatrix* B,
  SqMatrix* C,
  SqMatrixSize b_size
) {
  SqMatrixSize size = sqmatrix_size(C);
  
  for (SqMatrixSize kk = 0; kk < size ; kk += b_size)
    for (SqMatrixSize jj = 0; jj < size ; jj += b_size)
      for (SqMatrixSize i = 0; i < size ; i++)
        for (SqMatrixSize j = jj; j < jj + b_size; j++) {
          int sum = sqmatrix_get(C, i, j);
          
          for (SqMatrixSize k = kk; k < kk + b_size; k++)
            sum = sum + sqmatrix_get(A, i, k) * sqmatrix_get(B, k, j);
          
          *sqmatrix_query(C, i, j) = sum;
        }
}
