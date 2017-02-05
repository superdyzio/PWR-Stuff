# coding: utf-8
from django.db import models

class Konkurencja(models.Model):
    Nazwa = models.CharField(max_length=20,primary_key=True,unique=True,default='')
    Kon = models.CharField(max_length=4,primary_key=False,unique=True,default='')
    
    class Meta:
        verbose_name_plural = 'Konkurencje'
        ordering = ('Nazwa',)
        
    def __unicode__(self):
        return self.Nazwa
    
      
class Kategoria(models.Model):
    Kat = models.CharField(max_length=4,primary_key=True,unique=True,default='')
    
    class Meta:
        verbose_name_plural = 'Kategorie'
        ordering = ('Kat',)
        
    def __unicode__(self):
        return self.Kat
    

class Uzytkownik(models.Model):
    Imie = models.CharField(max_length=20,default='')
    Nazwisko = models.CharField(max_length=30,default='')
    login = models.CharField(max_length=30,primary_key=True,unique=True)
    uprawnienia = models.CharField(max_length=40,primary_key=False,default='0000000000000000000000000000000000000000')
    TS = models.CharField(max_length=3,default='S',choices=(('T','Trener'),('S','Sędzia')))
    Team = models.CharField(max_length=20,primary_key=False,blank=True)
    
    class Meta:
        verbose_name_plural = 'Użytkownicy'
        ordering = ('login',)

    def __unicode__(self):
        return self.login
    
    
class Druzyna(models.Model):
    Nazwa = models.CharField(max_length=20,primary_key=True,unique=True,default='')
    Trener = models.OneToOneField(Uzytkownik,primary_key=False)
    Konkurencja = models.ForeignKey(Konkurencja,primary_key=False,null=True,blank=True)
    Kategoria = models.ForeignKey(Kategoria,primary_key=False,null=True,blank=True)
    Wynik_K = models.DecimalField(default=0.0,max_digits=4,decimal_places=2)
    Wynik_S = models.DecimalField(default=0.0,max_digits=4,decimal_places=2)
    
    class Meta:
        verbose_name_plural = 'Drużyny'
        ordering = ('-Wynik_S',)
        
    def __unicode__(self):
        return self.Nazwa
    
   
class Uczestnik(models.Model):
    ID = models.AutoField(primary_key=True,unique=True)
    Druzyna = models.ForeignKey(Druzyna,primary_key=False)
    Imie = models.CharField(max_length=20,default='')
    Nazwisko = models.CharField(max_length=30,default='')
    Lider = models.BooleanField(default=False)
    
    class Meta:
        verbose_name_plural = 'Uczestnicy'
        ordering = ('Nazwisko','Imie',)
        
    def __unicode__(self):
        return self.Imie + ' ' + self.Nazwisko
    
 
class Ocena(models.Model):
    ID = models.AutoField(primary_key=True,unique=True)
    Druzyna = models.ForeignKey(Druzyna,primary_key=False)
    Sedzia = models.ForeignKey(Uzytkownik,primary_key=False)
    Czas = models.DateField()
    Spontan = models.BooleanField(default=False)
    Ocena = models.IntegerField(choices=((0,'0'),(1,'1'),(2,'2'),(3,'3'),(4,'4'),(5,'5'),(6,'6'),(7,'7'),(8,'8'),(9,'9'),(10,'10')))
    
    class Meta:
        verbose_name_plural = 'Oceny'
        ordering = ('Czas','Druzyna',)
        
    def __unicode__(self):
        if self.Spontan:
            kon = 'Spontan'
        else:
            kon = str(self.Druzyna.Konkurencja)
        return str(self.Druzyna) + ' - ' + kon + ': ' + str(self.Ocena) + ' (' + str(self.Sedzia) + ')'