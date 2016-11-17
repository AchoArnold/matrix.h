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

/* A sample program to test polynomial regression */

#include "matrix.h"

int main()
{
	const int len = 10;
  	int i;
	float begin = -5.0;
	float end = 5.0;
	float diff;
	float a = 1.0;
	float b = 2.0;
	float c = 3.0;
	float d = 4.0;

	Matrix *x = matrix_alloc(1,len);
	Matrix *y = matrix_alloc(1,len);

 	/* Fillin the vector x */
	diff = (end - begin)/len; 
  	for(i = 0; i < x->col_size; i++)
    {
		x->matrix_entry[0][i] = begin + diff * i;
    }
	matrix_print(x);
	/* -------------------------------------------------------------*/		
  	/* Test 1st order linear reression y = ax + b                   */
	/* -------------------------------------------------------------*/	
  	printf("\n\tTest 1st order linear reression y = %6.2fx + %6.2f\n", a, b);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] + b * x->matrix_entry[0][i] ;
    }
  	Matrix * result = matrix_polyfit(x, y, 1);
  	printf("\n\tgives y^ = %6.2fx + %6.2f\n", result->matrix_entry[0][0], result->matrix_entry[0][1]);  	
  	matrix_free(result);

	/* -------------------------------------------------------------*/	
  	/* Test 2nd order quadratic reression y = ax^2 + bx + c         */
	/* -------------------------------------------------------------*/	
	/*
  	printf("\n\tTest 2nd order quadratic reression y = %6.2fx^2 + %6.2fx + %6.2f\n", a, b, c);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] * x->matrix_entry[0][i] + b * x->matrix_entry[0][i];
    }
  	Matrix * result = matrix_polyfit(x, y, 2);	
  	printf("\n\tgives y^ = %6.2fx^2 + %6.2fx + %6.2f\n", result->matrix_entry[0][0], result->matrix_entry[0][1], result->matrix_entry[0][2]);  	
  	matrix_free(result);
	*/
	/* -------------------------------------------------------------*/	
  	/* Test 3rd order polynomial reression y = ax^3 + bx^2 + cx + d */
	/* -------------------------------------------------------------*/
	/*
  	printf("\n\tTest 3rd order reression y = %6.2fx^3 + %6.2fx^2 + %6.2fx + %6.2f\n", a, b, c, d);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] * x->matrix_entry[0][i] + b * x->matrix_entry[0][i] ;
    }
  	Matrix * third = matrix_polyfit(x, y, 2);	
  	printf("\n\tgives y^ = %6.2fx^3 + %6.2fx^2 + %6.2fx + %6.2f\n", linear->matrix_entry[0][0], linear->matrix_entry[0][1], linear->matrix_entry[0][2], linear->matrix_entry[0][3]);  	  
  	matrix_free(result);
	*/

  	/* Freeing the alocated matrix spaces */
  	matrix_free(x);
  	matrix_free(y);
}
