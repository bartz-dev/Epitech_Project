#!/bin/bash

sed "1~2d"| rev | cut -d ":" -f7 | sort -r | sed -n "$MY_LINE1, $MY_LINE2"p | sed ':a;N;$!ba;s/\n/, /g' | tr "\n" "." 
