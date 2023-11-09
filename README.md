# Sorting Algorithms Performance Evaluation Project

## Overview

This project aims to assess the efficiency of various sorting algorithms under different input conditions. By generating arrays with distinct patterns and measuring the execution times, we compare how each algorithm performs, providing insights into their behavior for sorting tasks.

## Application Functionality

### Features:

- **Data Generation**: Arrays are generated in ascending, descending, or random order, defined by parameters in **`comparison.h`**.
- **Sorting Functions**: Implemented in **`sorting.h`**, e.g., **`void bubbleSort(int *, int);`**.
- **Execution Timing**: Sorting times are recorded using the system clock, adhering to the formula: `n = (MinimumSize - MaximumSize) / IncrementValue + 1`.
- **Results Recording**: Execution times for each algorithm and array size are stored in a results matrix.
- **Cumulative Moving Average**: Averages are updated after each data point, using the formula: `(x1 + x2 + … + xt) / t`.
- **Output**: Timing data is exported to **`data.txt`** in a tabular layout, listing sorting method, array size, and execution time.
- **Visualization**: **`script.bash`** uses **`gnuplot`** to plot execution times against array sizes in **`execution_time.png`**.

## Benchmarking Methodology

### Test Environment

- **Hardware**: Intel Core i7-10700KF, 32GB RAM, 512GB SSD
- **Software**: WSL2 Ubuntu 22.04 LTS, GCC 11.4.0, GNU Make 4.3, gnuplot 5.4

### Data Types

- **Sorted Arrays**: To evaluate efficiency when minimal sorting is needed.
- **Reversed Arrays**: To test algorithms under maximum strain.
- **Random Arrays**: To assess average performance.

Array sizes scale from small to large in predefined increments.

## Results and Analysis

### Test 1: Pre-sorted arrays

Results show:

![Untitled](https://github.com/marwaneRomani/sorting-algorithms-comparison/assets/96589855/0d13df19-afd0-413b-93ac-fd0e6bd5735f)


- **Bubble Sort**: Potential for early termination to improve O(n^2) complexity.
- **Selection Sort**: Consistently O(n^2) due to non-optimization for pre-sorted data.
- **Insertion Sort**: Nearly O(n), performing well with pre-sorted data.
- **Heap Sort**: Unaffected by pre-sorting, maintains O(n log n).
- **Quick Sort**: Worst-case O(n^2) without pivot optimization.
- **Merge Sort**: Steady O(n log n) regardless of pre-sorting.

### Test 2: Reversed arrays

![Untitled 1](https://github.com/marwaneRomani/sorting-algorithms-comparison/assets/96589855/18087fbd-0521-478f-b95a-44f078542fd8)



Performance details:

- **Bubble Sort**: O(n^2) due to maximum swaps needed.
- **Selection Sort**: O(n^2) as pre-sorting order has no impact.
- **Insertion Sort**: Decreased efficiency at O(n^2) with reverse data.
- **Heap Sort**: Consistent O(n log n) as heap construction is order-agnostic.
- **Quick Sort**: O(n^2) due to unbalanced partitions without pivot optimizations.
- **Merge Sort**: Maintains O(n log n) through systematic decomposition and merging.

### Test 3: Random arrays
![Untitled 2](https://github.com/marwaneRomani/sorting-algorithms-comparison/assets/96589855/1cac6838-87c9-496e-90fb-218bfaa0c930)


Key observations:

- **Quick Sort**: Improved to O(n log n) due to less chance of worst-case partitions.

## Conclusion

The project highlights that algorithm selection is a multifaceted decision, relying on more than just time complexity—data size, element order, and memory constraints are crucial. Each algorithm's strengths and weaknesses should guide the optimal choice, tailored to specific sorting needs.

---

## Usage

To run the performance evaluation, follow these steps:

1. Generate arrays by setting the desired parameters in **`main.c`**.
2. Run **`script.bash`** to visualize results with gnuplot.

Ensure all prerequisites are installed on your system before running the tests.
