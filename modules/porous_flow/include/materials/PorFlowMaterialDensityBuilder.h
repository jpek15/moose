/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/


#ifndef PORFLOWMATERIALDENSITYBUILDER_H
#define PORFLOWMATERIALDENSITYBUILDER_H

#include "DerivativeMaterialInterface.h"
#include "Material.h"

#include "PorFlowVarNames.h"

//Forward Declarations
class PorFlowMaterialDensityBuilder;

template<>
InputParameters validParams<PorFlowMaterialDensityBuilder>();

/**
 * Material designed to form a std::vector of density
 * from the individual phase densities
 */
class PorFlowMaterialDensityBuilder : public DerivativeMaterialInterface<Material>
{
public:
  PorFlowMaterialDensityBuilder(const InputParameters & parameters);

protected:

  unsigned int _num_phases;

  /// The variable names UserObject for the Porous-Flow variables
  const PorFlowVarNames & _porflow_name_UO;

  /// computed density of the phase
  MaterialProperty<std::vector<Real> > & _density;

  /// old value of density of the phase
  MaterialProperty<std::vector<Real> > & _density_old;

  /// d(density)/d(PorFlow variable)
  MaterialProperty<std::vector<std::vector<Real> > > & _ddensity_dvar;

  /// density of each phase
  std::vector<const MaterialProperty<Real> *> _phase_density;

  /// d(density of each phase)/d(var)
  std::vector<const MaterialProperty<std::vector<Real> > *> _dphase_density_dvar;

  virtual void initQpStatefulProperties();
  virtual void computeQpProperties();
};

#endif //PORFLOWMATERIALDENSITYBUILDER_H
