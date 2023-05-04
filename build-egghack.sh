#!/bin/bash


EMSDK=PATH_TO_EMSDK
source "${EMSDK}/emsdk_env.sh"

# EMCC=/opt/emscripten-llvm/bin
EMCC=$EMSDK/upstream/emscripten/emcc
JOB_COUNT=4

EMCMAKE=/usr/lib/emscripten/emcmake

WORK_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

runLinuxSetup() {
  pushd sys/unix
  sh setup.sh hints/linux
  # TODO graves: Remove once not necessary anymore
  # sh setup.sh hints/linux-minimal
  popd
  echo "Ran setup.sh"

  # 1. Makefile calls src/Makefile
  # src/Makefile calls util/Makefile

  # pushd src
  #   make monst.o
  #   make objects.o
  # popd

  pushd util
    make
    # make makedefs
    # make tilemap
  popd


  pushd src
    make ../include/onames.h
    make ../include/pm.h
    make ../include/vis_tab.h
    make vis_tab.c
    make tile.c

    # Not sure if I need to extra do these two
    make monst.o
    make objects.o


  popd

  make CC=$EMCC -s WASM=0 --debug
}

runMake() {
  # make

  pushd util
  make makedefs
  make tilemap
  popd

  pushd src
  make monst.o
  make objects.o
  popd

  make
  # make all
}


runEmmake() {

  # replicate make
  pushd util
  emmake make CC=$EMCC --debug makedefs
  # Not sure about tilemap
  # emmake make CC=$EMCC tilemap
  popd

  pushd src
  # emmake make --debug makedefs
  # emmake make --debug monst.o
  # emmake make --debug objects.o

  # emmake make --debug ../include/onames.h
  # emmake make --debug ../include/pm.h
  # emmake make --debug ../include/vis_tab.h
  # popd


  # emmake make --debug

  # MAKEFLAGS="-j4" emmake make
  # MAKEFLAGS="-j4" emmake make
  # make CC=$EMCC -j$JOB_COUNT
  # make install CC=$EMCC PREFIX=$WORK_DIR/build
}

runLinuxSetup
# runMake
# runEmmake
