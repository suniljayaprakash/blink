// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ImagePainter_h
#define ImagePainter_h

namespace blink {

class GraphicsContext;
struct PaintInfo;
class LayoutPoint;
class LayoutRect;
class RenderImage;

class ImagePainter {
public:
    ImagePainter(RenderImage& renderImage) : m_renderImage(renderImage) { }

    void paint(const PaintInfo&, const LayoutPoint& paintOffset);
    void paintReplaced(const PaintInfo&, const LayoutPoint& paintOffset);
    void paintIntoRect(GraphicsContext*, const LayoutRect& paintOffset);

private:
    void paintAreaElementFocusRing(const PaintInfo&);

    RenderImage& m_renderImage;
};

} // namespace blink

#endif // ImagePainter_h
