The following is the output from the BFS.C program with HEADER FILE as QUE.H.

<<<A SAMPLE INPUT AND OUTPUT ON TERMINAL>>>

sony@ubuntu:~/Desktop/daa/dfs$ cd ../bfs/
sony@ubuntu:~/Desktop/daa/bfs$ gcc bfs.c
sony@ubuntu:~/Desktop/daa/bfs$ ./a.out
enter no. of nodes5
enter adjacency matrix

enter adjacency matrix value for node 0
0
1
0
1
1

enter adjacency matrix value for node 1
1
0
1
1
0

enter adjacency matrix value for node 2
1
1
0
0
1

enter adjacency matrix value for node 3
0
0
1
0
1

enter adjacency matrix value for node 4
0
1
1
0
0

matrix
	0	1	2	3	4
0	0	1	0	1	1	
1	1	0	1	1	0	
2	1	1	0	0	1	
3	0	0	1	0	1	
4	0	1	1	0	0	
enter starting node2
2(0,-1)->0(1,2)->1(2,2)->4(3,2)->3(4,0)->NULL
sony@ubuntu:~/Desktop/daa/bfs$ 
