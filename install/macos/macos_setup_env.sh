#!/bin/bash

# this is a script shell sets up a macos environment where MeshLab can be compiled
# and deployed.
# Run this script if you never installed any of the MeshLab dependencies.
#
# Requires: homebrew (https://brew.sh/)

brew install llvm libomp qt npm
npm install -g appdmg

echo "export QTDIR=/usr/local/opt/qt" >> ~/.bash_profile
echo "export PATH=/usr/local/opt/qt/bin:$PATH" >> ~/.bash_profile
echo "export LD_LIBRARY_PATH=/usr/local/opt/qt/lib:$LD_LIBRARY_PATH" >> ~/.bash_profile
echo "export PKG_CONFIG_PATH=/usr/local/opt/qt/lib:$PKG_CONFIG_PATH" >> ~/.bash_profile

source ~/.bash_profile
