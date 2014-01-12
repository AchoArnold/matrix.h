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

/* A sample program to perfom the multiplication of two matrices */

#include "matrix.h"

int main()
{
  Matrix *matrix[2];
  matrix[0] = matrix_alloc(2,2);
  matrix[1] = matrix_alloc(2,2);
  Matrix *result;
  int i,j,k;

  /*Fillin the matrices */
  for(i = 0; i < 2; i++)
    {
      for(j = 0; j<2; j++)
	{
	  for(k = 0; k <2; k++)
	    {
	      matrix[i]->matrix_entry[j][k] = rand()%3;
	    }
	}
    }

  result = matrix_multiply( matrix[0], matrix[1]);

  /*Printing the operation just carried out */
  printf("\n\tMultiplying\n");
  matrix_print(matrix[0]);
  printf("\n\twith\n");
  matrix_print(matrix[1]);

  /*Printing the result matrix of the multiplication */
  printf("\n\tGives\n");
  matrix_print(result);
  
  /* Freeing th alocated matrix spaces */
  for( i =0; i< 2; i++)
    {
      matrix_free(matrix[i]);
    }
  matrix_free(result);
}
