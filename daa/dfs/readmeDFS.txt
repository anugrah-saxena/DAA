Header file:	LINK.H

Input file:	INPUT.TXT	(DISJOINT GRAPH)

Output file:	OUTPUT.TXT

** some answer on terminal too
(another pair of input and output being INPUT2.TXT & OUTPUT2.TXT for FULLY JOINED GRAPH)

DFS_VISIT function to check and add the connected child nodes... and then searching through them


Array:
	2D:
		A = graph and its edges
	1D:
		COLOR = color of node (-1 = white or not traversed; 0 = gray or being traversed; 1 = black or is traversed)
		PARENT = parent node of this node i.e., through which node is this node reached (default -1 = NIL)
		D = start time of traversal
		F = end time of traversal
