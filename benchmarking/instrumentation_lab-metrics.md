# Controlled Instrumentation Experiment

## Run 1
```text
TOTAL seconds: 0.000777
BUILD_DATA seconds: 0.000299
PROCESS seconds: 0.000337
REDUCE seconds: 0.000135
```

## Run 2
```text
TOTAL seconds: 0.000786
BUILD_DATA seconds: 0.000321
PROCESS seconds: 0.000311
REDUCE seconds: 0.000147
```

## Run 3
```text
TOTAL seconds: 0.000718
BUILD_DATA seconds: 0.000269
PROCESS seconds: 0.000308
REDUCE seconds: 0.000135
```

## Measurement boundaries

TOTAL starts immediately before build_dataset() and ends immediately after reduce_checksum().

BUILD_DATA measures only build_dataset().

PROCESS measures only process_dataset().

REDUCE measures only reduce_checksum().

The total measurement includes the three phases and the overhead of the timing calls.

TOTAL should be greater than or equal to each individual phase.

## Analysis

The three phases are measured independently using clock().

The results help identify where CPU execution time is spent.

The measurements represent CPU time, not direct electrical energy consumption.
