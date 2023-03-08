package edu.pdx;

import java.util.stream.Stream;

public class Main
{
    public static void main(String[] args) {
        Stream<Integer> xs = Stream.of(1, 2, 3, 4, 5);
        xs.map((i) -> i * 2 ).forEach((s) -> { System.out.println(s); });
    }
}
