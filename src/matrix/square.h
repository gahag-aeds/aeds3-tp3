#ifndef __MATRIX_SQUARE_H__
#define __MATRIX_SQUARE_H__

#include <stdint.h>


typedef uint_fast16_t SqMatrixSize;

typedef struct SqMatrix SqMatrix;


SqMatrix* new_sqmatrix(SqMatrixSize size);

void delete_sqmatrix(SqMatrix**);


SqMatrixSize sqmatrix_size(const SqMatrix*);

int* sqmatrix_query(SqMatrix*, SqMatrixSize i, SqMatrixSize j);
int  sqmatrix_get(const SqMatrix*, SqMatrixSize i, SqMatrixSize j);


#endif /* __MATRIX_SQUARE_H__ */
