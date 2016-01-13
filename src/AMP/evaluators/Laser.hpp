//*****************************************************************//
//    Albany 2.0:  Copyright 2012 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//

#ifndef _AMP_LASER_HPP_
#define _AMP_LASER_HPP_

#include "Phalanx_config.hpp"
#include "Phalanx_Evaluator_WithBaseImpl.hpp"
#include "Phalanx_Evaluator_Derived.hpp"
#include "Phalanx_MDField.hpp"
#include "Teuchos_ParameterList.hpp"
#include "Epetra_Vector.h"
#include "Sacado_ParameterAccessor.hpp"
#include "Stokhos_KL_ExponentialRandomField.hpp"
#include "Teuchos_Array.hpp"
#include "Albany_Layouts.hpp"



namespace AMP
{
  // define a structure to store laser center info
  struct LaserCenter
  {
    RealType t; // time
    RealType x; // x-ccordinate
    RealType z; // z-coordinate
    int power;  // 1 => laser active. 0 => laser inactive
  };

  class Laser
  {
  public:
    // default constructor
    Laser();
    // copy constructor
    Laser(const Laser &A);
    // destructor
    ~Laser();
    // get LaserData_
    const Teuchos::Array<LaserCenter> &getLaserData();
    // interpolate
    void getLaserPosition(RealType time, LaserCenter val, RealType &x, RealType &z, int &power);
  private:
    Teuchos::Array<LaserCenter> LaserData_;
  };
  
  bool compLaserCenter(LaserCenter A, LaserCenter B);

}

#endif
