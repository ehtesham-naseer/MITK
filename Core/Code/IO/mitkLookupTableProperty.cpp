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


#include "mitkLookupTableProperty.h"

mitk::LookupTableProperty::LookupTableProperty()
{
}

mitk::LookupTableProperty::LookupTableProperty(const mitk::LookupTable::Pointer lut)
{
    this->SetLookupTable(lut);
}

//mitk::LookupTableProperty::LookupTableProperty(const mitk::LookupTable &aLookupTable)
//{
//    SetLookupTable(aLookupTable);
//}

mitk::LookupTableProperty::~LookupTableProperty()
{
}

bool mitk::LookupTableProperty::IsEqual(const BaseProperty& property) const
{
    return *(this->m_LookupTable) == *(static_cast<const Self&>(property).m_LookupTable);
}

void mitk::LookupTableProperty::SetLookupTable(const mitk::LookupTable::Pointer aLookupTable)
{
//    MITK_INFO << "setting LUT property ... " << std::endl;
   
    if((m_LookupTable != aLookupTable) || (*m_LookupTable != *aLookupTable))
    {
        m_LookupTable = aLookupTable;
        Modified();
    }
          
//    MITK_INFO << "setting LUT property OK! " << std::endl;    
}
