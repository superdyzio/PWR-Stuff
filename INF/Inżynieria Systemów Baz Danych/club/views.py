from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin
from django.db.models import Q
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.views.generic import TemplateView
from .models import *


@login_required(login_url="login/")
def home(request):
    if request.LANGUAGE_CODE == 'pl':
        return HttpResponseRedirect('/pl/employees')
    else:
        return HttpResponseRedirect('/en/employees')


class PlayersView(TemplateView):
    template_name = "players.html"
    page = 'players'

    def get_context_data(self, **kwargs):
        sort_by = self.request.GET.get('sort')
        desc = self.request.GET.get('desc') == 'yes'
        context = super(PlayersView, self).get_context_data(**kwargs)
        context['page'] = self.page
        if sort_by:
            if desc:
                context['playersfields'] = Players.objects.all().order_by('-' + sort_by)
            else:
                context['playersfields'] = Players.objects.all().order_by(sort_by)
            context['sort_param'] = sort_by
        else:
            context['playersfields'] = Players.objects.all()
        return context

    @classmethod
    def filter_players(cls, request):
        page = 'players'
        search_phrase = request.GET.get('search_phrase', '')
        filtered_players = Players.objects.filter(
            Q(name__icontains=search_phrase) | Q(surname__icontains=search_phrase) |
            Q(position__name__icontains=search_phrase))
        context = {'playersfields': filtered_players, 'search_phrase': search_phrase, 'page': page}
        return render(request, "players.html", context)


class PlayerDetailsView(TemplateView):
    template_name = "player_details.html"
    page = 'player'
    player_slug = None

    def get(self, request, *args, **kwargs):
        self.player_slug = kwargs.get('player_slug')
        return super(PlayerDetailsView, self).get(request, *args, **kwargs)

    def get_context_data(self, **kwargs):
        context = super(PlayerDetailsView, self).get_context_data(**kwargs)
        context['page'] = self.page
        context['player'] = Players.objects.get(slug=self.player_slug)
        context['countries'] = COUNTRIES
        context['legs'] = Players.BETTER_LEG
        context['injuries'] = Players.INJURY
        return context


class EmployeesView(LoginRequiredMixin, TemplateView):
    template_name = "employees.html"
    page = 'employees'
    login_url = "/login"

    def get_context_data(self, **kwargs):
        sort_by = self.request.GET.get('sort')
        desc = self.request.GET.get('desc') == 'yes'
        context = super(EmployeesView, self).get_context_data(**kwargs)
        context['page'] = self.page
        if sort_by:
            if desc:
                context['employeesfields'] = Employees.objects.exclude(role_id=None).order_by('-' + sort_by)
            else:
                context['employeesfields'] = Employees.objects.exclude(role_id=None).order_by(sort_by)
            context['sort_param'] = sort_by
        else:
            context['employeesfields'] = Employees.objects.exclude(role_id=None)
        return context

    @classmethod
    def filter_employees(cls, request):
        page = 'employees'
        search_phrase = request.GET.get('search_phrase', '')
        filtered_employees = Employees.objects.filter(
            Q(first_name__icontains=search_phrase) | Q(last_name__icontains=search_phrase) |
            Q(role__name__icontains=search_phrase))
        context = {'employeesfields': filtered_employees, 'search_phrase': search_phrase, 'page': page}
        return render(request, "employees.html", context)


class EmployeeDetailsView(LoginRequiredMixin, TemplateView):
    template_name = "employee_details.html"
    page = 'employees'
    employee_slug = None
    login_url = "/login"

    def get(self, request, *args, **kwargs):
        self.employee_slug = kwargs.get('employee_slug')
        return super(EmployeeDetailsView, self).get(request, *args, **kwargs)

    def get_context_data(self, **kwargs):
        context = super(EmployeeDetailsView, self).get_context_data(**kwargs)
        context['page'] = self.page
        context['employee'] = Employees.objects.get(slug=self.employee_slug)
        context['countries'] = COUNTRIES
        return context


class TrophiesView(TemplateView):
    template_name = "trophies.html"
    page = 'trophies'

    def get_context_data(self, **kwargs):
        sort_by = self.request.GET.get('sort')
        desc = self.request.GET.get('desc') == 'yes'
        context = super(TrophiesView, self).get_context_data(**kwargs)
        context['page'] = self.page
        if sort_by:
            if desc:
                context['trophiesfields'] = Trophies.objects.all().order_by('-' + sort_by)
            else:
                context['trophiesfields'] = Trophies.objects.all().order_by(sort_by)
            context['sort_param'] = sort_by
        else:
            context['trophiesfields'] = Trophies.objects.all()
        return context

    @classmethod
    def filter_trophies(cls, request):
        page = 'trophies'
        search_phrase = request.GET.get('search_phrase', '')
        if request.LANGUAGE_CODE == 'pl':
            filtered_trophies = Trophies.objects.filter(name_pl__icontains=search_phrase)
        else:
            filtered_trophies = Trophies.objects.filter(name__icontains=search_phrase)
        context = {'trophiesfields': filtered_trophies, 'search_phrase': search_phrase, 'page': page}
        return render(request, "trophies.html", context)


