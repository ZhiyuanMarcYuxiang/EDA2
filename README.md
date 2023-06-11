# EDA2
Projecte per a fer una Xarxa Social.

Zhiyuan, Marc, Yuxiang

INTRODUCCIÓ

El projecte d’aquest trimestre era un repte desafiant on requeria implementar molts conceptes treballats en les classes de teoria. El projecte consistia en dissenyar un prototip d’una xarxa social funcional en grup. Cada grup estava format per tres integrants i durant les classes de laboratori i fora d'aquestes classes havíem d’anar treballant. Ens vam inspirar amb les xarxes socials populars que hi ha avui en dia com Twitter, Instagram…

La guía de práctica de l’Aula Global va ser de gran ajuda, va definir el nostre punt de partida i què haviem de fer durant el trimestre. També ens va ajudar a organitzar-nos. 

Un cop llegit la introducció i la Sessió 1 de la guía de práctica, vam emprendre amb el projecte. 

El primer pas va ser definir un menú principal amb les funcions principals que havia de tenir una xarxa social, permetre afegir usuaris, operar com a un usuari específic i permetre aquest usuari específic interactuar amb altres usuaris, etc.

A partir d’aquí hem anat desenvolupant i modificant. En alguns casos, amb cada nou repte/funcionalitat havíem de fer alguns canvis petits en les funcions que prèviament haviem definit perquè tot tingués sentit. 


Objectius obligatoris, desitjables i lliures   

Crec que hem assolit tots els objectius obligatoris:

Les Llistes hem implementat moltes al llarg del treball, tenim una estructura que es diu Network i dins d’aquesta tenim una llista d’usuaris. Cada nou usuari que  s’inserta, s’afegirà a la llista d’usuaris. 

La Pila hem implementat en una de les funcions que es mostra quan operas com a usuari específic (Send friend request to random user), aquesta funció l’explicarem més tard, és un dels objectius desitjables.

La Cola l’hem implementat per la llista de sol·licituds de cada usuari. Les funcions que es mostra quan operas com a usuari específic (Send friend request i Manage friend request) utilitzen la llista de sol·licituds, aquestes dues funcions l’explicarem més endavant, formen part dels objectius obligatoris.







El Diccionari l’hem implementat perquè com a CEO de la nostra xarxa social, ens interessa saber quins son els temes més parlats entre els nostres usuaris i volem contar quantes vegades s’ha utilitzat cada paraula.   

Hem implementat els dos algoritmes de recerca, Linear Search i Binary Search. En el nostre projecte hem fet servir moltes llistes de string, un exemple és la llista d’amics. Abans d’enviar sol·licitud d’amistat a algú, primer recorrem la llista d’amics(Linear Search) per veure si ja era amic teu. Tenim una funció (searchNetwork) que donat un nom o qualsevol altra atribut, busca en la llista d’usuaris del Network(Binary Search) si existeix algun usuari amb aquell atribut. 

Els algoritmes d’ordenament que hem empleat són MergeSort i SelectiveSort. El MergeSort el fem servir per ordenar la llista d’usuaris del Network (sortNetwork). Podem ordenar la llista d’usuaris del Network pel nom o per qualsevol altra atribut (alfabèticament o numèricament). El SelectiveSort el fem servir per ordenar el diccionari, ens interessa les 10 paraules més utilitzades i no cal ordenar tot el diccionari, només ordenar els 10 primers elements. 

Insertar usuari(objectiu obligatori): Demanar un nom, un edat, un email, una ciutat i cinc hobbies. El nom, l'edat, l’email i la ciutat han de cumplir una sèrie de requisits per ser vàlids, si no és vàlid, el programa demanarà que es torni a introduir. Si tots els atributs són vàlids,  el nou usuari s’afegirà a la llista d’usuaris (Llista dinámica) i també quedará guardada en un fitxer extern CSV  (objectiu desitjable). Les variables utilitzats són strings principalment perquè els atributs (nom, edat, email…) són strings. Les estructures de dades utilitzades són Network i User. Les funcions es troben principalment en el fitxer 1.new_user.c, hi ha algunes funcions auxiliars com expandUser(realloc) es troben en els fitxers network_data_control.c i network_file_control.c.

