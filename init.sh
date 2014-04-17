#!/bin/bash

DIR_BASE="$HOME/research/composite/src"
DIR_TEST="$DIR_BASE/components/implementation/tests/"
DIR_RUNSCRIPT="$DIR_BASE/platform/linux/util"

cp -r ./unit_sqlite/ $DIR_TEST
cp unit_sqlite.sh $DIR_RUNSCRIPT
