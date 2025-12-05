// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/linux/linux_ui_delegate.h"

#include "base/functional/callback.h"
#include "base/notreached.h"

namespace ui {

// static
LinuxUiDelegate* LinuxUiDelegate::instance_ = nullptr;

// static
LinuxUiDelegate* LinuxUiDelegate::GetInstance() {
  return instance_;
}

LinuxUiDelegate::LinuxUiDelegate() {
  if (instance_) {
    fprintf(stderr, "WARN: LinuxUiDelegate: there's already a LinuxUiDelegate\n");
  } else {
    instance_ = this;
  }
}

LinuxUiDelegate::~LinuxUiDelegate() {
  if (instance_ == this)
    instance_ = nullptr;
  else
    fprintf(stderr, "WARN: LinuxUiDelegate: destructing a secondary instance\n");
  DCHECK_EQ(instance_, this);
  instance_ = nullptr;
}

bool LinuxUiDelegate::ExportWindowHandle(
    uint32_t parent_widget,
    base::OnceCallback<void(const std::string&)> callback) {
  // This function should not be called when using a platform that doesn't
  // implement it.
  NOTREACHED();
}

void LinuxUiDelegate::SetTransientWindowForParent(
    gfx::AcceleratedWidget parent,
    gfx::AcceleratedWidget transient) {
  // This function should not be called when using a platform that doesn't
  // implement it.
  NOTREACHED();
}

}  // namespace ui
