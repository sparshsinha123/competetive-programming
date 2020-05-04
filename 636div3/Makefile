.PHONY = all
FILE := $(shell ls -tp | grep -v /$ | head -1)
all :
	g++ $(FILE)
	echo "first testcase : "
	cat in1
	echo "first testcase output: "
	./a.out < in1
