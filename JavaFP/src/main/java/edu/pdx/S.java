package edu.pdx;

import java.util.function.Function;

class S implements Nat {
    private Nat p;

    public S(Nat n) {
        p = n;
    }

    public Nat pred() {
        return p;
    }

    public String toString() {
        return "(S " + p + ")";
    }

    @Override
    public Function<Nat, Nat> accept(NatVisitor visitor) {
        return visitor.visit(this);
    }
}
