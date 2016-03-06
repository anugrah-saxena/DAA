Input files:
FP:	INPUT.TXT ( no. of matrices N and ROWS X COLS for each matrix)
FO:	OPTIMALPATH.TXT (name of matrices through which Optimal Paranthesis will be derived)

Output file:
FP:	OUTPUT.TXT

in matrix m 0 signifies no scalar multiplication required for that i & j pair
in matrix s -1 represents that it is of no use in matrix multiplication

Arrays: 2D = A for RXC values; 1D = P with size of N+1 will help us to get final value of RXC

Arrays: 2D = M for no of scalar multiplications required; 2D = S for value of matrix (K) used for optimization.
