#!/usr/bin/env bash

function yes_or_no {
    while true; do
        read -p "$* [y/n]: " yn
        case $yn in
            [Yy]*) return 0  ;;  
            [Nn]*) return 1  ;;
        esac
    done
}


echo "Building the project..."
if make > /dev/null; then
  echo "Project has been built. App is in ./build/GiveMeAutomat"
  echo "Run 'make clean' to delete the build dir"
else
  echo "You failed the compilation"
  rm -rf build
  exit 1
fi

yes_or_no "Do you wanna launch app instantly?" && ./build/exec/GiveMeAutomat
