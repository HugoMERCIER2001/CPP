cmake_minimum_required(VERSION 3.0)
project(CollectionParticule)

# Ajoutez vos fichiers source
set(SOURCES
    CollectionParticule.cpp
    Particule.cpp
    Vecteur.cpp
)

# Ajouter votre exécutable
add_executable(CollectionParticule ${SOURCES})

# Ajouter une règle pour exécuter le programme avec des arguments spécifiés
add_custom_target(run
    COMMAND ./CollectionParticule 16 32 64 128 256 512 1024 2048 4096 > réponses.txt
    DEPENDS CollectionParticule
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

