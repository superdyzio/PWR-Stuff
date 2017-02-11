from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from django.utils.translation import ugettext_lazy as _
from models import *

class EmployeesAdmin(UserAdmin):
    fieldsets = (
        (None, {'fields': ('username', 'password')}),
        (_('Personal info'), {'fields': ('first_name', 'last_name', 'email', 'gender',
                                         'date_of_birth', 'country', 'phone_number',
                                         'role', 'lineup')}),
        (_('Permissions'), {'fields': ('is_active', 'is_staff', 'is_superuser',
                                       'groups', 'user_permissions')}),
        (_('Important dates'), {'fields': ('last_login', 'date_joined')}),
    )
    list_display = ('username', 'last_name', 'first_name', 'email', 'is_active', 'is_staff',
                    'is_superuser', 'last_login', 'date_joined')
    list_display_links = ('username', 'last_name', 'first_name', 'email')
    list_filter = ()
    search_fields = ('last_name', 'first_name', 'username', 'email')


class PlayersAdmin(admin.ModelAdmin):
    list_display = ('surname', 'name', 'lineup', 'fromTeam', 'position', 'number')
    list_display_links = ('surname', 'name')
    search_fields = ('surname', 'name', 'fromTeam__name', 'lineup__name', 'position__name',
                     'number')


class TeamsAdmin(admin.ModelAdmin):
    list_display = ('name', 'inLeague')
    search_fields = ('name', )


class TrophiesAdmin(admin.ModelAdmin):
    list_display = ('name', 'season_start', 'season_end')
    list_display_links = ('name', 'season_start', 'season_end')
    search_fields = ('name', 'season_start', 'season_end')


class RolesAdmin(admin.ModelAdmin):
    search_fields = ('name',)


class SeasonsAdmin(admin.ModelAdmin):
    list_display = ('name', )
    search_fields = ('name',)


class GamesAdmin(admin.ModelAdmin):
    list_display = ('homeTeam', 'awayTeam', 'game_date', 'game_hour', 'match_result')
    list_display_links = ('homeTeam', 'awayTeam', 'game_date', 'game_hour', 'match_result')
    search_fields = ('homeTeam__name', 'awayTeam__name')


admin.site.register(Employees, EmployeesAdmin)
admin.site.register(Players, PlayersAdmin)
admin.site.register(Teams, TeamsAdmin)
admin.site.register(Trophies, TrophiesAdmin)
admin.site.register(Roles, RolesAdmin)
admin.site.register(Seasons, SeasonsAdmin)
admin.site.register(Games, GamesAdmin)
