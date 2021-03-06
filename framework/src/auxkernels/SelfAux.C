/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#include "SelfAux.h"

template<>
InputParameters validParams<SelfAux>()
{
  InputParameters params = validParams<AuxKernel>();
  return params;
}

SelfAux::SelfAux(const InputParameters & parameters) :
    AuxKernel(parameters)
{
}

Real
SelfAux::computeValue()
{
  return _u[_qp];
}
