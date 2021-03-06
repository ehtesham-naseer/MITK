/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#include "mitkNodePredicateNot.h"

mitk::NodePredicateNot::NodePredicateNot(const mitk::NodePredicateBase *p)
{
  m_ChildPredicates.push_back(p);
}

mitk::NodePredicateNot::~NodePredicateNot()
{
}

bool mitk::NodePredicateNot::CheckNode(const mitk::DataNode *node) const
{
  if (node == nullptr)
    throw std::invalid_argument("NodePredicateNot: invalid node");

  // return the negation of the child predicate
  return !m_ChildPredicates.front()->CheckNode(node);
}

void mitk::NodePredicateNot::AddPredicate(const mitk::NodePredicateBase *p)
{
  if (!m_ChildPredicates.empty())
    m_ChildPredicates.clear();

  NodePredicateCompositeBase::AddPredicate(p);
}
