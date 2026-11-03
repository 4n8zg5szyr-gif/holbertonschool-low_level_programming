# Green Efficiency Analysis

## Measurement Methodology

The experiments use execution time as a performance indicator. The baseline loop was executed three times, with 100,000,000 iterations per run. Its recorded execution times were 0.226186 seconds, 0.227812 seconds, and 0.227386 seconds. The average execution time was 0.227128 seconds.

The algorithm comparison measured a naive algorithm and a single-pass algorithm. Their recorded average execution times were 2.766371 seconds and 0.000106 seconds respectively. The reported relative performance indicates that the naive algorithm was approximately 26,016 times slower.

The instrumentation experiment was executed three times. It measured the total execution time and three separate phases: BUILD_DATA, PROCESS, and REDUCE. The total times were 0.000777, 0.000786, and 0.000718 seconds. The average total time was approximately 0.000760 seconds.

## Observed Performance Differences

The baseline loop showed relatively consistent execution times across its three runs. The difference between its slowest and fastest runs was 0.001626 seconds. This indicates that the measured runtime remained close to 0.227 seconds during these executions.

The algorithm comparison showed a much larger difference. The naive algorithm averaged 2.766371 seconds, while the single-pass algorithm averaged 0.000106 seconds. The measurements therefore show a substantial runtime advantage for the single-pass implementation in this experiment.

However, the recorded results were different: the naive algorithm returned 625025000, while the single-pass algorithm returned 25000. This means the outputs must be checked before concluding that both implementations performed exactly the same computation.

## Relation Between Runtime and Energy Consumption

Execution time can help engineers study computational efficiency. When two implementations perform equivalent work on the same hardware, a shorter runtime may indicate that the processor is active for less time.

The algorithm comparison demonstrates a large difference in measured execution time. If both implementations performed equivalent work, this difference could be relevant when investigating energy efficiency.

However, execution time alone does not measure electrical energy consumption. Energy depends on both power usage and the duration of operation. None of the recorded experiments directly measured electrical power or energy. Therefore, these results cannot establish an exact energy saving.

## Limitations of the Experiment

The experiments were conducted using a limited number of runs: three for the baseline loop and instrumentation experiment. A small sample may not represent performance under all system conditions.

Execution times can also be affected by background processes and available CPU resources. In addition, the algorithm comparison contains different reported output values, so equivalence between the two computations has not been established.

Finally, the experiments use CPU execution time rather than a direct energy measurement. No electrical power meter or energy-monitoring instrument was used.

## Practical Engineering Takeaway

The measurements show that algorithm design can have a major impact on execution time. In this comparison, the single-pass algorithm was substantially faster than the naive algorithm according to the recorded averages.

Engineers should consider algorithm complexity, avoid unnecessary repeated work, and measure performance using repeated tests. They should also verify that compared implementations produce equivalent results.

For green computing, runtime measurements are useful indicators, but they should be combined with direct power or energy measurements before making claims about actual energy savings.
