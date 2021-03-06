/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/


//  Rogers-Stallybrass-Clements version of effective saturation as a function of CAPILLARY pressure, and derivs wrt that capillary pressure.
//  valid for residual saturations = 0, and viscosityOil = 2*viscosityWater.  (the "2" is important here!).
// C Rogers, MP Stallybrass and DL Clements "On two phase filtration under gravity and with boundary infiltration: application of a Backlund transformation" Nonlinear Analysis Theory Methods and Applications 7 (1983) 785--799.
//
#include "RichardsSeffRSC.h"

Real
RichardsSeffRSC::seff(Real pc, Real shift, Real scale)
{
  Real x = (pc - shift)/scale;
  Real ex = std::exp(x);
  return std::pow(1 + ex, -0.5);
}

Real
RichardsSeffRSC::dseff(Real pc, Real shift, Real scale)
{
  Real x = (pc - shift)/scale;
  Real ex = std::exp(x);
  return -0.5*ex*std::pow(1 + ex, -1.5)/scale;
}

Real
RichardsSeffRSC::d2seff(Real pc, Real shift, Real scale)
{
  Real x = (pc - shift)/scale;
  Real ex = std::exp(x);
  return (0.75*ex*ex*std::pow(1 + ex, -2.5) - 0.5*ex*std::pow(1 + ex, -1.5))/scale/scale;
}
