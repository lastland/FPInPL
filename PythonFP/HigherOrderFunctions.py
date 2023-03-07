#!/usr/bin/env python3

import functools
import operator

def scalarProduct(xs, ys):
    zs = map(lambda x: x[0] * x[1], zip(xs, ys))
    return functools.reduce(operator.add, zs, 0)
    
if __name__ == "__main__":
    print("Map on lazy lists:")
    xs = range(1, 6)
    ys = list(map(lambda x: x * 2, xs))
    for i in ys:
        print(i)

    print("Reduce on the list:")
    s = functools.reduce(lambda x, y: x + y, ys, 0)
    print(s)

    print("Scalar product:")
    s = scalarProduct([1,2,3], [4,5,6])
    print(s)
