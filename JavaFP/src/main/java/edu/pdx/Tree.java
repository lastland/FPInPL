package edu.pdx;

public interface Tree<A extends Comparable<? super A>> {
    public void insert(A v);
}
