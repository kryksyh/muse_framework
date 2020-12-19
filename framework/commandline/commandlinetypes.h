//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_COMMANDLINE_COMMANDLINETYPES_H
#define MU_COMMANDLINE_COMMANDLINETYPES_H

#include <string>
#include <utility>
#include <vector>

namespace mu::commandline {
using CommandLineOption = std::list<std::string>;
using CommandLineValue = std::string;
using CommandLineValues = std::vector<CommandLineValue>;

inline bool operator ==(const CommandLineOption& opt, const std::string& str)
{
    for (const std::string& o : opt) {
        if (o == str) {
            return true;
        }
    }
    return false;
}
}

#endif // MU_COMMANDLINE_COMMANDLINETYPES_H
