#ifndef HORRIBLE_UTILS_HPP_
#define HORRIBLE_UTILS_HPP_

#include <vector>
#include <utility>
#include <array>
#include <memory>

namespace horrible::utils
{



template<size_t... IDX, typename T>
void fill_values(std::index_sequence<IDX...>, T& row, std::vector<double>& data) {
    data.insert(data.end(), {std::get<IDX>(row)...});
}


/*
    - each datapoint is a value of type `double`
    - a Sample is a row of `COLS` doubles
    - a Dataset is a collection of `Sample` objects.

    - EX: a Dataset of 6 Samples

    1   2   3   4   5           
    0   0   0   0   0
    1   2   1   2   1
    0   2   4   1   4
    0   0   2   2   2
    9   9   9   8   8

*/



using DTYPE = double;

template<size_t COLS> 
using Sample = std::array<DTYPE, COLS>;

template<size_t COLS>
using Dataset = std::vector<Sample<COLS>>;


template<size_t COLS>
class Range {
public:
    Range(std::vector<size_t>&& i, Dataset<Cols> const* d): i_{std::move(i)}, d_{d} { }
    
    
    size_t size() const { return i_.size(); }

    // Clang did this for their clang::SourceLocation, etc...
    DTYPE at(size_t r, size_t c) const {
        return (*d_)[i_[r]][c];
    }

private:
    std::vector<size_t>     i_ { };
    Dataset<COLS> const*    d_ { };
};


class Node {
public:
    Node() = default;

    // explicitly deleted copy operations:
    Node(Node const&) = delete;
    Node& operator=(Node const&) = delete;


    Node(std::unique_ptr<Node> left, std::unique_ptr<Node> right, size_t split_col, DTYPE split_value)
        : left_(std::move(left)),
          right_(std::move(right)),
          split_col_(split_col),
          split_value_(split_value) { }

    Node(size_t size): size_{size}, is_external_{true} { }
        
private:
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
    size_t split_col_;
    DTYPE split_value_;
    size_t size_;

    bool is_external_ { };
};

}                   // end namespace horrible::utils

#endif              // HORRIBLE_UTILS_HPP_