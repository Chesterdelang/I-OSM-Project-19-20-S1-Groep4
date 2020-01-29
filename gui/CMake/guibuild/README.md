# OSM Project - Spaanders B.V. Groep 4

## Gebruik maken van het buildscript

De volgende dependencies zijn vereist tijdens buildtime:

qt4-dev-tools qt4-qmake libboost-dev(>1.60) 

### Debian Buster:
``` apt install qt4-dev-tools qt4-qmake libboost-all-dev```

Het buildscript (build.sh) is te vinden in de root directory en bevat een aantal functies. 

- core
- gui
- all
- clean

core: compileert de standaard C++ code, zoals productioncontrol en machinecontrol.
```./build.sh core```

gui: compileert de grafische interface met Qt4 en QMake.
```./build.sh gui```

all: compileert core en gui.
```./build.sh all```

clean: verwijdert executable files, dit is dus iets anders dan ```make clean```.
```./build.sh clean```


### Custom boost directory.
Het buildscript leest extra parameters uit en passed deze aan make, deze parameter kan gebruikt worden voor het aangeven van een custom boost directory. 

Voorbeeld:
```./build.sh all --with-boost=$PAD_NAAR_BOOST```

Als de code succesvol gecompileerd is, kan de gui in de 'gui/build' map gevonden worden en de core in 'linux', gekeken vanaf de root directory.

## Handmatig compileren

De standaard C++ code kan simpelweg met autotools en een compatible C++ compilier gegenereerd worden. 

### Core

1. Maak een map voor de build output (zoals linux, win of build).

2. Voer vanuit de root ```./autogen.sh``` uit.

3. Navigeer naar de nieuwe map (met cd) en voer ```../configure --with-cxx=17``` uit.

4. Voer ```make``` uit.

### GUI

1. Maak een map voor de build output in './gui'.

2. Voer ```cmake .``` uit.

3. Voer ```make all``` uit.

## FAQ

**V: Waarom krijg ik `permission denied` als ik configure of autogen.sh uitvoer?**\
*A: Voer `chmod +x autogen.sh configure` uit*

**V: Ik krijg een foutmelding dat Boost niet gevonden kan worden tijdens het configure commando.**\
*A: Voer stap 3 uit met de ```--with-boost=$BOOST_INSTALLATIE_DIR``` flag. $BOOST_INSTALLATIE_DIR moet worden vervangen met de eigenlijke Boost installatiemap gekozen in de installatiehandleiding op OnderwijsOnline.*
