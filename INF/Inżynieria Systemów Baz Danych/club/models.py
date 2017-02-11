from __future__ import unicode_literals
from django.contrib.auth.models import AbstractUser
from django.db import models
from django.utils.datetime_safe import datetime
from django.utils.text import slugify
from django.utils.translation import ugettext_lazy as _
from klubpilkarski.core_variables import COUNTRIES, GENDER


class Teams(models.Model):
    name = models.CharField(verbose_name=_('Team name'), max_length=25, blank=False, default="")
    inLeague = models.BooleanField(verbose_name=_('In our league'))
    isOursTeam = models.BooleanField(verbose_name=_('Is ours team'))

    class Meta:
        verbose_name = _("Team")
        verbose_name_plural = _("Teams")
        ordering = ('name', 'inLeague')

    def __unicode__(self):
        return self.name


class Trophies(models.Model):
    name = models.CharField(verbose_name=_('Trophy name'), max_length=100, blank=False, default="")
    name_pl = models.CharField(verbose_name=_('Polish name of the trophy'), max_length=100, blank=False, default="")
    season_start = models.IntegerField(verbose_name=_("Year start of the season"), default="", blank=False)
    season_end = models.IntegerField(verbose_name=_("Year end of the season"), default="", blank=True, null=True)

    class Meta:
        verbose_name = _("Trophy")
        verbose_name_plural = _("Trophies")
        ordering = ('season_start', 'season_end', 'name')

    def __unicode__(self):
        return self.name


class Lineups(models.Model):
    name = models.CharField(verbose_name=_('Lineup name'), max_length=25, blank=False)
    name_pl = models.CharField(verbose_name=_('Polish name of the lineup'), max_length=25, blank=False, default="")

    class Meta:
        verbose_name = _("Lineup")
        verbose_name_plural = _("Lineups")

    def __unicode__(self):
        return self.name


class Roles(models.Model):
    name = models.CharField(verbose_name=_('Role name'), max_length=25, blank=False)
    name_pl = models.CharField(verbose_name=_('Polish name of the role'), max_length=25, blank=False, default="")

    class Meta:
        verbose_name = _("Role")
        verbose_name_plural = _("Roles")
        ordering = ('name',)

    def __unicode__(self):
        return self.name


class Positions(models.Model):
    name = models.CharField(verbose_name=_('Position'), max_length=100, blank=False)

    class Meta:
        verbose_name = _("Position")
        verbose_name_plural = _("Positions")

    def __unicode__(self):
        return self.name


class Players(models.Model):
    name = models.CharField(verbose_name=_('Name'), max_length=100, blank=False)
    surname = models.CharField(verbose_name=_('Surname'), max_length=30, blank=False)
    gender = models.CharField(verbose_name=_('Gender'), choices=GENDER, max_length=1, default=_('M'), blank=False)
    person_id = models.BigIntegerField(verbose_name=_('Person ID'), blank=True, default=0)
    captain = models.BooleanField(verbose_name=_('Is this player the team captain?'), default=False)
    date_of_birth = models.DateField(verbose_name=_('Date of birth'), blank=False, null=True)
    height = models.IntegerField(verbose_name=_('Height'), blank=False, default=0)
    weight = models.FloatField(verbose_name=_('Weight'), blank=False, default=0)
    country = models.CharField(verbose_name=_('Country'), choices=COUNTRIES, max_length=2, default=_('PL'), blank=False)
    BETTER_LEG = (
        (_('L'), _('Left')),
        (_('R'), _('Right'))
    )
    better_leg = models.CharField(verbose_name=_('Better leg'), choices=BETTER_LEG, max_length=1, blank=True,
                                  default=_('R'))
    number = models.IntegerField(verbose_name=_('Player number'), blank=True, null=None, default=0)
    INJURY = (
        (_('Y'), _('Yes')),
        (_('N'), _('No'))
    )
    injury = models.CharField(verbose_name=_('Injury'), choices=INJURY, max_length=5, default=_('N'))
    image = models.ImageField(upload_to='media/players', verbose_name=_("Image"), blank=True, default="")
    slug = models.SlugField(unique=True, db_index=True, blank=True, editable=False)
    lineup = models.ForeignKey(Lineups, primary_key=False, verbose_name=_('Lineup'))
    fromTeam = models.ForeignKey(Teams, primary_key=False, verbose_name=_('Transfer from'), blank=True, null=True)
    position = models.ForeignKey(Positions, primary_key=False, verbose_name=_('Position'))

    class Meta:
        verbose_name = _("Player")
        verbose_name_plural = _("Players")
        ordering = ('id', 'surname', 'name', 'lineup', 'fromTeam', 'position')

    def save(self, *args, **kwargs):
        if not self.id and not self.slug:
            slug = slugify(self.surname + '-' + self.name)
            slug_exists = True
            counter = 1
            self.slug = slug
            while slug_exists:
                try:
                    slug_exits = Players.objects.get(slug=slug)
                    if slug_exits:
                        slug = self.slug + '-' + str(counter)
                        counter += 1
                except Players.DoesNotExist:
                    self.slug = slug
                    break
        super(Players, self).save(*args, **kwargs)

    def __unicode__(self):
        return self.name


