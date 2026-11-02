# Green Efficiency Analysis

## Measurement Methodology

The experiments used the C `clock()` function to measure CPU execution time. The elapsed CPU time was calculated by subtracting the starting clock value from the ending clock value and dividing the result by `CLOCKS_PER_SEC`.

Each experiment was executed three times. The recorded results were then used to calculate average execution times.

The baseline experiment executed 100,000,000 loop iterations. The algorithm comparison experiment evaluated two methods for counting even numbers: a naive implementation using nested loops and a single-pass implementation using one loop. Finally, the controlled instrumentation experiment measured three separate functions: `build_dataset()`, `process_dataset()`, and `reduce_checksum()`.

## Observed Performance Differences

The baseline loop completed 100,000,000 iterations in an average of 0.227128 seconds. Its three recorded execution times were 0.226186, 0.227812, and 0.227386 seconds. The relatively small differences show that the measured execution time remained consistent across these runs.

The algorithm comparison showed a much larger performance difference. The naive algorithm had an average execution time of 2.766371 seconds, while the single-pass algorithm averaged approximately 0.000106333 seconds. The naive implementation was approximately 26,016 times slower.

Both implementations produced results for counting even numbers, but the naive implementation used nested loops with O(n²) time complexity. The single-pass implementation used one loop with O(n) time complexity. These results demonstrate the significant runtime impact of avoiding repeated operations.

In the instrumentation experiment, the average total execution time was approximately 0.000760333 seconds. The average times for the individual phases were 0.000296333 seconds for BUILD_DATA, 0.000318667 seconds for PROCESS, and 0.000139 seconds for REDUCE. PROCESS was the longest measured phase in all three runs.

## Relation Between Runtime and Energy Consumption

Execution time can help evaluate software efficiency because a program that finishes sooner may require fewer CPU resources over time. However, runtime alone does not establish how much electrical energy a program consumes.

The experiments measured CPU time using `clock()`. They did not measure electrical power in watts or energy in joules. Therefore, the results can demonstrate differences in execution performance, but they cannot prove that one implementation consumed a specific amount of energy or was more energy-efficient.

## Limitations of the Experiment

Several limitations affect the interpretation of these results. First, each experiment was executed only three times, which provides a limited sample. System activity, processor scheduling, and available CPU resources may influence the measurements.

Second, the experiments were performed in a particular computing environment. Different processors, compiler versions, compiler optimization settings, and operating systems could produce different execution times.

Third, the instrumentation experiment measures very short operations. The timing calls themselves may represent a noticeable part of the measured duration. Finally, no direct power or energy measurement equipment was used.

## Practical Engineering Takeaway

The experiments show that algorithm design has a major impact on execution time. In particular, replacing a nested-loop solution with a single-pass solution reduced the measured runtime dramatically.

Software engineers should consider algorithmic complexity, avoid unnecessary repeated operations, and measure performance before and after optimization. Instrumentation can also identify which parts of a program take the most CPU time.

For greener software engineering, runtime optimization is a useful starting point, but it should be combined with direct energy measurements before making claims about actual electricity consumption.
