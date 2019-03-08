// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SHELL_PLATFORM_EMBEDDER_VSYNC_WAITER_EMBEDDER_H_
#define SHELL_PLATFORM_EMBEDDER_VSYNC_WAITER_EMBEDDER_H_

#include "flutter/fml/macros.h"
#include "flutter/shell/common/vsync_waiter.h"

namespace shell {

class VsyncWaiterEmbedder final : public VsyncWaiter {
 public:
  using VsyncCallback = std::function<void(intptr_t)>;

  VsyncWaiterEmbedder(VsyncCallback callback, blink::TaskRunners task_runners);

  ~VsyncWaiterEmbedder() override;

  static bool OnEmbedderVsync(intptr_t baton,
                              fml::TimePoint frame_start_time,
                              fml::TimePoint frame_target_time);

 private:
  const VsyncCallback vsync_callback_;

  // |shell::VsyncWaiter|
  void AwaitVSync() override;

  FML_DISALLOW_COPY_AND_ASSIGN(VsyncWaiterEmbedder);
};

}  // namespace shell

#endif  // SHELL_PLATFORM_EMBEDDER_VSYNC_WAITER_EMBEDDER_H_
