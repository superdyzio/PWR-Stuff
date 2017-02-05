# _*_ coding: utf-8 _*_
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.template.loader import get_template
from django.template import RequestContext
from django.contrib.auth import logout
from datetime import datetime
import sys
from enum import Enum
from oceny.models import *
from oceny.forms import *

class Konk(Enum):
    gra = 0
    kino = 1
    kul = 2
    poc = 3
    tech = 4
    
class Kate(Enum):
    U6 = 0
    U10 = 1
    U14 = 2
    U19 = 3
    U26 = 4
    
def sedzia(request):
    template = get_template("sedzia.html")
    variables = RequestContext(request,{'uzytkownicy':Uzytkownik.objects.all(),'druzyny':Druzyna.objects.all()})  
    output = template.render(variables)
    return HttpResponse(output)

def trener(request):
    template = get_template("trener.html")
    variables = RequestContext(request,{'uzytkownicy':Uzytkownik.objects.all(),'druzyny':Druzyna.objects.all()})  
    output = template.render(variables)
    return HttpResponse(output)

def main_page(request):
    template = get_template("main_page.html")
    variables = RequestContext(request,{'podpis': 'Odyseja umysłu 2015','uzytkownicy': Uzytkownik.objects.all()})  
    output = template.render(variables)
    return HttpResponse(output)

def tabela(request):
    template = get_template("tabela.html")
    for d in Druzyna.objects.all():
        sumaK = 0; sumaS = 0; nK = 0; nS = 0
        for o in Ocena.objects.all():
            if o.Druzyna == d:
                if o.Spontan:
                    sumaS += o.Ocena; nS += 1
                else:
                    sumaK += o.Ocena; nK += 1
        sumaS += sumaK; nS += nK
        d.Wynik_K = (float)(sumaK) / (float)(nK); d.Wynik_S = (float)(sumaS) / (float)(nS)
        d.save()
    variables = RequestContext(request,{'druzyny':Druzyna.objects.all()})
    output = template.render(variables)
    return HttpResponse(output)

def zobacz_oceny(request):
    template = get_template("sedzia/zobacz_oceny.html")
    variables = RequestContext(request,{'oceny':Ocena.objects.filter(Sedzia=request.user.username)})
    output = template.render(variables)
    return HttpResponse(output)

def wyswietl_oceny(request):
    template = get_template("trener/wyswietl_oceny.html")
    dr = Druzyna.objects.get(Trener = request.user.username)
    variables = RequestContext(request,{'oceny':Ocena.objects.filter(Druzyna = dr,Spontan = False)})
    output = template.render(variables)
    return HttpResponse(output)

def wyswietl_uczestnikow(request):
    template = get_template("trener/wyswietl_uczestnikow.html")
    dr = Druzyna.objects.get(Trener = request.user.username)
    variables = RequestContext(request,{'uczestnicy':Uczestnik.objects.filter(Druzyna = dr)})
    output = template.render(variables)
    return HttpResponse(output)

def logout_page(request):
    logout(request)
    return HttpResponseRedirect("/")

def register_page(request):
    if request.method == 'POST':
        form = FormularzRejestracji(request.POST)
        if form.is_valid():
            imie = form.cleaned_data['imie']
            nazwisko = form.cleaned_data['nazwisko']
            ts = form.cleaned_data['ts']
            team = form.cleaned_data['team']
            user = User.objects.create_user(
                username = form.cleaned_data['username'],
                password = form.cleaned_data['password1'],
                email = form.cleaned_data['email']
            )
            user.last_name = form.cleaned_data['phone']
            user.save()
            u = Uzytkownik(Imie=imie,Nazwisko=nazwisko,login=user.username,TS=ts,Team=team)
            u.save()
            if ts == 'T':
                d = Druzyna(Nazwa=team,Trener=u)
                d.save()
            template = get_template("registration/register_success.html")
            variables = RequestContext(request,{'username':form.cleaned_data['username']})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzRejestracji()
    template = get_template("registration/register.html")    
    variables = RequestContext(request,{'form':form})
    output = template.render(variables)
    return HttpResponse(output)

def dodawanie_kategorii(request):
    if request.method == 'POST':
        user = User.objects.get(username=request.user.username)
        form = FormularzKategoria(request.POST)
        if form.is_valid():
            kategoria = form.cleaned_data['kategoria']
            druzyna = Druzyna.objects.get(Trener=user.username)
            druzyna.Kategoria = Kategoria.objects.get(Kat=kategoria)
            druzyna.save()
            template = get_template("trener/dodaj_kategorie.html")
            variables = RequestContext(request,{'druzyny':Druzyna.objects.all(),'kategoria':form.cleaned_data['kategoria']})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzKategoria()
    template = get_template("trener/dodaj_kategorie.html")    
    variables = RequestContext(request,{'form':form,'druzyny':Druzyna.objects.all()})
    output = template.render(variables)
    return HttpResponse(output)

