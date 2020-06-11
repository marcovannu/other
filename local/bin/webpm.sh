#!/bin/bash

`for file in phone/*; do cwebp -q 70 "$file" -o "${file%.*}.webp"; done`
