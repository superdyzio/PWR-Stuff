# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Druzyna',
            fields=[
                ('Nazwa', models.CharField(default=b'', max_length=20, unique=True, serialize=False, primary_key=True)),
                ('Wynik_K', models.IntegerField(default=0)),
                ('Wynik_S', models.IntegerField(default=0)),
            ],
            options={
                'ordering': ('Nazwa',),
                'verbose_name_plural': 'Dru\u017cyny',
            },
        ),
        migrations.CreateModel(
            name='Kategoria',
            fields=[
                ('Kat', models.CharField(default=b'', max_length=4, unique=True, serialize=False, primary_key=True)),
            ],
            options={
                'ordering': ('Kat',),
                'verbose_name_plural': 'Kategorie',
            },
        ),
        migrations.CreateModel(
            name='Konkurencja',
            fields=[
                ('Nazwa', models.CharField(default=b'', max_length=20, unique=True, serialize=False, primary_key=True)),
            ],
            options={
                'ordering': ('Nazwa',),
                'verbose_name_plural': 'Konkurencje',
            },
        ),
        migrations.CreateModel(
            name='Ocena',
            fields=[
                ('ID', models.AutoField(unique=True, serialize=False, primary_key=True)),
                ('Czas', models.DateField()),
                ('Spontan', models.BooleanField(default=False)),
                ('Ocena', models.IntegerField(choices=[(0, b'0'), (1, b'1'), (2, b'2'), (3, b'3'), (4, b'4'), (5, b'5'), (6, b'6'), (7, b'7'), (8, b'8'), (9, b'9'), (10, b'10')])),
                ('Druzyna', models.ForeignKey(to='oceny.Druzyna')),
            ],
            options={
                'ordering': ('Czas', 'Druzyna'),
                'verbose_name_plural': 'Oceny',
            },
        ),
        migrations.CreateModel(
            name='Uczestnik',
            fields=[
                ('ID', models.AutoField(unique=True, serialize=False, primary_key=True)),
                ('Imie', models.CharField(default=b'', max_length=20)),
                ('Nazwisko', models.CharField(default=b'', max_length=30)),
                ('Lider', models.BooleanField(default=False)),
                ('Druzyna', models.ForeignKey(to='oceny.Druzyna')),
            ],
            options={
                'ordering': ('Nazwisko', 'Imie'),
                'verbose_name_plural': 'Uczestnicy',
            },
        ),
        migrations.CreateModel(
            name='Uzytkownik',
            fields=[
                ('Imie', models.CharField(default=b'', max_length=20)),
                ('Nazwisko', models.CharField(default=b'', max_length=30)),
                ('login', models.CharField(max_length=30, unique=True, serialize=False, primary_key=True)),
                ('uprawnienia', models.CommaSeparatedIntegerField(default=b'0000000000000000000000000000000000000000', max_length=40)),
                ('TS', models.CharField(default=b'S', max_length=3, choices=[(b'T', b'Trener'), (b'S', b'S\xc4\x99dzia')])),
                ('Team', models.CharField(max_length=20, blank=True)),
            ],
            options={
                'ordering': ('login',),
                'verbose_name_plural': 'U\u017cytkownicy',
            },
        ),
        migrations.AddField(
            model_name='ocena',
            name='Sedzia',
            field=models.ForeignKey(to='oceny.Uzytkownik'),
        ),
        migrations.AddField(
            model_name='druzyna',
            name='Kategoria',
            field=models.ForeignKey(blank=True, to='oceny.Kategoria', null=True),
        ),
        migrations.AddField(
            model_name='druzyna',
            name='Konkurencja',
            field=models.ForeignKey(blank=True, to='oceny.Konkurencja', null=True),
        ),
        migrations.AddField(
            model_name='druzyna',
            name='Trener',
            field=models.OneToOneField(to='oceny.Uzytkownik'),
        ),
    ]
