

## Graph-Isomorphism

2-1, CS-F222, Discrete Structures for CS Assignment. We have to report if two ```undirected graphs``` are ```isomorphic``` or not.

## Part A

> Output the degree sequence of the graph.
> The ```degree sequence``` is obtained by determining the degrees of each node in the graph and arranging it as a sequence in non-increasing order.

### Input
> The first line of the input would be an integer n - the number of nodes.
> Second line of the input would be an integer e - the number of edges The next e lines contain a pair x and y ( 1≤ x,y ≤ n and x ≠ y) , to indicate that
> there is an edge between nodes numbered x and y.

### Output
> Output the degree sequence in non-increasing order. Output should be printed in standard output.


## Installation

```bash
gcc PartA.c
./a.out ./TestA/a.txt
```

## Part B

> Determine if two given input graphs are ```isomorphic``` or not.
> Check for some ```invariants```, namely you have to check if the number of nodes, number of edges, degree sequence are same for both graphs or not.

### Input
> The first line of the input would be an integer n - the number of nodes.
> Second line of the input would be an integer e - the number of edges The next e lines contain a pair x and y ( 1≤ x,y ≤ n and x ≠ y) , to indicate that
> there is an edge between nodes numbered x and y.

### Output
> If the graphs come out to isomorphic output “Isomorphic” and also output a bijective mapping of the nodes that preserves adjacency.
> However, if the graphs turn out to be non isomorphic output “Not Isomorphic, no bijection found.”

## Installation

```bash
make
./run ./TestB/a.txt ./TestB/c.txt
```
#### To remove the object and exe files use

```bash
make clean
```
<br/><br/>
<p align = "center">
<img src = "https://user-images.githubusercontent.com/97559428/206896007-184b1a25-63c5-4642-93cc-1df7b7eaab57.gif" width = "500px" height = "500px">
</p>

