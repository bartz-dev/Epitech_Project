#!/bin/bash
cut -d \; -f 3 | grep -cie "$1"
