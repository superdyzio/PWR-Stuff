# _*_ coding: utf-8 _*_
from django.conf.urls import patterns, include, url
from django.conf import settings
from django.contrib import admin
from django.views.generic import TemplateView
from oceny.views import *
import os

admin.autodiscover()

urlpatterns = patterns('',
    (r'^admin/',include(admin.site.urls)),
    (r'^$',main_page),
    (r'^tabela',tabela),
    (r'^login/$','django.contrib.auth.views.login'),
    (r'^register/$',register_page),
    (r'^logout/$',logout_page),
    (r'^trener/$',trener),
    (r'^sedzia/$',sedzia),
    (r'^sedzia/zobacz_oceny/$',zobacz_oceny), # np podstrona localhost:8000/sedzia/zobacz_oceny i jak pojawi sie ten adres to wywolany jest widok zobacz_oceny
    (r'^sedzia/dodaj_ocene/$',dodaj_ocene),
    (r'^trener/dodaj_kategorie/$',dodawanie_kategorii),
    (r'^trener/dodaj_konkurencje/$',dodawanie_konkurencji),
    (r'^trener/dodaj_uczestnika/$',dodaj_uczestnika),
    (r'^trener/usun_uczestnika/$',usun_uczestnika),
    (r'^trener/wyswietl_oceny/$',wyswietl_oceny),
    (r'^trener/wyswietl_uczestnikow/$',wyswietl_uczestnikow),
    (r'^media/(?P<path>.*)$','django.views.static.serve',{'document_root': settings.MEDIA_ROOT})
)