Llistar usuaris(objectiu obligatori): Llegir dades d’un fitxer extern (objectiu desitjable) que en aquest cas és un CSV. Imprimir els usuaris per pantalla, la manera com s’imprimeix per pantalla és especial, té un format semblant a una taula. Les variables utilitzats són ints. Les estructures de dades utilitzades són Network i User. Les funcions es troben principalment en el fitxer 2.list_users.c, hi ha algunes funcions auxiliars com readUsersFile es troben en el fitxer network_file_control.c.






Operar com a usuari específic(objectiu obligatori): Introduir el nom de l'usuari qui volem operar. El programa buscarà el nom, si el troba, s’imprimeix per pantalla que s’ha inicialitzat correctament i es mostrarà un submenú. A part d’inicialitzar com a usuari, hi ha l'opció d’inicialitzar com a CEO (introdueix “CEO” per consola). El CEO té un submenú especial. Les variables utilitzats són ints i strings. Les estructures de dades utilitzades són Network i User. Les funcions es troben principalment en el fitxer 3.operate_user.c .

Un cop que estem operant com a usuari específic, tenim tres opcions, cada una d’aquestes opcions s’especialitza en una tasca diferent. 

Totes les funcions que tenen a veure amb les sol·licituds d’amistats estan dins del fitxer 31.manage_request.c. 

Totes les funcions que tenen a veure amb els amics dels usuaris estan dins del fitxer 32.manage_friends.c 

Totes les funcions que tenen a veure amb les publicacions estan dins del fitxer 33.manage_posts.c

Enviar sol·licituds d’amistats(objectiu obligatori): Introduir el nom de l’usuari qui volem enviar sol·licitud. El programa farà una sèrie de comprovacions, com per exemple, el nom de l’usuari qui volem enviar sol·licitud no pot coincidir amb el nom de l’usuari que hem inicialitzat. Si passa per les comprovacions correctament, s’enviarà la sol·licitud d'amistat i s’imprimirà per pantalla que s’ha enviat correctament. Les variables utilitzats son ints, strings i llista de string. Les estructures de dades utilitzades son Network i User. Les funcions es troben principalment en el 31.manage_requests.c, hi ha algunes funcions auxiliars com expandStringArray que es troben en els fitxers network_data_control.c. 













Enviar sol·licitud d’amistats a persones desconeguts(objectiu desitjable): En aquí, hem aprofitat la funció anterior, ja que fan els codis semblants per afegir als altres usuaris. La única diferència és que en aquesta part, hem de triar 3 usuaris desconeguts(que no estan afegits en la llista de amics de la persona que està connectat) i podem decidir si volem enviar la solicitud o no a aquestes persones. Ho hem aprofitat de la següent manera: Hem posat una variable int i un bucle if-else. Amb aquesta variable int, podem saber si estem utilitzant l'opció de enviar solicitud aleatori o decidit. I segons aquesta variable int, amb el bucle if-else actuar de forma diferent. 
En aquesta opció, hem creat 4 funcions noves, 3 que tenen la funcionalitat de crear i modificar la estructura de stack, i fer servir per emmagatzemar els 3 usuaris random  i l’altra serveix per buscar quines 3 usuaris són. 
Aquestes funcions adicionals també es poden trobar en 31.manage_request.c i network_data_control.h.











Administrar sol·licituds d’amistats(objectiu obligatori): Per aconseguir-lo, hem implementat varies funcions i varies opcions diferents. 
Una funció per imprimir la cola de sol·licituds de més antics als més recents. Una funció serveix per donar l’opció de aceptar a una solicitud concreta o rebutjar-lo. Com que en C11 no existeix la estructura booleana, doncs fem servir dues constants que indiquen un número en concret, i si la opció introduït no fossi aquestes dues constants, doncs demana a l'usuari que segueix introduint.
La tercera funció, serveix per fer tots els canvis necessaris després d'acceptar a una solicitud. Bàsicament és afegir a l’usuari actual al la llista d’amics de la persona que va enviar la solicitud, i viceversa.  Aquestes funcions es poden trobar en 31.manage_request.c i utilitzant les estructures definides en network_data_control.h.

Llistar les publicacions d’un amic(objectiu lliure): Es demanarà a l’usuari introduir el nom de l'amic qui vol buscar les publicacions. Si no troba l’amic, avisarà l’usuari per pantalla. Les publicacions s’imoprimirà de més recents a més antics. Aquest objectiu utilitza la funció list_string array, que explicarem més endavant. Aquestes funcions es poden trobar en 32.manage_friend.c.

