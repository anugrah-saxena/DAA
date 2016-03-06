Compile using:
		gcc floyd.c -lm

(to include MATH.H functions)

Input file:
	INPUT.TXT (root node, weight for edges)
Output file:
	OUTPUT.TXT

	no. of edges not required from the file: calculated manually by the program as the no of rows from file = sqrt(no of strings in the file)

let -1 be NIL and 1000 Infinites

Array:
	2D:
		W = weights
		PARENT = to store no. of parent node (default -1)
		KEY = to store distance value (default 1000)

RELAX function to update key is strictly mentioned with comments
