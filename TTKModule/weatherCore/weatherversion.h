#ifndef WEATHERVERSION_H
#define WEATHERVERSION_H

/* =================================================
 * This file is part of the TTK Weather project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

//update time 2019.04.15
#define TTKWEATHER_STR         "TTKWeather"
#define TTKWEATHER_VERSION_STR "1.2.0.0"

#define TTKWEATHER_MAJOR_VERSION 1
#define TTKWEATHER_MIDLE_VERSION 2
#define TTKWEATHER_MINOR_VERSION 0
#define TTKWEATHER_PATCH_VERSION 0

#define TTKWEATHER_VERSION 0x01200

#define TTKWEATHER_VERSION_CHECK(major, middle, minor, patch) ((major<<12)|(middle<<8)|(minor<<4)|(patch))


#endif // WEATHERVERSION_H

