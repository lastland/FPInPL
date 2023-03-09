package edu.pdx;

public class Node<A extends Comparable<? super A>> implements Tree<A> {
    public Tree<A> left;
    public Tree<A> right;
    public A value;

    public Node(A v) {
        left = null;
        right = null;
        value = v;
    }

    public Node(Tree<A> l, A v, Tree<A> r) {
        left = l;
        right = r;
        value = v;
    }

    @Override
    public void insert(A v) {
        if (v.compareTo(value) < 0) {
            if (left != null) {
                left.insert(v);
            } else {
                left = new Node<A>(v);
            }
        } else if (v.compareTo(value) > 0) {
            if (right != null) {
                right.insert(v);
            } else {
                right = new Node<A>(v);
            }
        }
    }

    public String toString() {
        String l = "Empty";
        if (left != null) {
            l = left.toString();
        }
        String r = "Empty";
        if (right != null) {
            r = right.toString();
        }
        return "(" + l + ", " + value + ", " + r + ")";
    }
}
