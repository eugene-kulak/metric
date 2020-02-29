/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.

Copyright (c) 2019 Panda Team
*/

#ifndef _METRIC_MAPPING_ESN_HPP
#define _METRIC_MAPPING_ESN_HPP

#include "../../3rdparty/blaze/Blaze.h"

#include  "PCFA.hpp" // this is for metafunctions determine_container_type and determine_container_type
// TODO move them to some single common unit and include it instead of PCFA.hpp !!

namespace metric {



//// common metafunctions for ESN, PCFA and DSPCC - included from PCFA.hpp


//template <typename>
//struct determine_container_type  // checks whether container is STL container (1) or Blaze vector (2)
//{
//    constexpr static int code = 0;
//};

//template <template <typename, typename> class Container, typename ValueType, typename Allocator>
//struct determine_container_type<Container<ValueType, Allocator>>
//{
//    constexpr static int code = 1;
//};

//template <template <typename, bool> class Container, typename ValueType, bool F>
//struct determine_container_type<Container<ValueType, F>>
//{
//    constexpr static int code = 2;
//};



//template<typename C, int = determine_container_type<C>::code>
//struct determine_element_type  // determines type of element both for STL containers and Blaze vectors
//{
//    using type = void;
//};

//template<typename C>
//struct determine_element_type<C, 1>
//{
//    using type = typename C::value_type;
//};

//template<typename C>
//struct determine_element_type<C, 2>
//{
//    using type = typename C::ElementType;
//};






/**
 * @class ESN
 * 
 * @brief 
 */
template <typename recType, typename Metric>
class ESN {

public:

    using value_type = typename determine_element_type<recType>::type;

    /**
     * @brief Construct a new ESN object
     * 
     * @param w_size 
     * @param w_connections 
     * @param w_sr 
     * @param alpha_ 
     * @param washout_ 
     * @param beta_ 
     */
    ESN(size_t w_size = 500,  // number of elements in reservoir
        value_type w_connections = 10,  // number of interconnections (for each reservoir element)
        value_type w_sr = 0.6,  // desired spectral radius of the reservoir
        value_type alpha_ = 0.5,  // leak rate, number of slices excluded from output for washout
        size_t washout_ = 1,
        value_type beta_ = 0.5  // ridge solver metaparameter
    );

    /**
     * @brief 
     * 
     * @param Slices 
     * @param Target 
     */
    void train(const blaze::DynamicMatrix<value_type>& Slices, const blaze::DynamicMatrix<value_type>& Target);

    /**
     * @brief
     *
     * @param Slices
     * @param Target
     */
    void train(const std::vector<recType> & Slices, const std::vector<recType> & Target);


    /**
     * @brief 
     * 
     * @param Slices 
     * @return 
     */
    blaze::DynamicMatrix<value_type> predict(const blaze::DynamicMatrix<value_type>& Slices);

    /**
     * @brief
     *
     * @param Slices
     * @return
     */
    std::vector<recType> predict(const std::vector<recType> & Slices);


private:
    blaze::DynamicMatrix<value_type> W_in;
    blaze::CompressedMatrix<value_type> W;
    blaze::DynamicMatrix<value_type> W_out = blaze::DynamicMatrix<value_type>(0, 0);
    bool trained = false;
    value_type alpha = 0.5;
    value_type beta = 0.5;
    size_t washout = 1;
    std::default_random_engine rgen;

    void create_W(size_t w_size, value_type w_connections, value_type w_sr);

    blaze::DynamicMatrix<value_type> vector_to_blaze(const std::vector<recType> & In);

    template <typename R>
    typename std::enable_if <
     determine_container_type<R>::code == 1,
     std::vector<R>
    >::type
    blaze2rectype(const blaze::DynamicMatrix<typename ESN<R, Metric>::value_type> & In);

    template <typename R>
    typename std::enable_if<
     determine_container_type<R>::code == 2,
     std::vector<R>
    >::type
    blaze2rectype(const blaze::DynamicMatrix<typename ESN<R, Metric>::value_type> & In);

};  // class ESN

}  // namespace metric

#include "ESN.cpp"

#endif  // _METRIC_MAPPING_DETAILS_ESN_HPP
