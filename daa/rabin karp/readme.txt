compile by:

gcc rabinkarp.c -lm

to include MATH.H.

file input: INPUT.TXT
file output: OUTPUT.TXT

MOD function returns X%Y value; where Y is from file: here its 13 (variable name B)

text string, length, mod value = TEXT: L1: A		(part of TEXT string is integer value TEX with size of L2, mod value of TEX is A)
pattern string, length, mod value = PATTERN: L2: PAT

if A = PAT then check for each character of TEXT with PATTERN if matches then output otherwise its a Spurious Hit.
