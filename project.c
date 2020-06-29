/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* 
Name: Stephen Parinas
Username: npar276
ID: 875329986
*/

#include "project.h"

/*
The function TimeWorked takes in as inputs two clock times (in minutes and seconds), and returns the difference
between these two times (in seconds). Both times are first converted into seconds, then the difference is calculated.
If the difference between timeA and timeB is negative, it is multiplied by -1 before being returned.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB, timeDifference;
	timeA = minuteA * 60 + secondA;
	timeB = minuteB * 60 + secondB;
	timeDifference = timeA - timeB;

	if (timeDifference >= 0) {
		return timeDifference;
	}
	else {
		return timeDifference * -1;
	}	
}

/*
The function WarehouseAddress takes in as input an integer value, and returns the highest prime number less than this value. A nested for 
loop is used, the first one running through each value less than the inputted integer, down to 2 (lowest prime number), and the second
for loop runs counts the number of values that this value is divisible by. If the count is 0, the number is prime, and is returned.
*/
int WarehouseAddress(int maximum)
{
	int i, j, maxPrime, count, modulus;

	maxPrime = maximum;

	for (i = maximum - 1; i >= 2; i--) {
		count = 0;
		for (j = 2; j < i; j++) {
			modulus = i % j;
			if (modulus == 0) {
				count++;
			}
		}
		if (count == 0) {
			return maxPrime = i;
		}
	}

	return maxPrime;
}

/*
The function Advertise modifies an inputted string of characters, where the position of each character is moved by one to the left.
The first character in the string is initially saved in a temporary variable. A for loop is run from index 1 (second character) to 
the last character, moving its position to the left by one. Finally, the original first character is moved to the other end of the 
string, now being the last character. 
*/
void Advertise(char *words)
{
	int i, length;
	char firstLetter;
	length = strlen(words);
	
	firstLetter = words[0];

	for (i = 1; i < length; i++) {
		words[i - 1] = words[i];
	}
	words[i - 1] = firstLetter;
}

/*
The function WinningBid takes in as inputs an array of values and the length of this array (number of values), and returns the lowest
non-repeating value in the array. The values in the array are first placed in ascending order, then the modified array is run through
a for loop that checks the adjacent values to see if they are the same. The lowest value, where neither of the adjacent values are the 
same, is returned. If the for loop finishes running and there is no non-repeating value, then -1 is returned, and if there is only one
value in the array, this is returned.
*/
int WinningBid(int *values, int length)
{
	int i, j, temp;

	if (length == 1) {
		return values[0];
	}
	else {
		for (i = 0; i < length; i++) {
			for (j = i + 1; j < length; j++) {
				if (values[i] > values[j]) {
					temp = values[i];
					values[i] = values[j];
					values[j] = temp;
				}
			}
		}

		if (values[0] != values[1]) {
			return values[0];
		}
		else {
			for (i = 1; i < length - 1; i++) {
				if (values[i] != values[i - 1] && values[i] != values[i + 1]) {
					return values[i];
				}
			}
		}

		if (i == length - 1 && values[length - 1] != values[length - 2]) {
			return values[length - 1];
		}
		else {
			return -1;
		}
	}
}

/*
The function BoxDesign takes in as input a string in which the final box design is to be stored, as well as the width and height of the box
to be designed. For loops are used to create the borders of the box (set as *) and if the position on the string % width + 1 == width, a \n
is used to create a line break. In addition, if the width and height are both greater than or equal to 3, the centre position(s) of the box
are found and set to an X. If both width and height are odd, then only one X is set, otherwise, two X's are set for the centre of whichever
dimensions are even. The total length of the string must be equal to (width + 1) multiplied by the height.
*/
void BoxDesign(char *design, int width, int height)
{
	int i;
	int totalLength = (width + 1) * height;

	if (width == 1 && height == 1) {
		design[0] = '*';
		design[1] = '\n';
	}
	else if (width != 1 && height == 1) {
		for (i = 0; i < width; i++) {
			design[i] = '*';
		}
		design[i] = '\n';
	}
	else {
		for (i = 0; i < totalLength; i++) {
			if (i % (width + 1) == width) {
				design[i] = '\n';
			}
			else if (i % (width + 1) == 0 || i % (width + 1) == width - 1) {
				design[i] = '*';
			}
			else {
				design[i] = ' ';
			}
		}
		for (i = 0; design[i] != '\n'; i++) {
			design[i] = '*';
		}
		for (i = totalLength - 2; design[i] != '\n'; i--) {
			design[i] = '*';
		}
	}
	

	if (width >= 3 && height >= 3) {
		if (width % 2 == 1 && height % 2 == 1) {
			design[totalLength / 2 - 1] = 'X';
		}
		else if (width % 2 == 1 && height % 2 == 0) {
			design[(totalLength / 2) - ((width + 1) / 2) - 1] = 'X';
			design[(totalLength / 2) + ((width + 1) / 2) - 1] = 'X';
		}
		else if (width % 2 == 0 && height % 2 == 1) {
			design[totalLength / 2 - 1] = 'X';
			design[totalLength / 2] = 'X';
		}
		else {
			design[(totalLength / 2) - ((width + 1) / 2) - 1] = 'X';
			design[(totalLength / 2) + ((width + 1) / 2) - 1] = 'X';
			design[(totalLength / 2) - ((width + 1) / 2) - 2] = 'X';
			design[(totalLength / 2) + ((width + 1) / 2)] = 'X';
		}
	}
}

