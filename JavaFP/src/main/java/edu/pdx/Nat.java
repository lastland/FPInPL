package edu.pdx;

import java.util.function.Function;

public interface Nat {
    public Function<Nat, Nat> accept(NatVisitor visitor);
}
