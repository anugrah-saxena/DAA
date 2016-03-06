My Header file:
	QUE.H

Q1 is of type struct queue, with item in it. (min priority queue if empty return -10)

Input file:
	INPUT.TXT (edges)
	WEIGHT.TXT (weight for edges)
Output file:
	OUTPUT.TXT
** some intermediate output on the terminal

let -1 be NIL and 1000 Infinites

ROOT starting node

Arrays:
	2D:
		A = edges
		W = weights
		Q = with 1st column has item and 2nd column has if the item is used or not
	1D:
		PARENT = to store no. of parent node (default -1)
		KEY = to store distance value (default 1000)
