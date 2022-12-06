/*
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __YOSYS_UTILS_H__
#define __YOSYS_UTILS_H__

#include "odin_types.h"

Yosys::Wire *to_wire(std::string wire_name, Yosys::Module *module);
std::pair<Yosys::RTLIL::IdString, int> wideports_split(std::string name);
const std::string str(Yosys::RTLIL::SigBit sig);
const std::string str(Yosys::RTLIL::IdString id);
void handle_cell_wideports_cache(Yosys::hashlib::dict<Yosys::RTLIL::IdString, Yosys::hashlib::dict<int, Yosys::SigBit>> *cell_wideports_cache,
                                 Yosys::Design *design, Yosys::Module *module, Yosys::Cell *cell);
void handle_wideports_cache(Yosys::hashlib::dict<Yosys::RTLIL::IdString, std::pair<int, bool>> *wideports_cache, Yosys::Module *module);

#endif //__YOSYS_UTILS_H__