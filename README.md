# 2D Interpolation


## Task Description
----

Write a function that does a [bilinear interpolation](https://en.wikipedia.org/wiki/Bilinear_interpolation) on a 2D grid of data-points. 

<img src="https://i.ibb.co/681rdms/Screenshot-2020-04-03-at-16-19-50.png" width="200">

The function shall have the following API
```c++
using DataGrid = std::vector<std::vector<float>>;
using LookupPoint = std::pair<float, float>;
float Interpolate2D(const DataGrid& data_grid, const LookupPoint& lookup_point);
```
The DataGrid can be expected to be a [cartesian 2D grid](https://en.wikipedia.org/wiki/Regular_grid "Regular grid"). For the sake of this example we assume the non-negative indices x and y to be equal to the index. The entry at x, y is the corresponding z-value. Hence the following grid and lookup point:
```c++
const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};
// e.g. 1.0F == data_grid[1][0]
const LookupPoint lookup_point{0.8F, 0.4F};
```
can be visualized as the following:

![enter image description here](https://i.ibb.co/5L4XdTg/image-5.png)


## Example
const DataGrid data_grid{{0.0F, 2.0F}, {1.0F, 3.0F}};

## Edge cases
---
**If the lookup point is out of bounds, and therefore can not be mapped to either one or multiple grid entries, the algorithm should assert!**