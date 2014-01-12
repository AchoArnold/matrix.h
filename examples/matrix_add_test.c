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

/* A sample program to perfom the addition of two matrices
 */
#include "matrix.h"

int main()
{
  Matrix *matrix1 = matrix_alloc(2,2);
  Matrix *matrix2 = matrix_alloc(2,2);
  Matrix *result = matrix_alloc(2,2);
  int j,k;

 
 for(j = 0; j<2; j++)
    {
      for(k = 0; k < 2; k++)
      {
	matrix1->matrix_entry[j][k] = rand()%3;
      }
    }
  printf("\n\tMatrix1 is:\n");
  matrix_print(matrix1);

  for(j = 0; j<2; j++)
    {
      for(k = 0; k < 2; k++)
      {
	matrix2->matrix_entry[j][k] = rand()%3;
      }
    }
  printf("\n\tMatrix2 is:\n");
  matrix_print(matrix2);

  matrix_add(result, matrix1, matrix2);
 
  printf("\n\tThe result matrix of the addition is:\n");
  matrix_print(result);
  
  /* Freeing th alocated matrix spaces */
  matrix_free(matrix1);
  matrix_free(matrix2);
  matrix_free(result);
}
