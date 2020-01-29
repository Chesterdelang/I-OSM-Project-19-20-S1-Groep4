#!/usr/bin/env bash

gui() {
	echo "Attempting to build GUI with QT4"
	pwd
	cd gui
	mkdir -p build
	cmake .
	make all
	echo "The generated executable can be found in the build directory, if the build hasn't failed."
	cd ..
}

core() {
	echo "Attempting to build core executables"
	echo $1
	mkdir -p linux
	./autogen.sh
	cd linux
	../configure -C --with-cxx=17 $2
	make all
	cd ..
}

clean() {
	echo "Warning, this function deletes the build files irrevocably! This function is not the same as the regular 'make clean' function!"
	rm -rf linux
	rm -rf gui/build
	echo "Build files deleted."
}

all() {
core
gui
}

# Check if the function exists (bash specific)
if declare -f "$1" > /dev/null
then
  # call arguments
  "$@"
else
  # Show a  error
  echo "'$1' is not a known function name" >&2
  exit 1
fi
