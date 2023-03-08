package edu.pdx;

public interface Tree<A extends Comparable> {
    public Tree<A> insert(A v);
}