Veure la meva llista d’amics(objectiu lliure): S’imprimeix per pantalla els amics de l’usuari específic.Les variables que utilitza són string i llista de string Aquestes funcions es poden trobar en 32.manage_friend.c.

Suprimir un amic(objectiu lliure):  L’usuari podrà triar l’amic que vol eliminar introduïnt el nom. Si no té cap amic o l’amic que vol eliminar no existeix, s’informarà a l’usuari per la consola. La variable utilitzat és una llista de string on conté els amics. Les funcions es troben principalment en el 32.manage_friend.c

Fer una publicació nova(objectiu obligatori): Es demanarà a l’usuari introduir el contingut de la publicació. Les variables utilitzats son string i llista de string. La estructura de dada utilitzada és el User. Les funcions es troben principalment en el 33.manage_post.c,  hi ha algunes funcions auxiliars com expandStringArray que es troben en els fitxers network_data_control.c. 

Llistar els posts de l’usuari específic(objectiu obligatori): S’informarà l’usuari si té alguna publicació o no. Si té publicacions, s’imprimirà per pantalla les publicacions de més recent a més antic. Les variables que hem utilitzat son int i llista de string. La variable who (int) s’utilitza per saber si les publicacions que volem imprimir son de l’usuari especific que hem inicialitzat o són publicacions dels seus amics. Tenim una funció que és llistar les publicacions dels amics(objectiu desitjable), per aquesta raó és necessari la variable who. La estructura de dada que hem utilitzat és el User. Les funcions es troben principalment en el 33.manage_post.c.

Suprimir una publicació(objectiu lliure): L’usuari podrà triar la publicació que vol eliminar introduïnt el número de la publicació. Si no té cap publicacions o la publicació que vol eliminar no existeix, s’informarà a l’usuari per la consola. La variable utilitzat és una llista de string on conté les publicacions. Les funcions es troben principalment en el 33.manage_post.c


1. MÒDUL DEL CONTROL DE LES ESTRUCTURES DE LA XARXA

Constants:
- ATTRIBUTES: Quanitat de dades d'un usuari.
- MAX_DICTIONARY_ELEMENTS: Elements màxims del diccionari
- NAME, AGE, EMAIL, (...): Són els índex per a accedir als atributs de les dades de l'usuari.
- NULL_SIZE: Mida d'una array buida (0).
- ONE_SIZE: Mida d'una array amb un element (1).
- INCREMENT_SIZE, DECREMENT_SIZE: Incrementar o decrementar la mida d'una array.
- MULTIPLICATIVE_FACTOR: Per a incrementar una array en varis element.
- NOT_ORDERED: La llista no té cap tipus d'ordenació.
- BUFFER_SIZE: Un nombre molt gran, per a un buffer de caràcters (2^10 bytes)
- END_CHARACTER: Per a aturar una string llegida per consola.
- RESET: Per a tornar a 0 una variable.
- SET_ZERO: Inicialitzar una variable a 0.
- LESSTHAN, GREATHERTHAN, EQUAL: Per a la comparació d'strings.
- ACCEPT, DENY: Per a acceptar o denegar sol·licituds.

Estructures de Dedes:

Usuari:
- data: Array d'strings que conté els atributs de l'usuari. Sempre tindrà mida de la constant ATTRIBUTES.
- request: Array que conté els usuris que li han enviat licitud a un usuari.
- size_requests: Quantitat de sol·licituds.
- friends: Array que conté els nostres amics, que són els usuaris els quals els hi hem acceptat la sol·licitud.
- size_requests: Quantitat d'amics.
- post: Array que conté les publicions d'un usuari (format de text).
- size_requests: Quantitat de publicacions.

Dict:
- element: Elements del diccionari
- current_elements: Q

Network:
- user: Array dinàmica dels usuaris.
- size_users: Quantitat d'usuaris.
- order_users: La forma d'ordenació de la llista (per nom, edat, correu, etc.).
- dictionary: Diccionari que compta de el Top 10 de paraules.
- banned_user: Array els noms dels usuaris banejats.
- size_banned_users: Quantitat de banejats.


2. MÒDUL DEL CONTROL DEL FITXER DELS USUARIS

READ_TITLES_LINE

Llegim per caràcters la primera línia, la qual és la dels títols (no la utilitzem).

