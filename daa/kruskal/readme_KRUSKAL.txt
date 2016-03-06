Input file:
	INPUT.TXT (edges)
	WEIGHT.TXT (weights)
Output file:
	OUTPUT.TXT

	no. of edges not required from the file: calculated manually by the program as the no of rows from file = sqrt(no of strings in the file)

let -1 be NIL and 1000 Infinites

Array:
	2D:
		A = edges
		W = weights
		SORT = sort edges in increasing order of their weight.
		SPANTREE (spanning tree will have the final set of edges to be included... initially NULL set)
		PARENT = to store no. of parent node (default -1)
		KEY = to store distance value (default 1000)
	1D:
		MAKESET = initially make different set of each node: when clubbing the nodes then make both their sets as same. (use in findset function)

RELAX function to update key is strictly mentioned with comments
