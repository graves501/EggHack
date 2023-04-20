#!/bin/bash

# EMCC=/opt/emscripten-llvm/bin
EMCC=/usr/lib/emscripten/emcc
JOB_COUNT=4

EMCMAKE=/usr/lib/emscripten/emcmake

WORK_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

runLinuxMake() {
  pushd sys/unix || exit
  sh setup.sh hints/linux
  # TODO graves: Remove once not necessary anymore
  # sh setup.sh hints/linux-minimal
  popd || exit
  make
}

runWebMake() {
  # emcmake cmake web
  make PREFIX="${WORK_DIR}/web" install
}

runEmscripten() {
  pushd src || exit
  make CC=$EMCC -j$JOB_COUNT
  popd || exit
}

runLinuxMake
runWebMake
# runEmscripten
