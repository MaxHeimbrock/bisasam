#!/bin/bash

echo ""
echo "MAX: Starting cmake"
cmake .

echo ""
echo "MAX: Starting make"
cmake --build .
