# _*_ coding: utf-8 _*_
import re
from django import forms
from django.contrib.auth.models import User
from django.contrib.admin.widgets import AdminDateWidget
from django.core.exceptions import ObjectDoesNotExist
from oceny.models import *

class FormularzRejestracji(forms.Form):
    username = forms.CharField(label="Login:",max_length=30)
    email = forms.EmailField(label="Email:")
    password1 = forms.CharField(label="Hasło:",widget=forms.PasswordInput())
    password2 = forms.CharField(label="Powtórz hasło:",widget=forms.PasswordInput())
    phone = forms.CharField(label="Telefon:",max_length=20,required=False)
    imie = forms.CharField(label="Imię:",max_length=20,required=True)
    nazwisko = forms.CharField(label="Nazwisko:",max_length=30,required=True)
    ts = forms.ChoiceField(label='Trener / Sędzia',choices=(('T','Trener'),('S','Sędzia')),required=True)
    team = forms.CharField(label='Nazwa drużyny:',max_length=20,required=False)
    
    def clean_username(self):
        username = self.cleaned_data['username']
        if not re.search(r'^\w+$',username):
            raise forms.ValidationError("Dopuszczalne są tylko cyfry, litery angielskie i _")
        try:
            User.objects.get(username = username)
        except ObjectDoesNotExist:
            return username
        raise forms.ValidationError("Taki użytkownik już istnieje")
    
    def clean_team(self):
        team = self.cleaned_data['team']
        trener = self.cleaned_data['ts']
        if trener == 'T':
            if team == '':
                raise forms.ValidationError("Nazwa drużyny jest wymagana")
            else:
                if not re.search(r'^\w+$',team):
                    raise forms.ValidationError("Dopuszczalne są tylko cyfry, litery angielskie i _")
                try:
                    Druzyna.objects.get(Nazwa = team)
                except ObjectDoesNotExist:
                    return team
                raise forms.ValidationError("Taka drużyna już istnieje")
        if trener == 'S':
            if team != '':
                raise forms.ValidationError("Tylko trener może zarejestrować drużynę")
            else:
                return team
    
    def clean_password2(self):
        password1 = self.cleaned_data['password1']
        password2 = self.cleaned_data['password2']
        if password1 == password2:
            return password2
        else:    
            raise forms.ValidationError("Hasła się różnią")
        
    def clean_email(self):
        email = self.cleaned_data['email']
        if not re.search(r'^\w+@\w+.\w+$',email):
            raise forms.ValidationError("Podaj poprawny adres email")
        try:
            User.objects.get(email = email)
        except ObjectDoesNotExist:
            return email
        raise forms.ValidationError("Ten mail został już użyty do rejestracji innego konta")
    
    
class FormularzKategoria(forms.Form):
    kategoria = forms.ChoiceField(label='Kategoria:',choices=[ (o.Kat, o.Kat) for o in Kategoria.objects.all()],required=True)
    
    
class FormularzKonkurencja(forms.Form):
    konkurencja = forms.ChoiceField(label='Konkurencja:',choices=[ (o.Nazwa, o.Nazwa) for o in Konkurencja.objects.all()],required=True)
    

class FormularzUczestnik(forms.Form):
    imie = forms.CharField(label='Imię:',max_length=20,required=True)
    nazwisko = forms.CharField(label='Nazwisko:',max_length=30,required=True)
    lider = forms.BooleanField(label='Lider:',required=False)
    

class FormularzUsunUczestnik(forms.Form):
    uczestnik = forms.ChoiceField(label="Uczestnicy:",choices=[ (o.ID, str(o)) for o in Uczestnik.objects.all()],required=True)
    
    
class FormularzOcena(forms.Form):
    druzyna = forms.ChoiceField(label='Druzyna:',choices=[ (o.Nazwa, o.Nazwa) for o in Druzyna.objects.all()],required=True)
    spontan = forms.BooleanField(label='Spontan:',required=False)
    ocena = forms.ChoiceField(label='Ocena:',required=True,choices=((0,'0'),(1,'1'),(2,'2'),(3,'3'),(4,'4'),(5,'5'),(6,'6'),(7,'7'),(8,'8'),(9,'9'),(10,'10')))