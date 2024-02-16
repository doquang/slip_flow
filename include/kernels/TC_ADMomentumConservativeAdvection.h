
#pragma once

#include "ADKernelGrad.h"

class TC_ADMomentumConservativeAdvection : public ADVectorKernelGrad
{
public:
  TC_ADMomentumConservativeAdvection(const InputParameters & parameters);
  static InputParameters validParams();

protected:
  ADRealTensorValue precomputeQpResidual() override;

  /// This model calculates a kinematic viscosity, so rho must multiply this
  const ADMaterialProperty<Real> & _rho;
};