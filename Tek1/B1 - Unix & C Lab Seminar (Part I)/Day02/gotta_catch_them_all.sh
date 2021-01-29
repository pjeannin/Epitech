#!/bin/bash

cut -d ":" -f 5 | cut -d " " -f 2 | grep -c "^$1"
