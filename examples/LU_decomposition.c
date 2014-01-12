/*
 * Copyright (C) 2013- Acho Arnold
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* A sample program to perfom LU decompostion of a matrix  using the 
 *  LU_decompose function */

#include "matrix.h"

int main()
{
  Matrix *upper_triangular_matrix, *lower_triangular_matrix;
  upper_triangular_matrix = matrix_alloc(3,3);
  lower_triangular_matrix  = matrix_callalloc(3);
  int j,k;

  /*Fillin the upper triangular  with random numbers less that 3 */
  for(j = 0; j<3; j++)
    {
      for(k = 0; k < 3; k++)
      {
	upper_triangular_matrix->matrix_entry[j][k] = rand()%6;
      }
    }
  
  /* Printing the oridginal matrix is */
  printf("\tThe oridginal matrix is \n");
  matrix_print(upper_triangular_matrix);

  /* Carrying out row reduction of the matrix */
  LU_decompose( upper_triangular_matrix, lower_triangular_matrix);
 
 /*Printing the row reduced matrix */
  printf("\n\tThe upper triangular matrix after LU decomposition  is \n");
  matrix_print(upper_triangular_matrix);

  printf("\n\tThe lower triangular matrix after LU decomposition is \n");
  matrix_print(lower_triangular_matrix);
  
  /* Freeing th alocated matrix spaces */
  matrix_free(upper_triangular_matrix);
  matrix_free(lower_triangular_matrix);

  return 0;
}
