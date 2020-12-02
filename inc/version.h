#ifndef VERSION_H
#define VERSION_H
/***************************************************************************
*             Version info for libConway
*
*   File    : version.h
*   Author  : Emeric Frémion <ScrimeT@hotmail.fr>
*   Date    : December 2, 2020
*   Licence : The Unlicence - https://unlicense.org/
*   Repo    : https://github.com/Tloz/libconway
*   Purpose : Header for version info.
*
***************************************************************************/

/**************************************************************************\

 .-.--------------------------------------------------------------------------.-.
((o))                             THE UNLICENSE                                  )
 \U/____________________________________________________________________________/
   |                                                                           |
   |  This is free and unencumbered software released into the public domain.  |
   |                                                                           |
   |  Anyone is free to copy, modify, publish, use, compile, sell, or          |
   |  distribute this software, either in source code form or as a compiled    |
   |  binary, for any purpose, commercial or non-commercial, and by any        |
   |  means.                                                                   |
   |                                                                           |
   |  In jurisdictions that recognize copyright laws, the author or authors    |
   |  of this software dedicate any and all copyright interest in the          |
   |  software to the public domain. We make this dedication for the benefit   |
   |  of the public at large and to the detriment of our heirs and             |
   |  successors. We intend this dedication to be an overt act of              |
   |  relinquishment in perpetuity of all present and future rights to this    |
   |  software under copyright law.                                            |
   |                                                                           |
   |  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,          |
   |  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF       |
   |  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   |
   |  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR        |
   |  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,    |
   |  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR    |
   |  OTHER DEALINGS IN THE SOFTWARE.                                          |
   |                                                                           |
   |  For more information, please refer to <https://unlicense.org>            |
   |                                                                           |
   |___________________________________________________________________________|
  /A\                                                                           \
 ((o))                                                                           )
  '-'---------------------------------------------------------------------------'


/**************************************************************************\
*                  REQUIRED HEADERS AND MACRO DEFINITION                   *
\**************************************************************************/
#include <string>

#define CONWAY_SEMVER_x 1
#define CONWAY_SEMVER_y 0
#define CONWAY_SEMVER_z 1
#define CONWAY_INFO "https://github.com/Tloz/libconway"
#define CONWAY_LICENSE "the unlicense"
#define CONWAY_LICENSE_INFO "https://unlicense.org"

/**************************************************************************\
*                               PROTOTYPES                                 *
\**************************************************************************/

int version_x();
int version_y();
int version_z();
std::string version_a();
std::string version();
std::string compiledate();
std::string conway_info();
std::string license();
std::string license_info();
void version_info();

#endif // VERSION_H /************** END OF FILE - version.h ***************/

