zacz¹³em pracowaæ na dok³adnie tym projekcie, który na laboratorium dzia³a³ bez zarzutu i teraz, z przyczyn których zupe³nie nie rozumiem, dzia³a wszystko oprócz dodawania pizzy -> model ma ci¹gle Id = 0 i pojawia siê b³¹d, ¿e Id niepoprawne
poczyta³em internetu i radzili zmieniaæ nazwê Id na jak¹œ inn¹, kombinowaæ jakieœ inne rzeczy, ale nic nie podzia³a³o, wiêc postanowi³em jakoœ ¿yæ z tym problemem

Okaza³o siê, ¿e po wywaleniu linijki HiddenFor wszystko zadzia³a³o. (nazwa klucza zmieniona na PizzaId i dodana adnotacja [Key])


Jeœli macie jakiœ pomys³ dlaczego tak siê sta³o to prosi³bym o wyjaœnienie!


TODO:
1) przechowywaæ gdzieœ potwierdzone zamówienia
2) dorobiæ widok (wejœcie po podaniu has³a) dla listy potwierdzonych zamówieñ, z opcj¹ usuniêcia ka¿dego z nich