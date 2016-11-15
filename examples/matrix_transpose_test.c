/*
 * Copyright (C) 2016 - Jaroslaw Oska
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

/* A sample program to test matrix transpose */

#include "matrix.h"

int main()
{
	Matrix *matrix = matrix_alloc(3,2);
  	int i,j,k;

  	/* Fillin the matrix */
	k = 0;
  	for(i = 0; i < matrix->row_size; i++)
    {
    	for(j = 0; j < matrix->col_size; j++)
		{
	      matrix->matrix_entry[i][j] = (float) (k++);
		}
    }

  	Matrix * result = matrix_transpose( matrix );

  	/* Printing */
  	printf("\n\tTransposition of matrix\n");
  	matrix_print(matrix);
  	printf("\n\tgives\n");
  	matrix_print(result);
  
  	/* Freeing the alocated matrix spaces */
  	matrix_free(result);
  	matrix_free(matrix);
}
