/*
 * Copyright (C) 2013 - Acho Arnold
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

/* A sample program to look for the matrix inverse using the matrix_row_reduce
 * function */

#include "matrix.h"

int main()
{
  Matrix * matrix = matrix_alloc(3,3);
  int j,k;

  for(j = 0; j<3; j++)
    {
      for(k = 0; k < 3; k++)
      {
	matrix->matrix_entry[j][k] = rand()%3;
      }
    }

  printf("\tThe oridginal matrix is \n");
  matrix_print(matrix);

  matrix_invert(matrix);
 
  printf("\n\tThe  inverse matrix is \n");
  matrix_print(matrix);
  
  /* Freeing th alocated matrix spaces */
  matrix_free(matrix);

  return 0;
}
