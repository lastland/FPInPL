package edu.pdx;

import java.util.function.Function;

public interface NatVisitor {
    public Function<Nat, Nat> visit(Z n);
    public Function<Nat, Nat> visit(S n);
}
