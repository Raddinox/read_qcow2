# Read QCow2
Just a simple program to convert a QCow2 file to an IMG file without reading the backing file.

WARNING! If you have the backing file you should not use this program.

I wrote this program because I failed at backing up my data, and then I deleted my backing file. I could not find a way to use Qemus QCow2 tools to create an IMG file without the backing file. So I just wrote my own.

## What it will do

The software will read the data in the QCow2 file and write it in byte order in an IMG file.

If there is no data in the QCow2 image it will just write a 0 to the IMG file.

The result will be a broken IMG file.

## What it doesn't do

The software will ignore backing files, even though they exists.

The software will never be able to recover files that was stored in the backing file and not ever touched so it was written in the new QCow2 file.

## Recovery

I used the testdisk tool found at https://www.cgsecurity.org/wiki/TestDisk_Download

First I created a loop device of my broken IMG file using losetup
```
losetup /dev/loop0 broken.img
```

then I used the testdisk tool to recover my files.

## Build

just run `make`

## Run

`./qcow2_read path/to/file.qcow2 path/to/file.img`

if you run `./qcow2_read path/to/file.qcow2` it will just print some header details about the QCow2 file.