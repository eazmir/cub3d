#!/bin/bash

FOLDER=maps/bad

# Avoid errors if no .cub files
shopt -s nullglob

make re

for map in "$FOLDER"/*.cub
do
    echo "--------------------------------"
    echo "Testing map: $map"
    time valgrind ./cub3D "$map"
    echo "Done testing $map"
    echo "--------------------------------"
    sleep 2
done