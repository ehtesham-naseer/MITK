/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef QmitkImageAndRoiDataGeneratorBase_h
#define QmitkImageAndRoiDataGeneratorBase_h

#include "QmitkDataGeneratorBase.h"
#include <MitkImageStatisticsUIExports.h>

/*!
Base class that can be used for generators that should alow the image nodes and the ROI nodes as vectors (like generated by node selection widgets).
This class ensures that data for every combination of images and ROIs (basicly a folding) will be processed.
@sa QmitkDataGeneratorBase
*/
class MITKIMAGESTATISTICSUI_EXPORT QmitkImageAndRoiDataGeneratorBase : public QmitkDataGeneratorBase
{
public:
  using Superclass = QmitkDataGeneratorBase;

  using NodeVectorType = std::vector<mitk::DataNode::ConstPointer>;

  NodeVectorType GetImageNodes() const;
  NodeVectorType GetROINodes() const;

public slots:
    /*! @brief Setter for image nodes
    */
    void SetImageNodes(const NodeVectorType& imageNodes);
    /*! @brief Setter for roi nodes
    */
    void SetROINodes(const NodeVectorType& roiNodes);

protected:
  QmitkImageAndRoiDataGeneratorBase(mitk::DataStorage::Pointer storage, QObject* parent = nullptr) : QmitkDataGeneratorBase(storage, parent) {};
  QmitkImageAndRoiDataGeneratorBase(QObject* parent = nullptr) : QmitkDataGeneratorBase(parent) {};

  using InputPairVectorType = Superclass::InputPairVectorType;
  
  bool ChangedNodeIsRelevant(const mitk::DataNode *changedNode) const override;
  InputPairVectorType GetAllImageROICombinations() const override;

  NodeVectorType m_ImageNodes;
  NodeVectorType m_ROINodes;

  QmitkImageAndRoiDataGeneratorBase(const QmitkImageAndRoiDataGeneratorBase&) = delete;
  QmitkImageAndRoiDataGeneratorBase& operator = (const QmitkImageAndRoiDataGeneratorBase&) = delete;
};

#endif
