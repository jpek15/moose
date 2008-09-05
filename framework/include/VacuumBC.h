#include "BoundaryCondition.h"

#ifndef VACUUMBC_H
#define VACUUMBC_H

//Forward Declarations
class VacuumBC;

/**
 * Implements a simple Vacuum BC for neutron diffusion on the boundary.
 * Vacuum BC is defined as \f$ D\frac{du}{dn}+\frac{u}{2} = 0\f$, where u is neutron flux.
 * Hence, \f$ D\frac{du}{dn}=-\frac{u}{2} \f$ and \f$ -\frac{u}{2} \f$ is substitute into 
 * the Neumann BC term produced from integrating the diffusion operator by parts.
 */
class VacuumBC : public BoundaryCondition
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  VacuumBC(Parameters parameters, std::string var_name, unsigned int boundary_id)
    :BoundaryCondition(parameters, var_name, true, boundary_id)
  {}

  virtual ~VacuumBC(){}

protected:
  virtual Real computeQpResidual()
  {
    return _phi_face[_i][_qp]*_u[_qp]/2.;
  }
  virtual Real computeQpJacobian()
  {
    return _phi_face[_i][_qp]*_phi_face[_j][_qp]/2.;    
  }
};

#endif //VACUUM_H
