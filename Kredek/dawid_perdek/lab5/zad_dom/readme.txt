zacz��em pracowa� na dok�adnie tym projekcie, kt�ry na laboratorium dzia�a� bez zarzutu i teraz, z przyczyn kt�rych zupe�nie nie rozumiem, dzia�a wszystko opr�cz dodawania pizzy -> model ma ci�gle Id = 0 i pojawia si� b��d, �e Id niepoprawne
poczyta�em internetu i radzili zmienia� nazw� Id na jak�� inn�, kombinowa� jakie� inne rzeczy, ale nic nie podzia�a�o, wi�c postanowi�em jako� �y� z tym problemem

Okaza�o si�, �e po wywaleniu linijki HiddenFor wszystko zadzia�a�o. (nazwa klucza zmieniona na PizzaId i dodana adnotacja [Key])


Je�li macie jaki� pomys� dlaczego tak si� sta�o to prosi�bym o wyja�nienie!


TODO:
1) przechowywa� gdzie� potwierdzone zam�wienia
2) dorobi� widok (wej�cie po podaniu has�a) dla listy potwierdzonych zam�wie�, z opcj� usuni�cia ka�dego z nich