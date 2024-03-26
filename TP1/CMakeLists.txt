cmake_minimum_required(VERSION 3.0)
project(CollectionParticule)

# Ajoutez vos fichiers source
set(SOURCES
    Particule.cpp
    Particule.h
    Vecteur.h
    Vecteur.cpp
    StormerVerlet.h
    StormerVerlet.cpp
)

# Ajouter l'exécutable de CollectionParticule

# Ajouter l'exécutable de StormerVerlet
add_executable(executeStormerVerlet executeStormerVerlet.cpp ${SOURCES})

# Ajouter une règle pour exécuter le programme avec des arguments spécifiés
add_custom_target(run
    COMMAND ./CollectionParticule 16 32 64 128 256 512 1024 2048 4096 > réponses.txt
    DEPENDS CollectionParticule
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(run2
    COMMAND ./executeStormerVerlet > réponses2.txt
    DEPENDS StormerVerlet
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

