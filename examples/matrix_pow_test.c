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

/* A sample program text the "matrix_pow" function*/

#include "matrix.h"

int main()
{
  Matrix *matrix;
  matrix = matrix_alloc(2,2);
  Matrix *result;
  int j,k;

  /*Fillin the matrices */
  for(j = 0; j<2; j++)
    {
      for(k = 0; k <2; k++)
	{
	  matrix->matrix_entry[j][k] = rand()%3;
	}
    }

  printf("\n\tMatrix A =\n");
  matrix_print(matrix);

  result = matrix_pow( matrix, 4);

  /*Printing the operation just carried out */
  printf("\n\tMatrix A raised to the power 4  (ie A^4) =\n");
  matrix_print(result);
  
  /* Freeing th alocated matrix spaces */
  
  matrix_free(matrix);
  matrix_free(result);

  return 0;
}
