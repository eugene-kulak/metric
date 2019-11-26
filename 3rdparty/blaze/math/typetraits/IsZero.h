//=================================================================================================
/*!
//  \file blaze/math/typetraits/IsZero.h
//  \brief Header file for the IsZero type trait
//
//  Copyright (C) 2012-2019 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_TYPETRAITS_ISZERO_H_
#define _BLAZE_MATH_TYPETRAITS_ISZERO_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include "../../math/typetraits/IsExpression.h"
#include "../../math/typetraits/IsStrictlyLower.h"
#include "../../math/typetraits/IsStrictlyUpper.h"
#include "../../util/EnableIf.h"
#include "../../util/IntegralConstant.h"
#include "../../util/typetraits/IsSame.h"


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename T > struct IsZero;
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Auxiliary helper struct for the IsZero type trait.
// \ingroup math_traits
*/
template< typename T
        , typename = void >
struct IsZeroHelper
   : public BoolConstant< IsStrictlyLower_v<T> && IsStrictlyUpper_v<T> >
{};

template< typename T >  // Type of the operand
struct IsZeroHelper< T, EnableIf_t< IsExpression_v<T> && !IsSame_v<T,typename T::ResultType> > >
   : public IsZero< typename T::ResultType >::Type
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Compile time check for zero vectors or matrices.
// \ingroup math_type_traits
//
// This type trait tests whether or not the given template parameter is a zero vector or matrix
// type (i.e. a vector or matrix type that is guaranteed to be zero at compile time). In case the
// type is a zero vector or matrix type, the \a value member constant is set to \a true, the nested
// type definition \a Type is \a TrueType, and the class derives from \a TrueType. Otherwise
// \a value is set to \a false, \a Type is \a FalseType, and the class derives from \a FalseType.

   \code
   using DiagonalMatrixType = blaze::DiagonalMatrix< StaticMatrix<float,3UL,3UL> >;

   blaze::IsZero< ZeroVector<int> >::value          // Evaluates to 1
   blaze::IsZero< const ZeroMatrix<float> >::Type   // Results in TrueType
   blaze::IsZero< volatile ZeroMatrix<double> >     // Is derived from TrueType
   blaze::IsZero< DynamicMatrix<int> >::value       // Evaluates to 0
   blaze::IsZero< const DiagonalMatrixType >::Type  // Results in FalseType
   blaze::IsZero< volatile CompressedMatrix<int> >  // Is derived from FalseType
   \endcode
*/
template< typename T >
struct IsZero
   : public IsZeroHelper<T>
{};
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsZero type trait for const types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsZero< const T >
   : public IsZero<T>
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsZero type trait for volatile types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsZero< volatile T >
   : public IsZero<T>
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsZero type trait for cv qualified types.
// \ingroup math_type_traits
*/
template< typename T >
struct IsZero< const volatile T >
   : public IsZero<T>
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Auxiliary variable template for the IsZero type trait.
// \ingroup math_type_traits
//
// The IsZero_v variable template provides a convenient shortcut to access the nested \a value
// of the IsZero class template. For instance, given the type \a T the following two statements
// are identical:

   \code
   constexpr bool value1 = blaze::IsZero<T>::value;
   constexpr bool value2 = blaze::IsZero_v<T>;
   \endcode
*/
template< typename T >
constexpr bool IsZero_v = IsZero<T>::value;
//*************************************************************************************************

} // namespace blaze

#endif
