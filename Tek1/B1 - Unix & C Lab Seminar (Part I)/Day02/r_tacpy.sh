#!/bin/bash

cat Day02/passwd | cut -d : -f 1 | sed -n "n;p"  | rev | sort -r | sed -n $MY_LINE1','$MY_LINE2'p' | tr '\n' ',' | sed 's/,/, /g' | sed '$s/,.$/.\n/'
