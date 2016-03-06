My Header file:
	QUE.H

Q1 is of type struct queue, with item in it. (min priority queue if empty return -10)

Input file:
	INPUT.TXT (no. of edges, root node, weight for edges)
Output file:
	OUTPUT.TXT
let -1 be NIL and -1 Infinites

Array:
	2D:
		W = weights
		S = set to include the nodes which have been traversed
	1D:
		PARENT = to store no. of parent node (default -1)
		KEY = to store distance value (default -1)

RELAX function to update key is strictly mentioned with comments