def dodawanie_konkurencji(request):
    if request.method == 'POST':
        user = User.objects.get(username=request.user.username)
        form = FormularzKonkurencja(request.POST)
        if form.is_valid():
            konkurencja = form.cleaned_data['konkurencja']
            druzyna = Druzyna.objects.get(Trener=user.username)
            druzyna.Konkurencja = Konkurencja.objects.get(Nazwa=konkurencja)
            druzyna.save()
            template = get_template("trener/dodaj_konkurencje.html")
            variables = RequestContext(request,{'druzyny':Druzyna.objects.all(),'konkurencja':form.cleaned_data['konkurencja']})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzKonkurencja()
    template = get_template("trener/dodaj_konkurencje.html")    
    variables = RequestContext(request,{'form':form,'druzyny':Druzyna.objects.all()})
    output = template.render(variables)
    return HttpResponse(output)

def dodaj_uczestnika(request):
    if request.method == 'POST':
        user = User.objects.get(username=request.user.username)
        form = FormularzUczestnik(request.POST)
        druzyna = Druzyna.objects.get(Trener=user.username)
        try:
            obecny_lider = Uczestnik.objects.get(Druzyna=druzyna,Lider=True)
            if obecny_lider:
                lider = False
            form.fields['lider'].widget = forms.HiddenInput()
        except Uczestnik.DoesNotExist:
            obecny_lider = None
        if form.is_valid():
            imie = form.cleaned_data['imie']
            nazwisko = form.cleaned_data['nazwisko']
            lider = form.cleaned_data['lider']
            u = Uczestnik(Druzyna=druzyna,Imie=imie,Nazwisko=nazwisko,Lider=lider)
            u.save()
            template = get_template("trener/dodaj_uczestnika.html")
            variables = RequestContext(request,{})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzUczestnik()
    template = get_template("trener/dodaj_uczestnika.html")    
    variables = RequestContext(request,{'form':form})
    output = template.render(variables)
    return HttpResponse(output)

def usun_uczestnika(request):
    if request.method == 'POST':
        user = User.objects.get(username=request.user.username)
        form = FormularzUsunUczestnik(request.POST)
        druzyna = Druzyna.objects.get(Trener=user.username)
        if form.is_valid():
            uczestnik = form.cleaned_data['uczestnik']
            choices = Uczestnik.objects.filter(Druzyna=druzyna)
            form.fields['uczestnik'].choices = [ (o.ID,str(o)) for o in choices ]
            ob = Uczestnik.objects.get(ID=uczestnik)
            ob.delete()
            template = get_template("trener/usun_uczestnika.html")
            variables = RequestContext(request,{'uczestnicy':Uczestnik.objects.filter(Druzyna=druzyna)})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzUsunUczestnik()
    template = get_template("trener/usun_uczestnika.html")    
    variables = RequestContext(request,{'form':form})
    output = template.render(variables)
    return HttpResponse(output)
    
def dodaj_ocene(request):
    if request.method == 'POST':
        user = User.objects.get(username=request.user.username)
        sedzia = Uzytkownik.objects.get(login=user.username)
        form = FormularzOcena(request.POST)
        if form.is_valid():
            druzyna = form.cleaned_data['druzyna']
            dr = Druzyna.objects.get(Nazwa=druzyna)
            spontan = form.cleaned_data['spontan']
            ocena = form.cleaned_data['ocena']
            o = Ocena(Sedzia=sedzia,Druzyna=dr,Czas=datetime.now(),Spontan=spontan,Ocena=ocena)
            if dr.Konkurencja.Kon == 'kino':
                indeks = 5
            if dr.Konkurencja.Kon == 'gra':
                indeks = 0
            if dr.Konkurencja.Kon == 'kul':
                indeks = 11
            if dr.Konkurencja.Kon == 'poc':
                indeks = 17
            if dr.Konkurencja.Kon == 'tech':
                indeks = 23
            if dr.Kategoria.Kat == 'U6':
                indeks += 0
            if dr.Kategoria.Kat == 'U10':
                indeks += 1
            if dr.Kategoria.Kat == 'U14':
                indeks += 2
            if dr.Kategoria.Kat == 'U19':
                indeks += 3
            if dr.Kategoria.Kat == 'U26':
                indeks += 4
            try:
                ocena_spontan = Ocena.objects.get(Sedzia=sedzia,Druzyna=dr,Spontan=True)
            except OcenaDoesNotExist:
                ocena_spontan = None
            if o.Spontan == True and ocena_spontan == None:
                o.save()
            if sedzia.uprawnienia[indeks] == '1':
                o.save()
            template = get_template("sedzia/dodaj_ocene.html")
            variables = RequestContext(request,{'form':form})
            output = template.render(variables)
            return HttpResponse(output)            
    else:
        form = FormularzOcena()
    template = get_template("sedzia/dodaj_ocene.html")    
    variables = RequestContext(request,{'form':form})
    output = template.render(variables)
    return HttpResponse(output)