/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* Copyright (C) 2016 Tadej Novak <tadej@tano.si>
* Copyright (C) 2014-2015, Sergey Radionov <rsatom_gmail.com>
*
* This file is based on QmlVlc library
*
* This library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "core/RGBVideoFrame.h"

VlcRGBVideoFrame::VlcRGBVideoFrame(unsigned *width,
                                   unsigned *height,
                                   unsigned *pitches,
                                   unsigned *lines)
    : VlcAbstractVideoFrame(1)
{
    this->width = *width;
    this->height = *height;

    *pitches = (*width) * 4;
    *lines = this->height;

    frameBuffer.resize((*pitches)*(*lines));


    setPitchesAndLines(pitches, lines);
}

VlcRGBVideoFrame::~VlcRGBVideoFrame() {}

VlcRGBVideoFrame::VlcRGBVideoFrame(const std::shared_ptr<VlcRGBVideoFrame> &frame)
    : VlcAbstractVideoFrame(1)
{
    frameBuffer.resize(frame->frameBuffer.size());

    width = frame->width;
    height = frame->height;

    setPitchesAndLines(frame);
}
