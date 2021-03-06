#include <stdio.h>

#include "test.h"
#include "matrix.h"
#include "strassen.h"

int main(int argc, char *argv[]) {
  size_t n = 1 << 12;

  float **A = allocate_random_matrix(n, n);
  float **B = allocate_random_matrix(n, n);
  float **C0 = allocate_matrix(n, n);
  float **C1 = allocate_matrix(n, n);


  printf("n\tNaive Alg.\tStrassen's Alg.\tSame result\n");
  for (size_t j = 1; j <= n; j *= 2) {

    printf("%ld", j);
 
    printf("\t%lf", test(strassen_matrix_multiplication, C1, A, B, j));
    printf("\t%lf", test(naive_matrix_multiplication, C0, A, B, j));

    printf("\t%d\n", same_matrix((float const *const *const)C0,
                                 (float const *const *const)C1, j, j));
  }

  deallocate_matrix(A, n);
  deallocate_matrix(B, n);
  deallocate_matrix(C0, n);
  deallocate_matrix(C1, n);

  return 0;
}
