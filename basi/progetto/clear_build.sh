#!/usr/bin/env bash
set -euo pipefail

SRC_DIR="src"
BUILD_DIR="${SRC_DIR}/build"

echo "Pulizia degli artefatti di build in \"$SRC_DIR\"..."

if [ -d "$BUILD_DIR" ]; then
  rm -rf "$BUILD_DIR"
  echo "Directory \"$BUILD_DIR\" rimossa."
else
  echo "Nessuna directory \"$BUILD_DIR\" trovata."
fi

for f in Makefile cmake_install.cmake CMakeCache.txt; do
  if [ -f "${SRC_DIR}/$f" ]; then
    rm "${SRC_DIR}/$f"
    echo "File \"${SRC_DIR}/$f\" rimosso."
  fi
done

if [ -d "${SRC_DIR}/CMakeFiles" ]; then
  rm -rf "${SRC_DIR}/CMakeFiles"
  echo "Directory \"${SRC_DIR}/CMakeFiles\" rimossa."
fi

echo "Pulizia completata."
