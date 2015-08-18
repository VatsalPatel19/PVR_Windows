//-*-c++-*--------------------------------------------------------------------//

/*
    This file is part of PVR. Copyright (C) 2012 Magnus Wrenninge

    PVR is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PVR is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//----------------------------------------------------------------------------//

/*! \file Types.h
  Contains the Types class and related functions.
 */

//----------------------------------------------------------------------------//

#ifndef __INCLUDED_PVR_TYPES_H__
#define __INCLUDED_PVR_TYPES_H__

//----------------------------------------------------------------------------//
// Includes
//----------------------------------------------------------------------------//

// System includes

#include <stdexcept>

// Library includes

#include <boost/smart_ptr/shared_ptr.hpp>

#include <Imath/ImathBox.h>
#include <Imath/ImathColor.h>
#include <Imath/ImathEuler.h>
#include <Imath/ImathLine.h>
#include <Imath/ImathMatrix.h>
#include <Imath/ImathPlane.h>
#include <Imath/ImathQuat.h>
#include <Imath/ImathVec.h>

#include <Field3D/Field.h>

//----------------------------------------------------------------------------//
// Namespaces 
//----------------------------------------------------------------------------//

namespace pvr {

//----------------------------------------------------------------------------//
// Smart pointers
//----------------------------------------------------------------------------//
 
#define PVR_TYPEDEF_SMART_PTRS(name)            \
  typedef boost::shared_ptr<name>       Ptr;    \
  typedef boost::shared_ptr<const name> CPtr;   \

#define PVR_DEFINE_CREATE_FUNC(name)            \
  static Ptr create()                           \
  { return Ptr(new name); }                     \
  
#define PVR_DEFINE_CREATE_FUNC_1_ARG(name, argType)     \
  static Ptr create(argType arg)                        \
  { return Ptr(new name(arg)); }                        \

#define PVR_DEFINE_CREATE_FUNC_2_ARG(name, argType1, argType2)   \
  static Ptr create(argType1 arg1, argType2 arg2)                \
  { return Ptr(new name(arg1, arg2)); }                          \

#define PVR_DEFINE_CREATE_FUNC_3_ARG(name, argType1, argType2, argType3) \
  static Ptr create(argType1 arg1, argType2 arg2, argType3 arg3)        \
  { return Ptr(new name(arg1, arg2, arg3)); }                           \

#define PVR_DEFINE_TYPENAME(name)               \
  virtual std::string typeName() const          \
  { return std::string(#name); }                \

//----------------------------------------------------------------------------//

namespace Util {

  //! Traits class, assists in creating a shared pointer to a given type.
  template <typename T>
  struct SPtr
  {
    //! Access to type
    typedef boost::shared_ptr<T> type;
  };

}

//----------------------------------------------------------------------------//
// Interval
//----------------------------------------------------------------------------//

//! Represents a single integration interval. This communicates to a raymarcher
//! what parts of a ray should be integrated, and is normally only created
//! by the Volume::intersect() routines.
//! The interval is assumed to be inclusive, i.e. [t0,t1].
struct Interval
{
  // Constructor ---------------------------------------------------------------

  //! Default constructor
  Interval(double start, double end, double step)
    : t0(start), t1(end), stepLength(step) 
  { }

  // Public data members -------------------------------------------------------

  //! The start of the interval (inclusive)
  double t0;
  //! The end of the interval (inclusive)
  double t1;
  //! The world space step length that is reasonable to use for the given 
  //! interval.
  double stepLength;
};

typedef std::vector<Interval> IntervalVec;

//----------------------------------------------------------------------------//
// Common PVR types
//----------------------------------------------------------------------------//

typedef Imath::Box3d   BBox;
typedef Imath::Box3i   DiscreteBBox;
typedef Imath::C3f     Color;
typedef Imath::Eulerd  Euler;
typedef Imath::Line3d  Ray;
typedef Imath::M44d    Matrix;
typedef Imath::Plane3d Plane;
typedef Imath::Quatd   Quat;
typedef Imath::V3d     Vector;

//----------------------------------------------------------------------------//

} // namespace pvr

//----------------------------------------------------------------------------//

#endif // Include guard
