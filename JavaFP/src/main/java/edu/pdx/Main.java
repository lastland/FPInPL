package edu.pdx;

import java.util.stream.Stream;

public class Main
{
    public static void main(String[] args) {
        Stream<Integer> xs = Stream.of(1, 2, 3, 4, 5);
        xs.map((i) -> i * 2 ).forEach((s) -> { System.out.println(s); });

        Nat zero = NatFactory.Z();
        Nat one = NatFactory.S(zero);
        Nat two = NatFactory.S(one);

        NatAddVisitor v = new NatAddVisitor();
        System.out.println(zero.accept(v).apply(two)); // Expecting two
        System.out.println(two.accept(v).apply(two));  // Expecting four
    }
}
