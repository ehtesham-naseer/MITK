/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/
#include "QmitkUSNavigationAbstractSettingsWidget.h"

#include "mitkCommon.h"
#include "mitkDataNode.h"

#include <ctkDirectoryButton.h>

#include <QSettings>

QmitkUSNavigationAbstractSettingsWidget::QmitkUSNavigationAbstractSettingsWidget(QWidget *parent) :
  QWidget(parent)
{
}

QmitkUSNavigationAbstractSettingsWidget::~QmitkUSNavigationAbstractSettingsWidget()
{
}

void QmitkUSNavigationAbstractSettingsWidget::LoadSettings()
{
  this->OnLoadSettingsProcessing();
}

void QmitkUSNavigationAbstractSettingsWidget::SetSettingsNode(mitk::DataNode::Pointer settingsNode, bool overwriteValues)
{
  m_SettingsNode = settingsNode;

  this->OnSetSettingsNode(m_SettingsNode, overwriteValues);

  emit SettingsChanged(m_SettingsNode);
}

itk::SmartPointer<mitk::DataNode> QmitkUSNavigationAbstractSettingsWidget::GetSettingsNode()
{
  return m_SettingsNode;
}

void QmitkUSNavigationAbstractSettingsWidget::OnSave()
{
  this->OnSaveProcessing();

  emit SettingsChanged(m_SettingsNode);
  emit Saved();
}

void QmitkUSNavigationAbstractSettingsWidget::OnCancel()
{
  this->OnCancelProcessing();

  emit Canceled();
}
