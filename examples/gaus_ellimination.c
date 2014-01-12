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

/* A sample program to perfom gauss elimination using the row_reduction 
 * function */

#include "matrix.h"

int main()
{
  Matrix *matrix;
  matrix = matrix_alloc(2,3);
  Matrix *result;
  int i,j,k;

  /*Fillin the matrices with random numbers less that 3 */
  for(i = 0; i < 1; i++)
    {
      for(j = 0; j<2; j++)
	{
	  for(k = 0; k < 3; k++)
	    {
	      matrix->matrix_entry[j][k] = rand()%3;
	    }
	}
    }
  
  /* Printing the oridginal matrix is */
  printf("Oridginal matrix is \n");
  matrix_print(matrix);

  /* Carrying out row reduction of the matrix */
  matrix_row_reduce(matrix, matrix->row_size);
 
 /*Printing the row reduced matrix */
  printf("\n\tMatrix after row reduction is \n");
  matrix_print(matrix);
  printf("\n\tColumn  matrix of unknowns is\n");
  matrix_print_part(matrix, matrix->row_size);
  
  /* Freeing th alocated matrix spaces */
  matrix_free(matrix);

  return 0;
}
