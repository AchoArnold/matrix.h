/**
 * @mainpage matrix.h header file documentation
 *
 * @section Introduction
 *
 * The C programming language includes a very limited standard library in
 * comparison to other modern programming languages.  This is a collection
 * some very basic matrix algorithms which can be used  used in C projects to
 * manipulate matrices
 * 
 * The code is licensed under the GNU General Public License as published by
 * the Free Software Foundation as such, it may be reused in any project, whether
 * Proprietary or Open Source.
 *
 * @section Data_Structures Data structures
 * 
 * @subsection Collections
 *
 * @li @link matrix.h Matrix @endlink: A two dimensional array of matrix entries.
 *
 * @section Utility_functions Utility functions
 *
 * All the matrix algorithms  rely on the @ref _Matrix structure and it is 
 * sometimes necessary to compare matrix sizes (when adding matrices for 
 * example), to divide a matrix my a particular value or to compare the rows and 
 * columns of two matrices (when doing matrix multiplication). The following 
 * functions provide this functionality for these algorithms.
 *
 * @li Matrix size @link matrix_equal_size comparison @endlink.
 * @li Matrix @link matrix_copy copy@endlink.
 * @li Matrix @link row_divide row divide @endlink.
 * @li Matrix @link row_operation row operation@endlink.
 * @li @link matrix_print_part Print part@endlink of a matrix.
 * @li @link terminate Terminate@endlink A program in case of an error
 *
 *
 * @section Debug
 * If you downloaded this package from github or sourceforge, then there is a folder
 * included in it called *debug/* which contains basically the same files but which has 
 * has been optimized for debugging through the use of printlinning.
 *
 *
 * @section Examples
 * You can see some example of  how to use the this header file by browsing 
 * through the Examples directory that  was download together with this package
 *
 */
