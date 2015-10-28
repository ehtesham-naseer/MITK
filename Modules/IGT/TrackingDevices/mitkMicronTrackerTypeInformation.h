/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#ifndef mitkMicronTrackerTypeInformation_h
#define mitkMicronTrackerTypeInformation_h

#include <MitkIGTExports.h>

#include "mitkTrackingDeviceTypeInformation.h"

namespace mitk
{

  static TrackingDeviceData DeviceDataMicronTrackerH40 = {TRACKING_DEVICE_IDENTIFIER_MICRON, "Micron Tracker H40", "ClaronMicron.stl", "X"};

  class MITKIGT_EXPORT MicronTrackerTypeInformation : public TrackingDeviceTypeInformation
  {
    public:
      MicronTrackerTypeInformation();
      virtual ~MicronTrackerTypeInformation();

      virtual TrackingDeviceSource::Pointer CreateTrackingDeviceSource(mitk::TrackingDevice::Pointer trackingDevice,
                                                                       mitk::NavigationToolStorage::Pointer navigationTools,
                                                                       std::string* errorMessage,
                                                                       std::vector<int>* toolCorrespondencesInToolStorage) override;
  };
} // namespace mitk

#endif //mitkMicronTrackerTypeInformation_h