class Employees(AbstractUser):
    first_name = models.CharField(_('First name'), max_length=30, blank=False)
    last_name = models.CharField(_('Last name'), max_length=30, blank=False)
    gender = models.CharField(verbose_name=_('Gender'), choices=GENDER, max_length=1, default=_('M'), blank=False)
    date_of_birth = models.DateField(verbose_name=_('Date of birth'), blank=True, null=True)
    country = models.CharField(verbose_name=_('Country'), choices=COUNTRIES, max_length=2, default=_('PL'), blank=False)
    phone_number = models.CharField(verbose_name=_('Phone number'), max_length=12, blank=True)
    slug = models.SlugField(unique=True, db_index=True, blank=True, editable=False)
    role = models.ForeignKey(Roles, primary_key=False, verbose_name=_('Role'), default='', blank=True, null=True)
    lineup = models.ForeignKey(Lineups, primary_key=False, verbose_name=_('Lineup'), default='', blank=True, null=True)

    class Meta:
        verbose_name = _("Employee")
        verbose_name_plural = _("Employees")
        ordering = ('id', 'username', 'last_name', 'first_name', 'email')

    def save(self, *args, **kwargs):
        if not self.id and not self.slug:
            slug = slugify(self.last_name + '-' + self.first_name)
            slug_exists = True
            counter = 1
            self.slug = slug
            while slug_exists:
                try:
                    slug_exits = Employees.objects.get(slug=slug)
                    if slug_exits:
                        slug = self.slug + '-' + str(counter)
                        counter += 1
                except Employees.DoesNotExist:
                    self.slug = slug
                    break
        super(Employees, self).save(*args, **kwargs)

    def __unicode__(self):
        return self.first_name


class Seasons(models.Model):
    name = models.CharField(verbose_name=_('Name'), max_length=100, blank=False, unique=True,
                            default=("%s/%s" % (str(datetime.now().year), str(datetime.now().year + 1))))

    class Meta:
        verbose_name = _("Season")
        verbose_name_plural = _("Seasons")
        ordering = ('name', )

    def __unicode__(self):
        return self.name


class Fixtures(models.Model):
    name = models.CharField(verbose_name=_('Fixture name'), max_length=100, blank=False, default="")
    name_pl = models.CharField(verbose_name=_('Polish name of the fixture'),
                               max_length=100, blank=False, default="")

    class Meta:
        verbose_name = _("Fixture")
        verbose_name_plural = _("Fixtures")

    def __unicode__(self):
        return self.name


class Games(models.Model):
    homeTeamGoals = models.IntegerField(verbose_name=_('Home team goals'), blank=False, default=0)
    awayTeamGoals = models.IntegerField(verbose_name=_('Away team goals'), blank=False, default=0)
    game_date = models.DateField(verbose_name=_('Game Date'), blank=False, null=True)
    game_hour = models.TimeField(verbose_name=_('Game hour'), blank=False, null=True)
    statistics = models.CharField(verbose_name=_('Statistics'), max_length=255, blank=True)
    slug = models.SlugField(unique=True, db_index=True, blank=True, editable=False)
    homeTeam = models.ForeignKey(Teams, primary_key=False, related_name="home_team", verbose_name=_('Home Team'))
    awayTeam = models.ForeignKey(Teams, primary_key=False, related_name="away_team", verbose_name=_('Away Team'))
    fixture = models.ForeignKey(Fixtures, primary_key=False, related_name="match_fixtures",
                                verbose_name=_('Match Fixture'))
    season = models.ForeignKey(Seasons, primary_key=False, related_name="match_season", verbose_name=_('Season'))

    class Meta:
        verbose_name = _("Game")
        verbose_name_plural = _("Games")
        ordering = ('-game_date', 'game_hour', 'homeTeam', 'awayTeam')

    def match_result(self):
        return '%s:%s' % (str(self.homeTeamGoals), str(self.awayTeamGoals))

    def save(self, *args, **kwargs):
        if not self.id and not self.slug:
            slug = slugify(self.homeTeam.name + '-' + self.awayTeam.name)
            slug_exists = True
            counter = 1
            self.slug = slug
            while slug_exists:
                try:
                    slug_exits = Games.objects.get(slug=slug)
                    if slug_exits:
                        slug = self.slug + '-' + str(counter)
                        counter += 1
                except Games.DoesNotExist:
                    self.slug = slug
                    break
        super(Games, self).save(*args, **kwargs)

    def __unicode__(self):
        return self.slug
