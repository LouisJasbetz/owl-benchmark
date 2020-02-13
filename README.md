# owl-benchmark
Computer benchmarking application.

## Compiling:
```
$ g++ main.cpp -o owl-benchmark
$ ./owl-benchmark --help

owl-benchmark v1.0.1.

Usage:
        owl-benchmark [--memory | --help]

$
```

## Memory Benchmark (--memory):

### WARP (PC Engines)
```
    Writing 10G of data took 416 s, speed 23.984 MB/s
    Reading 10G of data took 490 s, speed 20.385 MB/s
    Copy 10G of data took 170 s, speed 58.607 MB/s
```

### Pentium 4 - 1,7GHz
```
    Writing 10G of data took 18 s, speed 546.060 MB/s
    Reading 10G of data took 25 s, speed 399.760 MB/s
    Copy 10G of data took 19 s, speed 504.337 MB/s
```

### Pentium - 1,8 GHz
```
    Writing 10G of data took 12 s, speed 833.333 MB/s
    Reading 10G of data took 12 s, speed 797.003 MB/s
    Copy 10G of data took 8 s, speed 1194.030 MB/s
```

### AMD Athlon - 2 GHz
```
    Writing 10G of data took 15 s, speed 631.792 MB/s
    Reading 10G of data took 10 s, speed 980.008 MB/s
    Copy 10G of data took 9 s, speed 1056.078 MB/s
```

### Centrino Duo - 1,66Ghz
```
    Writing 10G of data took 15 s, speed 634.211 MB/s
    Reading 10G of data took 19 s, speed 514.060 MB/s
    Copy 10G of data took 9 s, speed 1107.174 MB/s
```

### Raspberry PI 1 Model B
```
    Writing 10G of data took 452 s, speed 22.090 MB/s
    Reading 10G of data took 575 s, speed 17.373 MB/s
    Copy 10G of data took 27 s, speed 364.378 MB/s
```

### Raspberry PI 3 Model B
```
    Writing 10G of data took 125 s, speed 79.673 MB/s
    Reading 10G of data took 210 s, speed 47.598 MB/s
    Copy 10G of data took 8 s, speed 1169.727 MB/s
```

### Intel i5-2500K - 3.3 GHz
```
    Writing 10G of data took 5 s, speed 1695.778 MB/s
    Reading 10G of data took 5 s, speed 1718.804 MB/s
    Copy 10G of data took 1 s, speed 5773.672 MB/s
```

EOF
