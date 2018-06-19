/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VRBROWSER_WIDGET_RESIZER_DOT_H
#define VRBROWSER_WIDGET_RESIZER_DOT_H

#include "vrb/Forward.h"
#include "vrb/MacroUtils.h"

#include <memory>
#include <string>
#include <vector>
#include <functional>

namespace crow {

class WidgetResizer;
typedef std::shared_ptr<WidgetResizer> WidgetResizerPtr;

class WidgetResizer {
public:
  static WidgetResizerPtr Create(vrb::ContextWeak aContext, const vrb::Vector& aMin, const vrb::Vector& aMax);
  vrb::NodePtr GetRoot() const;
  void ToggleVisible(bool aVisible);
  bool TestIntersection(const vrb::Vector& point) const;
protected:
  struct State;
  WidgetResizer(State& aState, vrb::ContextWeak& aContext);
  ~WidgetResizer();
private:
  State& m;
  WidgetResizer() = delete;
  VRB_NO_DEFAULTS(WidgetResizer)
};

} // namespace crow

#endif // VRBROWSER_WIDGET_RESIZER_DOT_H