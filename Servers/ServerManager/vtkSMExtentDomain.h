/*=========================================================================

  Program:   ParaView
  Module:    vtkSMExtentDomain.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMExtentDomain - int range domain based on data set extent
// .SECTION Description
// vtkSMExtentDomain is a subclass of vtkSMIntRangeDomain. In its Update
// method, it determines the minimum and maximum extent in each dimension of
// the structured data set with which it is associated. It requires a
// vtkSMSourceProxy to do this.
// .SECTION See Also
// vtkSMIntRangeDomain

#ifndef __vtkSMExtentDomain_h
#define __vtkSMExtentDomain_h

#include "vtkSMIntRangeDomain.h"

class vtkSMProxyProperty;

class VTK_EXPORT vtkSMExtentDomain : public vtkSMIntRangeDomain
{
public:
  static vtkSMExtentDomain* New();
  vtkTypeRevisionMacro(vtkSMExtentDomain, vtkSMIntRangeDomain);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  // Description:
  // Update self checking the "unchecked" values of all required
  // properties. Overwritten by sub-classes.
  virtual void Update(vtkSMProperty*);
  
  // Description:
  // Set the value of an element of a property from the animation editor.
  virtual void SetAnimationValue(vtkSMProperty *property, int idx,
                                 double value);

  // Description:
  // Set the value of an element of a property from the animation editor in
  // a batch script
  virtual void SetAnimationValueInBatch(ofstream *file,
                                        vtkSMProperty *property,
                                        vtkClientServerID sourceID,
                                        int idx, double value);

protected:
  vtkSMExtentDomain();
  ~vtkSMExtentDomain();
  
  void Update(vtkSMProxyProperty *pp);

private:
  vtkSMExtentDomain(const vtkSMExtentDomain&); // Not implemented
  void operator=(const vtkSMExtentDomain&); // Not implemented
};

#endif