/*
The function WorkerRoute takes in as input a 10x10 2D array, where all positions are spaces (set as '0') except for two, one being the
position of a worker (set as '1') and the other being the position of a box (set as '2'). The objective is to find the shortest path between
the two positions, and setting the path taken as '3'. The worker must first move horizontally until it is in the same column as the box, and
then move vertically until it is in the position of the box. Note that the positions set as 1 and 2 are not replaced with a 3.
*/
void WorkerRoute(int warehouse[10][10])
{
	int i, j;
	int row1 = 0;
	int row2 = 0;
	int col1 = 0;
	int col2 = 0;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				row1 = i;
				col1 = j;
			}
			else if (warehouse[i][j] == 2) {
				row2 = i;
				col2 = j;
			}
		}
	}
	
	if (col1 < col2) {
		i = row1;
		for (j = col1 + 1; j < col2; j++) {
			warehouse[i][j] = 3;
		}
		if (warehouse[i][j] != 2) {
			warehouse[i][j] = 3;
		}
		if (row1 < row2) {
			for (i = row1 + 1; i < row2; i++) {
				warehouse[i][j] = 3;
			}
		}
		else if (row1 > row2) {
			for (i = row1 - 1; i > row2; i--) {
				warehouse[i][j] = 3;
			}
		}
	}

	else if (col1 > col2) {
		i = row1;
		for (j = col1 - 1; j > col2; j--) {
			warehouse[i][j] = 3;
		}
		if (warehouse[i][j] != 2) {
			warehouse[i][j] = 3;
		}
		if (row1 < row2) {
			for (i = row1 + 1; i < row2; i++) {
				warehouse[i][j] = 3;
			}
		}
		else if (row1 > row2) {
			for (i = row1 - 1; i > row2; i--) {
				warehouse[i][j] = 3;
			}
		}
	}

	else {
		i = row1;
		j = col1;
		if (row1 < row2) {
			for (i = row1 + 1; i < row2; i++) {
				warehouse[i][j] = 3;
			}
		}
		else if (row1 > row2) {
			for (i = row1 - 1; i > row2; i--) {
				warehouse[i][j] = 3;
			}
		}
	}
}

/*
The function MakeMove takes in as inputs a 10x10 2D array of a warehouse, containing a worker, boxes, targets, spaces and walls, and a 
character (w, a, s or d) that indicates the direction that the worker is to move. The worker may only move if the adjacent position in the 
indicated direction is a space or target, or if the adjacent position is a box and the position adjacent to the box in the indicated 
direction is a space or a target. Whether or not the worker and/or the box is on a target must also be taken into account. At the end of 
each move, the board must be checked to see if the game is over (when the boxes and worker are all on a target), in which the function will
return 1. Otherwise, it will return 0 and the user is asked to input another move.
*/
int MakeMove(int warehouse[10][10], char move) 
{
	int i, j, tile, *worker, *adjacent1, *adjacent2;
	int count = 0;
	int workerRow = 0;
	int workerCol = 0;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 5 || warehouse[i][j] == 6) {
				workerRow = i;
				workerCol = j;
			}
		}
	}
	worker = &warehouse[workerRow][workerCol];

	if (move == 'w') {
		adjacent1 = &warehouse[workerRow - 1][workerCol];
		adjacent2 = &warehouse[workerRow - 2][workerCol];
	}
	else if (move == 'a') {
		adjacent1 = &warehouse[workerRow][workerCol - 1];
		adjacent2 = &warehouse[workerRow][workerCol - 2];
	}
	else if (move == 's') {
		adjacent1 = &warehouse[workerRow + 1][workerCol];
		adjacent2 = &warehouse[workerRow + 2][workerCol];
	}
	else if (move == 'd') {
		adjacent1 = &warehouse[workerRow][workerCol + 1];
		adjacent2 = &warehouse[workerRow][workerCol + 2];
	}
	else {
		adjacent1 = &warehouse[workerRow][workerCol];
		adjacent2 = &warehouse[workerRow][workerCol];
	}

	if (*adjacent1 == 0 && *worker == 5) {
		*adjacent1 = 5;
		*worker = 0;
	}
	else if (*adjacent1 == 2 && *worker == 5) {
		*adjacent1 = 6;
		*worker = 0;
	}
	else if (*adjacent1 == 0 && *worker == 6) {
		*adjacent1 = 5;
		*worker = 2;
	}
	else if (*adjacent1 == 2 && *worker == 6) {
		*adjacent1 = 6;
		*worker = 2;
	}
	else if (*adjacent1 == 3) {
		if (*adjacent2 == 0) {
			if (*worker == 5) {
				*adjacent2 = 3;
				*adjacent1 = 5;
				*worker = 0;
			}
			else if (*worker == 6) {
				*adjacent2 = 3;
				*adjacent1 = 5;
				*worker = 2;
			}
		}
		else if (*adjacent2 == 2) {
			if (*worker == 5) {
				*adjacent2 = 4;
				*adjacent1 = 5;
				*worker = 0;
			}
			else if (*worker == 6) {
				*adjacent2 = 4;
				*adjacent1 = 5;
				*worker = 2;
			}
		}
	}
	else if (*adjacent1 == 4) {
		if (*adjacent2 == 0) {
			if (*worker == 5) {
				*adjacent2 = 3;
				*adjacent1 = 6;
				*worker = 0;
			}
			else if (*worker == 6) {
				*adjacent2 = 3;
				*adjacent1 = 6;
				*worker = 2;
			}
		}
		else if (*adjacent2 == 2) {
			if (*worker == 5) {
				*adjacent2 = 4;
				*adjacent1 = 6;
				*worker = 0;
			}
			else if (*worker == 6) {
				*adjacent2 = 4;
				*adjacent1 = 6;
				*worker = 2;
			}
		}
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			tile = warehouse[i][j];

			if (tile == 0 || tile == 1 || tile == 4 || tile == 6) {
				count++;
			}
		}
	}
	if (count == 100) {
		return 1;
	}
	else {
		return 0;
	} 
}