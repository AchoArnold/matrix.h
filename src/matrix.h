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

/**
 * @file matrix.h
 *
 * @brief Matrices
 *
 * This header file contains all the functions which can be used to  manipulate the
 * matrices so as to obtain required outputs.
 * 
 * To create a new matrix, you will have to allocate space for the matrix using
 *  @ref matrix_alloc or @ref matrix_callalloc
 * 
 * To  copy  a matrix into another, use @ref matrix_copy.
 * 
 * To multiply two matrices, use @ref matrix_multiply.
 * 
 * To multiply a matrix by itself 'n' times (i.e raise the matrix to the nth power)
 * use @ref matrix_pow.
 * 
 * To add or subtract two matrices, use @ref matrix_add or @ref  matrix_subtract 
 * respectively.
 * 
 * To perform LU decomposition of a matrix, use @ref LU_decompose.
 * 
 * To perform row echelon reduction of a particular matrix, use
 * @ref matrix_row_reduce.
 * 
 * To print the matrix at any time, use @ref matrix_print or @ref matrix_print_part
 * 
 * The function @ref row_divide is  used as an accessory function in  other functions
 * to divide a row of a matrix by a specific value.
 * 
 * The function  @ref row_operation is used as an accessory function in other 
 * functions to perform row operations on a matrix.
 * 
* The function  @ref matrix_equal_size checks if two matrices have the same 
 * number or rows and columns
 */


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


/**
 * Definition of a  @ref _Matrix structure to hold the matrix entries.
 * A new matrix can be created using the @ref matrix_alloc function.
 */
struct _Matrix
{
  /** The number  of rows in the matrix */
  int row_size;

  /** The number of columns in the matrix */
  int col_size;
  
  /** The individual entries in the matrix */
  float **matrix_entry;
};

/**
 * Represents the @link _Matrix matrix structure@endlink which holds the matrix entries.
 * to initialise a new Matrix, simply create a variable of this type
 * and initialise to NULL if necessary
 * 
 * @see matrix_alloc
 */

typedef struct _Matrix Matrix;

/**
 * Print  whole entire matrix  to stdout
 * 
 * @param matrix  Pointer to the matrix to be printed to stdout
 */

void matrix_print (Matrix *matrix);

/**
 *  Printing some columns of a matrix 
 * 
 * @param matrix       The matrix whose part is to be printed
 * @param start_index   The  column number to start printing from
 */

void matrix_print_part(Matrix *matrix, int start_index );


/**
 * This fills the entire matrix with values which are  gotten form
 * stdin.
 *  
 * @param matrix  Pointer to the matrix structure which is to
 * be filled.
 */

void matrix_fill(Matrix *matrix );

/**
 * Creates an identity matrix that is all the diagonal entries are 
 * initialised to 1 and all other entries to zero).
 *  
 * @param matrix_size    The number of rows and columns in the
 *                                        identity matrix.
 * @return                        A pointer to the new identity matrix just 
 *                                        created
 */

Matrix * matrix_callalloc(int matrix_size); 

/**
 * Allocates memory for a new matrix
 * 
 * @param row_size       The number of rows in the matrix
 * @param col_size         The number of columns in the matrix
 * @return                      The location of the memory block that was 
 *                                       allocated to hold the matrix
 */

Matrix *matrix_alloc(int row_size, int col_size);

/**
 * Copies the content of one matrix1 into matrix2
 * 
 * @param matrix1       Pointer  the matrix to be copied
 * @param matrix2       Pointer to the matrix to which the other is to
 *                                   be copied into
 */

void matrix_copy(Matrix *matrix1, Matrix *matrix2);

/**
 * Multiplies two matrices
 * 
 * @param matrix1     Pointer to the first matrix for the multiplication
 * @param matrix2     The second matrix for the multiplication
 * @return                  The location of a matrix which holds the result
 *                                of the multiplication
 */
Matrix *matrix_multiply(const Matrix *matrix1, const Matrix *matrix2);

/**
 * Multiplies a matrix by itself 'n' times
 * 
 * @param matrix       The matrix which is to self multiplied 'n' times
 * @param index         The number of times the matrix is to be multiplied to 
 *                                 itself
 * @return                  The location of the matrix which holds the results
 *                                    of the multiplications
 */

Matrix  *matrix_pow(Matrix *matrix, int index);

/**
 * Free an entire matrix
 * 
 * @param matrix       The matrix to free.
 */
void matrix_free(Matrix *matrix);


/**
 * Divides an entire row of a matrix by a value of the pivot position
 * 
 * @param matrix       The matrix whose row is to be divided
 * @param pivot          The pivot position of the matrix to do the division
 */
void row_divide(Matrix *matrix, int pivot);

/**
 * Row operations on the matrix
 * 
 * @param multiplier_matrix    A matrix to store the various multipliers used 
 *                                             in row reduction
 * @param matrix          A matrix on which to carry out the row 
 *                                  operations
 * @param pivot            The pivot position of the matrix to use
 * @param  row_index   The row number on which to carry out row operations
 */

void row_operation(Matrix *multiplier_matrix, Matrix *matrix, int pivot, int row_index);

/**
 * Row echelon reduction a matrix
 * 
 * @param matrix     The matrix on which to carry out row reduction
 * @param zero_control      Maximum amount of zeros that can be found on a
 *                                        row
 */

void matrix_row_reduce( Matrix *matrix, int zero_control);

/**
 * This function performs the  LU decomposition of a matrix
 * 
 * @param upper_triangular        A pointer to the matrix on which to perform
 *                                                 LU decomposition.
 * @param lower_triangular          A pointer to the lower triangular matrix
 * @note You should allocate memory for the lower_triangular matrix with 
 * @ref matrix_callalloc before passing it to this function
 */
void LU_decompose(Matrix *upper_triangular, Matrix *lower_triangular);

/**
 * Subtracts one matrix from another
 * 
 * @param result         A  matrix to hold the result of the subtraction
 * @param matrix1      The matrix to subtract from
 * @param matrix2       The matrix to be subtracted from another
 */

void matrix_subtract(Matrix *result, Matrix *matrix1, Matrix *matrix2);

/**
 * Adds one matrix to another
 * 
 * @param result        A  matrix to hold the result of the addition
 * @param matrix1     The first matrix for the addition
 * @param matrix2     The second matrix for the addition
*/

void matrix_add(Matrix *result, Matrix *matrix1, Matrix *matrix2);

/**
 * Perform the inverse of a matrix
 *
 * @param inverse_matrix The matrix which is to be inverted
 */
void matrix_invert(Matrix *inverse_matrix);

/**
 * Checks if two matrices have equal rows and columns
 *
 * @param matrix1    The first matrix
 * @param matrix2    The second matrix
 * @return          Non-zero if the matrix row and columns  are equal, zero if they 
 *                        are not equal.
 */

int matrix_equal_size( Matrix *matrix1, Matrix *matrix2);

/**
 * Checks  if there are too many zeros in a single line
 *
 * @param matrix The matrix which is to be checked
 * @param control_index    The maximum amount of zero's that can be contained
 *                                         in a single row
 */
void error_zeros( Matrix *matrix, int control_index);

/**
 * Function to terminate an application in case of an error
 * 
 *  @param string     Message to displayed to stdout in case of an error 
 */
void terminate( char *string);
