LIBS =
CFLAGS = -Wall -ggdb


SRC=$(wildcard *.c)


.PHONY: read_qcow2

read_qcow2: $(SRC)
	gcc $^ $(CFLAGS) $(LIBS) -o $@

clean:
	rm read_qcow2

run-debug:
	rm /games/old_home_fs.img
	gdb -ex=r --args ./read_qcow2 old_home_fs.qcow2 /games/old_home_fs.img
