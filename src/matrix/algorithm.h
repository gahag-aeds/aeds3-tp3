#ifndef __MATRIX_ALGORITHM_H__
#define __MATRIX_ALGORITHM_H__

#include <matrix/square.h>


void sqmatrix_mult(const SqMatrix*, const SqMatrix*, SqMatrix* out);

void sqmatrix_blockmult(const SqMatrix*, const SqMatrix*, SqMatrix* out, SqMatrixSize b_size);


#endif /* __MATRIX_ALGORITHM_H__ */
