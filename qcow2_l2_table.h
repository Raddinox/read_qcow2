/*
    read_qcow2
    Copyright (C) 2020  Peter Hansen (phaanx@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _QCOW2_L2_TABLE_H_
#define _QCOW2_L2_TABLE_H_

uint64_t *qcow2_l2_load(qcow2_state *c, uint64_t l2_offset);
void qcow2_l2_dump(uint64_t *l2buf, int num);

void qcow2_l2_free();

#endif