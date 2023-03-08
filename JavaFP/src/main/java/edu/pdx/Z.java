package edu.pdx;

import java.util.function.Function;

class Z implements Nat {
    public String toString() {
        return "Z";
    }

    @Override
    public Function<Nat, Nat> accept(NatVisitor visitor) {
        return visitor.visit(this);
    }

}
