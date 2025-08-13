#ifndef HORRIBLE_UTILS_HPP_
#define HORRIBLE_UTILS_HPP_

#include <cstddef>              // std::size_t

namespace horrible::utils
{

template<typename T, T... ints>
class integer_sequence {
public:
    using value_type = T;
    static constexpr std::size_t size() noexcept { return sizeof...(ints); }
};

template<std::size_t... ints>
using index_sequence = integer_sequence<std::size_t, ints...>;






}                   // end namespace horrible::utils


namespace horrible::utils::inline detail 
{




}                   // end namespace horrible::utils::inline detail

#endif              // HORRIBLE_UTILS_HPP_