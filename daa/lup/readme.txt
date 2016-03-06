Input file:
	INPUT.TXT (no of rows, matrix, B of constant matrix)
output file:
	OUTPUT.TXT

(another pair of files are INPUT2.TXT & OUTPUT2.TXT)

ABSOLUTE function returns the positive value of any floating digit.
INTEGER P is used to identify the maximum value needed to be replaced.

Array:
	2D M = input matrix;
	2D PARENT or P matrix of A=LUX=PB initially an identity matrix, used to specify which variable Y's value can be extracted when a 1 in a row then that element from constant's B array is used.
	2D L = lower triangular matrix attained from M after various transformations. (use in solving to get Y from LY=PB)
	2D U = upper triangular matrix attained from M after various transformations. (use in solving to get X from UX=Y)

