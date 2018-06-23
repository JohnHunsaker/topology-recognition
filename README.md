# topology-recognition
Application that scans an inputted adjacency matrix, then determines which network model is represented.

![network](https://user-images.githubusercontent.com/22629266/41686455-002aea2a-7499-11e8-8455-bd32537c478f.png)

The input is a weight matrix W[0..n −1, 0..n −1], where n > 3, which is the weight matrix of a weighted, connected, undirected graph modeling a network with a topology, if any, that the matrix represents. Assume the weights to be positive integer values. Instead of infinity, use the value of 100 for elements representing infinity.

<br />
<br />

## Instructions
1. Download the .exe file and run the console application.
2. When prompted, enter the number of nodes in the network.
3. When prompted, enter the adjacency matrix as requested.
4. The output will be MESH, RING, STAR, or NEITHER.

<br />
<br />

## Example #1 (RING)

Number of Nodes: 5

Enter the weight matrix:

0      2     100  100  5
2      0     3     100  100
100  3      0     1     100
100  100  1      0     4
5     100   100  4     0

<br />
<br />


## Example #2 (STAR)

Number of Nodes: 5

Enter the weight matrix:
0  2     3      4     5
2  0     100  100  100
3  100  0     100  100
4  100  100  0     100
5  100  100  100  0

<br />
<br />


## Example #3 (MESH)

Number of Nodes: 5

Enter the weight matrix:
0  1  2  3  4 
1  0  5  2  3
2  5  0  4  1
3  2  4  0  2
4  3  1  2  0

<br />
<br />


## Example #4 (NEITHER)

Number of Nodes: 5

Enter the weight matrix:
0      2     100  4  5
2      0     3     100  100
100  3      0     1     100
4     100  1      0     4
5     100   100  4     0
