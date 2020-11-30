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
#include "img.h"

FILE *fp;

int img_openFile(const char *filename) {
  if( fp != NULL ) {
    img_closeFile();
  }
  fp = fopen(filename, "a");
  if( fp == NULL ) {
    printf("Error opening file.\n");
    return 1;
  }
  printf("IMG File %s opened.\n", filename);

  return 0;
}

void img_closeFile() {
  printf("Closing IMG file.\n");
  if( fp != NULL ) {
    fclose(fp);
  }
}

int img_write(uint64_t offset, uint64_t bytes, char *buf) {
    return fwrite(buf, bytes, 1, fp);
}