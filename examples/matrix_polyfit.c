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
#include <time.h>


float noise(float n)
{
	float r = (float)(rand() - (RAND_MAX/2));
 	float rf = r/RAND_MAX;    
	return n * rf; 
}

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
	float noiseLevel = 0.5;

	srand(time(NULL));

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
  	/* Test 1st order linear regression y = ax + b                   */
	/* -------------------------------------------------------------*/	
  	printf("\n\tTest 1st order linear reression y = %6.7fx + %6.7f\n with noise %6.2f", a, b, noiseLevel);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] + b + noise(noiseLevel);
    }
  	Matrix * result = matrix_polyfit(x, y, 1);
  	printf("\n\tgives y^ = %6.7fx + %6.7f\n", result->matrix_entry[0][1], result->matrix_entry[0][0]);  	
  	matrix_free(result);

	/* -------------------------------------------------------------*/	
  	/* Test 2nd order quadratic regression y = ax^2 + bx + c         */
	/* -------------------------------------------------------------*/	
  	printf("\n\tTest 2nd order quadratic reression y = %6.7fx^2 + %6.7fx + %6.7f\n with noise %6.2f", a, b, c, noiseLevel);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] * x->matrix_entry[0][i] + b * x->matrix_entry[0][i] + c + noise(noiseLevel);
    }
  	result = matrix_polyfit(x, y, 2);	
  	printf("\n\tgives y^ = %6.7fx^2 + %6.7fx + %6.7f\n", result->matrix_entry[0][2], result->matrix_entry[0][1], result->matrix_entry[0][0]);  	
  	matrix_free(result);

	/* -------------------------------------------------------------*/	
  	/* Test 3rd order polynomial regression y = ax^3 + bx^2 + cx + d */
	/* -------------------------------------------------------------*/
  	printf("\n\tTest 3rd order reression y = %6.7fx^3 + %6.7fx^2 + %6.7fx + %6.7f\n with noise %6.2f", a, b, c, d, noiseLevel);
  	for(i = 0; i < y->col_size; i++)
    {
		y->matrix_entry[0][i] = a * x->matrix_entry[0][i] * x->matrix_entry[0][i] * x->matrix_entry[0][i] + b * x->matrix_entry[0][i] * x->matrix_entry[0][i] + \
		c * x->matrix_entry[0][i] + d + noise(noiseLevel);
    }
  	result = matrix_polyfit(x, y, 3);	
  	printf("\n\tgives y^ = %6.7fx^3 + %6.7fx^2 + %6.7fx + %6.7f\n", result->matrix_entry[0][3], result->matrix_entry[0][2], result->matrix_entry[0][1], result->matrix_entry[0][0]);  	  
  	matrix_free(result);

  	/* Freeing the alocated matrix spaces */
  	matrix_free(x);
  	matrix_free(y);
}
