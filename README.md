# Search Algorithms

This project contains implementations of various search algorithms and data structures, including B-Trees and KD-Trees. The project is organized into different components, each focusing on a specific algorithm or data structure.

## Project Structure

- **b_tree.cpp**: Contains the implementation of a B-Tree data structure, which is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.

- **ann/tree/kd_tree.cpp**: Implements a KD-Tree, which is a space-partitioning data structure for organizing points in a k-dimensional space. It is useful for applications that involve multidimensional search keys, such as range searches and nearest neighbor searches.

- **utils/my_limits.hpp**: Provides custom limits for data types, specifically defining maximum and minimum values for `double` types.

## Usage

### B-Tree

The B-Tree implementation includes basic operations such as insertion and splitting of nodes. It is designed to handle large amounts of data efficiently.

### KD-Tree

The KD-Tree implementation supports insertion of points and finding the nearest neighbor for a given query point. The main function demonstrates how to use the KD-Tree to insert points and query the nearest neighbor.

### Custom Limits

The `my_limits.hpp` file defines custom limits for `double` types, which are used in the KD-Tree implementation to handle maximum and minimum values.

## Compilation

To compile the KD-Tree example, you can use a C++ compiler like `g++`. Here is a sample command to compile `kd_tree.cpp`:

```bash
g++ -o kd_tree ann/tree/kd_tree.cpp
```

Run the compiled program:

```bash
./kd_tree
```

## License

This project is open-source and available under the MIT License.
