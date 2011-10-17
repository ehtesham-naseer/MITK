/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#ifndef BASEPROPERTY_H_HEADER_INCLUDED_C1F4DF54
#define BASEPROPERTY_H_HEADER_INCLUDED_C1F4DF54

#include <string>
#include <itkObjectFactory.h>
#include <MitkExports.h>
#include <mitkCommon.h>

namespace mitk {

/*! \brief Abstract base class for properties
    
  \ingroup DataManagement

    Base class for properties. Properties are arbitrary additional information
    (to define a new type of information you have to define a subclass of
    BaseProperty) that can be added to a PropertyList.
    Concrete subclasses of BaseProperty should define Set-/Get-methods to assess 
    the property value, which should be stored by value (not by reference).
    Subclasses must implement an operator==(const BaseProperty& property), which
    is used by PropertyList to check whether a property has been changed.
*/
class MITK_CORE_EXPORT BaseProperty : public itk::Object
{
  public:

    mitkClassMacro(BaseProperty,itk::Object);

    /*! @brief Subclasses must implement IsEqual(const BaseProperty&) to support comparison.

        operator== which is used by PropertyList to check whether a property has been changed.
    */
    bool operator==(const BaseProperty& property) const;
    
    virtual BaseProperty& operator=(const BaseProperty& property);
    
    virtual std::string GetValueAsString() const;
    
    /*!
      Should be implemented by subclasses to indicate whether they can accept the parameter
      as the right-hand-side argument of an assignment. This test will most probably include
      some dynamic_cast.
     */
    virtual bool Assignable(const BaseProperty& ) const;

  protected:
    BaseProperty();
    
    virtual ~BaseProperty();

  private:
    /*!
      Override this method in subclasses to implement a meaningful comparison. The property
      argument is guaranteed to be castable to the type of the implementing subclass.
    */
    virtual bool IsEqual(const BaseProperty& property) const = 0;
};

} // namespace mitk



#endif /* BASEPROPERTY_H_HEADER_INCLUDED_C1F4DF54 */


