"""klubpilkarski URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.8/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import include, url
from django.conf.urls.i18n import i18n_patterns
from django.contrib import admin
from django.contrib.auth import views
from django.template import context
from club.forms import LoginForm
from club.views import *

urlpatterns = [
    url(r'^i18n/', include('django.conf.urls.i18n')),
    url(r'^admin/', include(admin.site.urls))
]

urlpatterns += i18n_patterns(
    url(r'^$', home, name='home'),
    url(r'^players$', PlayersView.as_view(), name='players'),
    url(r'^players/filter-players$', PlayersView.filter_players, name='filter-players'),
    url(r'^players/(?P<player_slug>[a-zA-Z0-9\-]+)$', PlayerDetailsView.as_view(), name='player-details'),
    url(r'^employees$', EmployeesView.as_view(), name='employees'),
    url(r'^employees/filter-employees$', EmployeesView.filter_employees, name='filter-employees'),
    url(r'^employees/(?P<employee_slug>[a-zA-Z0-9\-]+)$', EmployeeDetailsView.as_view(), name='employee-details'),
    url(r'^trophies$', TrophiesView.as_view(), name='trophies'),
    url(r'^trophies/filter-trophies$', TrophiesView.filter_trophies, name='filter-trophies'),
    url(r'^lineups$', LineupsView.as_view(), name='lineups'),
    url(r'^lineups/(?P<pk>\d+)/$', LineupDetailsView.as_view(), name='lineup-details'),
    url(r'^games/(?P<season_id>\d+)/(?P<fixture_id>\d+)/$', GamesView.as_view(), name='games'),
    url(r'^games/(?P<season_id>\d+)/(?P<fixture_id>\d+)/filter-games$', GamesView.filter_games,
        name='filter-games'),
    url(r'^games/(?P<game_slug>[a-zA-Z0-9\-]+)$', GameDetailsView.as_view(), name='game-details'),
    url(r'^login/$', views.login, {'template_name': 'login.html', 'authentication_form': LoginForm,
                                   'extra_context': {'page': 'login'}}, name='login'),
    url(r'^logout/$', views.logout, {'next_page': '/login'}, name='logout')
)
