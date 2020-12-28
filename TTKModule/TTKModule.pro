# =================================================
# * This file is part of the TTK Weather project
# * Copyright (C) 2015 - 2021 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# =================================================

win32:TARGET = ../../bin/TTKCore
unix:TARGET = ../lib/TTKCore
TEMPLATE = lib

CONFIG += TTK_BUILD_LIB

INCLUDEPATH += $$PWD

include(../TTKWeather.pri)
unix:VERSION += $$TTKWeather

SOURCES += \
    weatherapplication.cpp 

HEADERS  += \
    weatherapplication.h

RESOURCES += \
    ../TTKQrc/TTKWeather.qrc
    
win32{
    RC_FILE = TTKCore.rc
}
