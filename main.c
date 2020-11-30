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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include "qcow2.h"
#include "img.h"

int main(int argc, char *argv[]) {
  printf("read_qcow2  Copyright (C) 2020  Peter Hansen\n");
  printf("This program comes with ABSOLUTELY NO WARRANTY\n");
  printf("This is free software, and you are welcome to redistribute it\n");
  printf("under the terms of the GNU General Public License as published by\n");
  printf("the Free Software Foundation\n\n");

  uint64_t bytes;

  if( argc == 2 ) {
    qcow2_openFile(argv[1]);

    uint64_t fileSize = qcow2_getFileSize();
    printf("File size: %" PRIu64 "bytes\n", fileSize);

    bytes = 1024*1024;
    char *b = malloc(bytes);
    if( qcow2_read(0, bytes, b) != 0 ) {
      printf("Failed to read\n");
    }

    printf("\n");

    qcow2_closeFile();
  } else if ( argc >= 3 ) {
    qcow2_openFile(argv[1]);
    img_openFile(argv[2]);

    uint64_t fileSize = qcow2_getFileSize();
    printf("File size: %" PRIu64 "bytes\n", fileSize);

    bytes = 1024*1024; // Num bytes to read at once
    char *buf = malloc(bytes);

    uint64_t offset = 0;
    while(fileSize > 0) {

      //printf("Bytes to go: %" PRIu64 "\n", fileSize);
      if( qcow2_read(offset, bytes, buf) != 0 ) {
        printf("Failed to read\n");
        break;
      }

      img_write(0, bytes, buf);

      //for(uint64_t i=0; i<bytes; i++) {
      //  printf("%2x ", (unsigned)(unsigned char)buf[i]);
      //}
      //printf("\n");

      fileSize -= bytes;
      offset += bytes;
      usleep(10000);
    };

    img_closeFile();
    qcow2_closeFile();
  } else {
    printf("Usage: read_qcow2 <qcow2-file> <img-file>\n");
  }
  return 0;
}
