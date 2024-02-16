//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADKernelGrad.h"

/**
 * This class adds PSPG stabilization to the mass equation, enabling use of
 * equal order shape functions for pressure and velocity variables
 */
class NewINSADMass : public ADKernelGrad
{
public:
  static InputParameters validParams();

  NewINSADMass(const InputParameters & parameters);

protected:
  ADRealVectorValue precomputeQpResidual() override;

  const ADVectorVariableValue & _velocity;
};
