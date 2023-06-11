# EDA2
Projecte per a fer una Xarxa Social.

Zhiyuan, Marc, Yuxiang

1. MÒDUL DEL CONTROL DE LES ESTRUCTURES DE LA XARXA

Constants:
- ATTRIBUTES: Quanitat de dades d'un usuari.
- NAME, AGE, EMAIL, (...): Són els índex per a accedir als atributs de les dades de l'usuari.
- NULL_SIZE: Mida d'una array buida.
- INCREMENT_SIZE: Per a incrementar la mida d'una array d'un en un.
- MULTIPLICATIVE_FACTOR: Per a incrementar una array en varis element.
- NOT_ORDERED: La llista no té cap tipus d'ordenació.
- BUFFER_SIZE: Un nombre molt gran, per a un buffer de caràcters (2^10 bytes)

Estructures de Dedes:

Usuari:
- data: Array d'strings que conté els atributs de l'usuari. Sempre tindrà mida de la constant ATTRIBUTES.
- request: Array que conté els usuris que li han enviat licitud a un usuari.
- size_requests: Quantitat de sol·licituds.
- friends: Array que conté els nostres amics, que són els usuaris els quals els hi hem acceptat la sol·licitud.
- size_requests: Quantitat d'amics.
- post: Array que conté les publicions d'un usuari (format de text).
- size_requests: Quantitat de publicacions.

Network:
- user: Array dinàmica dels usuaris.
- size_users: Quantitat d'usuaris.
- order_users: La forma d'ordenació de la llista (per nom, edat, correu, etc.).


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

6. MÒDUL DEL MENÚ PRINCIPAL

showMenu()

Menú principal del programa. Inicialitzem l'estructura de la xarxa i llegim informació del fitxer dels 20 usuaris.
Tenim tres opcions al menú: afegir un nou usuari, enllistar tots els usuaris o operar amb un d'ells.

7. MÒDUL DE L'USUARI NOU

newUserData()

Llegim els atributs de l'usuari per consola i els col·loquem dins d'una array d'strings. Al final, retornem aquesta array de dades.
Els atributs estaran validats segons unes condicions que hem imposat al sistema, sobretot per a NAME, AGE, EMAIL i CITY.

newUser()

Bàsicament, expandeix la llista d'usuaris i afegeix les noves dades per a l'últim d'aquests.
Afegim el nou usuari en el fitxer.


8. MÒDUL D'ENLLISTAR ELS USUARIS

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

9. MÒDUL D'OPERAR AMB UN USUARI

operateUserMenu

@param n: Llista d'usuaris inicialitzada i necessàriament ordenada.
Submenú que ens mostra quatre opcions específiques d'un usuari si l'usuari està registrat.

chooseUser
Funció auxiliar per a triar l'usuari amb el qual volem operar.
