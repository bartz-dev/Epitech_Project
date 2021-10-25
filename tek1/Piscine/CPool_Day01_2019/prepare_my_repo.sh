#!/bin/bash

blih -u clement.fleur@epitech.eu repository create $1
blih -u clement.fleur@epitech.eu repository setacl $1 ramassage-tek r
blih -u clement.fleur@epitech.eu repository getacl $1
