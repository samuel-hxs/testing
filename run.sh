#!/bin/sh
# Debug->deb, Release->rel
conf=deb
cd ./bin/$conf/ && ./proc
