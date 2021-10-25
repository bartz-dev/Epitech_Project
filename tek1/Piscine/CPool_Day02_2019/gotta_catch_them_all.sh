#!/bin/bash
cut -d ":" -f 5 | grep -ci " $1"

