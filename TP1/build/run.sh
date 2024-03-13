#!/bin/bash
g++ -Werror Particule.cpp Vecteur.cpp CollectionParticule.cpp -o CollectionParticule
./CollectionParticule 16 32 64 128 256 512 1024 2048 4096 > output.txt
