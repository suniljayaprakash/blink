// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PermissionCallbacks_h
#define PermissionCallbacks_h

#include "platform/PlatformExport.h"
#include "wtf/Functional.h"
#include "wtf/Noncopyable.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"

namespace blink {

class PLATFORM_EXPORT PermissionCallbacks {
    WTF_MAKE_NONCOPYABLE(PermissionCallbacks);
public:
    static PassOwnPtr<PermissionCallbacks> create(PassOwnPtr<Closure> allowed, PassOwnPtr<Closure> denied);
    virtual ~PermissionCallbacks() { }

    void onAllowed() { (*m_allowed)(); }
    void onDenied() { (*m_denied)(); }

private:
    PermissionCallbacks(PassOwnPtr<Closure> allowed, PassOwnPtr<Closure> denied);

    OwnPtr<Closure> m_allowed;
    OwnPtr<Closure> m_denied;
};

} // namespace blink

#endif // PermissionCallbacks_h
