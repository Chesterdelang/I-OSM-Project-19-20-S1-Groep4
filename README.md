# OSM Project - Spaanders B.V. Groep 4

## Compileren

1. Maak een map voor de build output (zoals linux, win of build).

2. Voer vanuit de root ```./autogen.sh``` uit.

3. Navigeer naar de nieuwe map (met cd) en voer ```../configure --with-cxx=17``` uit.

4. Voer ```make``` uit.

## FAQ

**V: Waarom krijg ik `permission denied` als ik configure of autogen.sh uitvoer?**\
*A: Voer `chmod +x autogen.sh configure` uit*

**V: Ik krijg een foutmelding dat Boost niet gevonden kan worden tijdens het configure commando.**\
*A: Voer stap 3 uit met de ```--with-boost=$BOOST_INSTALLATIE_DIR``` flag. $BOOST_INSTALLATIE_DIR moet worden vervangen met de eigenlijke Boost installatiemap gekozen in de installatiehandleiding op OnderwijsOnline.*


## FAQ Communication

**V: Hoe kan ik een bericht versturen via een client?**\
*A: Maak een ClientHandler aan via ```Messaging::ClientHandler($IP, $PORT, $RESPONSE_HANDLER)```. Roep hierna de functie dispatchMessage($MESSAGING::MESSAGE) aan en stop hier je message in.

**V: Hoe kan ik iets doen met het bericht wat terug heb gekregen van de Server?**\
*A: In MachineControl staat de fucntie ```handleResponse(Messaging::Message aMessage)```. In deze functie wordt de parameter met de teruggeven message meegegeven. Op deze parameter kan je bijvoorbeeld ```aMessage.getBody()``` aanroepen om te zien wat de message was.

**V: Hoe krijg ik een bericht terug van de server?**\
*A: Check in de ProductionControl Main of er een server is aangemaakt met ```ServerMain($REQUEST_HANDLER, $ADDRESS_IP, $PORT)```. Roep hierna in de ClientHandler de messageType aan die je nodig hebt. Als deze is aangemaakt dan zal je een reply krijgen vanuit de production control

**V: Hoe maak ik een messageType aan?**\
*A: Als je een message vanuit de client wilt sturen, maak je een nieuwe messagetype in de main (Zie enum). Zet dezelfde messagetype in de serversession (Zie enum), vul deze messageType in, in de switch case en zeg wat de respond moet zijn.  

**V: Wat kan ik allemaal in een message zetten?**\
*A: Een messegeType (Char), messageHeader (String), en een messageBody(String). De body is de string die wordt verstuurd. Lees deze uit.

**V: Hoe lees ik het bericht uit van de ClientHandler en doe ik er iets mee?**\
*A: In ProductionControl staat de functie ```handleRequest(Messaging::Message aMessage)```. Gebruik de parameter aMessage om de message uit te lezen van de message. Hiermee kan je iets doen in de ProductionControl.

**V: Hoe kan de machine met de ProductionControl communiceren?**\
*A: Maak een machine aan en roep een ClientHandler erop aan. Vanuit deze clienthandler kan je verschillende messages versturen.

**V: Hoe vul ik een messageHeader?**\
*A: Kijk in de Message class (Zie libraries/message.hpp) voor een de MessageHeader die je wilt gebruiken. Er zijn een aantal copy contstuctors aangemaakt 