READ_USERS_LINES

Caràcter per a la lectura del fitxer. Dereferència de la llista dels usuaris.
Inicialitzem a 0 els índexs per a recórrer l'array multidimensional d'usuaris.
omptador de salts de línia al final del fitxer.
Soluciona un bug que es produeix amb el tamany de la xarxa social.
Ampliem la llista dels usuaris (segons un factor multiplicador).
Realitzem la lectura de la resta de línies del fitxer caràcter a caràcter.
Si el caràcter no és coma, salt de línia o final de fitxer...
Incrementant l'índex dels caràcters.
Col·loquem el càracter dins la string auxiliar
En cas contrari...
Després de l'últim caràcter del buffer, hi col·loquem l'acabament de string.
Reservem memòria per una nova string (atribut de l'usuari).
Ressetejem l'índex dels caràcters i incremenetem l'índex dels atributs.
Si en particular detectem un salt de línia...
Ressetejem l'índex dels atributs i incrementem l'índex dels usuaris.
Mentre el caràcter no sigui End Of File (OxFFFFFFFF).
Actualitzem a la llista d'usuaris.
Actualitzem el tamany de la xarxa.

readUsersFile()

@param net: Xarxa d'usuaris inicialitzada.
@param fileName: Nom d'un fitxer .csv existent amb la primera línia emprada per títols i la resta per amb els
atributs dels usuaris. D'atributs n'hi ha d'haver de 9 tipus, d'usuris (files) tants com vulguem.
Llegim caràcter a caràcter cadascuna de les strings separades per comes i les col·loquem a xarxa social.



3. MÒDUL D'ALGORITMES DE CERCA

binarySearch()

Resultat:
- Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat o un error en cas contrari.

Paràmetres:
- attribute: Un atribut a cercar a la llista.
- user: Llista d'usuaris inicialitzada i ordenada alfabèticament segons un tipus.
- size_users: Mida de la llista d'usuaris (no negatiu).
- type: Tipus d'atribut de l'usuari: NAME, AGE, EMAIL, etc.

Inicialitzem els tres índexs i també un enter de comparació.
L'índex de l'esquerra comença a la posició 0.
L'índex de la dreta comença a la posició última.
Mentre els índexs no es creuin.
Comparació entre l'atribut a cercar i un atribut de la llista.
Si l'usuari que hem introduït és més gran en ASCII que el de la llista,
vol dir que l'usuari no és entre els primers de l'alfabet i avancem el punter esquerre.
Si no, si l'usuari és més petit en ASCII,
llavors està entre els primers i avancem el dret.
Altrament, hem trobat l'usuari i retornem la posició dins de la llista.
En cas de no haver trobat l'usuari, la cerca no ha estat exitosa.


fencedAttribute()

Resultat: Retorna TRUE quan l'atribut és més gran que el primer de la llista o quan és
més petit que l'últim usuari i FALSE en cas contrari. Hi ha probabilitat que un usuari fitat pugui estar a la llista.

Paràmetres: els mateixos que binarySearch.

Perquè estigui fitat l'usuari ha de ser més gran o igual al primer usuari o més petit o igual a l'últim.


searchNetwork()

Resultat:
- Ens retorna l'índex de l'usuari dins la llista en cas de ser trobat i un error en cas contrari.
  Per defecte, la llista queda ordenada segons un atribut.

Paràmetre:
- net: Llista d'usuaris inicialitzada i necessàriament ordenada.

S'ordena la llista segons el tipus d'atribut escollit.
Verifiquem que estigui fitat dins la llista.
Iniciem la cerca binària de l'atribut i en retornem l'índex.
Si el nom de l'usuari no està fitat i la llista té una mida inferior a 1, no intentarem cercar-lo.


4. MÒDUL D'ALGORITMES D'ORDENACIÓ

compAttribute()

@param userA: Un usuari de la xarxa.
@param userB: Un altra usuari de la xarxa.
@param type: Tipus d'atribut.
@return Compara dos atributs del mateix tipus i de dos usuaris diferents.

merge()

@param userA: Sub-llista d'usuaris inicialitzada (meitat inferior).
@param sizeA: Mida de "userA".
@param userB: Sub-llista d'usuaris inicialitzada (meitat superior)
@param sizeB: Mida de "userB".
@param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
@return Retornem una nova llista d'usuaris, userC, que és la combinació ordenada de les llistes userA i userB.

Reservem memòria per a una nova llista d'usuaris anomenada "C".
Afegim els element de la llista "A" i la "B" de forma ordenada a la "C".
Si l'atribut d'un usuari de "A" és més petit que "B", el copiem a "C".
En aquest punt, alguna de les dues llistes, "A" o "B", està buida.
Afegim els element que falten de "A" a la llista "C".
Afegim els element que falten de "B" a la llista "C".
Retornem la llista combinada.

mergeSort()

@param user: Usuari inicialitzat amb valors per als seus atributs.
@param size_users: Mida de la llista d'usuaris.
@param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
@return Retornem una nova llista d'usuaris ordenada ascendentment a partir de l'atribut del nom.
"Merge Sort" és un ordenament de recursiu a partir de trossejar i combinar la llista.


sortNetwork()

Ordena si hi ha més d'un usuari.
Ordena si el tipus d'atribut que volem ordenar no està ordenat.
Apliquem l'ordenació combinada.
Actualitzem l'estat d'ordenació de la llista: la llista ja està ordenada segons aquest atribut.


5. MÒDUL DE LES OPCIONS

flushInput()

Funció que s'encarrega de cancel·lar el bucle que es produiria en el programa si no s'introdueix un enter a la
funció read_int. És la funció que supleix a fgetc(stdin), però és més efectiva, ja que esborra més d'un caràcter
incorrecte.

readInt()

@param message: Un text que ens indica que hem d'entrar per consola un enter.
@return Llegeix un entern validat i ens el retorna. Hi col·labora la funció de "flushInput", que és per a treure el
caràcter de '\n' de la lectura per consola.

// Entrem un enter i comprovem que sigui sols un enter (no altres caràcters).
// Esborra TOTS els caràcters incorrectes de stdin.
// Entrem al bucle while.
// Elimina també el caràcter '\n' en clicar ENTER després d'introduir l'enter.
// Repetim l'entrada de l'enter.

### 6. MÒDUL DEL MENÚ PRINCIPAL

showMenu()

Menú principal del programa. Inicialitzem l'estructura de la xarxa i llegim informació del fitxer dels 20 usuaris.
Tenim tres opcions al menú: afegir un nou usuari, enllistar tots els usuaris o operar amb un d'ells.

### 7. MÒDUL DE L'USUARI NOU

newUserData()

Llegim els atributs de l'usuari per consola i els col·loquem dins d'una array d'strings. Al final, retornem aquesta array de dades.
Els atributs estaran validats segons unes condicions que hem imposat al sistema, sobretot per a NAME, AGE, EMAIL i CITY.

newUser()

Bàsicament, expandeix la llista d'usuaris i afegeix les noves dades per a l'últim d'aquests.
Afegim el nou usuari en el fitxer.


### 8. MÒDUL D'ENLLISTAR ELS USUARIS

maxAttributesLengths

Resutlat: De cada columna d'atributs, mirem quina és l'string que té longitud màxima i retornem aquest valor.

Paràmetres:
- user: Llista d'usuaris inicialitzada.
- size_users: Mida de la llista d'usuaris.
- type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).


printUser

Resultat: Imprimim per pantalla els atributs d'un usuari.

Paràmetres:
- user: Usuari inicialitzat amb valors.
- maximums: Llista que conté les longituds de les strings més llargues de cada columna d'atributs.

Iterem per cada columna.
Per a NAME, AGE, EMAIL I CITY.
Imiprimim l'atribut i omplim amb espais proporcionals.
Per als 4 primers hobbies.
Els imprimim separant-los amb punt i coma.
Per a l'últim hobby.
L'imprimim amb un caràcter de salt de línia.

listUsers

Resultat: Imprimeix per pantalla tots els usuaris inscrits a la xarxa.
Paràmetre net: Llista d'usuaris inicialitzada.

// Imprimim la quantitat d'usuaris.
// Creem una llista amb els títols dels atributs dels usuaris.
// Creem una llista amb les màximes longituds de les strings dels atributs.
// Imprimim usuari a usuari.

### 9. MÒDUL D'OPERAR AMB UN USUARI

operateUserMenu

@param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
Submenú que ens mostra quatre opcions específiques d'un usuari si l'usuari està registrat.

chooseUser
Funció auxiliar per a triar l'usuari amb el qual volem operar.
