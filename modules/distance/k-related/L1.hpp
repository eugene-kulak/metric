#ifndef _METRIC_DISTANCE_DETAILS_K_RELATED_L1_HPP
#define _METRIC_DISTANCE_DETAILS_K_RELATED_L1_HPP
/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.

Copyright (c) 2019 Panda Team
*/

#include "../../../3rdparty/blaze/Blaze.h"


namespace metric
{


// the UNFINISHED code for L1 metrics from the review papaer


/*


template <typename V>
struct Sorensen_t  // version similar to the existing code
{
    using value_type = V;
    using distance_type = value_type;

    Sorensen_t() = default;

    template<typename Container>
    //typename std::enable_if<!std::is_same<Container, V>::value, distance_type>::type // compiled only if Container differs from V
    distance_type
    operator()(const Container &a, const Container &b) const;

    //distance_type
    //operator()(const V &a, const V &b) const;

};


struct Sorensen_s // version without type members
{
    Sorensen_s() = default;

    template<typename Container>
    typename Container::value_type operator()(const Container &a, const Container &b) const;
};



template <typename V>
struct Sorensen
{
    //using value_type = V;
    //using distance_type = value_type;

    Sorensen() = default;

    template <typename Container>
    V operator()(const Container &a, const Container &b) const;

    template <typename ValueType>
    V operator()(const blaze::CompressedVector<ValueType> &a, const blaze::CompressedVector<ValueType> &b) const;
};

*/


//template <template <typename> class Container, typename Value>
//double sorensen(Container<Value> &a, Container<Value> &b);

//template <template <typename, typename> class Container, typename Value, typename Allocator>
//double sorensen(Container<Value, Allocator> &a, Container<Value, Allocator> &b);


template <typename T>
double sorensen(T &a, T &b);


template <typename Value>
double sorensen(blaze::CompressedVector<Value> &a, blaze::CompressedVector<Value> &b);

} // namespace metric

#include "L1.cpp"

#endif // Header Guard