class LineupsView(TemplateView):
    template_name = "lineups.html"
    page = 'lineups'

    def get_context_data(self, **kwargs):
        context = super(LineupsView, self).get_context_data(**kwargs)
        context['page'] = self.page
        context['lineupsfields'] = Lineups.objects.all()
        return context


class LineupDetailsView(LoginRequiredMixin, TemplateView):
    template_name = "lineup_details.html"
    page = "lineups"
    lineup_id = None
    login_url = "/login"

    def get(self, request, *args, **kwargs):
        self.lineup_id = kwargs.get('pk')
        return super(LineupDetailsView, self).get(request, *args, **kwargs)

    def get_context_data(self, **kwargs):
        sort_by = self.request.GET.get('sort')
        sort_table = self.request.GET.get('table')
        desc = self.request.GET.get('desc') == 'yes'
        context = super(LineupDetailsView, self).get_context_data(**kwargs)
        context['page'] = self.page
        context['object'] = Lineups.objects.get(id=self.lineup_id)
        context['lineups'] = Lineups.objects.all()
        if sort_by:
            context['sort_param'] = sort_by
            if sort_table == 'players':
                if self.request.session.get('employees_sort'):
                    context['employees'] = Employees.objects.filter(lineup_id=self.lineup_id).order_by(
                        self.request.session.get('employees_sort'))
                else:
                    context['employees'] = Employees.objects.filter(lineup_id=self.lineup_id)
                if desc:
                    self.request.session['players_sort'] = '-' + sort_by
                    context['players'] = Players.objects.filter(lineup_id=self.lineup_id).order_by('-' + sort_by)
                else:
                    self.request.session['players_sort'] = sort_by
                    context['players'] = Players.objects.filter(lineup_id=self.lineup_id).order_by(sort_by)
            else:
                if self.request.session.get('players_sort'):
                    context['players'] = Players.objects.filter(lineup_id=self.lineup_id).order_by(
                        self.request.session.get('players_sort'))
                else:
                    context['players'] = Players.objects.filter(lineup_id=self.lineup_id)
                if desc:
                    self.request.session['employees_sort'] = '-' + sort_by
                    context['employees'] = Employees.objects.filter(lineup_id=self.lineup_id).order_by('-' + sort_by)
                else:
                    self.request.session['employees_sort'] = sort_by
                    context['employees'] = Employees.objects.filter(lineup_id=self.lineup_id).order_by(sort_by)
        else:
            context['players'] = Players.objects.filter(lineup_id=self.lineup_id)
            context['employees'] = Employees.objects.filter(lineup_id=self.lineup_id)
        return context


class GamesView(TemplateView):
    template_name = "games.html"
    page = 'games'
    season_id = None
    fixture_id = None

    def get(self, request, *args, **kwargs):
        self.season_id = kwargs.get('season_id')
        self.fixture_id = kwargs.get('fixture_id')
        return super(GamesView, self).get(request, *args, **kwargs)

    def get_context_data(self, **kwargs):
        sort_by = self.request.GET.get('sort')
        desc = self.request.GET.get('desc') == 'yes'
        context = super(GamesView, self).get_context_data(**kwargs)
        context['page'] = self.page
        context['seasons'] = Seasons.objects.filter(pk__in=Games.objects.all().values_list('season_id'))
        context['fixtures'] = Fixtures.objects.filter(pk__in=Games.objects.filter(
            season_id=self.season_id).values_list('fixture_id'))
        context['season_id'] = self.season_id
        context['fixture_id'] = self.fixture_id
        if sort_by:
            if desc:
                context['gamesfields'] = Games.objects.filter(season_id=self.season_id,
                                                              fixture_id=self.fixture_id).order_by('-' + sort_by)
            else:
                context['gamesfields'] = Games.objects.filter(season_id=self.season_id,
                                                              fixture_id=self.fixture_id).order_by(sort_by)
            context['sort_param'] = sort_by
        else:
            context['gamesfields'] = Games.objects.filter(season_id=self.season_id,
                                                          fixture_id=self.fixture_id).order_by('-game_date', '-game_hour')
        return context

    @classmethod
    def filter_games(cls, request, **kwargs):
        page = 'games'
        context = {}
        cls.season_id = kwargs.get('season_id')
        cls.fixture_id = kwargs.get('fixture_id')
        search_phrase = request.GET.get('search_phrase', '')
        filtered_games = Games.objects.filter(
            Q(homeTeam__name__icontains=search_phrase,
              season_id=cls.season_id, fixture_id=cls.fixture_id) |
            Q(awayTeam__name__icontains=search_phrase, season_id=cls.season_id, fixture_id=cls.fixture_id)
        )
        context['page'] = page
        context['gamesfields'] = filtered_games
        context['search_pharse'] = search_phrase
        context['seasons'] = Seasons.objects.all()
        context['fixtures'] = Fixtures.objects.filter(pk__in=Games.objects.filter(
            season_id=cls.season_id).values_list('fixture_id'))
        context['season_id'] = cls.season_id
        context['fixture_id'] = cls.fixture_id

        return render(request, "games.html", context)


class GameDetailsView(TemplateView):
    template_name = "game_details.html"
    page = 'game_details'
