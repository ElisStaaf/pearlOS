#!/bin/sh

PROFILE_DIR=./config/profiles
PROFILE=$PROFILE_DIR/default

if [ $# -gt 0 ]; then
    PROFILE=$PROFILE_DIR/$1
fi

for rc in $PROFILE/*; do
    if [ -f $rc ]; then
        rm kernel/$(basename $rc)
        cp $rc kernel/$(basename $rc)
    fi
done

set -x

touch kernel/debug.h
mkdir -p dist/
mkdir -p mk/
mkdir -p mk/bin/
mkdir -p mk/kernel/
mkdir -p mk/drivers/
mkdir -p mk/cpu/
mkdir -p mk/lib/
mkdir -p mk/fs/
