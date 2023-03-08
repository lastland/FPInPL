package edu.pdx;

import java.util.function.Function;

public class NatAddVisitor implements NatVisitor {
    @Override
    public Function<Nat, Nat> visit(Z n) {
        return (m)-> m;
    }

    @Override
    public Function<Nat, Nat> visit(S n) {
        Nat n1 = n.pred();
        Function<Nat, Nat> f = n1.accept(this);
        return f.andThen((m) -> new S(m));
    }
}
