#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include "cmath"

//predeclarations
class QStandardItemModel;
class QColor;

/**
 * @brief Returns true if targetValue is contained inside [array[startIndex],array[startIndex + arraySize]]
 * If true index will be the index at which the value was found.
 *
 * @param array
 * @param startIndex
 * @param arraySize
 * @param targetValue
 * @param index
 * @return
 */
bool Contains(const QString array[], int startIndex, int arraySize, const QString& targetValue, int &index);

/**
 * @brief Trim
 * Removes all leading and trailing white spaces.
 * @param str
 */
void Trim(QString& str);

/**
 * Initialize the rand functions by setting a new seed.
 */
void RandomInitialize();

/**
* Get a random number in [0,max]
*/
int RandomInt(int max);

/**
* Get a random number in [min,max]
*/
int RandomInt(int min,int max);

/**
 * Converts a number to its binary representation, with 
 * digitNumber number of digits.
 */
QString ToBinary(int number,int digitNumber);

#ifdef  _MSC_VER
/**
 * Computes the logarithm 2 of the n number.
 * Defined only for MSVS compiler
 */
double log2( double n )
{
    // log(n)/log(2) is log2.
    return log( n ) / log( 2 );
}
#endif

/**
 * Change the background color of all rows in [start,end].
 */
void HighlightRows(QStandardItemModel* model,int start,int end,const QColor& color);

/**
 * Change the background color of the given row.
 */
void HighlightSingleRow(QStandardItemModel* model,int row,const QColor& color);

#endif // HELPER_H
