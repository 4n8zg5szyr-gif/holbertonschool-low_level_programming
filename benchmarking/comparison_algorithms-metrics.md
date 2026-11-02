# Algorithmic Efficiency Comparison

## Execution results

### Run 1
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.779558 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

### Run 2
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.756613 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000107 seconds
```

### Run 3
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.762941 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000106 seconds
```

## Average execution times

- Naive algorithm average: 2.766371 seconds
- Single-pass algorithm average: 0.000106 seconds

## Relative performance

- The naive algorithm is approximately 26016 times slower than the single-pass algorithm.

## Analysis

The naive algorithm uses two nested loops and has O(n²) time complexity.

The single-pass algorithm uses one loop and has O(n) time complexity.

Both implementations count even numbers, but the single-pass implementation is significantly faster because it avoids repeated work.
